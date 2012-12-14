/****************************************************************************
** Meta object code from reading C++ file 'main_window.h'
**
** Created: Thu Dec 13 22:22:18 2012
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
      31,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      26,   11,   11,   11, 0x08,
      36,   11,   11,   11, 0x08,
      53,   11,   11,   11, 0x08,
      73,   11,   11,   11, 0x08,
      85,   11,   11,   11, 0x08,
     106,  100,   11,   11, 0x08,
     170,  148,   11,   11, 0x08,
     213,   11,   11,   11, 0x08,
     223,   11,   11,   11, 0x08,
     237,   11,   11,   11, 0x08,
     254,   11,   11,   11, 0x08,
     273,   11,   11,   11, 0x08,
     293,   11,   11,   11, 0x08,
     309,   11,   11,   11, 0x08,
     325,   11,   11,   11, 0x08,
     343,   11,   11,   11, 0x08,
     363,   11,   11,   11, 0x08,
     382,   11,   11,   11, 0x08,
     405,   11,   11,   11, 0x08,
     432,  424,   11,   11, 0x08,
     450,   11,   11,   11, 0x08,
     469,   11,   11,   11, 0x08,
     477,   11,   11,   11, 0x08,
     502,  497,   11,   11, 0x08,
     522,  424,   11,   11, 0x0a,
     541,   11,   11,   11, 0x0a,
     570,  564,   11,   11, 0x0a,
     602,  598,   11,   11, 0x0a,
     619,  598,   11,   11, 0x0a,
     640,  598,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0viewUpdated()\0openRCG()\0"
    "openOutputFile()\0outputCurrentData()\0"
    "saveImage()\0startMonitor()\0error\0"
    "printMonitorError(QProcess::ProcessError)\0"
    "exit_code,exit_status\0"
    "printMonitorExit(int,QProcess::ExitStatus)\0"
    "kickOff()\0setLiveMode()\0connectMonitor()\0"
    "connectMonitorTo()\0disconnectMonitor()\0"
    "toggleMenuBar()\0toggleToolBar()\0"
    "toggleStatusBar()\0toggleFieldCanvas()\0"
    "toggleFullScreen()\0showPlayerTypeDialog()\0"
    "showDetailDialog()\0checked\0changeStyle(bool)\0"
    "showConfigDialog()\0about()\0"
    "printShortcutKeys()\0size\0resizeCanvas(QSize)\0"
    "toggleRecord(bool)\0receiveMonitorPacket()\0"
    "point\0updatePositionLabel(QPoint)\0pos\0"
    "dropBall(QPoint)\0freeKickLeft(QPoint)\0"
    "freeKickRight(QPoint)\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->viewUpdated(); break;
        case 1: _t->openRCG(); break;
        case 2: _t->openOutputFile(); break;
        case 3: _t->outputCurrentData(); break;
        case 4: _t->saveImage(); break;
        case 5: _t->startMonitor(); break;
        case 6: _t->printMonitorError((*reinterpret_cast< QProcess::ProcessError(*)>(_a[1]))); break;
        case 7: _t->printMonitorExit((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 8: _t->kickOff(); break;
        case 9: _t->setLiveMode(); break;
        case 10: _t->connectMonitor(); break;
        case 11: _t->connectMonitorTo(); break;
        case 12: _t->disconnectMonitor(); break;
        case 13: _t->toggleMenuBar(); break;
        case 14: _t->toggleToolBar(); break;
        case 15: _t->toggleStatusBar(); break;
        case 16: _t->toggleFieldCanvas(); break;
        case 17: _t->toggleFullScreen(); break;
        case 18: _t->showPlayerTypeDialog(); break;
        case 19: _t->showDetailDialog(); break;
        case 20: _t->changeStyle((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->showConfigDialog(); break;
        case 22: _t->about(); break;
        case 23: _t->printShortcutKeys(); break;
        case 24: _t->resizeCanvas((*reinterpret_cast< const QSize(*)>(_a[1]))); break;
        case 25: _t->toggleRecord((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: _t->receiveMonitorPacket(); break;
        case 27: _t->updatePositionLabel((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 28: _t->dropBall((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 29: _t->freeKickLeft((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 30: _t->freeKickRight((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
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
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::viewUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
