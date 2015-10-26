/****************************************************************************
** Meta object code from reading C++ file 'qtapplication.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qtapplication.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtapplication.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QtApplication_t {
    QByteArrayData data[11];
    char stringdata[153];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtApplication_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtApplication_t qt_meta_stringdata_QtApplication = {
    {
QT_MOC_LITERAL(0, 0, 13), // "QtApplication"
QT_MOC_LITERAL(1, 14, 15), // "processBtnEvent"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 16), // "processDialEvent"
QT_MOC_LITERAL(4, 48, 3), // "val"
QT_MOC_LITERAL(5, 52, 15), // "processBoxEvent"
QT_MOC_LITERAL(6, 68, 20), // "processComboBoxEvent"
QT_MOC_LITERAL(7, 89, 15), // "processBarEvent"
QT_MOC_LITERAL(8, 105, 14), // "processExample"
QT_MOC_LITERAL(9, 120, 14), // "processHistory"
QT_MOC_LITERAL(10, 135, 17) // "processColorEvent"

    },
    "QtApplication\0processBtnEvent\0\0"
    "processDialEvent\0val\0processBoxEvent\0"
    "processComboBoxEvent\0processBarEvent\0"
    "processExample\0processHistory\0"
    "processColorEvent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtApplication[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a /* Public */,
       3,    1,   55,    2, 0x0a /* Public */,
       5,    1,   58,    2, 0x0a /* Public */,
       6,    1,   61,    2, 0x0a /* Public */,
       7,    1,   64,    2, 0x0a /* Public */,
       8,    0,   67,    2, 0x0a /* Public */,
       9,    0,   68,    2, 0x0a /* Public */,
      10,    0,   69,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QtApplication::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QtApplication *_t = static_cast<QtApplication *>(_o);
        switch (_id) {
        case 0: _t->processBtnEvent(); break;
        case 1: _t->processDialEvent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->processBoxEvent((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->processComboBoxEvent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->processBarEvent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->processExample(); break;
        case 6: _t->processHistory(); break;
        case 7: _t->processColorEvent(); break;
        default: ;
        }
    }
}

const QMetaObject QtApplication::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_QtApplication.data,
      qt_meta_data_QtApplication,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QtApplication::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtApplication::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QtApplication.stringdata))
        return static_cast<void*>(const_cast< QtApplication*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int QtApplication::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
