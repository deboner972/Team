#include "exceltopdf.h"
#include <QtWidgets/QApplication>
#include "ui_exceltopdf.h"
#include "c:\Qt\Qt5.6.3\QtXlsxWriter-master\include\QtXlsx\xlsxdocument.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ExcelToPdf w;
	w.show();
	return a.exec();
}
