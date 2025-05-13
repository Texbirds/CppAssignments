#include <iostream>

const int SIZE = 4;

double sumColumn(const double m[][SIZE], int rowSize, int columnIndex) {
    double sum = 0;
    for (int i = 0; i < rowSize; i++) {
        sum += m[i][columnIndex];
    }
    return sum;
}

int main() {
    const int ROWS = 3;
    double matrix[ROWS][SIZE];

    std::cout << "Enter a 3-by-4 matrix row by row:" << "\n";

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < SIZE; j++) {
            std::cin >> matrix[i][j];
        }
    }

    for (int col = 0; col < SIZE; col++) {
        double total = sumColumn(matrix, ROWS, col);
        std::cout << "Sum of the elements at column " << col << " is " << total << "\n";
    }

    return 0;
}