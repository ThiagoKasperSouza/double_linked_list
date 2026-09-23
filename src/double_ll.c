#include <stdio.h>
#include <stdlib.h>
#include "double_ll.h"

void insert_begining(Node **head, Student s) {
    //aloca
    if (head == NULL) return;
    Node *l = (Node*) malloc(sizeof(Node));
    //atribui val e head no proximo
    if(l == NULL) return;
    l->data=s;
    l->next=*head;
    l->previous=NULL;

    if(*head !=NULL) {
        (*head)->previous=l;
    }
    //atribui novo inicio
    *head = l;
   
    
}

int list_size(Node **head) {
    if (head == NULL) return 0;
    int cont = 0;
    Node *node = *head;
    while(node !=NULL) {
        cont++;
        node = node->next;
    }
    return cont;
}
int is_empty(Node *head) {
    return head == NULL;
}

void insert_in_order(Node **head, Student s) {
    if (head == NULL) return;

    // 1. Aloca o novo nó
    Node *new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) return; // Trata falha de alocação

    new_node->data = s;
    new_node->next = NULL;
    new_node->previous=NULL;

    // 2. Ponteiros para percorrer a lista EXISTENTE (*head)
    Node *previous = NULL;
    Node *current = *head;

    // 3. Avança até encontrar a posição correta (ordem crescente por id)
    while (current != NULL && current->data.id < s.id) {
        previous = current;
        current = current->next;
    }

    // 4. Inserção no início da lista (lista vazia ou id é a menor)
    if (previous == NULL) {
        new_node->previous=NULL;
        if (*head != NULL) {
            (*head)->previous = new_node;
        }
        new_node->next = *head;
        *head = new_node;
    } 
    // 5. Inserção no meio ou no final
    else {
        new_node->next = current;
        new_node->previous = previous;
        previous->next = new_node;
        if(current !=NULL) current->previous=new_node;
    }
}

void insert_end(Node **head, Student s) {
    if(head == NULL) return;
    //aloca
    Node *l = (Node*) malloc(sizeof(Node));
    if(l == NULL ) return;
    //atribui val e head no proximo
    l->data=s;
    // next eh o fim
    l->next = NULL;

    if(*head == NULL) {
        l->previous = NULL;
        *head = l;
        return;
    }

    Node *current = *head;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = l;
    l->previous = current;
    
}

void print_list(Node *head) {
    Node *current = head;
    while(current !=NULL) {
        printf("Name: %s\n", current->data.name);
        printf("ID: %ld\n", current->data.id);
        printf("N1: %.2f, N2: %.2f, N3: %.2f\n", current->data.n1, current->data.n2, current->data.n3);
        printf("|\n");
        printf("V\n");
        current = current->next;
    }
    printf("NULL\n");
}
void remove_node(Node **head, Student s) {
    Node *current = *head;
    Node *previous = NULL;

    // Se a lista estiver vazia
    if (current == NULL) return;

    // Se o elemento a remover for o primeiro nó (compara pelo id)
    if (current->data.id == s.id) {
        *head = current->next;
        free(current);
        return;
    }

    // Busca o nó pelo id
    while (current != NULL && current->data.id != s.id) {
        previous = current;
        current = current->next;
    }

    // Se não for encontrado
    if (current == NULL) return;

    // Desconecta o nó da lista e libera memória
    previous->next = current->next;
    free(current);
}

void free_list(Node **head) {
   if (head == NULL || *head == NULL) return;

    Node *current = *head;
    Node *next_node = NULL;

    while (current != NULL) {
        next_node = current->next;
        
        // If your Node structure allocated memory for strings or dynamic data, 
        // free them here first (e.g., free(current->data);)
        
        free(current);
        current = next_node;
    }

    *head = NULL;
}