#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function declarations
Node* create_node(int data);
void insert_at_beginning(Node** head, int data);
void insert_at_end(Node** head, int data);
void insert_at_position(Node** head, int data, int position);
void delete_node(Node** head, int key);
Node* search(Node* head, int key);
void display_list(Node* head);
void free_list(Node** head);

#endif // LINKED_LIST_H
