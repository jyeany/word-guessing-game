import QtQuick 2.15
import QtTest 1.0
//import GameState
import "./../../src/components"

TestCase {
    id: wordGuessTestCase
    name: "WordGuessQmlCase"

//    GameState {
//        id: gameState
//    }

    function initTestCase() {
    }

    function cleanupTestCase() {
    }

    function test_case1() {
        compare(1 + 1, 2, "sanity check");
        verify(true);
    }

    function benchmark_once_word_guess_create() {
        const component = Qt.createComponent("./../../src/components/WordGuess.qml")
        var wordGuess = component.createObject(wordGuessTestCase)
        wordGuess.destroy()
        component.destroy()
    }

    function test_word_guess() {
        const component = Qt.createComponent("./../../src/components/WordGuess.qml")
        var wordGuess = component.createObject(wordGuessTestCase)
        verify(wordGuess !== null)
    }
}
