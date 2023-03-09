#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct tree {
    struct tree *left, *right;
    char data;
};

void Operand(char a);
void Operator(char op);
void push(struct tree*);
struct tree* pop();

void inorder(struct tree *root);

struct tree *stack[20];
int top = -1;

int main() {
    
    char postfix[30];
    printf("Enter postfix expression: ");
    scanf(" %s", postfix);
    
    int i=0;
    while(postfix[i] != '\0') {
        if isalnum(postfix[i]) {
            Operand(postfix[i]);
        }
        else {
            Operator(postfix[i]);
        }
        i++;
    }
    
    inorder(stack[top]);
    
    return 0;
}

void push(struct tree* root) {
    stack[++top] = root;
}

struct tree* pop() {
    return stack[top--];
}

void Operand(char a) {
    struct tree *curr;
    curr = (struct tree*)malloc(sizeof(struct tree));
    curr->data = a;
    curr->left = NULL;      curr->right = NULL;
    push(curr);
}

void Operator(char op) {
    struct tree *curr;
    curr = (struct tree*)malloc(sizeof(struct tree));
    curr->data = op;
    curr->right = pop();
    curr->left = pop();      
    push(curr);
}

void inorder(struct tree *root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
    }
}
