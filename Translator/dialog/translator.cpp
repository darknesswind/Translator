#include "stdafx.h"
#include "translator.h"
#include "io/tmxReader.h"

Translator::Translator(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	initMenu();
}

Translator::~Translator()
{

}

void Translator::initMenu()
{

}
