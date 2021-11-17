#include <iostream>
#include <vector>

using namespace std;

typedef struct _cell {
    int x;
    int y;
} cell;

// è per grafi non direzionali, da fixare

bool is_cyclic(int current, vector<vector<int>> &adjancency, int n, bool *visited) {
    if (visited[current-1]) {
        return true;
    } else {
        bool result = false;
        visited[current-1] = true;
        for (int i = 0; i < adjancency[current-1].size(); i++) {
            bool to_visit = adjancency[current-1][i] == 1;
            if (to_visit) {
                result = result && is_cyclic(i+1, adjancency, n, visited);
            }
            
        }
        return result;
    }
}

bool removable(int n, int m, vector<int> &x, vector<int> &y) {
    vector<vector<int>> adjancency;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++) {
        vector<int> row;
        adjancency.push_back(row);
        visited[i-1] = false;
    }
    for (int i = 0; i < m; i++) {
        adjancency[x[i]-1][y[i]-1] = 1;
    }
    bool result = is_cyclic(1, adjancency, n, visited);
    delete[] visited;
    return result;
}


int main() {
    int n, m;
    vector<int> x;
    vector<int> y;
    cout << removable(n, m, x, y) << endl;
}