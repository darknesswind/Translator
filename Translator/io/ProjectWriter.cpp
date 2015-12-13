#include "stdafx.h"
#include "ProjectWriter.h"
#include "ProjectIOAdapter.h"
#include <QDir>
#include <QFile>
#include <QXmlStreamWriter>

ProjectWriter::ProjectWriter()
	: m_errCode(NoError)
{
}

ProjectWriter::~ProjectWriter()
{
}

bool ProjectWriter::write(const ProjectIOAdapter& proj)
{
	if (!QDir::current().mkpath(proj.path()))
	{
		QMessageBox::warning(nullptr, QSTR_Error, QSTR_Err_MkPathFailed.arg(proj.path()));
		m_errCode = PathError;
		return false;
	}

	QString fullPath = QString("%1/%2%3").arg(proj.path(), proj.name(), QSTR_ProjectExt);
	QFile file(fullPath);
	if (file.exists())
	{
		QMessageBox::StandardButton res = QMessageBox::information(
			nullptr,
			QString(),
			QSTR_Ask_FileExist.arg(fullPath),
			QMessageBox::Yes,
			QMessageBox::No);
		if (res != QMessageBox::Yes)
			return false;
	}

	if (!file.open(QFile::WriteOnly))
	{
		QMessageBox::warning(nullptr, QSTR_Error, QSTR_Err_OpenFailed.arg(fullPath));
		m_errCode = OpenFileError;
		return false;
	}

	QXmlStreamWriter xml(&file);
	xml.setAutoFormatting(true);
	writeProject(proj, xml);

	file.close();
	return (NoError == m_errCode);
}

void ProjectWriter::writeProject(const ProjectIOAdapter& proj, QXmlStreamWriter& xml)
{
	xml.writeStartDocument("1.0");
	xml.writeStartElement("project");
	xml.writeAttribute("toolversion", "1.0");
	xml.writeEndElement();
	xml.writeEndDocument();
}
