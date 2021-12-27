#ifndef tanks_h
#define tanks_h

#include <iostream>
#include <string>
using namespace std;

// Tank Class. Players are contained here.
class tank
{
    public:
        tank();
        string name;
        int hearts, acPoints, range, position[2];
        bool dead, haunted;

    // Set user name for UI
        void setName(string input){
            this -> name = input;
        }
    // Helper Fuctions.
        string printName(){
           return this -> name;
        }

        void subtractPoints(int i){
            this -> acPoints = this -> acPoints - i;
        }

        void subtractHearts(int i ){
            cout << hearts << endl;
            this -> hearts = this -> hearts - i ;
            cout << hearts << endl;
        }

        void printHearts(){
            cout << hearts << endl;
        }

        int getHearts(){
            return this -> hearts;
        }

        int getPoints(){
            return this -> acPoints;
        }

        void setPosition(board& gameboard){
            srand((unsigned int)time(NULL));
            int x = rand() % 12 + 1;
            int y = rand() % 12 + 1;
            bool notComplete = true;
            while (notComplete)
            {
                if(gameboard.checkIfempty(x,y)){
                    gameboard.putUser(x,y,name);
                    this -> position[0] = x;
                    this -> position[1] = y;
                    notComplete = false;
                }
                else{
                    x = rand() % 12 + 1;
                    y = rand() % 12 + 1;
                }            
            }
        }

      void checkAction(int action, bool& gamestate, board& gameboard){
            int past = this->range;
            switch (action)
            {                
            case 0:
                cout << "Exit\n";
                gamestate = false;
                break;
            case 1:
                cout << "The current board looks like this:\n\n";
                gameboard.printTable();
                break;
            case 2:
                cout << "Your have " << this->acPoints << " points" << "\n";                
                break;
            case 3:
                cout << "You have " << this->hearts << " hearts" << "\n";
                break;
            case 4:
                cout << "Your current range is " << this->range << " in either direction." << "\n";
                break;
            case 5:
                this->range +=1;
                cout << "You have upgraded your range from " << past << " to " << this->range << "\n";
                break;
            case 6:
                cout << "Where would you like to move?\n";
                cout << "1.Up\n2.Down\n3.Left\n4.Right";
                break;
            case 7:
                cout << "Who do you want to attack?\n";
                gameboard.printTable();
                break;            
            default:
                cout << "Not sure what you entered, but it wasn't right m8.\n";
                break;
            }
        }
      

};

tank::tank(){
        // Tank Constructor
        hearts = 3;
        acPoints = 0;
        dead = false;
        haunted = false;
        range = 2;

}

#endif