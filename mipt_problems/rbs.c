#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node_t {struct node_t *next; int data;};

struct node_t* insert(struct node_t *head, int el);
void print_and_free(struct node_t **buckets, int len);

int main(void) {
    int len;
    if (scanf("%d", &len) != 1 || len < 1) {
        perror("wrong value of len");
        return -1;
    }

    int max = 0;
    int *arr = malloc(len * sizeof(int));

    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > max) max = arr[i];
    }

    struct node_t **buckets = calloc(len, sizeof(struct node_t*));
    int bucket_size = max / len;
    if (bucket_size == 0) bucket_size = 1;

    for (int i = 0; i < len; i++) {
        int bucket_index = arr[i] / bucket_size;
        if (bucket_index >= len) bucket_index = len - 1;
        buckets[bucket_index] = insert(buckets[bucket_index], arr[i]); // возвращаем голову bucket'a
    }

    print_and_free(buckets, len);

    return 0;
}

struct node_t* insert(struct node_t *head, int el) {
    struct node_t *new_node = calloc(1, sizeof(struct node_t));
    new_node->data = el;
    new_node->next = NULL;

    if (!head || head->data >= el) { // если вставляем в самое начало (надо изменить голову)
        new_node->next = head;
        return new_node;
    }

    struct node_t *curr = head;
    while (curr->next && curr->next->data <= el) {
        curr = curr->next;
    }
    new_node->next = curr->next;
    curr->next = new_node;

    return head;
}

void print_and_free(struct node_t **buckets, int len) {
    for (int i = 0; i < len; i++) {
        struct node_t *curr = *(buckets + i);
        while (curr) {
            printf("%d ", curr->data);
            struct node_t *temp = curr;
            curr = curr->next;
            free(temp); // очищаем по указателю
        }
        printf("0 ");
    }
    printf("\n");
}
