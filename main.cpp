#include <iostream>
#include <string>
#include <conio.h>
#include "cryptocpp/aes.h"
#include "headers/board.h"
#include "headers/tanks.h"
#include "headers/json.hpp"


using namespace std;


string attack(tank& attacker,tank& defender){    
            attacker.subtractPoints(1);
            defender.subtractHearts(1);
            return "fuck";
}

void joinGame(){

}

void createGame(){

}

// login function to ask user for username and password and lookup values in json file
string login(){
    string username;
    string password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

}

int main(){

    int userAmounts = 0;
    int action = 0;
    tank player[12];
    board gameboard;
    bool gameRunning = true;
    string authToken = "";

    authToken = login();

    cout << "Welcome to the game!!\n"  << "\n";
    cout << "Are you \n 1.joining an existing game \n or\n 2.creating one?" << "\n";
    cin >> action;
    switch (action)
    {
    case 1:
        joinGame();
        break;
    case 2:
        createGame();
        break;
    default:
        cout << "Invalid Answer!!\n";
        break;
    }


    for (int i =0; i < userAmounts; i++){
        cout << "What is your name player" << i << "?" << "\n";
        string name = "";
        cin >> name;
        player[i].setName(name);
        player[i].setPosition(gameboard);
    }
    
    system("cls");


    
    while(gameRunning){
        system("cls");
        cout << "What would you like to do?\n" << "\n";
        cout << "1. Print Board" << "\n" << "2. Check Points" << "\n" << "3. Check Hearts" << "\n" << "4. Check Range" << "\n" << 
                "5. Upgrade Range" << "\n" <<"6. Move" << "\n" << "7. Attack" << "\n" << "0. Exit" << "\n";
        cout << "Enter the number: "; 
        cin >> action;     
        player[1].checkAction((int)action, gameRunning, gameboard);
        system("pause"); 
    }
  return 0;
  }