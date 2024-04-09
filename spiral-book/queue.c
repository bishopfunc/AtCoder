#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

int head, tail, Q[MAX];

void initialize() {
  head = tail = 0;
}

int isEmpty() {
  return head == tail;
}

int isFull() {
  return head == (tail + 1) % MAX;
}


void enqueue(int x) {
  if (isFull()) {
    printf("warning: queue is full\n");
  }
  Q[tail] = x;
  // if (tail + 1 == MAX) {
  //   tail = 0;
  // } else {
  //   tail++;
  // }
  tail = (tail + 1) % MAX;
}

int dequeue() {
  if (isEmpty()) {
    printf("warning: queue is empty\n");
  }
  int x = Q[head];
  // if (head + 1 == MAX) {
  //   head = 0;
  // } else {
  //   head++;
  // }
  head = (head + 1) % MAX;
  return x;
}
