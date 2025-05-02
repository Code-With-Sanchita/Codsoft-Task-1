

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Game {
private:
    int snum;  
    int max;   
    bool un;    

public:
    Game() {
        srand(time(0));
        snum = rand() % 100 + 1;
        max = 0;
        un = false;
    }

    void selectlevel(int level) {
        switch (level) {
            case 1:
                un = true;
                break;
            case 2:
                max = 15;
                break;
            case 3:
                max = 7;
                break;
            default:
               // cout << "Invalid choice. Defaulting to Easy." << endl;
                un = true;
                break;
        }
    }

    void play() {
        int guess;
        int attempts = 0;
        cout << "Guess the number between 1 to 100!" << endl;

        while (un || attempts < max) {
            cout << "Enter your guess: ";
            cin >> guess;
            attempts++;

            if (guess == snum) {
                cout << "Congratulations! You guessed the correct number in " << attempts << " attempt(s)." << endl;
                return;
            } else if (guess < snum) {
                cout << "Too low. Try again." << endl;
            } else {
                cout << "Too high. Try again." << endl;
            }

            if (!un && attempts >= max) {
                cout << "You have run out of attempts! The number was: " << snum << endl;
            }
        }
    }

    void reset() {
        snum = rand() % 100 + 1;
    }
};

int main() {
    Game g;
    char playagain;
    int choice;

    do {
        cout << "\nSelect Difficulty Level:" << endl;
        cout << "1. Easy (Unlimited attempts)" << endl;
        cout << "2. Medium (15 attempts)" << endl;
        cout << "3. Hard (7 attempts)" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        g.selectlevel(choice);
        g.play();

        cout << "Do you want to play again? (y/n): ";
        cin >> playagain;

        if (playagain == 'y' || playagain == 'Y') {
            g.reset();
        }

    } while (playagain == 'y' || playagain == 'Y');

    cout << "Thanks for playing!" << endl;
    return 0;
}
