#include "exceltopdf.h"
//엑셀라이브러리를 사용하기위한 ActiveX
#include <qobject.h>
#include <qaxobject.h>
//FileDialog
#include <QFileDialog>

QString g_sParamSourceBookPath; //엑셀 파일 경로
QString g_sParamExportFilePath; //pdf 파일 경로


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
	/* 1. QFileDialog로 Excel 파일 저장 경로 지정
	2. textBrowser에 저장 경로 및 파일명 출력 */

	QString m_sSzFilter = "Excel Files(*.xlsx)"; //파일 확장자 지정
	QFileDialog m_dlg;
	g_sParamSourceBookPath = m_dlg.getOpenFileName(this, tr("Open File"), tr("C://"), m_sSzFilter);

	textBrowser = ui.textBrowser;
	textBrowser->setText(g_sParamSourceBookPath); //textBrowser에 Excel 경로, 파일명 출력
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

void ExcelToPdf::convertPdf() //PDF 변환
{ 
	/* 엑셀 파일을 한 페이지에 모든 열 맞춤으로 설정 후 PDF로 변환 
	1. 엑셀 열기
	2. 한 페이지에 모든 열 맞춤 설정하기
	3. PDF로 저장하기*/

	//1. 엑셀 열기
	QAxObject* m_excel = new QAxObject("Excel.Application", 0);
	QAxObject* m_workBooks = m_excel->querySubObject("Workbooks");
	QAxObject* m_workBook = m_workBooks->querySubObject("Open(const QString&)", g_sParamSourceBookPath);
	QAxObject* m_sheets = m_workBook->querySubObject("Worksheets");
	QAxObject* m_sheet;
	QAxObject* m_pageSetup;

	//Sheet 수 세기
	int m_count = m_sheets->dynamicCall("Count()").toInt(); 
	m_count = m_sheets->property("Count").toInt();

	//Sheet 수만 큼 한 페이지에 모든 열 맞춤 설정
	for (int i = 1; i <= m_count; i++) 
	{
		//2. 한 페이지에 모든 열 맞춤 설정하기
		//엑셀파일의 m_workSheets 수만큼 돌림. 이유, 모든 시트에 PageSetup 설정을 위해
		m_sheet = m_sheets->querySubObject("Item( int )", i);
		m_pageSetup = m_sheet->querySubObject("PageSetup");
		m_pageSetup->querySubObject("Zoom", false);
		m_pageSetup->querySubObject("FitToPagesWide(int)",1);
		m_pageSetup->querySubObject("FitToPagesTall",false);
	}
	
	//3. 엑셀 파일을 PDF로 저장한다.
	m_workBook->querySubObject("ExportAsFixedFormat(XlFixedFormatType, const QString&)", "xlTypePDF", g_sParamExportFilePath);

	m_workBook->dynamicCall("Close()");
	m_excel->dynamicCall("Quit()");
}