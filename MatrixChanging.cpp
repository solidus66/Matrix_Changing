#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<vector<int>> readMatrixFromFile(const string& fileName, int& n, int& m) {
    ifstream inputFile(fileName);

    if (!inputFile) {
        cerr << "Cannot open file " << fileName << endl;
        exit(1);
    }

    inputFile >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            inputFile >> matrix[i][j];
        }
    }

    inputFile.close();

    return matrix;
}

void writeMatrixToFile(const string& fileName, const vector<vector<int>>& matrix, int n, int m) {
    ofstream outputFile(fileName);

    if (!outputFile) {
        cerr << "Cannot open file " << fileName << endl;
        exit(1);
    }

    outputFile << n << " " << m << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            outputFile << matrix[i][j] << " ";
        }
        outputFile << endl;
    }

    outputFile.close();
}

void findMaxElement(const vector<vector<int>>& matrix, int n, int m, int& maxElement, int& maxRow, int& maxCol) {
    maxElement = matrix[0][0];
    maxRow = 0;
    maxCol = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] > maxElement) {
                maxElement = matrix[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }
}

void swapRowsAndCols(vector<vector<int>>& matrix, int n, int m, int maxRow, int maxCol) {
    swap(matrix[0], matrix[maxRow]);
    for (int i = 0; i < n; ++i) {
        swap(matrix[i][0], matrix[i][maxCol]);
    }
}

void printMatrix(const vector<vector<int>>& matrix, int n, int m) {
    cout << n << " " << m << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    vector<vector<int>> matrix = readMatrixFromFile("C:/Users/solidus66/OneDrive/projects c++/MatrixChanging/input&output/input.txt", n, m);

    cout << "Contents of the input.txt file:" << endl;
    printMatrix(matrix, n, m);

    int maxElement, maxRow, maxCol;
    findMaxElement(matrix, n, m, maxElement, maxRow, maxCol);
    swapRowsAndCols(matrix, n, m, maxRow, maxCol);

    cout << "\nContents of the output.txt file:" << endl;
    printMatrix(matrix, n, m);

    writeMatrixToFile("C:/Users/solidus66/OneDrive/projects c++/MatrixChanging/input&output/output.txt", matrix, n, m);

    return 0;
}
