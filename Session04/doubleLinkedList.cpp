#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char name[50];
    int score;
    /// link
    Node *prev, *next;
} *head, *tail;

Node *createNode(char name[], int score)
{
    Node *curr = (Node *)malloc(sizeof(Node));
    strcpy(curr->name, name);
    curr->score = score;
    curr->prev = curr->next = 0;
    return curr;
}

void push_head(char name[], int score)
{
    Node *curr = createNode(name, score);
    if (head == 0)
    {
        head = tail = curr;
    }
    else
    {
        curr->next = head;
        head->prev = curr;
        head = curr;
    }
}

void push_tail(char name[], int score)
{
    Node *curr = createNode(name, score);
    if (head == 0)
    {
        head = tail = curr;
    }
    else
    {
        curr->prev = tail;
        tail->next = curr;
        tail = curr;
    }
}

void view()
{
    Node *curr = head;
    while (curr != 0)
    {
        printf("%s, %d\n", curr->name, curr->score);
        curr = curr->next;
    }
}

void pop_head()
{
    if (head != 0)
    {
        if (head == tail)
        { // cuma ada 1 data
            free(head);
            head = tail = 0;
        }
        else
        {
            Node *curr = head;
            head = head->next;
            head->prev = 0;
            free(curr);
        }
    }
}

void pop_tail()
{
    if (head != 0)
    {
        if (head == tail)
        { // cuma ada 1 data
            free(head);
            head = tail = 0;
        }
        else
        {
            Node *curr = tail;
            tail = tail->prev;
            tail->next = 0;
            free(curr);
        }
    }
}

void push_mid(char name[], int score)
{
    if (head == 0)
    {
        push_head(name, score);
    }
    else if (score < head->score)
    {
        push_head(name, score);
    }
    else if (score >= tail->score)
    {
        push_tail(name, score);
    }
    else
    {
        Node *curr = head;
        while (curr->score <= score)
        {
            curr = curr->next;
        }
        Node *newNode = createNode(name, score);
        newNode->next = curr;
        newNode->prev = curr->prev;
        curr->prev->next = newNode;
        curr->prev = newNode;
    }
}

Node * search(char name[]) {
    Node * curr = head;
    while (curr != 0) {
        if (strcmp(curr->name, name) == 0) {
            return curr;
        }
        curr = curr->next;
    }
    return 0;
}

void pop_mid(char name[]) {
    Node * curr = search(name);
    if (curr != 0) {
        if(curr == head) {
            pop_head();
        } else if (curr == tail) {
            pop_tail();
        } else {
            Node * temp = curr->next;
            curr->prev->next = temp;
            temp->prev = curr->prev;
            free(curr);
        }
    }
}

int main()
{
    push_mid("Kevin", 90);
    push_mid("Bayu", 50);
    push_mid("Budi", 75);
    push_mid("Juni", 75);
    push_mid("Juli", 85);
    push_mid("Agus", 65);
    view();
    return 0;
}