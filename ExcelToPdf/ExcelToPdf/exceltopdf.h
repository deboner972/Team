#ifndef EXCELTOPDF_H
#define EXCELTOPDF_H

#include <QtWidgets/QMainWindow>
#include "ui_exceltopdf.h"

class ExcelToPdf : public QMainWindow
{
	Q_OBJECT

public:
	ExcelToPdf(QWidget *parent = 0);
	~ExcelToPdf();

private slots:
	void setExcelPath();
	void setPdfPath();
	void convertPdf();

private:
	Ui::ExcelToPdfClass ui;
	QTextBrowser *textBrowser_2;
};

#endif // EXCELTOPDF_H
