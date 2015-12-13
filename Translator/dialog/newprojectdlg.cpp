#include "stdafx.h"
#include "newprojectdlg.h"
#include <QFileInfo>
#include <QFileDialog>

NewProjectDlg::NewProjectDlg(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	initForm();
}

NewProjectDlg::~NewProjectDlg()
{

}

void NewProjectDlg::accept()
{
	if (!checkProjectName())
		return;

	if (!checkProjectPath())
		return;

	QDialog::accept();
}

void NewProjectDlg::initForm()
{
	connect(ui.btnBrowse, &QPushButton::clicked, this, &NewProjectDlg::onBrowse);
}

bool NewProjectDlg::checkProjectName()
{
	m_projectName = ui.edName->text();
	if (m_projectName.isEmpty())
	{
		QMessageBox::warning(this, QSTR_Error, tr("Name is empty!"));
		ui.edName->setFocus();
		return false;
	}
	QRegExp validName("[\\\\/:*?\"<>|]");
	if ((uint)m_projectName.indexOf(validName) < (uint)m_projectName.size())
	{
		QMessageBox::warning(this, QSTR_Error, tr(R"(Char \/:*?"<>| is not allow!)"));
		ui.edName->setFocus();
		return false;
	}
	return true;
}

bool NewProjectDlg::checkProjectPath()
{
	m_path = ui.edPath->text();
	if (m_path.isEmpty())
	{
		QMessageBox::warning(this, QSTR_Error, tr("Path is empty!"));
		ui.edPath->setFocus();
		return false;
	}

	if (!QDir::current().mkpath(m_path))
	{
		QMessageBox::warning(this, QSTR_Error, QSTR_Err_MkPathFailed.arg(m_path));
		ui.edPath->setFocus();
		return false;
	}
	return true;
}

void NewProjectDlg::onBrowse()
{
	QString newPath = QFileDialog::getExistingDirectory(
		this,
		tr("Select project location"),
		ui.edPath->text());

	if (!newPath.isEmpty())
		ui.edPath->setText(newPath);
}
