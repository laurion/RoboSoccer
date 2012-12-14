/****************************************************************************
** Meta object code from reading C++ file 'field_canvas.h'
**
** Created: Thu Dec 13 21:24:29 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "field_canvas.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'field_canvas.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FieldCanvas[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   13,   12,   12, 0x05,
      34,   13,   12,   12, 0x05,
      55,   13,   12,   12, 0x05,
      86,   77,   12,   12, 0x05,
     120,  114,   12,   12, 0x05,
     141,  114,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
     160,   12,   12,   12, 0x0a,
     171,   12,   12,   12, 0x0a,
     186,   12,   12,   12, 0x0a,
     207,  202,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FieldCanvas[] = {
    "FieldCanvas\0\0pos\0dropBall(QPoint)\0"
    "freeKickLeft(QPoint)\0freeKickRight(QPoint)\0"
    "mode,pos\0playModeChanged(int,QPoint)\0"
    "point\0focusChanged(QPoint)\0"
    "mouseMoved(QPoint)\0dropBall()\0"
    "freeKickLeft()\0freeKickRight()\0mode\0"
    "changePlayMode(int)\0"
};

void FieldCanvas::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FieldCanvas *_t = static_cast<FieldCanvas *>(_o);
        switch (_id) {
        case 0: _t->dropBall((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 1: _t->freeKickLeft((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 2: _t->freeKickRight((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 3: _t->playModeChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2]))); break;
        case 4: _t->focusChanged((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 5: _t->mouseMoved((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 6: _t->dropBall(); break;
        case 7: _t->freeKickLeft(); break;
        case 8: _t->freeKickRight(); break;
        case 9: _t->changePlayMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData FieldCanvas::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FieldCanvas::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FieldCanvas,
      qt_meta_data_FieldCanvas, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FieldCanvas::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FieldCanvas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FieldCanvas::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FieldCanvas))
        return static_cast<void*>(const_cast< FieldCanvas*>(this));
    return QWidget::qt_metacast(_clname);
}

int FieldCanvas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void FieldCanvas::dropBall(const QPoint & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FieldCanvas::freeKickLeft(const QPoint & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FieldCanvas::freeKickRight(const QPoint & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FieldCanvas::playModeChanged(int _t1, const QPoint & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void FieldCanvas::focusChanged(const QPoint & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void FieldCanvas::mouseMoved(const QPoint & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
