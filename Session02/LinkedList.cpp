#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    // data
    int score;
    char name[20];
    // link
    struct node *next;
} *head = 0, *tail = 0;

void push_head(int score, char name[]) {
    struct node *curr = (struct node*)malloc(sizeof(struct node));
    curr->score = score;
    strcpy(curr->name, name);
    curr->next = 0;
    if (head == 0) { // list kosong
        head = curr;
        tail = curr;
    } else { // list tidak kosong
        curr->next = head;
        head = curr;
    }
}

void push_tail(int score, char name[]) {
    struct node *curr = (struct node*)malloc(sizeof(struct node));
    curr->score = score;
    strcpy(curr->name, name);
    curr->next = 0;
    if (head == 0) { // list kosong
        head = curr;
        tail = curr;
    } else { // list tidak kosong
        tail->next = curr;
        tail = curr;
    }
}

void view(){
    struct node *curr = head;
    while (curr != 0)
    {
        printf("%s - %d\n", curr->name, curr->score);
        curr = curr->next;
    }
}

void pop_head() {
    if (head != 0) {
        struct node *curr = head;
        head = head->next;
        free(curr);
    }
}

void pop_tail() {
    if(head == tail) { // list cuma ada 1 data
        free(head);
        head = tail = 0;
    } else {
        struct node * curr = head;
        while (curr->next != tail) { // selama curr->next bukan tail
            curr = curr->next; // maka pindah ke setelahnya
        }
        free(tail);
        curr->next = 0;
        tail = curr;
    }
}

struct node* search(int index) {
    if (index == 0) {
        return head;
    } else {
        node* curr = head;
        while (curr != 0 && index > 0) {
            curr = curr->next;
            index--;
        }
        return curr;
    } 
}

node * searchName(char name[]) {
    node * curr = head;
    while (curr != 0) {
        if (strcmp(curr->name, name) == 0) {
            return curr;
        }
        curr = curr->next;
    }
    return 0;
}

void push_mid(int index, int score, char name[]){
    node * curr = (node*)malloc(sizeof(node));
    curr->score = score;
    strcpy(curr->name, name);
    node* temp = search(index);
    if (temp != 0) {
        curr->next = temp->next;
        temp->next = curr;
    }
}

int main() {
    push_head(80, "Udin");  // 2
    push_head(85, "Kevin"); // 1
    push_head(70, "Davin"); // 0
    push_tail(90, "Budi");  // 3
    push_mid(2, 75, "Andi");
    head->next->score = 88;
    pop_head();
    view();
    node* curr = search(4);
    if (curr != 0) {
        printf("%d\n", curr->score);
    } else {
        printf("Not found.\n");
    }
    curr = searchName("Udi");
    if (curr != 0) {
        printf("%d\n", curr->score);
    } else {
        printf("Not found.\n");
    }
    // printf("%s\n", head->next->next->next->name);
    return 0;
}