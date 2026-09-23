#ifndef DOUBLE_LINKED_H
#define DOUBLE_LINKED_H
struct student {
    char name[40];
    unsigned long int id;
    float n1,n2,n3;
};

typedef struct student Student;

struct list {
    Student data;
    struct list *previous;
    struct list *next;
};

typedef struct list Node;

int list_size(Node **head);
int is_empty(Node *head);
void insert_begining(Node **head, Student s);
void insert_in_order(Node **head, Student s);
void insert_end(Node **head,  Student s);
void print_list(Node *head);
void remove_node(Node **head,  Student s);
void free_list(Node **head);
#endif