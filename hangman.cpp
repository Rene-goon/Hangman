// we will utilize vectors objects, vector member functions, iterators, library
// algorithms

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <ctype.h

using namespace std;

int main()
{
    const int MAX_WRONG = 8; // max number of guesses

    vector<string> words; // collections of words to guess
    words.push_back("GUESS");
    words.push_back("HANGMAN");
    words.push_back("DIFFICULT");

    //pick random word in vector
    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(), words.end());

    const string THE_WORD = words[0];
    int wrongGuesses = 0;                       //number of wrong guesses
    string soFar(THE_WORD.size(), '-');         //words guessed so far
    string usedLetters = "";                    //letters guessed already

    cout << "Welcome to Hangman. Good luck!\n";

    //main loop
    while((wrongGuesses < MAX_WRONG) && (soFar != THE_WORD))
    {
        cout << "\nYou have " << (MAX_WRONG - wrongGuesses) << " incorrect "
             << "guesses left.\n"
             << "\nYou've used the following letters:\n" << usedLetters << endl;
        cout << "\nSo far, the word is:\n" << soFar << endl;

        //getting player's guess
        char guess;
        cout << "\n\nEnter your guess: ";
        cin >> guess;
        guess = toupper(guess);

        while(usedLetters.find(guess) != string::npos) //till end of string
        {
            cout << "\nYou've already guessed " << guess << endl
                 << "Enter your guess: ";
            cin >> guess;
            guess = toupper(guess);
        }

        usedLetters += guess;

        if(THE_WORD.find(guess) != string::npos)
        {
            cout << "That's rights! " << guess << " is in the word.\n";

            //update soFar to include the guessed letter
            for(int i = 0; i < THE_WORD.length(); ++i)
            {
                if(THE_WORD[i] == guess)
                    soFar[i] = guess;
            }
        }
        else
        {
            cout << "Sorry, " << guess << " isn't in the word.\n";
            ++wrongGuesses;
        }
    }

    if(wrongGuesses == MAX_WRONG)
        cout << "\nYou've been hanged...";
    else
        cout << "\nYou guessed it!";

    cout << "\nThe word was " << THE_WORD << endl;

    system("PAUSE > NULL");
    return 0;
}
