#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  char value[15];
  struct node *prev;
  struct node *next;

} Node;

typedef struct {
  int length;
  Node *head;
  Node *tail;
} List;

List lst = {.length = 0, .head = NULL, .tail = NULL};

bool addNodeTail(char *value) {

  if (value == NULL) {
    return false;
  }

  Node *newNode;

  newNode = malloc(sizeof(Node));
  memset(newNode, 0, sizeof(Node));
  strncpy(newNode->value, value, 15);
  newNode->prev = NULL;
  newNode->next = NULL;

  if (lst.length == 0) {
    lst.head = newNode;
    lst.tail = newNode;
    lst.length++;
    return true;
  } else {

    lst.tail->next = newNode;
    newNode->prev = lst.tail;
    lst.tail = newNode;
    lst.length++;
    return true;
  }

  return false;
}

bool removeTail() {

  if (lst.length == 0) {
    return false;
  } else if (lst.length == 1) {

    Node *tail = lst.tail;
    lst.head = lst.tail = NULL;

    free(tail);
    lst.length--;
    return true;
  }

  // length > 1

  Node *tail = lst.tail;

  Node *prevOne = lst.tail->prev;
  prevOne->next = NULL;
  lst.tail = prevOne;
  free(tail);
  lst.length--;

  return true;
}

bool addHead(char *value) {

  if (value == NULL) {
    return false;
  }

  Node *newNode = malloc(sizeof(Node));

  memset(newNode, 0, sizeof(Node));
  strncpy(newNode->value, value, 15);

  newNode->next = newNode->prev = NULL;

  if (lst.length == 0) {

    lst.head = lst.tail = newNode;
    lst.length++;
    return true;
  }

  // length > 0

  lst.head->prev = newNode;
  newNode->next = lst.head;
  lst.head = newNode;
  lst.length++;
  return true;
}

bool removeHead() {

  if (lst.length == 0) {
    return false;
  } else if (lst.length == 1) {
    Node *head = lst.head;
    lst.head = lst.tail = NULL;
    free(head);
    lst.length--;
    return true;
  }

  // length > 1
  Node *head = lst.head;
  Node *nextOne = lst.head->next;
  nextOne->prev = NULL;
  lst.head = nextOne;
  free(head);
  lst.length--;
  return true;
}

void printNodes() {

  Node *now = lst.head;

  for (int i = 0; i < lst.length; i++) {

    printf("val::%s\n", now->value);
    now = now->next;
  }
}
