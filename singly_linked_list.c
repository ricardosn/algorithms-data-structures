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

void deleteAtPosition(struct Node **head_ref, int position) {
    struct Node *tmp = (*head_ref);
    struct Node *prev = (*head_ref);
    int i = 0;

    if(tmp != NULL && position == 0) {
        *head_ref = tmp->next;
        free(tmp);
        return;
    }

    while(tmp != NULL && position != i) {
        prev = tmp;
        tmp = tmp->next;
        i++;
    }

    if(tmp == NULL) {
        printf("\nPosition [%d] not found.", position);
        return;
    }

    prev->next = tmp->next;
    free(tmp);
}

void deleteByKey(struct Node **head_ref, int key) {
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
        printf("\nKey:[%d] not found.", key);
        return;
    }

    prev->next = tmp->next;
    free(tmp);
}

int listLength(struct Node **head_ref) {
    struct Node *last = (*head_ref);
    int cont = 0;

    while(last != NULL) {
        last = last->next;
        cont++;
    }

    return cont;
}

void printList(struct Node *node) {
    printf("\nCreated Linked list is: ");

    while(node != NULL) {
        printf("%d, ", node->data);
        node = node->next;
    }
}

void initList(struct Node **head_ref) {
    push(head_ref, 7);

    push(head_ref, 8);

    append(head_ref, 10);

    append(head_ref, 5);

    append(head_ref, 6);

    insertAfter((*head_ref)->next, 11);

    deleteByKey(head_ref, 8);

    deleteByKey(head_ref, 31);

    deleteAtPosition(head_ref, 2);
}

int main() {

    struct Node *head = NULL;

    int aux = 0, value = 0;

    while(aux >= 0) {
        // init
        value = 0;

        printf("Menu:\n");
        printf("0 - Init List\n");
        printf("1 - Push\n");
        printf("2 - Append\n");
        printf("3 - Insert After\n");
        printf("4 - Delete By Key\n");
        printf("5 - Delete At Position\n");
        printf("6 - List Lenght\n");
        printf("7 - Print List\n");
        printf("Type Anything else to Exit\n");
        printf("Choose option:\n");
        scanf("%d", &aux);

        switch (aux) {
        case 0:
            initList(&head);
            break;

        case 1:
            printf("Choose Value:\n");
            scanf("%d", &value);
            push(&head, value);
            break;

        case 2:
            printf("Choose Value:\n");
            scanf("%d", &value);
            append(&head, value);
            break;

        case 3:
            printf("Choose Value:\n");
            scanf("%d", &value);
            insertAfter(head->next, 11);
            break;

        case 4:
            printf("Choose Value:\n");
            scanf("%d", &value);
            deleteByKey(&head, value);
            break;

        case 5:
            printf("Choose Value:\n");
            scanf("%d", &value);
            deleteAtPosition(&head, value);
            break;

        case 6:
            printf("\nList length is: %d\n", listLength(&head));
            break;

        case 7:
            printList(head);
            break;
        
        default:
            aux  = -1;
            break;
        }
    }

    return 0;

}