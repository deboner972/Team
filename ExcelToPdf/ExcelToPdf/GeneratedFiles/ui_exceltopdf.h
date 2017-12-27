/********************************************************************************
** Form generated from reading UI file 'exceltopdf.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXCELTOPDF_H
#define UI_EXCELTOPDF_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExcelToPdfClass
{
public:
    QWidget *centralWidget;
    QTextBrowser *textBrowser;
    QPushButton *setExcelPath;
    QTextBrowser *textBrowser_2;
    QPushButton *setPdfPath;
    QPushButton *convertPdf;

    void setupUi(QMainWindow *ExcelToPdfClass)
    {
        if (ExcelToPdfClass->objectName().isEmpty())
            ExcelToPdfClass->setObjectName(QStringLiteral("ExcelToPdfClass"));
        ExcelToPdfClass->resize(532, 132);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ExcelToPdfClass->sizePolicy().hasHeightForWidth());
        ExcelToPdfClass->setSizePolicy(sizePolicy);
        ExcelToPdfClass->setMinimumSize(QSize(532, 132));
        ExcelToPdfClass->setMaximumSize(QSize(532, 132));
        centralWidget = new QWidget(ExcelToPdfClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(10, 10, 371, 31));
        textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser->setLineWrapMode(QTextEdit::NoWrap);
        setExcelPath = new QPushButton(centralWidget);
        setExcelPath->setObjectName(QStringLiteral("setExcelPath"));
        setExcelPath->setGeometry(QRect(390, 10, 131, 31));
        textBrowser_2 = new QTextBrowser(centralWidget);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(9, 50, 371, 31));
        textBrowser_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser_2->setLineWrapMode(QTextEdit::NoWrap);
        setPdfPath = new QPushButton(centralWidget);
        setPdfPath->setObjectName(QStringLiteral("setPdfPath"));
        setPdfPath->setGeometry(QRect(390, 50, 131, 31));
        convertPdf = new QPushButton(centralWidget);
        convertPdf->setObjectName(QStringLiteral("convertPdf"));
        convertPdf->setGeometry(QRect(10, 90, 511, 31));
        ExcelToPdfClass->setCentralWidget(centralWidget);

        retranslateUi(ExcelToPdfClass);

        QMetaObject::connectSlotsByName(ExcelToPdfClass);
    } // setupUi

    void retranslateUi(QMainWindow *ExcelToPdfClass)
    {
        ExcelToPdfClass->setWindowTitle(QApplication::translate("ExcelToPdfClass", "ExcelToPdf", Q_NULLPTR));
        setExcelPath->setText(QApplication::translate("ExcelToPdfClass", "\354\227\264\352\270\260", Q_NULLPTR));
        setPdfPath->setText(QApplication::translate("ExcelToPdfClass", "\354\240\200\354\236\245", Q_NULLPTR));
        convertPdf->setText(QApplication::translate("ExcelToPdfClass", "PDF \353\263\200\355\231\230", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ExcelToPdfClass: public Ui_ExcelToPdfClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXCELTOPDF_H
