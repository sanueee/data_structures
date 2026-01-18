#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node_t *read_list(FILE *input);
struct node_t *reverse_list(struct node_t *top);
void delete_list(struct node_t *top);
void print_list(const struct node_t *top);

struct node_t {struct node_t *next; int data;};

int main(int argc, char** argv) {
    if (argc < 2) return -1;
    FILE* file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file.");
        abort();
    }

    struct node_t *list = read_list(file);
    if (!list) {
        fclose(file);
        return -1;
    }

    print_list(list);

    delete_list(list);
    fclose(file);
    return 0;
}

struct node_t *read_list(FILE *input) {
    int num;
    struct node_t *even_list = NULL, *odd_list = NULL, *node;
    struct node_t *last_even = NULL, *last_odd = NULL;
    
    while (fscanf(input, "%d", &num) == 1) {
        node = calloc(1, sizeof(struct node_t));
        node->data = num;
        if ((num & 0x1) == 0) {
            if (even_list == NULL) 
                last_even = node;
            node->next = even_list;
            even_list = node;
        } else {
            if (odd_list == NULL) 
                last_odd = node;
            node->next = odd_list;
            odd_list = node;
        }
    }

    if (last_odd == NULL) 
        return reverse_list(even_list);
    assert(last_odd->next == NULL);
    last_odd->next = even_list;

    return reverse_list(odd_list);
}

struct node_t *reverse_list(struct node_t *top) {
    struct node_t *xs;
    if (top == NULL) return NULL;
    if (top->next == NULL) return top;
    xs = reverse_list(top->next);
    top->next->next = top;
    top->next = NULL;
    return xs;
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