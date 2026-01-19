#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node_t {struct node_t *next; int data;};

struct node_t * read_list(FILE *file);
void delete_list(struct node_t *top);
void print_list(const struct node_t *top);

int main(int argc, char **argv) {
    if (argc < 2) {
        perror("no input file.");
        return -1;
    }
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("error opening file");
        return -1;
    }
    
    struct node_t *list = read_list(file);
    if (!list) {
        perror("error creating list");
        fclose(file);
        return -1;
    }

    

    print_list(list);
    delete_list(list);

    return 0;
}

struct node_t* read_list (FILE *file) {
    int num;
    if (fscanf(file, "%d", &num) != 1) {
        return NULL;  // файл пуст
    }
    struct node_t *top = calloc(1, sizeof(struct node_t));
    top->data = num;
    struct node_t *curr = top;
    while (fscanf(file, "%d", &num) == 1) {
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