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
    QMenu *menuFile;
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
        actionReload->setEnabled(false);
        actionClose = new QAction(TranslatorClass);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionClose->setEnabled(false);
        actionSave = new QAction(TranslatorClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave->setEnabled(false);
        actionReleaseCur = new QAction(TranslatorClass);
        actionReleaseCur->setObjectName(QStringLiteral("actionReleaseCur"));
        actionReleaseCur->setEnabled(false);
        actionReleaseAll = new QAction(TranslatorClass);
        actionReleaseAll->setObjectName(QStringLiteral("actionReleaseAll"));
        actionReleaseAll->setEnabled(false);
        actionSetting = new QAction(TranslatorClass);
        actionSetting->setObjectName(QStringLiteral("actionSetting"));
        actionSetting->setEnabled(false);
        actionQuit = new QAction(TranslatorClass);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralWidget = new QWidget(TranslatorClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        TranslatorClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TranslatorClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
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

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menu_Edit->menuAction());
        menuBar->addAction(menu_View->menuAction());
        menuBar->addAction(menu_Option->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionOpenGit);
        menuFile->addAction(actionRecent);
        menuFile->addAction(actionReload);
        menuFile->addAction(actionClose);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionReleaseCur);
        menuFile->addAction(actionReleaseAll);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menu_Option->addAction(actionSetting);

        retranslateUi(TranslatorClass);

        QMetaObject::connectSlotsByName(TranslatorClass);
    } // setupUi

    void retranslateUi(QMainWindow *TranslatorClass)
    {
        TranslatorClass->setWindowTitle(QApplication::translate("TranslatorClass", "Translator", 0));
        actionNew->setText(QApplication::translate("TranslatorClass", "&New Project", 0));
        actionNew->setShortcut(QApplication::translate("TranslatorClass", "Ctrl+N", 0));
        actionOpen->setText(QApplication::translate("TranslatorClass", "&Open Project", 0));
        actionOpen->setShortcut(QApplication::translate("TranslatorClass", "Ctrl+O", 0));
        actionRecent->setText(QApplication::translate("TranslatorClass", "Recent Project", 0));
        actionOpenGit->setText(QApplication::translate("TranslatorClass", "Creckout &Git Project", 0));
        actionReload->setText(QApplication::translate("TranslatorClass", "&Reload Project", 0));
        actionClose->setText(QApplication::translate("TranslatorClass", "&Close Project", 0));
        actionSave->setText(QApplication::translate("TranslatorClass", "&Save", 0));
        actionSave->setShortcut(QApplication::translate("TranslatorClass", "Ctrl+S", 0));
        actionReleaseCur->setText(QApplication::translate("TranslatorClass", "Release Current", 0));
        actionReleaseAll->setText(QApplication::translate("TranslatorClass", "Release All", 0));
        actionSetting->setText(QApplication::translate("TranslatorClass", "Project Setting", 0));
        actionQuit->setText(QApplication::translate("TranslatorClass", "Quit", 0));
        menuFile->setTitle(QApplication::translate("TranslatorClass", "&Project", 0));
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
