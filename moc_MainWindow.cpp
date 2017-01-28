/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "include/MainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata0[206];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 17), // "updateMaxVelocity"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 6), // "_value"
QT_MOC_LITERAL(4, 37, 14), // "updateMaxForce"
QT_MOC_LITERAL(5, 52, 16), // "updateViewRadius"
QT_MOC_LITERAL(6, 69, 18), // "updateObstacleSize"
QT_MOC_LITERAL(7, 88, 5), // "_size"
QT_MOC_LITERAL(8, 94, 8), // "newFlock"
QT_MOC_LITERAL(9, 103, 7), // "addBoid"
QT_MOC_LITERAL(10, 111, 10), // "removeBoid"
QT_MOC_LITERAL(11, 122, 11), // "addObstacle"
QT_MOC_LITERAL(12, 134, 7), // "addFood"
QT_MOC_LITERAL(13, 142, 10), // "removeFood"
QT_MOC_LITERAL(14, 153, 14), // "removeObstacle"
QT_MOC_LITERAL(15, 168, 12), // "toggleLeader"
QT_MOC_LITERAL(16, 181, 12), // "_leaderState"
QT_MOC_LITERAL(17, 194, 11) // "setPredator"

    },
    "MainWindow\0updateMaxVelocity\0\0_value\0"
    "updateMaxForce\0updateViewRadius\0"
    "updateObstacleSize\0_size\0newFlock\0"
    "addBoid\0removeBoid\0addObstacle\0addFood\0"
    "removeFood\0removeObstacle\0toggleLeader\0"
    "_leaderState\0setPredator"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

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
       1,    1,   79,    2, 0x0a /* Public */,
       4,    1,   82,    2, 0x0a /* Public */,
       5,    1,   85,    2, 0x0a /* Public */,
       6,    1,   88,    2, 0x0a /* Public */,
       8,    0,   91,    2, 0x0a /* Public */,
       9,    0,   92,    2, 0x0a /* Public */,
      10,    0,   93,    2, 0x0a /* Public */,
      11,    0,   94,    2, 0x0a /* Public */,
      12,    0,   95,    2, 0x0a /* Public */,
      13,    0,   96,    2, 0x0a /* Public */,
      14,    0,   97,    2, 0x0a /* Public */,
      15,    1,   98,    2, 0x0a /* Public */,
      17,    0,  101,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateMaxVelocity((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->updateMaxForce((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->updateViewRadius((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->updateObstacleSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->newFlock(); break;
        case 5: _t->addBoid(); break;
        case 6: _t->removeBoid(); break;
        case 7: _t->addObstacle(); break;
        case 8: _t->addFood(); break;
        case 9: _t->removeFood(); break;
        case 10: _t->removeObstacle(); break;
        case 11: _t->toggleLeader((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->setPredator(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
