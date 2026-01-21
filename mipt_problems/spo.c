#include <stdio.h>
#include <stdlib.h>

struct tree_t {
  struct tree_t *left;
  struct tree_t *right;
  int data;
};

struct stacknode {
    struct stacknode *next;
    struct tree_t *data;
};

void print_pre(struct tree_t *top);
void push(struct stacknode **stack, struct tree_t *node);
struct tree_t* pop(struct stacknode **stack);

int main(void) {

    return 0;
}

void print_pre(struct tree_t *top) {
    struct stacknode *s = NULL;
    push(&s, top);

    while (s != NULL) {
        struct tree_t *curr_node = pop(&s);
        fprintf(stdout, "%d ", curr_node->data);
        if (curr_node->right != NULL)
            push(&s, curr_node->right);
        if (curr_node->left != NULL)
            push(&s, curr_node->left);
    }
}

void push(struct stacknode **stack, struct tree_t *node) {
    struct stacknode *temp = calloc(1, sizeof(struct stacknode));
    temp->data = node;
    temp->next = *stack;
    *stack = temp;
}

struct tree_t* pop(struct stacknode **stack) {
    struct tree_t *data = (*stack)->data;
    struct stacknode *new_head = (*stack)->next;
    free(*stack);
    (*stack) = new_head;
    return data;
}