#include "stdafx.h"
#include "TransProject.h"
#include "io/ProjectIOAdapter.h"
#include "io/ProjectWriter.h"
#include "io/ProjectReader.h"

TransProject::TransProject()
	: m_bInited(false)
{
	m_dirSource = QDir("./source");
	m_dirTarget = QDir("./target");
}

TransProject::~TransProject()
{

}

bool TransProject::create(QString name, QString path)
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

bool TransProject::open(QString filePath)
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

QString TransProject::fullPath() const
{
	return QString("%1/%2%3").arg(m_path, m_name, QSTR_ProjectExt);
}
