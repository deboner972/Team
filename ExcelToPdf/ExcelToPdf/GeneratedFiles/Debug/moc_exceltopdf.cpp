/****************************************************************************
** Meta object code from reading C++ file 'exceltopdf.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../exceltopdf.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'exceltopdf.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ExcelToPdf_t {
    QByteArrayData data[8];
    char stringdata0[65];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ExcelToPdf_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ExcelToPdf_t qt_meta_stringdata_ExcelToPdf = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ExcelToPdf"
QT_MOC_LITERAL(1, 11, 12), // "setExcelPath"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 10), // "setPdfPath"
QT_MOC_LITERAL(4, 36, 10), // "convertPdf"
QT_MOC_LITERAL(5, 47, 4), // "argc"
QT_MOC_LITERAL(6, 52, 7), // "char*[]"
QT_MOC_LITERAL(7, 60, 4) // "argv"

    },
    "ExcelToPdf\0setExcelPath\0\0setPdfPath\0"
    "convertPdf\0argc\0char*[]\0argv"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ExcelToPdf[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08 /* Private */,
       3,    0,   30,    2, 0x08 /* Private */,
       4,    2,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 6,    5,    7,

       0        // eod
};

void ExcelToPdf::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ExcelToPdf *_t = static_cast<ExcelToPdf *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setExcelPath(); break;
        case 1: _t->setPdfPath(); break;
        case 2: _t->convertPdf((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< char*(*)[]>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject ExcelToPdf::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ExcelToPdf.data,
      qt_meta_data_ExcelToPdf,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ExcelToPdf::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExcelToPdf::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ExcelToPdf.stringdata0))
        return static_cast<void*>(const_cast< ExcelToPdf*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ExcelToPdf::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
