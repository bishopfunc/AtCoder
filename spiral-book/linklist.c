#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  int key;
  struct Node *next, *prev;
} Node;

Node *nil; // dummy node

void initialize() {
  nil = (Node *)malloc(sizeof(Node)); // allocate memory for dummy node
  nil->next = nil;
  nil->prev = nil;
  // nil -> nil
  // nil <- nil
}

Node* listSearch(int key) {
  Node *cur = nil->next;
  while (cur != nil && cur->key != key) {
    cur = cur->next;
  }
  return cur;
}

void printList() {
  Node *cur = nil->next;
  int isf = 0; // flag
  while (1) {
    if (cur == nil) break;
    if (isf++ > 0) printf(" ");
    printf("%d", cur->key);
    cur = cur->next;
  }
  printf("\n");
}

void deleteNode(Node *t) {
  if (t == nil) return; // cannot delete dummy
  t->prev->next = t->next;
  t->next->prev = t->prev;
  free(t);
}

void deleteFirst() {
  deleteNode(nil->next);
}

void deleteLast() {
  deleteNode(nil->prev);
}

void deleteKey(int key) {
  deleteNode(listSearch(key));
}

void insert(int key) {
  Node *x = (Node *)malloc(sizeof(Node));
  x->key = key;
  x->next = nil->next; // x->next
  nil->next->prev = x; // x<-next
  nil->next = x; // nil->x
  x->prev = nil; // nil<-x
  // nil <-> x <-> next
}