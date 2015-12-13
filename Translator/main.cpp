#include "stdafx.h"
#include "translator.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Translator w;
	w.show();
	return a.exec();
}
