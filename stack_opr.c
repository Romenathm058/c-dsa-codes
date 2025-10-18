#include<stdio.h>
#include<stdlib.h>

struct Stack {
    int size;
    int top;
    int *arr;
};

void push(struct Stack *S){
    int val;
    printf("enter the value you want to push : ");
    if (scanf("%d", &val) != 1) {
        printf("invalid input\n");
        return;
    }

    if (S->top >= S->size - 1) {
        printf("Stack overflow\n");
        return;
    }

    S->top++;
    S->arr[S->top] = val;

    printf("successfully pushed\n");
}
void pop(struct Stack *S){
     if (S->top == -1) {
         printf("Stack is empty\n");
    } else {
         printf("Popped: %d\n", S->arr[S->top]);
           S->top--;
           }
}
void peek(struct Stack *S){
     if (S->top == -1) {
                    printf("Stack is empty\n");
                } else {
                    printf("Top element: %d\n", S->arr[S->top]);
                }
}

int main(){
    struct Stack *S;
    S = (struct Stack*)malloc(S->size * sizeof(struct Stack));
    S->size = 10;
    S->top = -1;
    S->arr =(int*)malloc(S->size * sizeof(int));
    

    printf("*****ENTER YOUR CHOICE*****\n");
    printf("1 = PUSH || 2 = POP || 3 = PEEK || 4 = EXIT \n");

    int n;
    while(1){
    printf("ENTER YOUR CHOICE :: ");
    scanf("%d", &n);
    if (n<=0 || n>4) {
            printf("Invalid input. Exiting...\n");
            break;
        }switch(n) {
            case 1:
                push(S);
                break;
            case 2:
                pop(S);
                break;
            case 3:
                peek(S);
                break;
            case 4:
                printf("Exiting...\n");
                free(S->arr);
                free(S);
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    free(S->arr);
    free(S);
    return 0;
}