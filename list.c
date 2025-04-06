#include "list.h"

// Function to create a new node
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert at the beginning
void insert_at_beginning(Node** head, int data) {
    Node* new_node = create_node(data);
    if (!new_node) return;
    new_node->next = *head;
    *head = new_node;
}

// Insert at the end
void insert_at_end(Node** head, int data) {
    Node* new_node = create_node(data);
    if (!new_node) return;
    
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    Node* temp = *head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Insert at a specific position
void insert_at_position(Node** head, int data, int position) {
    if (position < 1) {
        printf("Invalid position\n");
        return;
    }

    Node* new_node = create_node(data);
    if (!new_node) return;

    if (position == 1) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    Node* temp = *head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(new_node);
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

// Delete a node by key
void delete_node(Node** head, int key) {
    Node* temp = *head;
    Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

// Search for a node
Node* search(Node* head, int key) {
    Node* temp = head;
    while (temp) {
        if (temp->data == key) return temp;
        temp = temp->next;
    }
    return NULL;
}

// Display the list
void display_list(Node* head) {
    Node* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Free the list
void free_list(Node** head) {
    Node* temp = *head;
    while (temp) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
}
