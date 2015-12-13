/********************************************************************************
** Form generated from reading UI file 'projectsettingdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECTSETTINGDLG_H
#define UI_PROJECTSETTINGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_ProjectSettingDlg
{
public:

    void setupUi(QDialog *ProjectSettingDlg)
    {
        if (ProjectSettingDlg->objectName().isEmpty())
            ProjectSettingDlg->setObjectName(QStringLiteral("ProjectSettingDlg"));
        ProjectSettingDlg->resize(591, 370);

        retranslateUi(ProjectSettingDlg);

        QMetaObject::connectSlotsByName(ProjectSettingDlg);
    } // setupUi

    void retranslateUi(QDialog *ProjectSettingDlg)
    {
        ProjectSettingDlg->setWindowTitle(QApplication::translate("ProjectSettingDlg", "Project Setting", 0));
    } // retranslateUi

};

namespace Ui {
    class ProjectSettingDlg: public Ui_ProjectSettingDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECTSETTINGDLG_H
