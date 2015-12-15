#include "stdafx.h"
#include "FileFilterBase.h"
#include <QTextCodec>
#include <QFileInfo>
#include "TextFilter.h"

QMap<QString, FilterPtr> FileFilterBase::s_filterMap;

void FileFilterBase::InitBuildInFilter()
{
	RegisterFilter(std::make_shared<TextFilter>("*.txt", "Shift-JIS", "GBK"));
}

bool FileFilterBase::RegisterFilter(FilterPtr spFilter)
{
	if (nullptr == spFilter)
		return false;

	QString sName = spFilter->formatName();
	auto iter = s_filterMap.find(sName);
	if (iter != s_filterMap.end() && nullptr != iter.value())
		return false;

	s_filterMap[sName] = spFilter;
	return true;
}

FilterPtr FileFilterBase::GetFilter(QString name)
{
	auto iter = s_filterMap.find(name);
	if (iter != s_filterMap.end() && nullptr != iter.value())
		return iter.value();
	else
		return nullptr;
}

FileFilterBase::FileFilterBase(QString sPattern, const QByteArray& inputCodec, const QByteArray& outputCodec)
{
	m_patten.setPattern(sPattern);
	m_patten.setCaseSensitivity(Qt::CaseInsensitive);
	m_patten.setPatternSyntax(QRegExp::Wildcard);

	QTextCodec* pLocalCodec = QTextCodec::codecForLocale();

	m_pInCodec = QTextCodec::codecForName(inputCodec);
	if (!m_pInCodec)
		m_pInCodec = pLocalCodec;

	m_pOutCodec = QTextCodec::codecForName(outputCodec);
	if (!m_pOutCodec)
		m_pOutCodec = pLocalCodec;
}

bool FileFilterBase::isSupportFormat(const QFileInfo& info)
{
	return m_patten.exactMatch(info.fileName());
}

QString FileFilterBase::codecName() const
{
	return QString::fromLatin1(m_pInCodec->name());
}

