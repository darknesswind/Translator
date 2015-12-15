#include "stdafx.h"
#include "TransFile.h"
#include "TransProject.h"
#include "filter/FileFilterBase.h"

TransFile::TransFile(TransProject* pProject, const QFileInfo& info, FilterPtr& spFilter)
	: m_pProject(pProject)
	, m_info(info)
	, m_spFilter(spFilter)
{
	m_relPath = m_pProject->sourceDir().relativeFilePath(m_info.filePath());
}


TransFile::~TransFile()
{
}

QString TransFile::formatName() const
{
	return m_spFilter->formatName();
}

QString TransFile::codecName() const
{
	return m_spFilter->codecName();
}
