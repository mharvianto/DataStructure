#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
    int angka;
    // link
    Node *left, *right;
} *root;

Node* create_node(int angka) {
    Node* curr = (Node *)malloc(sizeof(Node));
    curr->angka = angka;
    curr->left = curr->right = 0;
    return curr;
} 

void push(Node **curr, int angka) {
    if (!(*curr)) {
        *curr = create_node(angka);
    } else {
        if((*curr)->angka == angka) {
            return;
        } else if(angka < (*curr)->angka) {
            push(&(*curr)->left, angka);
        } else {
            push(&(*curr)->right, angka);
        }
    }
}

void view_tree(Node *curr, int level = 0) {
    if (!curr) return;
    view_tree(curr->right, level + 1);
    for (int i = 0; i < level; i++) printf("  ");
    printf("%2d\n", curr->angka);
    view_tree(curr->left, level + 1);
}

void in_order(Node *curr){
    if (!curr) return;
    in_order(curr->left);
    printf("%d, ");
    in_order(curr->right);
}

void pre_order(Node *curr){
    if (!curr) return;
    printf("%d, ");
    pre_order(curr->left);
    pre_order(curr->right);
}

void post_order(Node *curr){
    if (!curr) return;
    post_order(curr->left);
    post_order(curr->right);
    printf("%d, ");
}

Node * search(Node * curr, int angka) {
    if (!curr) return 0;
    if (angka == curr->angka) return curr;
    if (angka < curr->angka) return search(curr->left, angka);
    return search(curr->right, angka);
}

Node * most_right(Node * curr) {
    if (!curr) return 0;
    if (curr->right) return most_right(curr->right);
    return curr;
}

void pop(Node **curr, int angka) {
    if (!(*curr)) return;
    if (angka < (*curr)->angka) pop(&(*curr)->left, angka);
    else if (angka > (*curr)->angka) pop(&(*curr)->right, angka);
    else {
        if ((*curr)->left && (*curr)->right) {
            Node *temp = most_right((*curr)->left);
            (*curr)->angka = temp->angka;
            pop(&(*curr)->left, temp->angka);
        } else if(!(*curr)->left && !(*curr)->right) {
            free(*curr);
            *curr = 0;
        } else{
            Node *temp = (*curr)->left;
            if ((*curr)->right) {
                temp = (*curr)->right;
            }
            free(*curr);
            *curr = temp; 
        }
    }
}

int main() {
    for (int i = 0; i < 15; i++) {
        int a = rand() % 100;
        printf("%d, ", a);
        push(&root, a);
    }
    printf("\n");
    view_tree(root);
    
    return 0;
}