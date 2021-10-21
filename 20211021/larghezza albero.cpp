#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

typedef struct _tree_node {
    int value;
    _tree_node *left;
    _tree_node *right;
} tree_node;

int explore(tree_node *start_node) {
    int mx = 0;
    queue<tree_node> q;
    q.push(*start_node);
    while (!q.empty()) {
        tree_node current = q.front();
        q.pop();
        if (current.left) {
            q.push(*current.left);
        }
        if (current.right) {
            q.push(*current.right);
        }
        mx = max(mx, (int)q.size());
    }
    int mx = 0;
}

int main() {
    explore(NULL);
}