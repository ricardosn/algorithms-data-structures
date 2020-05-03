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

    printf("\n Created Linked list is: ");

    printList(head);

}