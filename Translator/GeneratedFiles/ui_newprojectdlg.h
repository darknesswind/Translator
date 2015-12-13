/********************************************************************************
** Form generated from reading UI file 'newprojectdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWPROJECTDLG_H
#define UI_NEWPROJECTDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NewProjectDlg
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *edName;
    QLabel *label_2;
    QLineEdit *edPath;
    QPushButton *btnBrowse;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *btnGroup;

    void setupUi(QDialog *NewProjectDlg)
    {
        if (NewProjectDlg->objectName().isEmpty())
            NewProjectDlg->setObjectName(QStringLiteral("NewProjectDlg"));
        NewProjectDlg->resize(400, 106);
        verticalLayout = new QVBoxLayout(NewProjectDlg);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(NewProjectDlg);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        edName = new QLineEdit(NewProjectDlg);
        edName->setObjectName(QStringLiteral("edName"));
        edName->setMaxLength(255);

        gridLayout->addWidget(edName, 0, 1, 1, 1);

        label_2 = new QLabel(NewProjectDlg);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        edPath = new QLineEdit(NewProjectDlg);
        edPath->setObjectName(QStringLiteral("edPath"));

        gridLayout->addWidget(edPath, 1, 1, 1, 1);

        btnBrowse = new QPushButton(NewProjectDlg);
        btnBrowse->setObjectName(QStringLiteral("btnBrowse"));

        gridLayout->addWidget(btnBrowse, 1, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnGroup = new QDialogButtonBox(NewProjectDlg);
        btnGroup->setObjectName(QStringLiteral("btnGroup"));
        btnGroup->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(btnGroup);


        verticalLayout->addLayout(horizontalLayout);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(edName);
        label_2->setBuddy(edPath);
#endif // QT_NO_SHORTCUT

        retranslateUi(NewProjectDlg);
        QObject::connect(btnGroup, SIGNAL(accepted()), NewProjectDlg, SLOT(accept()));
        QObject::connect(btnGroup, SIGNAL(rejected()), NewProjectDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewProjectDlg);
    } // setupUi

    void retranslateUi(QDialog *NewProjectDlg)
    {
        NewProjectDlg->setWindowTitle(QApplication::translate("NewProjectDlg", "New Project", 0));
        label->setText(QApplication::translate("NewProjectDlg", "Project &Name:", 0));
        label_2->setText(QApplication::translate("NewProjectDlg", "Project &Location:", 0));
        btnBrowse->setText(QApplication::translate("NewProjectDlg", "&Browse...", 0));
    } // retranslateUi

};

namespace Ui {
    class NewProjectDlg: public Ui_NewProjectDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPROJECTDLG_H
