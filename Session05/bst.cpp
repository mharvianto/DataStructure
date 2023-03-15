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
    if (angka == curr->angka) {
        printf("Duplicate Key!");
    } else if (angka < curr->angka) {
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

Node * search(Node *curr, int angka) {
    if(curr != 0) {
        if (angka == curr->angka) {
            return curr;
        } else if (angka < curr->angka) {
            return search(curr->left, angka);
        } else {
            return search(curr->right, angka);
        }
    } else {
        return 0; // tidak ketemu
    }
}

Node * most_right(Node * curr) {
    if (curr != 0) {
        if (curr->right == 0) {
            return curr;
        } else {
            return most_right(curr->right);
        }
    } else {
        return 0;
    }
}

Node * pop (Node * curr, int score) {
    if (curr) { // curr != 0
        if (curr->angka == score) { // ketemu -> pop
            if(!curr->left && !curr->right) { // tidak punya anak
                free(curr);
                return 0;
            } else if(curr->left && curr->right) { // punya 2 anak
                Node * temp = most_right(curr->left);
                curr->angka = temp->angka;
                strcpy(curr->nama, temp->nama);
                curr->left = pop(curr->left, temp->angka);
            } else if(curr->left && curr->right == 0) { // hanya punya left child
                Node * temp = curr->left;
                free(curr);
                return temp;
            } else { // hanya punya right child
                Node * temp = curr->right;
                free(curr);
                return temp;
            }
        } else if(score < curr->angka) {
            curr->left = pop(curr->left, score);
        } else {
            curr->right = pop(curr->right, score);
        }
        return curr;
    } else {
        return 0;
    }
}

void view_tree(Node * curr, int level = 0) {
    if (curr) { // curr != 0
        view_tree(curr->right, level + 1);
        for (int i = 0; i < level; i++) {
            printf("    ");
        }
        printf("%d %s\n", curr->angka, curr->nama);
        view_tree(curr->left, level + 1);
    }
}

void pop_all(Node * curr) {
    if (curr) {
        pop_all(curr->left);
        pop_all(curr->right);
        free(curr);
        if (curr == root) {
            root = 0;
        }
    }
} 

int main(){
    root = push(root, 80, "Budi");
    root = push(root, 70, "Agnes");
    root = push(root, 90, "Joni");
    root = push(root, 85, "Kevin");
    // in_order(root);
    // printf("\n\n");
    // pre_order(root);
    // printf("\n\n");
    // post_order(root);
    // printf("\n\n");
    view_tree(root);
    printf("\n\n");
    // root = pop(root, 80);
    // view_tree(root);
    // printf("\n\n");
    // root = pop(root, 70);
    // view_tree(root);
    // printf("\n\n");
    // root = pop(root, 90);
    // view_tree(root);
    // printf("\n\n");
    // root = pop(root, 85);
    pop_all(root);
    view_tree(root);
    printf("\n\n");
    // in_order(root);
    return 0;
}