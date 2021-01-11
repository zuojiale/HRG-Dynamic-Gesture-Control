/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[24];
    char stringdata0[347];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 8), // "ToThread"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 20), // "std::vector<QString>"
QT_MOC_LITERAL(4, 38, 9), // "IPandPort"
QT_MOC_LITERAL(5, 48, 13), // "Hrg_Dev_Info*"
QT_MOC_LITERAL(6, 62, 3), // "dev"
QT_MOC_LITERAL(7, 66, 15), // "Hrg_Dev_Handle*"
QT_MOC_LITERAL(8, 82, 6), // "handle"
QT_MOC_LITERAL(9, 89, 15), // "HRGFrameIsReady"
QT_MOC_LITERAL(10, 105, 15), // "HRGDepthIsReady"
QT_MOC_LITERAL(11, 121, 6), // "CanDTW"
QT_MOC_LITERAL(12, 128, 24), // "on_buttonConnect_clicked"
QT_MOC_LITERAL(13, 153, 25), // "on_horizonFPS_sliderMoved"
QT_MOC_LITERAL(14, 179, 8), // "position"
QT_MOC_LITERAL(15, 188, 27), // "on_buttonDisconnect_clicked"
QT_MOC_LITERAL(16, 216, 21), // "on_buttonSave_clicked"
QT_MOC_LITERAL(17, 238, 17), // "dealWithOkClicked"
QT_MOC_LITERAL(18, 256, 11), // "S_updateAPP"
QT_MOC_LITERAL(19, 268, 11), // "F_updateAPP"
QT_MOC_LITERAL(20, 280, 14), // "DynamicGesture"
QT_MOC_LITERAL(21, 295, 12), // "HandTracking"
QT_MOC_LITERAL(22, 308, 15), // "TrainingGesture"
QT_MOC_LITERAL(23, 324, 22) // "on_buttonTrain_clicked"

    },
    "Widget\0ToThread\0\0std::vector<QString>\0"
    "IPandPort\0Hrg_Dev_Info*\0dev\0Hrg_Dev_Handle*\0"
    "handle\0HRGFrameIsReady\0HRGDepthIsReady\0"
    "CanDTW\0on_buttonConnect_clicked\0"
    "on_horizonFPS_sliderMoved\0position\0"
    "on_buttonDisconnect_clicked\0"
    "on_buttonSave_clicked\0dealWithOkClicked\0"
    "S_updateAPP\0F_updateAPP\0DynamicGesture\0"
    "HandTracking\0TrainingGesture\0"
    "on_buttonTrain_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   89,    2, 0x06 /* Public */,
       9,    0,   96,    2, 0x06 /* Public */,
      10,    0,   97,    2, 0x06 /* Public */,
      11,    0,   98,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   99,    2, 0x08 /* Private */,
      13,    1,  100,    2, 0x08 /* Private */,
      15,    0,  103,    2, 0x08 /* Private */,
      16,    0,  104,    2, 0x08 /* Private */,
      17,    1,  105,    2, 0x08 /* Private */,
      18,    0,  108,    2, 0x08 /* Private */,
      19,    0,  109,    2, 0x08 /* Private */,
      20,    0,  110,    2, 0x08 /* Private */,
      21,    0,  111,    2, 0x08 /* Private */,
      22,    0,  112,    2, 0x08 /* Private */,
      23,    0,  113,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 7,    4,    6,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Widget *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ToThread((*reinterpret_cast< std::vector<QString>(*)>(_a[1])),(*reinterpret_cast< Hrg_Dev_Info*(*)>(_a[2])),(*reinterpret_cast< Hrg_Dev_Handle*(*)>(_a[3]))); break;
        case 1: _t->HRGFrameIsReady(); break;
        case 2: _t->HRGDepthIsReady(); break;
        case 3: _t->CanDTW(); break;
        case 4: _t->on_buttonConnect_clicked(); break;
        case 5: _t->on_horizonFPS_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_buttonDisconnect_clicked(); break;
        case 7: _t->on_buttonSave_clicked(); break;
        case 8: _t->dealWithOkClicked((*reinterpret_cast< std::vector<QString>(*)>(_a[1]))); break;
        case 9: _t->S_updateAPP(); break;
        case 10: _t->F_updateAPP(); break;
        case 11: _t->DynamicGesture(); break;
        case 12: _t->HandTracking(); break;
        case 13: _t->TrainingGesture(); break;
        case 14: _t->on_buttonTrain_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< std::vector<QString> >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< std::vector<QString> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Widget::*_t)(std::vector<QString> , Hrg_Dev_Info * , Hrg_Dev_Handle * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Widget::ToThread)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Widget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Widget::HRGFrameIsReady)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Widget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Widget::HRGDepthIsReady)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Widget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Widget::CanDTW)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget.data,
      qt_meta_data_Widget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(const_cast< Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void Widget::ToThread(std::vector<QString> _t1, Hrg_Dev_Info * _t2, Hrg_Dev_Handle * _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Widget::HRGFrameIsReady()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Widget::HRGDepthIsReady()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Widget::CanDTW()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
