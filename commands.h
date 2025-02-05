#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "SparseMatrices.h"

using namespace std;

vector <SparceMatrix*> matrices:

void showHelp () {
    cout << "help" << endl;
    cout << "===== HELP =====" << endl;
    cout << "exit                - close the program" << endl;
    cout << "show i              - create a new matrix with m rows and n columns" << endl;
    cout << "showidx             - show all the indexes of the matrices" << endl;
    cout << "sum i j             - sum the matrices i and j of the vector of the matrices" << endl;
    cout << "multiply i j        - multiply the matrices i and j of the vector of the matrices" << endl;
    cout << "clear i             - clear the matrix i" << endl;
    cout << "read 'm.txt'        - read a sparse matrix from the file with name 'm.txt'" << endl;
    cout << "update m i j value  - update the value of the cell (i,j) in the matrix m" << endl;
    cout << "eraseAll            - erase all the matrices currently in the program" << endl;
     

}

void showMatrix (int idx) {
    if (idx < 0 || idx >= (int)matrices.size()) {
        cout << "Error:Invalid index" << endl;
        return;
    }
    matrices[idx]->print();
}

void showIndices (){
    if(matrices.empty()) {
        cout << "No matrices available";
    }
    else {
        for (size_t i = 0; i < matrices.size(); i++) {
        cout << i << " ";
    }
    }
    cout << endl;

    }
}

void sumMatrices(int i, int j) {
    if (i >= matrices.size() || j >= matrices.size()) {
        cout << "Error:Invalid index" << endl;
        return;
    }
    matrices.push_back(matrices[i]->sum(*matrices[j]));
    cout << "Sum result are saved: " << matrices.size() - 1 << endl;
}

void multiplyMatrices(int i, int j) {
    if (i >= matrices.size() || j >= matrices.size()) {
        cout << "Error:Invalid index" << endl;
        return;
    }
    matrices.push_back(matrices[i]->multiply(*matrices[j]));
    cout << "Multiplication result are saved: " << matrices.size() - 1 << endl;
}

void clearMatrix(int idx) {
    if (idx >= matrices.size()) {
        cout << "Error:Invalid index" << endl;
        return;
    }
    matrices[idx]->clear();
    cout << "Matrix" << idx << "nodes cleared" << endl;
}

void readMatrixFromFile(const string& filename){
       ifstream file(filename);
    if (!file) {
        cout << "Error:Unable to open" << filename << endl;
        return;
    }
    SparseMatrix* mat = new SparseMatrix();
    int i, j;
    double val;
    while (file >> i >> j >> val) {
        mat->insert(i, j, val);
    }
    matrices.push_back(mat);
    cout << "Matrix loaded from file" << filename << " at index " << matrices.size() - 1 << endl;
}

void updateMatrix(int idx, int i, int j, double value){
    if(idx >= matrices.size()){
        cout << "Error:Invalid index" << endl;
        return;
    }
    matrices[idx]->insert(i, j, value);
    cout << "Matrix" << idx << " update at (" << i << ", " << j << ") with value" << value << endl;
}

void eraseAllMatrices(){
    for (auto& mat : matrices) delete mat;
    matrices.clear();
    cout << "All matrices have been erased" << endl;
}



