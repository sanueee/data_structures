#include <stdio.h>
#include <stdlib.h>

struct node_t *read_list(FILE *input);
void delete_list(struct node_t *top);

struct node_t {struct node_t *next; int data;};

int main(int argc, char** argv) {
    if (argc < 2) return -1;
    FILE* file = fopen(argv[1], "r");
    if (!file) return -1;

    struct node_t *list = read_list(file);
    if (!list) {
        fclose(file);
        return -1;
    }

    printf("%d", list->data);

    delete_list(list);
    fclose(file);
    return 0;
}

struct node_t *read_list(FILE *input) {
    int num;
    if (fscanf(input, "%d", &num) != 1) {
        return NULL;  // файл пуст
    }

    struct node_t *top = calloc(1, sizeof(struct node_t));
    top->data = num;
    struct node_t *current = top; // указывает на последний узел
    
    while (fscanf(input, "%d", &num) == 1) {
        struct node_t *new_node = calloc(1, sizeof(struct node_t));
        new_node->data = num;
        current->next = new_node;
        current = new_node;        
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
