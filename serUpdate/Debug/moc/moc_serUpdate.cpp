/****************************************************************************
** Meta object code from reading C++ file 'serUpdate.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.11)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../serUpdate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serUpdate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.11. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_serUpdate_t {
    QByteArrayData data[7];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_serUpdate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_serUpdate_t qt_meta_stringdata_serUpdate = {
    {
QT_MOC_LITERAL(0, 0, 9), // "serUpdate"
QT_MOC_LITERAL(1, 10, 13), // "UpdateSerPort"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 8), // "portName"
QT_MOC_LITERAL(4, 34, 32), // "onSerConnnectPushButtom_callback"
QT_MOC_LITERAL(5, 67, 29), // "onOpenFilePushButtom_callback"
QT_MOC_LITERAL(6, 97, 27) // "onUploadPushButtom_callback"

    },
    "serUpdate\0UpdateSerPort\0\0portName\0"
    "onSerConnnectPushButtom_callback\0"
    "onOpenFilePushButtom_callback\0"
    "onUploadPushButtom_callback"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_serUpdate[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x08 /* Private */,
       4,    0,   37,    2, 0x08 /* Private */,
       5,    0,   38,    2, 0x08 /* Private */,
       6,    0,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void serUpdate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<serUpdate *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->UpdateSerPort((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 1: _t->onSerConnnectPushButtom_callback(); break;
        case 2: _t->onOpenFilePushButtom_callback(); break;
        case 3: _t->onUploadPushButtom_callback(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject serUpdate::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_serUpdate.data,
    qt_meta_data_serUpdate,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *serUpdate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *serUpdate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_serUpdate.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int serUpdate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
