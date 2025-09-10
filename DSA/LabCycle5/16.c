#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    int mark;
    struct Student* next;
};

struct Student* head = NULL;

struct Student* newStudent(int roll, char* name, int mark) {
    struct Student* s = (struct Student*)malloc(sizeof(struct Student));
    s->roll = roll;
    strcpy(s->name, name);
    s->mark = mark;
    s->next = NULL;
    return s;
}

void insert(int roll, char* name, int mark) {
    struct Student* s = newStudent(roll, name, mark);
    s->next = head;
    head = s;
}

void delete(int roll) {
    struct Student* temp = head, *prev = NULL;
    while (temp && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) return;
    if (!prev) head = temp->next;
    else prev->next = temp->next;
    free(temp);
}

void modify(int roll, char* name, int mark) {
    struct Student* temp = head;
    while (temp) {
        if (temp->roll == roll) {
            strcpy(temp->name, name);
            temp->mark = mark;
            return;
        }
        temp = temp->next;
    }
}

struct Student* search(int roll) {
    struct Student* temp = head;
    while (temp) {
        if (temp->roll == roll) return temp;
        temp = temp->next;
    }
    return NULL;
}

void printList() {
    struct Student* temp = head;
    while (temp) {
        printf("%d %s %d\n", temp->roll, temp->name, temp->mark);
        temp = temp->next;
    }
}

int main() {
    insert(1, "John", 85);
    insert(2, "Mary", 90);
    insert(3, "Alex", 78);
    printList();
    modify(2, "MaryJane", 95);
    delete(1);
    struct Student* s = search(3);
    if (s) printf("Found: %d %s %d\n", s->roll, s->name, s->mark);
    printList();
}
