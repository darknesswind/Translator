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

private slots:
	void updateProjectMenu();

	void onActionNew();
	void onActionOpen();

private:
	Ui::TranslatorClass ui;

	std::unique_ptr<TransProject> m_spProject;
};

#endif // TRANSLATOR_H
