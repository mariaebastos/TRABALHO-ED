#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "SparseMatrices.h"
#include "commands.h"

using namespace std;

int main (){
    string command;

    cout << "Type 'help' to see available commands" << endl;

    while (true){
        cout << "\nEnter a command: ";
        getline(cin, command);
        stringstream ss(command);
        string cmd;
        ss >> cmd;

        if (cmd == "help"){
            showHelp();
        }
        else if (cmd == "show"){
            int idx;
            if (ss >> idx){
                showMatrix(idx);
            }
            else{
                cout << "Error:Invalid command" << endl;
            }
        }
        else if (cmd == "showidx"){
            showIndices();
        }
        else if (cmd == "sum") {
            int i, j;
            if (ss >> i >> j){
                sumMatrices(i, j);
            }
            else{
                cout << "Error:Invalid command" << endl;
            }
        }
        else if (cmd == "multiply"){
            int i, j;
            if (ss >> i >> j){
                multiplyMatrices(i,j);
            }
            else{
                cout << "Error:Invalid command" << endl;
            }
        }
        else if (cmd == "clear"){
            int idx
            if (ss >> idx){
                clearMatrix(idx);
            }
            else{
                cout << "Error:Invalid command" << endl;
            }
        }
        else if (cmd == "read"){
            string filename;
            if (ss >> filename){
                readMatrixFromFile(filename);
            }
            else{
                cout << "Error:Invalid command" << endl;
            }
        }
        else if (cmd == "update"){
            int idx, i, j;
            double value;
            if (ss >> idx >> i >> j >> value){
                updateMatrix(idx, i, j, value);
            }
            else{
                cout << "Error:Invalid command" << endl;
            }
        }
        else if (cmd == "eraseAll"){
            erasesAllMatrices();
        }
        else if (cmd == "exit"){
            eraseAllMatrices();
            cout << "Program finished" << endl;
            break;
        }
        else{
            cout << "Error:Invalid command. Type 'help' to see available commands. " << endl;
        }
    }
    return 0;   
}
