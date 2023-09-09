#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ifstream inputFile("C:/Users/solidus66/OneDrive/projects c++/MatrixChanging/input&output/input.txt");

	if (!inputFile) {
		cerr << "Cannot open file input.txt" << endl;
		return 1;
	}

	int n, m;
	inputFile >> n >> m;

	vector<vector<int>> matrix(n, vector<int>(m));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			inputFile >> matrix[i][j];
		}
	}

	inputFile.close();

	ifstream input("C:/Users/solidus66/OneDrive/projects c++/MatrixChanging/input&output/input.txt");

	cout << "Contents of the input.txt file:" << endl;
	char ch;
	while (input.get(ch)) {
		cout << ch;
	}

	input.close();

	int maxElement = matrix[0][0];
	int maxRow = 0;
	int maxCol = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (matrix[i][j] > maxElement) {
				maxElement = matrix[i][j];
				maxRow = i;
				maxCol = j;
			}
		}
	}

	swap(matrix[0], matrix[maxRow]);
	for (int i = 0; i < n; ++i) {
		swap(matrix[i][0], matrix[i][maxCol]);
	}

	ofstream outputFile("C:/Users/solidus66/OneDrive/projects c++/MatrixChanging/input&output/output.txt");

	if (!outputFile) {
		cerr << "Cannot open file output.txt" << endl;
		return 1;
	}

	outputFile << n << " " << m << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			outputFile << matrix[i][j] << " ";
		}
		outputFile << endl;
	}

	outputFile.close();

	ifstream output("C:/Users/solidus66/OneDrive/projects c++/MatrixChanging/input&output/output.txt");

	cout << "\n\nContents of the output.txt:" << endl;
	while (output.get(ch)) {
		cout << ch;
	}

	output.close();

	return 0;
}