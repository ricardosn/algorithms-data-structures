#include <stdio.h>
#include <stdlib.h>

// malloc aloca memória e retorna o ponteiro para o primeiro Byte

struct Node {
    int data;
    struct Node *next;
};

void push(struct Node **head_ref, int data) {
    struct Node *new = (struct Node *) malloc(sizeof(struct Node));

    new->data = data;
    new->next = (*head_ref);

    (*head_ref) = new;
}

void append(struct Node **head_ref, int data) {
    struct Node *new = (struct Node *) malloc(sizeof(struct Node));
    struct Node *last = (*head_ref);

    new->data = data;
    new->next = NULL;

    if (*head_ref == NULL) {
        (*head_ref) = new;
        return;
    }

    // Last Node
    while(last->next != NULL) {
        last = last->next;
    }

    last->next = new;
}

void insertAfter(struct Node *prev_node, int data) {
    struct Node *new = (struct Node *) malloc(sizeof(struct Node));

    if (prev_node == NULL) {
        printf("Previous Node cannot be NULL");
        return;
    }

    new->data = data;
    new->next = prev_node->next;

    prev_node->next = new;
}

void delete(struct Node **head_ref, int key) {
    struct Node *tmp = (*head_ref);
    struct Node *prev = (*head_ref);

    if(tmp != NULL && tmp->data == key) {
        *head_ref = tmp->next;
        free(tmp);
        return;
    }

    while(tmp != NULL && tmp->data != key) {
        prev = tmp;
        tmp = tmp->next;
    }

    // Reached the end of the list without finding the key
    if(tmp == NULL) {
        printf("\nKey:[%d] Not found.", key);
        return;
    }

    prev->next = tmp->next;
    free(tmp);

}

void printList(struct Node *node) {
    while(node != NULL) {
        printf("%d, ", node->data);
        node = node->next;
    }
}

int main() {

    struct Node *head = NULL;

    push(&head, 7);

    push(&head, 8);

    append(&head, 10);

    insertAfter(head->next, 11);

    delete(&head, 8);

    delete(&head, 31);

    printf("\nCreated Linked list is: ");

    printList(head);

    return 0;

}