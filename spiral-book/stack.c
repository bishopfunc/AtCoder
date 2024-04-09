#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

int top, S[MAX];

void initialize() {
  top = 0;
}

int isEmpty() {
  return top == 0;
}

int isFull() {
  return top >= MAX - 1;
}


void push(int x) {
  if (isFull()) {
    printf("error: stack is full\n");
    return;
  }
  top++;
  S[top] = x;
}

int pop() {
  if (isEmpty()) {
    printf("error: stack is empty\n");
    return -1;
  }
  top--;
  return S[top + 1];
}

