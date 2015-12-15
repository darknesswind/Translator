#ifndef PROJFILEWIDGET_H
#define PROJFILEWIDGET_H

#include <QWidget>
#include "ui_projfilewidget.h"

class TransProject;
class ProjFileWidget : public QWidget
{
	Q_OBJECT

public:
	ProjFileWidget(QWidget *parent = 0);
	~ProjFileWidget();

	void setProject(TransProject* pProject);

public slots:
	void onProjectLoaded();

private:
	Ui::ProjFileWidget ui;
	TransProject* m_pProject;
};

#endif // PROJFILEWIDGET_H
