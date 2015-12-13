#ifndef NEWPROJECTDLG_H
#define NEWPROJECTDLG_H

#include <QDialog>
#include "ui_newprojectdlg.h"

class NewProjectDlg : public QDialog
{
	Q_OBJECT

public:
	NewProjectDlg(QWidget *parent = 0);
	~NewProjectDlg();

	QString projectName() { return m_projectName; }
	QString projectPath() { return m_path; }

protected:
	void accept() override;

private:
	void initForm();
	bool checkProjectName();
	bool checkProjectPath();

private slots:
	void onBrowse();

private:
	Ui::NewProjectDlg ui;

	QString m_projectName;
	QString m_path;
};

#endif // NEWPROJECTDLG_H
