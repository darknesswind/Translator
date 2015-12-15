#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QtWidgets/QMainWindow>
#include "ui_translator.h"

class TransProject;
class Translator : public QMainWindow
{
	Q_OBJECT

public:
	Translator(QWidget *parent = 0);
	~Translator();

private:
	void initMenu();
	void onProjectLoaded();

signals:
	void projectLoaded();

private slots:
	void updateProjectMenu();

	void onActionNew();
	void onActionOpen();
	void onActProjectFileView(bool bVisible);

private:
	Ui::TranslatorClass ui;

	std::unique_ptr<TransProject> m_spProject;
};

#endif // TRANSLATOR_H
