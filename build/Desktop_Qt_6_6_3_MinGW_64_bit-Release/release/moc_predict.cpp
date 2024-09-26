/****************************************************************************
** Meta object code from reading C++ file 'predict.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../predict.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'predict.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSPredictENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSPredictENDCLASS = QtMocHelpers::stringData(
    "Predict",
    "on_lineEdit_editingFinished",
    "",
    "on_lineEdit_2_editingFinished",
    "on_buttonBox_accepted"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSPredictENDCLASS_t {
    uint offsetsAndSizes[10];
    char stringdata0[8];
    char stringdata1[28];
    char stringdata2[1];
    char stringdata3[30];
    char stringdata4[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSPredictENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSPredictENDCLASS_t qt_meta_stringdata_CLASSPredictENDCLASS = {
    {
        QT_MOC_LITERAL(0, 7),  // "Predict"
        QT_MOC_LITERAL(8, 27),  // "on_lineEdit_editingFinished"
        QT_MOC_LITERAL(36, 0),  // ""
        QT_MOC_LITERAL(37, 29),  // "on_lineEdit_2_editingFinished"
        QT_MOC_LITERAL(67, 21)   // "on_buttonBox_accepted"
    },
    "Predict",
    "on_lineEdit_editingFinished",
    "",
    "on_lineEdit_2_editingFinished",
    "on_buttonBox_accepted"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSPredictENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x08,    1 /* Private */,
       3,    0,   33,    2, 0x08,    2 /* Private */,
       4,    0,   34,    2, 0x08,    3 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Predict::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSPredictENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSPredictENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSPredictENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Predict, std::true_type>,
        // method 'on_lineEdit_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_lineEdit_2_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_buttonBox_accepted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Predict::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Predict *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_lineEdit_editingFinished(); break;
        case 1: _t->on_lineEdit_2_editingFinished(); break;
        case 2: _t->on_buttonBox_accepted(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *Predict::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Predict::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSPredictENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Predict::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
