#include "exceltopdf.h"
#include <qobject.h>
#include <qaxobject.h>

#include <QPageSetupDialog>
#include <qprinter.h>
#include <QPrintDialog>
#include <QFileDialog>

QString g_sParamSourceBookPath; //���� ���� ���
QString g_sParamExportFilePath; //pdf ���� ���


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

void ExcelToPdf::convertPdf(int argc, char *argv[])
{

	//�����б�
	//����������
	//����Ʈ
	QApplication app(argc, argv);
	if (QFileInfo(g_sParamExportFilePath).suffix().isEmpty()) { g_sParamExportFilePath.append(".pdf"); }

	QPrinter printer(QPrinter::PrinterResolution);
	printer.setOutputFormat(QPrinter::PdfFormat);
	printer.setPaperSize(QPrinter::A4);
	printer.setOutputFileName(g_sParamExportFilePath);

}

//���� �о���� ���� //QXlxs -> QAxObject
//���� �� �������� ��� �� ���� ���� QPageSetupDialog
//������ PDF�� ����	//QPrinter
