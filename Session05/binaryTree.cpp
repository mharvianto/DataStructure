#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct Node{
    int angka;
    char nama[20];
    // link
    Node * left;
    Node * right;
} *root;

Node * create_node(int angka, char nama[]) {
    Node *curr = (Node*)malloc(sizeof(Node));
    curr->angka = angka;
    strcpy(curr->nama, nama);
    curr->left = curr->right = 0;
    return curr;
}

Node * push(Node * curr, int angka, char nama[]){
    if (curr == 0) {
        return create_node(angka, nama);
    }
    char a;
    printf("%d %s\n", angka, nama);
    printf("l for left, r for right. Choose: ");
    scanf("%c", &a); getchar();
    if (a == 'l') {
        curr->left = push(curr->left, angka, nama);
    } else {
        curr->right = push(curr->right, angka, nama);
    }
    return curr;
}

void in_order(Node * curr) {
    if (curr != 0) {
        in_order(curr->left);
        printf("%d %s\n", curr->angka, curr->nama);
        in_order(curr->right);
    }
}

void pre_order(Node * curr) {
    if (curr != 0) {
        printf("%d %s\n", curr->angka, curr->nama);
        pre_order(curr->left);
        pre_order(curr->right);
    }
}

void post_order(Node * curr) {
    if (curr != 0) {
        post_order(curr->left);
        post_order(curr->right);
        printf("%d %s\n", curr->angka, curr->nama);
    }
}

int main(){
    root = push(root, 80, "Budi");
    root = push(root, 70, "Agnes");
    root = push(root, 90, "Joni");
    root = push(root, 85, "Kevin");
    in_order(root);
    printf("\n\n");
    pre_order(root);
    printf("\n\n");
    post_order(root);
    return 0;
}