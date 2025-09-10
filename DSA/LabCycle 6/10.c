#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char url[100];
    struct Node *prev, *next;
};
struct Node *cur = NULL;

struct Node *newNode(char *url) {
    struct Node *t = malloc(sizeof(struct Node));
    strcpy(t->url, url);
    t->prev = t->next = NULL;
    return t;
}

void visit(char *url) {
    struct Node *t = newNode(url);
    if (cur) {
        t->prev = cur;
        cur->next = t;
    }
    cur = t;
    printf("Visited: %s\n", cur->url);
}
void back() {
    if (cur && cur->prev) {
        cur = cur->prev;
        printf("Back: %s\n", cur->url);
    }
}
void forward() {
    if (cur && cur->next) {
        cur = cur->next;
        printf("Forward: %s\n", cur->url);
    }
}

int main() {
    visit("a.com");
    visit("b.com");
    back();
    forward();
}
