#include "exceltopdf.h"
#include <qobject.h>
#include <qaxobject.h>
#include <QPageSetupDialog>
#include <qprinter.h>
#include <qprintpreviewdialog.h>

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
	QString filepath = "C:\\11.xlsx";
	QAxObject *excel = NULL;
	QAxObject *workbooks = NULL;
	QAxObject *workbook = NULL;

	excel = new QAxObject("Excel.Application");

	excel->dynamicCall("SetVisible(bool)", true);
	
	workbooks = excel->querySubObject("WorkBooks");

	workbook = workbooks->querySubObject("Open(const QString&, QVariant)", filepath, 0);


	workbook->dynamicCall("Close (Boolean)", false);
	delete excel;
}

//엑셀 읽어오기 성공 //QXlxs -> QAxObject
//엑셀 한 페이지에 모든 열 맞춤 설정 QPageSetupDialog
//엑셀을 PDF로 저장	//QPrinter
