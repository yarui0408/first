/****************************************************************************
** Meta object code from reading C++ file 'maindialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../client/maindialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'maindialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainDialog_t {
    QByteArrayData data[16];
    char stringdata0[382];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainDialog_t qt_meta_stringdata_MainDialog = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainDialog"
QT_MOC_LITERAL(1, 11, 15), // "OnConnectedFunc"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 16), // "OnDisconnectFunc"
QT_MOC_LITERAL(4, 45, 21), // "OnSocketReadyReadFunc"
QT_MOC_LITERAL(5, 67, 24), // "UpdateClientProgressFunc"
QT_MOC_LITERAL(6, 92, 16), // "DisplayErrorFunc"
QT_MOC_LITERAL(7, 109, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(8, 138, 16), // "MySystemTrayFunc"
QT_MOC_LITERAL(9, 155, 35), // "on_pushButton_ConnectServer_c..."
QT_MOC_LITERAL(10, 191, 38), // "on_pushButton_DidconnectServe..."
QT_MOC_LITERAL(11, 230, 26), // "on_pushButton_Exit_clicked"
QT_MOC_LITERAL(12, 257, 30), // "on_pushButton_ClearMsg_clicked"
QT_MOC_LITERAL(13, 288, 29), // "on_pushButton_SendMsg_clicked"
QT_MOC_LITERAL(14, 318, 32), // "on_pushButton_SelectFile_clicked"
QT_MOC_LITERAL(15, 351, 30) // "on_pushButton_SendFile_clicked"

    },
    "MainDialog\0OnConnectedFunc\0\0"
    "OnDisconnectFunc\0OnSocketReadyReadFunc\0"
    "UpdateClientProgressFunc\0DisplayErrorFunc\0"
    "QAbstractSocket::SocketError\0"
    "MySystemTrayFunc\0on_pushButton_ConnectServer_clicked\0"
    "on_pushButton_DidconnectServer_clicked\0"
    "on_pushButton_Exit_clicked\0"
    "on_pushButton_ClearMsg_clicked\0"
    "on_pushButton_SendMsg_clicked\0"
    "on_pushButton_SelectFile_clicked\0"
    "on_pushButton_SendFile_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    1,   82,    2, 0x08 /* Private */,
       6,    1,   85,    2, 0x08 /* Private */,
       8,    0,   88,    2, 0x08 /* Private */,
       9,    0,   89,    2, 0x08 /* Private */,
      10,    0,   90,    2, 0x08 /* Private */,
      11,    0,   91,    2, 0x08 /* Private */,
      12,    0,   92,    2, 0x08 /* Private */,
      13,    0,   93,    2, 0x08 /* Private */,
      14,    0,   94,    2, 0x08 /* Private */,
      15,    0,   95,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainDialog *_t = static_cast<MainDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnConnectedFunc(); break;
        case 1: _t->OnDisconnectFunc(); break;
        case 2: _t->OnSocketReadyReadFunc(); break;
        case 3: _t->UpdateClientProgressFunc((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 4: _t->DisplayErrorFunc((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 5: _t->MySystemTrayFunc(); break;
        case 6: _t->on_pushButton_ConnectServer_clicked(); break;
        case 7: _t->on_pushButton_DidconnectServer_clicked(); break;
        case 8: _t->on_pushButton_Exit_clicked(); break;
        case 9: _t->on_pushButton_ClearMsg_clicked(); break;
        case 10: _t->on_pushButton_SendMsg_clicked(); break;
        case 11: _t->on_pushButton_SelectFile_clicked(); break;
        case 12: _t->on_pushButton_SendFile_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

const QMetaObject MainDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MainDialog.data,
      qt_meta_data_MainDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int MainDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
