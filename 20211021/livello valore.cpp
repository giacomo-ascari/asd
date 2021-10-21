#include <iostream>

using namespace std;

typedef struct _tree_node {
    int value;
    _tree_node *left;
    _tree_node *right;
} tree_node;

int level_value(int level, tree_node *node) {

    if (node) {
        int result = 0;
        if (level == node->value) {
            result++;
        }
        return result
            + level_value(level+1, node->left)
            + level_value(level+1, node->right);
    } else {
        return 0;
    }

    /*int result = 0;
    if (level == node->value) {
        result++;
    }
    if (node->left) {
        result += level_value(level+1, node->left);
    }
    if (node->right) {
        result += level_value(level+1, node->right);
    }
    return result;*/
}

int main() {
    cout << level_value(0, NULL) << endl;
}