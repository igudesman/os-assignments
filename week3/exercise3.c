#include <stdio.h>
#include <stdlib.h>

struct linked_list {
  int value;
  struct linked_list * next;
};

void print_list(struct linked_list * head) {
  while (head != NULL) {
    printf("%d ", head->value);
    head = head->next;
  }
  printf("\n");
}

void insert_node(int value, struct linked_list * head) {
  struct linked_list * current = head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = (struct linked_list *) malloc(sizeof(struct linked_list));
  current->next->value = value;
  current->next->next = NULL;
}

int delete_node(int value, struct linked_list * head) {
  if (head == NULL) {
      return -1;
  }
  struct linked_list * prev = NULL;
  struct linked_list * current = head;
  while(current->value != value) {
    if(current->next == NULL) {
      return -1;
    } else {
      prev = current;
      current = current->next;
    }
  }
  if(current == head) {
    head = head->next;
  } else {
    prev->next = current->next;
  }   
  return 0;
}

int main() {
  struct linked_list * head = (struct linked_list *) malloc(sizeof(struct linked_list));
  insert_node(4, head);
  insert_node(8, head);
  insert_node(9, head);
  print_list(head);
  delete_node(4, head);
  print_list(head);
  delete_node(8, head);
  print_list(head);
  delete_node(9, head);
  print_list(head);
  delete_node(9, head);
  print_list(head);
  
  return 0;
}

