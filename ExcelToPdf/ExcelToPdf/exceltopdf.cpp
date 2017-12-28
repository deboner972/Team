#include "exceltopdf.h"
#include <qobject.h>
#include <qaxobject.h>
#include <QPageSetupDialog>
#include <qprinter.h>
#include <qprintpreviewdialog.h>
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

//���� �о���� ���� //QXlxs -> QAxObject
//���� �� �������� ��� �� ���� ���� QPageSetupDialog
//������ PDF�� ����	//QPrinter
