/****************************************************************************
** Meta object code from reading C++ file 'engine.hpp'
**
** Created: Mon Jan 13 19:50:01 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../inc/engine.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'engine.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Engine[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x08,
      19,   17,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Engine[] = {
    "Engine\0\0update()\0c\0intCar(Car*)\0"
};

void Engine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Engine *_t = static_cast<Engine *>(_o);
        switch (_id) {
        case 0: _t->update(); break;
        case 1: _t->intCar((*reinterpret_cast< Car*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Engine::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Engine::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Engine,
      qt_meta_data_Engine, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Engine::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Engine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Engine::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Engine))
        return static_cast<void*>(const_cast< Engine*>(this));
    return QWidget::qt_metacast(_clname);
}

int Engine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
