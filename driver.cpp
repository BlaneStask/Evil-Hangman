#include <iostream>
#include "list.h"
using namespace std;

const int MAX_GUESSES = 10;
int main(){
    list wordlist("words");

    cout << "Welcome to Hangman!!!\n\n";
    cout << "In this easy game of Hangman, you are given " << MAX_GUESSES << " wrong guesses!" << endl;
    string guessedLetters = "";
    int wrongCount = 0;
    bool won = false;

    while(wrongCount < MAX_GUESSES && !won){
        cout << "Word: " << wordlist.mask() << endl;
        cout << "Guess a letter: ";
        char letter;
        cin >> letter;
        while(guessedLetters.find(letter) != string::npos){
            cout << "You have already guessed " << letter << "!\nPlease try again: ";
            cin >> letter;
        }
        guessedLetters += letter;
        if(!wordlist.split(letter)) {
            wrongCount++;
            cout << "You were wrong! " << (MAX_GUESSES - wrongCount) << " chances left!" << endl;
        }
        won = wordlist.is_guessed();
    }
    if(won){
        cout << "You won!  The word was '" << wordlist.word() << endl;
    }
    else{
        cout << "You lost!  The word was '" << wordlist.word() << endl;
    }
    return 0;
}
