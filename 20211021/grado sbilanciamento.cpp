#include <iostream>
#include <cmath>

using namespace std;

typedef struct _tree_node {
    int value;
    _tree_node *left;
    _tree_node *right;
} tree_node;

int conta_foglie(tree_node *node) {
    if (node) {
        int tot = 0;
        if (node->left) {
            tot += conta_foglie(node->left);
        } else if (node->right) {
            tot += conta_foglie(node->right);
        } else {
            tot += 1;
        }
        return tot;
    } else {
        return 0;
    }
}

int grado_sbilanciamento_albero(tree_node *node, int &mx) {
    if (node) {
        int dx = grado_sbilanciamento_albero(node->right, mx); 
        int sx = grado_sbilanciamento_albero(node->left, mx);
        if (dx == 0 && sx == 0) {
            return 1;
        } else if (dx && sx) {
            mx = max(mx, abs(dx-sx));
        }
        return dx + sx;
    } else {
        return 0;
    }
}

int main() {
    int mx = 0;
    cout << grado_sbilanciamento_albero(NULL, mx) << endl;
}