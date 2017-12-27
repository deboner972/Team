#include "exceltopdf.h"
#include <QtWidgets/QApplication>
#include "ui_exceltopdf.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ExcelToPdf w;
	w.show();
	return a.exec();
}
