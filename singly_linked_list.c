#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void push(struct Node** head_ref, int data) {
    struct Node* new = (struct Node *) malloc(sizeof(struct Node));

    new->data = data;
    new->next = (*head_ref);

    (*head_ref) = new;
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

    printf("\n Created Linked list is: ");

    printList(head);

}