/********************************************************************************
** Form generated from reading UI file 'translator.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSLATOR_H
#define UI_TRANSLATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TranslatorClass
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionRecent;
    QAction *actionOpenGit;
    QAction *actionReload;
    QAction *actionClose;
    QAction *actionSave;
    QAction *actionReleaseCur;
    QAction *actionReleaseAll;
    QAction *actionSetting;
    QAction *actionQuit;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_Edit;
    QMenu *menu_View;
    QMenu *menu_Option;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TranslatorClass)
    {
        if (TranslatorClass->objectName().isEmpty())
            TranslatorClass->setObjectName(QStringLiteral("TranslatorClass"));
        TranslatorClass->resize(600, 400);
        actionNew = new QAction(TranslatorClass);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionOpen = new QAction(TranslatorClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionRecent = new QAction(TranslatorClass);
        actionRecent->setObjectName(QStringLiteral("actionRecent"));
        actionOpenGit = new QAction(TranslatorClass);
        actionOpenGit->setObjectName(QStringLiteral("actionOpenGit"));
        actionReload = new QAction(TranslatorClass);
        actionReload->setObjectName(QStringLiteral("actionReload"));
        actionClose = new QAction(TranslatorClass);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionSave = new QAction(TranslatorClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionReleaseCur = new QAction(TranslatorClass);
        actionReleaseCur->setObjectName(QStringLiteral("actionReleaseCur"));
        actionReleaseAll = new QAction(TranslatorClass);
        actionReleaseAll->setObjectName(QStringLiteral("actionReleaseAll"));
        actionSetting = new QAction(TranslatorClass);
        actionSetting->setObjectName(QStringLiteral("actionSetting"));
        actionQuit = new QAction(TranslatorClass);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralWidget = new QWidget(TranslatorClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        TranslatorClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TranslatorClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menu_Edit = new QMenu(menuBar);
        menu_Edit->setObjectName(QStringLiteral("menu_Edit"));
        menu_View = new QMenu(menuBar);
        menu_View->setObjectName(QStringLiteral("menu_View"));
        menu_Option = new QMenu(menuBar);
        menu_Option->setObjectName(QStringLiteral("menu_Option"));
        TranslatorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TranslatorClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TranslatorClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TranslatorClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TranslatorClass->setStatusBar(statusBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_Edit->menuAction());
        menuBar->addAction(menu_View->menuAction());
        menuBar->addAction(menu_Option->menuAction());
        menu_File->addAction(actionNew);
        menu_File->addAction(actionOpen);
        menu_File->addAction(actionOpenGit);
        menu_File->addAction(actionRecent);
        menu_File->addAction(actionReload);
        menu_File->addAction(actionClose);
        menu_File->addSeparator();
        menu_File->addAction(actionSave);
        menu_File->addSeparator();
        menu_File->addAction(actionReleaseCur);
        menu_File->addAction(actionReleaseAll);
        menu_File->addSeparator();
        menu_File->addAction(actionSetting);
        menu_File->addSeparator();
        menu_File->addAction(actionQuit);

        retranslateUi(TranslatorClass);

        QMetaObject::connectSlotsByName(TranslatorClass);
    } // setupUi

    void retranslateUi(QMainWindow *TranslatorClass)
    {
        TranslatorClass->setWindowTitle(QApplication::translate("TranslatorClass", "Translator", 0));
        actionNew->setText(QApplication::translate("TranslatorClass", "&New Project", 0));
        actionOpen->setText(QApplication::translate("TranslatorClass", "&Open Project", 0));
        actionRecent->setText(QApplication::translate("TranslatorClass", "Recent Project", 0));
        actionOpenGit->setText(QApplication::translate("TranslatorClass", "Open Git Project", 0));
        actionReload->setText(QApplication::translate("TranslatorClass", "Reload Project", 0));
        actionClose->setText(QApplication::translate("TranslatorClass", "Close Project", 0));
        actionSave->setText(QApplication::translate("TranslatorClass", "Save", 0));
        actionReleaseCur->setText(QApplication::translate("TranslatorClass", "Release Current", 0));
        actionReleaseAll->setText(QApplication::translate("TranslatorClass", "Release All", 0));
        actionSetting->setText(QApplication::translate("TranslatorClass", "Project Setting", 0));
        actionQuit->setText(QApplication::translate("TranslatorClass", "Quit", 0));
        menu_File->setTitle(QApplication::translate("TranslatorClass", "&Project", 0));
        menu_Edit->setTitle(QApplication::translate("TranslatorClass", "&Edit", 0));
        menu_View->setTitle(QApplication::translate("TranslatorClass", "&View", 0));
        menu_Option->setTitle(QApplication::translate("TranslatorClass", "&Option", 0));
    } // retranslateUi

};

namespace Ui {
    class TranslatorClass: public Ui_TranslatorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSLATOR_H
