#include <stdio.h>
#include <stdlib.h>

struct tree_t {
	struct tree_t *left;
	struct tree_t *right;
	int data;
};

int main(void) {
	return 0;
}

void print_pre(struct tree_t *top) {
	if (top == NULL) return;
	fprintf(stdout, "%d ", top->data);
	print_pre(top->left);
	print_pre(top->right);
}
		