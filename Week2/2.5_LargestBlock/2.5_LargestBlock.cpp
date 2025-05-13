#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> findLargestBlock(const std::vector<std::vector<int>>& m) {
    int n = m.size();
    if (n == 0) return { 0, 0, 0 };

    std::vector<std::vector<int>> dp(n, std::vector<int>(n));
    int maxSize = 0;
    int maxRow = 0;
    int maxCol = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (m[i][j] == 1) {
                if (i == 0 || j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = std::min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1;

                if (dp[i][j] > maxSize) {
                    maxSize = dp[i][j];
                    maxRow = i;
                    maxCol = j;
                }
            }
        }
    }

    return { maxRow - maxSize + 1, maxCol - maxSize + 1, maxSize };
}

int main() {
    int n;
    std::cout << "Enter the number of rows for the matrix: ";
    std::cin >> n;

    if (n <= 0 || n > 100) {
        std::cerr << "Invalid matrix size.\n";
        return 1;
    }

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    std::cout << "Enter the matrix row by row:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    std::vector<int> result = findLargestBlock(matrix);
    std::cout << "The maximum square submatrix is at ("
        << result[0] << ", " << result[1] << ") with size "
        << result[2] << std::endl;

    return 0;
}
