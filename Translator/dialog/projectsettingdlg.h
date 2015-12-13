#ifndef PROJECTSETTINGDLG_H
#define PROJECTSETTINGDLG_H

#include <QDialog>
#include "ui_projectsettingdlg.h"

class ProjectSettingDlg : public QDialog
{
	Q_OBJECT

public:
	ProjectSettingDlg(QWidget *parent = 0);
	~ProjectSettingDlg();

private:
	Ui::ProjectSettingDlg ui;
};

#endif // PROJECTSETTINGDLG_H
