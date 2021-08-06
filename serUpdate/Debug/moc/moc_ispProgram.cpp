/****************************************************************************
** Meta object code from reading C++ file 'ispProgram.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.11)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ispProgram.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ispProgram.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.11. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ispProgramThread_t {
    QByteArrayData data[6];
    char stringdata0[68];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ispProgramThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ispProgramThread_t qt_meta_stringdata_ispProgramThread = {
    {
QT_MOC_LITERAL(0, 0, 16), // "ispProgramThread"
QT_MOC_LITERAL(1, 17, 20), // "onNewSerialIspStatus"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 8), // "sendByte"
QT_MOC_LITERAL(4, 48, 15), // "downLoadPercent"
QT_MOC_LITERAL(5, 64, 3) // "run"

    },
    "ispProgramThread\0onNewSerialIspStatus\0"
    "\0sendByte\0downLoadPercent\0run"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ispProgramThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,
       3,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::SChar, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void ispProgramThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ispProgramThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onNewSerialIspStatus((*reinterpret_cast< qint8(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->sendByte((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->downLoadPercent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->run(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ispProgramThread::*)(qint8 , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ispProgramThread::onNewSerialIspStatus)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ispProgramThread::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ispProgramThread::sendByte)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ispProgramThread::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ispProgramThread::downLoadPercent)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ispProgramThread::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_ispProgramThread.data,
    qt_meta_data_ispProgramThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ispProgramThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ispProgramThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ispProgramThread.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ispProgramThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void ispProgramThread::onNewSerialIspStatus(qint8 _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ispProgramThread::sendByte(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ispProgramThread::downLoadPercent(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
