#include "exceltopdf.h"
//�������̺귯���� ����ϱ����� ActiveX
#include <qobject.h>
#include <qaxobject.h>
//FileDialog
#include <QFileDialog>

QString g_sParamSourceBookPath; //���� ���� ���
QString g_sParamExportFilePath; //pdf ���� ���


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
	/* 1. QFileDialog�� Excel ���� ���� ��� ����
	2. textBrowser�� ���� ��� �� ���ϸ� ��� */

	QString m_sSzFilter = "Excel Files(*.xlsx)"; //���� Ȯ���� ����
	QFileDialog m_dlg;
	g_sParamSourceBookPath = m_dlg.getOpenFileName(this, tr("Open File"), tr("C://"), m_sSzFilter);

	textBrowser = ui.textBrowser;
	textBrowser->setText(g_sParamSourceBookPath); //textBrowser�� Excel ���, ���ϸ� ���
}

void ExcelToPdf::setPdfPath() //PDF ���� ��� �о����
{
	/* 1. QFileDialog�� PDF���� ���� ��� ����
	2. textBrowser_2�� ���� ��� �� ���ϸ� ��� */

	QString m_sSzFilter = "PDF Files(*.pdf)|*.pdf||"; //���� Ȯ���� ����
	QFileDialog m_dlg;
	g_sParamExportFilePath = m_dlg.getSaveFileName(this, tr("Save File"), tr("C://"), m_sSzFilter);

	textBrowser_2 = ui.textBrowser_2;
	textBrowser_2->setText(g_sParamExportFilePath); //textBrowser�� ���� ���, ���ϸ� ���
}

void ExcelToPdf::convertPdf() //PDF ��ȯ
{ 
	/* ���� ������ �� �������� ��� �� �������� ���� �� PDF�� ��ȯ 
	1. ���� ����
	2. �� �������� ��� �� ���� �����ϱ�
	3. PDF�� �����ϱ�*/

	//1. ���� ����
	QAxObject* m_excel = new QAxObject("Excel.Application", 0);
	QAxObject* m_workBooks = m_excel->querySubObject("Workbooks");
	QAxObject* m_workBook = m_workBooks->querySubObject("Open(const QString&)", g_sParamSourceBookPath);
	QAxObject* m_sheets = m_workBook->querySubObject("Worksheets");
	QAxObject* m_sheet;
	QAxObject* m_pageSetup;

	//Sheet �� ����
	int m_count = m_sheets->dynamicCall("Count()").toInt(); 
	m_count = m_sheets->property("Count").toInt();

	//Sheet ���� ŭ �� �������� ��� �� ���� ����
	for (int i = 1; i <= m_count; i++) 
	{
		//2. �� �������� ��� �� ���� �����ϱ�
		//���������� m_workSheets ����ŭ ����. ����, ��� ��Ʈ�� PageSetup ������ ����
		m_sheet = m_sheets->querySubObject("Item( int )", i);
		m_pageSetup = m_sheet->querySubObject("PageSetup");
		m_pageSetup->querySubObject("Zoom", false);
		m_pageSetup->querySubObject("FitToPagesWide(int)",1);
		m_pageSetup->querySubObject("FitToPagesTall",false);
	}
	
	//3. ���� ������ PDF�� �����Ѵ�.
	m_workBook->querySubObject("ExportAsFixedFormat(XlFixedFormatType, const QString&)", "xlTypePDF", g_sParamExportFilePath);

	m_workBook->dynamicCall("Close()");
	m_excel->dynamicCall("Quit()");
}