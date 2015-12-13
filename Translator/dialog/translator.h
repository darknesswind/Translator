#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QtWidgets/QMainWindow>
#include "ui_translator.h"

class Translator : public QMainWindow
{
	Q_OBJECT

public:
	Translator(QWidget *parent = 0);
	~Translator();

private:
	void initMenu();

private:
	Ui::TranslatorClass ui;
};

#endif // TRANSLATOR_H
