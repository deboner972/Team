#include "exceltopdf.h"
#include <qobject.h>
#include <QtXlsx>

ExcelToPdf::ExcelToPdf(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.setExcelPath, SIGNAL(clicked()), this, SLOT(setExcelPath()));
	connect(ui.setPdfPath, SIGNAL(clicked()), this, SLOT(setPdfPath()));
	connect(ui.convertPdf, SIGNAL(clicked()), this, SLOT(convertPdf()));

}

ExcelToPdf::~ExcelToPdf()
{

}

void ExcelToPdf::setExcelPath()
{
	
}

void ExcelToPdf::setPdfPath()
{
	
}


void ExcelToPdf::convertPdf()
{
	
}