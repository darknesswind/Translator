#include "stdafx.h"
#include "ProjectReader.h"
#include "ProjectIOAdapter.h"
#include <QFileInfo>
#include <QXmlStreamReader>

ProjectReader::ProjectReader()
{
}

ProjectReader::~ProjectReader()
{
}

bool ProjectReader::read(ProjectIOAdapter& proj, QString filePath)
{
	QFileInfo info(filePath);
	proj.setName(info.baseName());
	proj.setPath(info.path());

	QFile file(filePath);
	if (!file.open(QFile::ReadOnly))
	{
		QMessageBox::warning(nullptr, QSTR_Error, QSTR_Err_OpenFailed);
		return false;
	}

	QXmlStreamReader xml(&file);

	file.close();
	return true;
}

void ProjectReader::readProject(ProjectIOAdapter& proj, QXmlStreamReader& xml)
{

}
