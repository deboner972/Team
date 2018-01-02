#ifndef EXCELTOPDF_H
#define EXCELTOPDF_H

#include <QtWidgets/QMainWindow>
#include "ui_exceltopdf.h"
#include "c:\Qt\Qt5.6.3\QtXlsxWriter-master\include\QtXlsx\xlsxdocument.h"

class ExcelToPdf : public QMainWindow
{
	Q_OBJECT

public:
	ExcelToPdf(QWidget *parent = 0);
	~ExcelToPdf();

public slots:
	void setExcelPath();
	void setPdfPath();
	void convertPdf();

private:
	Ui::ExcelToPdfClass ui;
	QTextBrowser *textBrowser_2;
	QTextBrowser *textBrowser;
};

#endif // EXCELTOPDF_H
