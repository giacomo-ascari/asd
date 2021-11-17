#include <iostream>
#include <vector>

using namespace std;

typedef struct _cell {
    int x;
    int y;
} cell;

int find_cawa_distance(vector<vector<int> > &matrix) /* N ^ 4 rip */ {
    int n = matrix.size();
    vector<vector<int>> distances;
    for (int i = 0; i < n; i++) {
        vector<int> row;
        for (int j = 0; j < n; j++) {
            row.push_back(2*n-2);
        }
        distances.push_back(row);
    }

    // sx --> dx
    for (int r = 0; r < n; r++) {
        bool found = false;
        int d = 0;
        for (int c = 0; c < n; c++) {
            if (matrix[r][c] == 3) found = true;
            if (found) { distances[r][c] = d; d++; }
        }
    }

    // sx <-- dx
    for (int r = n-1; r >= 0; r--) {
        bool found = false;
        int d = 0;
        for (int c = n-1; c >= 0; c--) {
            if (matrix[r][c] == 3) found = true;
            if (found) { distances[r][c] = d; d++; }
        }
    }

    // top --> bottom
    for (int c = 0; c < n; c++) {
        bool found = false;
        int d = 0;
        for (int r = 0; r < n; r++) {
            if (matrix[r][c] == 3) found = true;
            if (found) { distances[r][c] = d; d++; }
        }
    }

    // top <-- bottom
    for (int c = n-1; c >= 0; c--) {
        bool found = false;
        int d = 0;
        for (int r = n-1; r >= 0; r--) {
            if (matrix[r][c] == 3) found = true;
            if (found) { distances[r][c] = d; d++; }
        }
    }

    int mn = 2*n-2;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (matrix[r][c] == 1) {
                mn = min(distances[r][c], mn);
            }
        }
    }
    return mn;
}

int find_min_distance(vector<vector<int> > &matrix) /* N ^ 4 rip */ {
    vector<cell> ones;
    vector<cell> threes;
    int mn = 1000000;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == 1) {
                cell temp = {i, j};
                ones.push_back(temp);
            } else if (matrix[i][j] == 3) {
                cell temp = {i, j};
                threes.push_back(temp);
            }
        }
    }
    for (int i = 0; i < ones.size(); i++) {
        for (int j = 0; j < threes.size(); j++) {
            int temp = abs(ones[i].x - threes[j].x) + abs(ones[i].y - threes[j].y);
            mn = min(temp, mn);
        }
    }
    return mn;
}


int main() {

    vector<vector<int> > matrix = {
        { 1, 2, 2, 3 },
        { 2, 1, 2, 3 },
        { 2, 2, 2, 3 },
        { 3, 2, 1, 2 }
    };
    cout << find_min_distance(matrix) << endl;
    cout << find_cawa_distance(matrix) << endl;
}