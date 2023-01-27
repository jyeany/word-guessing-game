/****************************************************************************
** Meta object code from reading C++ file 'gamemanager.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../word-guess-game/src/gamemanager.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamemanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_GameManager_t {
    uint offsetsAndSizes[48];
    char stringdata0[12];
    char stringdata1[21];
    char stringdata2[1];
    char stringdata3[19];
    char stringdata4[11];
    char stringdata5[11];
    char stringdata6[16];
    char stringdata7[7];
    char stringdata8[14];
    char stringdata9[6];
    char stringdata10[15];
    char stringdata11[10];
    char stringdata12[15];
    char stringdata13[21];
    char stringdata14[11];
    char stringdata15[16];
    char stringdata16[19];
    char stringdata17[13];
    char stringdata18[17];
    char stringdata19[15];
    char stringdata20[15];
    char stringdata21[17];
    char stringdata22[18];
    char stringdata23[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_GameManager_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_GameManager_t qt_meta_stringdata_GameManager = {
    {
        QT_MOC_LITERAL(0, 11),  // "GameManager"
        QT_MOC_LITERAL(12, 20),  // "letterGuessesUpdated"
        QT_MOC_LITERAL(33, 0),  // ""
        QT_MOC_LITERAL(34, 18),  // "wordGuessesUpdated"
        QT_MOC_LITERAL(53, 10),  // "createGame"
        QT_MOC_LITERAL(64, 10),  // "wordLength"
        QT_MOC_LITERAL(75, 15),  // "makeLetterGuess"
        QT_MOC_LITERAL(91, 6),  // "letter"
        QT_MOC_LITERAL(98, 13),  // "makeWordGuess"
        QT_MOC_LITERAL(112, 5),  // "guess"
        QT_MOC_LITERAL(118, 14),  // "endGameMessage"
        QT_MOC_LITERAL(133, 9),  // "resetGame"
        QT_MOC_LITERAL(143, 14),  // "hasFoundLetter"
        QT_MOC_LITERAL(158, 20),  // "currentLetterIndices"
        QT_MOC_LITERAL(179, 10),  // "QList<int>"
        QT_MOC_LITERAL(190, 15),  // "getSolutionWord"
        QT_MOC_LITERAL(206, 18),  // "getSolutionLetters"
        QT_MOC_LITERAL(225, 12),  // "QList<QChar>"
        QT_MOC_LITERAL(238, 16),  // "getMissedLetters"
        QT_MOC_LITERAL(255, 14),  // "getMissedWords"
        QT_MOC_LITERAL(270, 14),  // "getWordGuesses"
        QT_MOC_LITERAL(285, 16),  // "getLetterGuesses"
        QT_MOC_LITERAL(302, 17),  // "getGuessedLetters"
        QT_MOC_LITERAL(320, 14)   // "getGameModeStr"
    },
    "GameManager",
    "letterGuessesUpdated",
    "",
    "wordGuessesUpdated",
    "createGame",
    "wordLength",
    "makeLetterGuess",
    "letter",
    "makeWordGuess",
    "guess",
    "endGameMessage",
    "resetGame",
    "hasFoundLetter",
    "currentLetterIndices",
    "QList<int>",
    "getSolutionWord",
    "getSolutionLetters",
    "QList<QChar>",
    "getMissedLetters",
    "getMissedWords",
    "getWordGuesses",
    "getLetterGuesses",
    "getGuessedLetters",
    "getGameModeStr"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_GameManager[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  116,    2, 0x06,    1 /* Public */,
       3,    0,  117,    2, 0x06,    2 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,  118,    2, 0x02,    3 /* Public */,
       6,    1,  121,    2, 0x02,    5 /* Public */,
       8,    1,  124,    2, 0x02,    7 /* Public */,
      10,    0,  127,    2, 0x02,    9 /* Public */,
      11,    0,  128,    2, 0x02,   10 /* Public */,
      12,    1,  129,    2, 0x02,   11 /* Public */,
      13,    0,  132,    2, 0x02,   13 /* Public */,
      15,    0,  133,    2, 0x02,   14 /* Public */,
      16,    0,  134,    2, 0x02,   15 /* Public */,
      18,    0,  135,    2, 0x02,   16 /* Public */,
      19,    0,  136,    2, 0x02,   17 /* Public */,
      20,    0,  137,    2, 0x02,   18 /* Public */,
      21,    0,  138,    2, 0x02,   19 /* Public */,
      22,    0,  139,    2, 0x02,   20 /* Public */,
      23,    0,  140,    2, 0x02,   21 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Bool, QMetaType::QChar,    7,
    QMetaType::Bool, QMetaType::QString,    9,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QChar,    7,
    0x80000000 | 14,
    QMetaType::QString,
    0x80000000 | 17,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::QString,
    QMetaType::QString,

       0        // eod
};

Q_CONSTINIT const QMetaObject GameManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_GameManager.offsetsAndSizes,
    qt_meta_data_GameManager,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_GameManager_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<GameManager, std::true_type>,
        // method 'letterGuessesUpdated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'wordGuessesUpdated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'createGame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'makeLetterGuess'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<QChar, std::false_type>,
        // method 'makeWordGuess'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'endGameMessage'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'resetGame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'hasFoundLetter'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<QChar, std::false_type>,
        // method 'currentLetterIndices'
        QtPrivate::TypeAndForceComplete<QList<int>, std::false_type>,
        // method 'getSolutionWord'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getSolutionLetters'
        QtPrivate::TypeAndForceComplete<QList<QChar>, std::false_type>,
        // method 'getMissedLetters'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getMissedWords'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getWordGuesses'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getLetterGuesses'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getGuessedLetters'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getGameModeStr'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
    >,
    nullptr
} };

void GameManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GameManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->letterGuessesUpdated(); break;
        case 1: _t->wordGuessesUpdated(); break;
        case 2: _t->createGame((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: { bool _r = _t->makeLetterGuess((*reinterpret_cast< std::add_pointer_t<QChar>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->makeWordGuess((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: { QString _r = _t->endGameMessage();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->resetGame(); break;
        case 7: { bool _r = _t->hasFoundLetter((*reinterpret_cast< std::add_pointer_t<QChar>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: { QList<int> _r = _t->currentLetterIndices();
            if (_a[0]) *reinterpret_cast< QList<int>*>(_a[0]) = std::move(_r); }  break;
        case 9: { QString _r = _t->getSolutionWord();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 10: { QList<QChar> _r = _t->getSolutionLetters();
            if (_a[0]) *reinterpret_cast< QList<QChar>*>(_a[0]) = std::move(_r); }  break;
        case 11: { QString _r = _t->getMissedLetters();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 12: { QString _r = _t->getMissedWords();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 13: { int _r = _t->getWordGuesses();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 14: { int _r = _t->getLetterGuesses();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 15: { QString _r = _t->getGuessedLetters();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 16: { QString _r = _t->getGameModeStr();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GameManager::*)();
            if (_t _q_method = &GameManager::letterGuessesUpdated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GameManager::*)();
            if (_t _q_method = &GameManager::wordGuessesUpdated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *GameManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GameManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int GameManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void GameManager::letterGuessesUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GameManager::wordGuessesUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
