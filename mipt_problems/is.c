#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct tree_t {
  struct tree_t *left;
  struct tree_t *right;
  int data;
};

int check_sub_tree(struct tree_t *top, int min, int max);

int check_is_bst(struct tree_t *top) {
    return check_sub_tree(top, INT_MIN, INT_MAX);
}

int check_sub_tree(struct tree_t *top, int min, int max) {
    if (top == NULL) return 1;

    int data = top->data;

    if (min >= data || data >= max) {
        return 0;
    }

    return check_sub_tree(top->left, min, data) &&
            check_sub_tree(top->right, data, max);
}
