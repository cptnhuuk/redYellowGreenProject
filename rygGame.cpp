#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Game {
    private:
        int numberToGuess;
        int userGuess;
        int numberToGuessDigits[3];
        int userGuessDigits[3];
        bool notGreen[3] = {true, true, true};
        bool notYellow[3] = {true, true, true};
    
    public:
    Game() { //constructor
         srand(time(NULL)); //seed for randomizer
    }
    void generateNumberToGuess() {
        numberToGuess = 322;//rand() % (999 -100 + 1) + 100; //Generates three digit number between 100 and 999
        generateNumberToGuessDigits();
    }
    void generateNumberToGuessDigits() {
        numberToGuessDigits[2] = numberToGuess % 10;
        numberToGuessDigits[1] = (numberToGuess / 10) % 10;
        numberToGuessDigits[0] = numberToGuess / 100;
    }
    void generateUserGuessDigits() {
        userGuessDigits[2] = userGuess % 10;
        userGuessDigits[1] = (userGuess / 10) % 10;
        userGuessDigits[0] = userGuess / 100;
    }
    void getUserGuess() {
        cout <<"Please enter a guess?" << endl;
        cin >> userGuess;
        generateUserGuessDigits();
    } 

     int getGreenDigits(){
        int greenCount = 0;
        for (int i = 0; i <3; i++){
            if (numberToGuessDigits[i] == userGuessDigits[i]){
                notGreen[i] = false;
                greenCount++;
        }
        }
        return greenCount;
    }
    int getYellowDigits(){
    int yellowCount = 0;
    bool matched[3] = {false, false, false};
    for (int i = 0; i < 3; i++){
        if (numberToGuessDigits[i] == userGuessDigits[i]){
            // This digit has already been counted as a green digit
            continue;
        }
        for (int o = 0; o < 3; o++) {
            if (!matched[o] && numberToGuessDigits[o] == userGuessDigits[i]){
                matched[o] = true;
                yellowCount++;
                break;
            }
        }
    }
    return yellowCount;
}
   int getRedDigits(){
    int redCount = 0;
    for (int i = 0; i < 3; i++){
        bool digitFound = false;
        for (int o = 0; o < 3; o++){
            if (numberToGuessDigits[o] == userGuessDigits[i] && notGreen[o] && notYellow[o]){
                digitFound = true;
                break;
            }
        }
        if(!digitFound)
            redCount++;
    }
    return redCount;
}

    void play(){
        generateNumberToGuess();

        while (true){
            getUserGuess();
            int greenCount = getGreenDigits();
            int yellowCount = getYellowDigits();
            int redCount = getRedDigits();

            if(greenCount == 3){
                cout << "CONGRATULATIONS, YOU ARE CORRECT!!!!!!!!!!!!!!" << endl;
                break;
            }else{
                cout << "You have: " << redCount << " red" << endl;
                cout << greenCount << " green" << endl;
                cout << yellowCount << " yellow" << endl;
            }
        }
    }
    
};

int main() {
    Game redYelloGreenGame;
    redYelloGreenGame.play();
    return 0;
}