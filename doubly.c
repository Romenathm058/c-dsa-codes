#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Forward traversal
void forwardTraversal(struct Node *ptr) {
    printf("Forward Traversal:\n");
    while (ptr != NULL) {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Reverse traversal
void reverseTraversal(struct Node *ptr) {
    printf("Reverse Traversal:\n");
    while (ptr != NULL) {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->prev;
    }
}

int main() {
    struct Node *N1, *N2, *N3, *N4;

    // Memory allocation
    N1 = (struct Node *)malloc(sizeof(struct Node));
    N2 = (struct Node *)malloc(sizeof(struct Node));
    N3 = (struct Node *)malloc(sizeof(struct Node));
    N4 = (struct Node *)malloc(sizeof(struct Node));

    // Assign data
    N1->data = 89;
    N2->data = 27;
    N3->data = 7;
    N4->data = 92;

    // Linking
    N1->next = N2;
    N1->prev = NULL;

    N2->next = N3;
    N2->prev = N1;

    N3->next = N4;
    N3->prev = N2;

    N4->next = NULL;
    N4->prev = N3;

    // Forward traversal
    forwardTraversal(N1);

    // Reverse traversal (start from last node)
    reverseTraversal(N4);

    return 0;
}
