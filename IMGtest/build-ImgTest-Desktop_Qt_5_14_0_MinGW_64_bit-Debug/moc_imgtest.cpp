/****************************************************************************
** Meta object code from reading C++ file 'imgtest.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ImgTest/imgtest.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imgtest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ImgTest_t {
    QByteArrayData data[22];
    char stringdata0[203];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImgTest_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImgTest_t qt_meta_stringdata_ImgTest = {
    {
QT_MOC_LITERAL(0, 0, 7), // "ImgTest"
QT_MOC_LITERAL(1, 8, 9), // "beginWork"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 3), // "img"
QT_MOC_LITERAL(4, 23, 8), // "QThread*"
QT_MOC_LITERAL(5, 32, 11), // "childThread"
QT_MOC_LITERAL(6, 44, 10), // "showCamera"
QT_MOC_LITERAL(7, 55, 2), // "id"
QT_MOC_LITERAL(8, 58, 7), // "preview"
QT_MOC_LITERAL(9, 66, 11), // "takePicture"
QT_MOC_LITERAL(10, 78, 10), // "tokenReply"
QT_MOC_LITERAL(11, 89, 14), // "QNetworkReply*"
QT_MOC_LITERAL(12, 104, 5), // "reply"
QT_MOC_LITERAL(13, 110, 8), // "imgReply"
QT_MOC_LITERAL(14, 119, 15), // "beginFaceDetect"
QT_MOC_LITERAL(15, 135, 8), // "postData"
QT_MOC_LITERAL(16, 144, 10), // "overThread"
QT_MOC_LITERAL(17, 155, 11), // "prePostData"
QT_MOC_LITERAL(18, 167, 10), // "pickCamera"
QT_MOC_LITERAL(19, 178, 3), // "idx"
QT_MOC_LITERAL(20, 182, 9), // "beginGame"
QT_MOC_LITERAL(21, 192, 10) // "analysGame"

    },
    "ImgTest\0beginWork\0\0img\0QThread*\0"
    "childThread\0showCamera\0id\0preview\0"
    "takePicture\0tokenReply\0QNetworkReply*\0"
    "reply\0imgReply\0beginFaceDetect\0postData\0"
    "overThread\0prePostData\0pickCamera\0idx\0"
    "beginGame\0analysGame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImgTest[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   69,    2, 0x0a /* Public */,
       9,    0,   74,    2, 0x0a /* Public */,
      10,    1,   75,    2, 0x0a /* Public */,
      13,    1,   78,    2, 0x0a /* Public */,
      14,    2,   81,    2, 0x0a /* Public */,
      17,    0,   86,    2, 0x0a /* Public */,
      18,    1,   87,    2, 0x0a /* Public */,
      20,    0,   90,    2, 0x0a /* Public */,
      21,    0,   91,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage, 0x80000000 | 4,    3,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QImage,    7,    8,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 4,   15,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ImgTest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ImgTest *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->beginWork((*reinterpret_cast< QImage(*)>(_a[1])),(*reinterpret_cast< QThread*(*)>(_a[2]))); break;
        case 1: _t->showCamera((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QImage(*)>(_a[2]))); break;
        case 2: _t->takePicture(); break;
        case 3: _t->tokenReply((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 4: _t->imgReply((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 5: _t->beginFaceDetect((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< QThread*(*)>(_a[2]))); break;
        case 6: _t->prePostData(); break;
        case 7: _t->pickCamera((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->beginGame(); break;
        case 9: _t->analysGame(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QThread* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QThread* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ImgTest::*)(QImage , QThread * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImgTest::beginWork)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ImgTest::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ImgTest.data,
    qt_meta_data_ImgTest,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ImgTest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImgTest::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ImgTest.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ImgTest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void ImgTest::beginWork(QImage _t1, QThread * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
