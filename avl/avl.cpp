#include<stdio.h>
#include<stdlib.h>

struct node
{
    int angka;
    int h;
    struct node *l, *r;
} *root;

node* createNode(int angka) {
    node* curr = (node*)malloc(sizeof(node));
    curr->angka = angka;
    curr->h = 1;
    curr->l = curr->r = 0;
    return curr;
}

int getHeight(node* curr) {
    if (curr) return curr->h;
    return 0;
}

int max(int a, int b) {
    return a > b ? a : b;
}

node* rightRotate(node* curr) {
    node* T = curr;
    node* S = curr->l;

    T->l = S->r;
    S->r = T;

    T->h = max(getHeight(T->l), getHeight(T->r)) + 1;
    S->h = max(getHeight(S->l), getHeight(S->r)) + 1;

    return S;
}

node* leftRotate(node* curr) {
    node* T = curr;
    node* S = curr->r;

    T->r = S->l;
    S->l = T;

    T->h = max(getHeight(T->l), getHeight(T->r)) + 1;
    S->h = max(getHeight(S->l), getHeight(S->r)) + 1;

    return S;
}

node* push(node* curr, int angka) {
    if (!curr) {
        return createNode(angka);
    } else {
        if(angka < curr->angka) {
            curr->l = push(curr->l, angka);
        } else if (curr->angka < angka) {
            curr->r = push(curr->r, angka);
        } else {
            return curr;
        }

        curr->h = max(getHeight(curr->l), getHeight(curr->r)) + 1;

        int diff = getHeight(curr->l) - getHeight(curr->r);

        
        if (diff == 2 && angka < curr->l->angka) {
            return rightRotate(curr);
        }

        if (diff == -2 && angka > curr->r->angka) {
            return leftRotate(curr);
        }

        if (diff == 2 && angka > curr->l->angka) {
            curr->l = leftRotate(curr->l);
            return rightRotate(curr);
        }

        if (diff == -2 && angka < curr->r->angka) {
            curr->r = rightRotate(curr->r);
            return leftRotate(curr);
        }

        return curr;
    }
}

void viewTree(node* curr, int level = 0) {
    if (curr) {
        viewTree(curr->r, level + 1);
        for (int i = 0; i < level; i++) printf("  ");
        printf("%d\n", curr->angka);
        viewTree(curr->l, level + 1);
    }
}

int main(){
    for (int i = 0; i < 20; i++) {
        int a = rand() % 100 + 1;
        printf("Insert %d\n", a);
        root = push(root, a);
        viewTree(root);
        printf("\n\n");
    }
    
    return 0;
}