#include<stdio.h>
#include<stdlib.h>

struct Node{

    int data;
    struct Node * next;

};

void LinkedListTraversal(struct Node *head){
    struct Node *ptr = head;
  
    do {
        printf("element is : %d \n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node * insertATfirst(struct Node *head,int data){
    struct Node *ptr = (struct Node* )malloc(sizeof(struct Node));  
    ptr ->data = data;
struct Node *p = head-> next;
while(p->next != head){
    p = p->next;
}
// at this point p points to the last node of this circular linked list
p->next = ptr;
ptr ->next = head ;
head = ptr;
return head;
}

struct Node *deleteFirst(struct Node* head){
    struct Node *ptr = head;
    struct Node *p = head;

    // find the last node
    while (p->next != head) {
        p = p->next;
    }

    // now p is last node, head is first node
    p->next = head->next; // link last node to second node
    head = head->next;    // move head to next node

    free(ptr); // free old head
    
    return head;
}

struct Node *deleteInBetween(struct Node *head,int index){
    if(head == NULL){
        return NULL;
    }

    if (index == 0){
        deleteFirst(head);
    }
    struct Node *p = head;
    struct Node *q = head->next;

    for(int i = 0;i< index -1 ;i++){
        p = p->next;
        q = q -> next;
        p->next = q->next;
        free(q);
        return head;
    }

}



int main(){

    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;

    // allocate memory for nodes in the linked list in heap

     head = (struct Node*)malloc(sizeof(struct Node));
     second = (struct Node*)malloc(sizeof(struct Node));
     third = (struct Node*)malloc(sizeof(struct Node));
     fourth = (struct Node*)malloc(sizeof(struct Node));

        // link first and second nodes

     head->data = 4;
     head->next = second;

        // link second and third nodes

     second->data = 3;
     second->next = third;

        // link the third and fourth nodes
    
    third->data = 6;
    third->next = fourth;

        // terminate the list at the fourth node

    fourth->data = 1;
    fourth->next = head;    

        //calling the fubction
printf("circular linked list berfore\n");
        LinkedListTraversal(head);
        head = insertATfirst(head,69);
printf("circular linked list after\n");
LinkedListTraversal(head);

head= deleteFirst(head);
printf("after Delete First\n");
LinkedListTraversal(head);

head = deleteInBetween(head,2);
printf("delete in between \n");\
LinkedListTraversal(head);

        


    return 0;
}