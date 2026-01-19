#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node_t {struct node_t *next; int data;};

struct node_t * read_list(int len);
void delete_list(struct node_t *top);
void print_list(const struct node_t *top);

int main(void) {
    int len;
    if (scanf("%d", &len) != 1 || len < 1) {
        perror("wrong value of len");
        return -1;
    }
    struct node_t *list = read_list(len);
    if (!list) {
        perror("error creating list");
        return -1;
    }

    

    print_list(list);
    delete_list(list);

    return 0;
}

struct node_t* read_list(int len) {
    int num;
    if (scanf("%d", &num) != 1) {
        return NULL;
    }
    struct node_t *top = calloc(1, sizeof(struct node_t));
    top->data = num;
    struct node_t *curr = top;
    while (scanf("%d", &num) == 1 && --len) {
        struct node_t *new_node = calloc(1, sizeof(struct node_t));
        new_node->data = num;
        curr->next = new_node;
        curr = new_node;
    }
    return top;
}

void delete_list(struct node_t *top) {
    struct node_t *current = top;
    while (current != NULL) {
        struct node_t *temp = current->next;
        free(current);
        current = temp;
    }
}

void print_list(const struct node_t *top) {
    const struct node_t *p;
    for (p = top; p != NULL; p = p->next) {
        printf("%d ", p->data);
    }
    printf("\n");
}
