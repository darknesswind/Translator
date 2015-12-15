#include "stdafx.h"
#include "projfilewidget.h"
#include "core/TransProject.h"

enum
{
	idxFileName = 0,
	idxFilter,
	idxCodec,
};

ProjFileWidget::ProjFileWidget(QWidget *parent)
	: QWidget(parent)
	, m_pProject(nullptr)
{
	ui.setupUi(this);
}

ProjFileWidget::~ProjFileWidget()
{

}

void ProjFileWidget::setProject(TransProject* pProject)
{
	m_pProject = pProject;
}

void ProjFileWidget::onProjectLoaded()
{
	if (!m_pProject)
		return;

	ui.tableWidget->clearContents();
	const TranslateFiles& files = m_pProject->transFiles();
	for (auto iter = files.begin(); iter != files.end(); ++iter)
	{
		int nLast = ui.tableWidget->rowCount();
		ui.tableWidget->insertRow(nLast);

		ui.tableWidget->setItem(nLast, idxFileName, new QTableWidgetItem(iter->relFilePath()));
		ui.tableWidget->setItem(nLast, idxFilter, new QTableWidgetItem(iter->formatName()));
		ui.tableWidget->setItem(nLast, idxCodec, new QTableWidgetItem(iter->codecName()));
	}

	ui.tableWidget->setColumnWidth(idxFileName, 200);
}
