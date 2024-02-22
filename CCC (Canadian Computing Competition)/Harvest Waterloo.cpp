#include <iostream>
#include <vector>
#include <string>
#include<functional>

using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<char>> patch(rows, vector<char>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> patch[i][j];
        }
    }

    int farmerRow, farmerCol;
    cin >> farmerRow >> farmerCol;

    int value = 0;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    // Function to recursively explore reachable pumpkins
    function<void(int, int)> explore = [&](int row, int col) {
        if (row < 0 || row >= rows || col < 0 || col >= cols || visited[row][col] || patch[row][col] == '*') {
            return;
        }

        visited[row][col] = true;

        switch (patch[row][col]) {
            case 'S':
                value += 1;
                break;
            case 'M':
                value += 5;
                break;
            case 'L':
                value += 10;
                break;
            default:
                break;
        }

        explore(row - 1, col);
        explore(row + 1, col);
        explore(row, col - 1);
        explore(row, col + 1);
    };

    // Start exploration from farmer's location
    explore(farmerRow, farmerCol);

    cout << value << endl;

    return 0;
}
