#ifndef board_h
#define board_h

#include <iostream>
#include <string>
using namespace std;

class board{
    private:
        int ROWS = 12;
        int COLS = 12;
        string table[12][12]=  {    {"","","","","","","","","","","",""},
                                    {"","","","","","","","","","","",""},
                                    {"","","","","","","","","","","",""},
                                    {"","","","","","","","","","","",""},
                                    {"","","","","","","","","","","",""},
                                    {"","","","","","","","","","","",""},
                                    {"","","","","","","","","","","",""},
                                    {"","","","","","","","","","","",""},
                                    {"","","","","","","","","","","",""},
                                    {"","","","","","","","","","","",""},
                                    {"","","","","","","","","","","",""},
                                    {"","","","","","","","","","","",""}
                                };
    public:
        bool checkIfempty(int x, int y){
            return this->table[x-1][y-1].empty();
        }

        void putUser(int x, int y, string user){
            table[x-1][y-1] = user;
        }  

        void printTable(){
            for(int first = 0; first < 12; first++){
                for(int second = 0; second < 12; second++){
                    if (table[first][second].empty()){
                        cout << "|  " << table[first][second] << " ";
                    }else{
                        cout << "| " << table[first][second] << " ";
                    }
                }
                cout << "|";
                cout << endl;
            }
        }


};

#endif 