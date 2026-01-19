
struct node_t {struct node_t *next; int data;};

int list_is_a_loop_fl(struct node_t *top);

int list_is_a_loop_fl(struct node_t *top) {
    struct node_t *rabbit = top, *turtle = top;
    while (rabbit != NULL) {
        rabbit = rabbit->next;
        turtle = turtle->next;
        if (rabbit == NULL) {
            return 0;
        }
        rabbit = rabbit->next;
        if (rabbit == turtle) {
            return 1;
        }
    }
    return 0;
}