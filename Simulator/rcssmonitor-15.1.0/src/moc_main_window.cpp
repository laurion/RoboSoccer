/****************************************************************************
** Meta object code from reading C++ file 'main_window.h'
**
** Created: Thu Dec 13 21:24:30 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "main_window.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      30,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      26,   11,   11,   11, 0x08,
      34,   11,   11,   11, 0x08,
      54,   11,   11,   11, 0x08,
      69,   11,   11,   11, 0x08,
      79,   11,   11,   11, 0x08,
      96,   11,   11,   11, 0x08,
     115,   11,   11,   11, 0x08,
     135,   11,   11,   11, 0x08,
     162,  154,   11,   11, 0x08,
     182,  154,   11,   11, 0x08,
     204,   11,   11,   11, 0x08,
     223,   11,   11,   11, 0x08,
     246,  154,   11,   11, 0x08,
     264,   11,   11,   11, 0x08,
     289,  283,   11,   11, 0x08,
     315,  311,   11,   11, 0x08,
     332,  311,   11,   11, 0x08,
     353,  311,   11,   11, 0x08,
     385,  375,   11,   11, 0x08,
     406,  375,   11,   11, 0x08,
     424,   11,   11,   11, 0x08,
     437,   11,   11,   11, 0x08,
     452,  447,   11,   11, 0x08,
     483,  472,   11,   11, 0x08,
     510,   11,   11,   11, 0x08,
     538,  533,   11,   11, 0x08,
     558,  283,   11,   11, 0x08,
     586,   11,   11,   11, 0x08,
     609,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0viewUpdated()\0about()\0"
    "printShortcutKeys()\0setQuitTimer()\0"
    "kickOff()\0connectMonitor()\0"
    "connectMonitorTo()\0disconnectMonitor()\0"
    "reconnectMonitor()\0checked\0"
    "toggleMenuBar(bool)\0toggleStatusBar(bool)\0"
    "toggleFullScreen()\0showPlayerTypeDialog()\0"
    "changeStyle(bool)\0showConfigDialog()\0"
    "point\0setFocusPoint(QPoint)\0pos\0"
    "dropBall(QPoint)\0freeKickLeft(QPoint)\0"
    "freeKickRight(QPoint)\0side,unum\0"
    "yellowCard(char,int)\0redCard(char,int)\0"
    "yellowCard()\0redCard()\0mode\0"
    "changePlayMode(int)\0mode,point\0"
    "changePlayMode(int,QPoint)\0"
    "receiveMonitorPacket()\0size\0"
    "resizeCanvas(QSize)\0updatePositionLabel(QPoint)\0"
    "updateBufferingLabel()\0showRecoveringState()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->viewUpdated(); break;
        case 1: _t->about(); break;
        case 2: _t->printShortcutKeys(); break;
        case 3: _t->setQuitTimer(); break;
        case 4: _t->kickOff(); break;
        case 5: _t->connectMonitor(); break;
        case 6: _t->connectMonitorTo(); break;
        case 7: _t->disconnectMonitor(); break;
        case 8: _t->reconnectMonitor(); break;
        case 9: _t->toggleMenuBar((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->toggleStatusBar((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->toggleFullScreen(); break;
        case 12: _t->showPlayerTypeDialog(); break;
        case 13: _t->changeStyle((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->showConfigDialog(); break;
        case 15: _t->setFocusPoint((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 16: _t->dropBall((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 17: _t->freeKickLeft((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 18: _t->freeKickRight((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 19: _t->yellowCard((*reinterpret_cast< const char(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 20: _t->redCard((*reinterpret_cast< const char(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 21: _t->yellowCard(); break;
        case 22: _t->redCard(); break;
        case 23: _t->changePlayMode((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 24: _t->changePlayMode((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2]))); break;
        case 25: _t->receiveMonitorPacket(); break;
        case 26: _t->resizeCanvas((*reinterpret_cast< const QSize(*)>(_a[1]))); break;
        case 27: _t->updatePositionLabel((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 28: _t->updateBufferingLabel(); break;
        case 29: _t->showRecoveringState(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::viewUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
