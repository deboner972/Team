#include "exceltopdf.h"
#include <qobject.h>
#include <qaxobject.h>

#include <QPageSetupDialog>
#include <qprinter.h>
#include <QPrintDialog>
#include <QFileDialog>

QString g_sParamSourceBookPath; //엑셀 파일 경로
QString g_sParamExportFilePath; //pdf 파일 경로


ExcelToPdf::ExcelToPdf(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.setExcelPath, SIGNAL(clicked()), this, SLOT(setExcelPath()));
	connect(ui.setPdfPath, SIGNAL(clicked()), this, SLOT(setPdfPath()));
	connect(ui.convertPdf, SIGNAL(clicked()), this, SLOT(convertPdf(int argc, char *argv[])));

}

ExcelToPdf::~ExcelToPdf()
{

}

void ExcelToPdf::setExcelPath()
{
	
}

void ExcelToPdf::setPdfPath() //PDF 저장 경로 읽어오기
{
	/* 1. QFileDialog로 PDF파일 저장 경로 지정
	   2. textBrowser_2에 저장 경로 및 파일명 출력 */

	QString m_sSzFilter = "PDF Files(*.pdf)|*.pdf||"; //파일 확장자 지정
	QFileDialog m_dlg;
	g_sParamExportFilePath = m_dlg.getSaveFileName(this, tr("Save File"), tr("C://"), m_sSzFilter);

	textBrowser_2 = ui.textBrowser_2;
	textBrowser_2->setText(g_sParamExportFilePath); //textBrowser에 저장 경로, 파일명 출력
}

void ExcelToPdf::convertPdf(int argc, char *argv[])
{

	//엑셀읽기
	//페이지설정
	//프린트
	QApplication app(argc, argv);
	if (QFileInfo(g_sParamExportFilePath).suffix().isEmpty()) { g_sParamExportFilePath.append(".pdf"); }

	QPrinter printer(QPrinter::PrinterResolution);
	printer.setOutputFormat(QPrinter::PdfFormat);
	printer.setPaperSize(QPrinter::A4);
	printer.setOutputFileName(g_sParamExportFilePath);

}

//엑셀 읽어오기 성공 //QXlxs -> QAxObject
//엑셀 한 페이지에 모든 열 맞춤 설정 QPageSetupDialog
//엑셀을 PDF로 저장	//QPrinter
