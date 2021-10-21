#include <iostream>
#include <cmath>

using namespace std;

typedef struct _tree_node {
    int value;
    _tree_node *left;
    _tree_node *right;
} tree_node;

int walk(tree_node *node) {
    int maxl = 0, maxr = 0;
    if (node) {
        if (node->left && node->left->value > node->value) {
            maxl = 1 + walk(node->left);
        }
        if (node->right && node->right->value > node->value) {
            maxr = 1 + walk(node->right);
        }
    }
    return max(maxl, maxr);
}

int main() {
    cout << walk(NULL) << endl;
}