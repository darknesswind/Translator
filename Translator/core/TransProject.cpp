#include "stdafx.h"
#include "TransProject.h"
#include "io/ProjectIOAdapter.h"
#include "io/ProjectWriter.h"
#include "io/ProjectReader.h"
#include "filter/FileFilterBase.h"

TransProject::TransProject()
	: m_bInited(false)
{
	m_srcRelPath = "./source";
	m_dstRelPath = "./target";
}

TransProject::~TransProject()
{

}

bool TransProject::create(const QString& name, const QString& path)
{
	assert(!m_bInited);

	m_name = name;
	m_path = path;

	ProjectIOAdapter adapter(*this);
	ProjectWriter writer;
	if (writer.write(adapter))
		m_bInited = true;

	return m_bInited;
}

bool TransProject::open(const QString& filePath)
{
	assert(!m_bInited);
	ProjectIOAdapter adapter(*this);
	ProjectReader reader;
	if (reader.read(adapter, filePath))
		m_bInited = true;

	return m_bInited;
}

bool TransProject::save()
{
	assert(m_bInited);
	return false;
}

void TransProject::refreshFilter()
{
	m_filters.clear();
	installFilter(FileFilterBase::GetFilter("Text"));
}

template <class Func>
void EnumFiles(const QDir& dir, Func func)
{
	QFileInfoList list = dir.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);
	for (auto iter = list.begin(); iter != list.end(); ++iter)
	{
		if (iter->isFile())
		{
			func(*iter);
		}
		else if (iter->isDir())
		{
			EnumFiles(QDir(iter->filePath()), func);
		}
	}
}

void TransProject::refreshSource()
{
	QDir root(m_path);
	if (!root.cd(m_srcRelPath))
		return;

	EnumFiles(root, [this](const QFileInfo& info)
	{
		for (auto iter = m_filters.begin(); iter != m_filters.end(); ++iter)
		{
			if ((*iter)->isSupportFormat(info))
			{
				m_transFiles.push_back(TransFile(this, info, *iter));
				break;
			}
		}
	});
}

QDir TransProject::sourceDir() const
{
	QDir source(m_path);
	source.cd(m_srcRelPath);
	return source;
}

QString TransProject::fullPath() const
{
	return QString("%1/%2%3").arg(m_path, m_name, QSTR_ProjectExt);
}

void TransProject::installFilter(FilterPtr spFilter)
{
	if (spFilter)
		m_filters.push_back(spFilter);
}
