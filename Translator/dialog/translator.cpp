#include "stdafx.h"
#include "translator.h"
#include "newprojectdlg.h"
#include "projectsettingdlg.h"

#include "core/transProject.h"
#include "filter/FileFilterBase.h"
#include <QFileDialog>

Translator::Translator(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	initMenu();

	connect(this, &Translator::projectLoaded, ui.projFileWidget, &ProjFileWidget::onProjectLoaded);

	FileFilterBase::InitBuildInFilter();
}

Translator::~Translator()
{

}

void Translator::initMenu()
{
// 	connect(ui.menuFile, &QMenu::aboutToShow, this, &Translator::updateProjectMenu);
	connect(ui.actionNew, &QAction::triggered, this, &Translator::onActionNew);
	connect(ui.actionOpen, &QAction::triggered, this, &Translator::onActionOpen);

	connect(ui.actionProjectFile, &QAction::toggled, this, &Translator::onActProjectFileView);
	connect(ui.dockProjFile, &QDockWidget::visibilityChanged, ui.actionProjectFile, &QAction::setChecked);

}

void Translator::onProjectLoaded()
{
	if (!m_spProject)
		return;

	setWindowTitle(m_spProject->projectName());
	updateProjectMenu();
	m_spProject->refreshFilter();
	m_spProject->refreshSource();
	ui.projFileWidget->setProject(m_spProject.get());
	emit projectLoaded();
}

void Translator::updateProjectMenu()
{
	bool bHasProject = (m_spProject.get());

	ui.actionReload->setEnabled(bHasProject);
	ui.actionClose->setEnabled(bHasProject);
	ui.actionSave->setEnabled(bHasProject);
	ui.actionReleaseAll->setEnabled(bHasProject);
	ui.actionReleaseCur->setEnabled(bHasProject);
}

#pragma region Actions

void Translator::onActionNew()
{
	NewProjectDlg newPrjDlg(this);
	if (QDialog::Rejected == newPrjDlg.exec())
		return;

	m_spProject = std::make_unique<TransProject>();
	if (!m_spProject->create(newPrjDlg.projectName(), newPrjDlg.projectPath()))
	{
		m_spProject.reset();
		return;
	}
	onProjectLoaded();
}

void Translator::onActionOpen()
{
	QString file = QFileDialog::getOpenFileName(
		this,
		tr("Open Project"),
		QString::fromUtf16((ushort*)L"D:/Develop/GitHub/幻想人形演舞外伝/"),//QDir::current().path(),
		"*.trproj");

	m_spProject = std::make_unique<TransProject>();
	if (!m_spProject->open(file))
	{
		m_spProject.reset();
		return;
	}
	onProjectLoaded();
}

void Translator::onActProjectFileView(bool bVisible)
{
	ui.dockProjFile->setVisible(bVisible);
}

#pragma endregion
