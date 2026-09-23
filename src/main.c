#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "double_ll.h"

int main() {
    Node *l = NULL; // lista vazia

    Student s1,s2,s3;
    strcpy(s1.name, "Teste1");
    s1.id = 1;
    s1.n1 = 6.0f;
    s1.n2= 7.0f;
    s1.n3 = 5.0f;

    strcpy(s2.name, "Teste2");
    s2.id = 12;
    s2.n1 = 6.0f;
    s2.n2= 7.0f;
    s2.n3 = 5.0f;

    strcpy(s3.name, "Teste3");
    s3.id = 23;
    s3.n1 = 6.0f;
    s3.n2= 7.0f;
    s3.n3 = 5.0f;

    insert_begining(&l,s1);
    insert_begining(&l,s2);
    insert_begining(&l,s3);

    printf("[INICIO] Lista atual: ");
    print_list(l);

    remove_node(&l,s1);
    printf("Apos remover s1: ");
    print_list(l);

    free_list(&l);

    Node *l2 = NULL; // lista vazia

    insert_end(&l2,s1);
    insert_end(&l2,s2);
    insert_end(&l2,s3);

    printf("\n[FIM] Lista atual: ");
    print_list(l2);

    remove_node(&l2,s1);
    printf("Apos remover s1: \n");
    print_list(l2);

    free_list(&l2);

    Node *l3 = NULL; 
    insert_in_order(&l3,s1);
    insert_in_order(&l3,s2);
    insert_in_order(&l3,s3);

    printf("\n[ORDEM] Lista atual: ");
    print_list(l3);

    remove_node(&l3,s1);
    printf("Apos remover s1: \n");
    print_list(l3);

    free_list(&l3);
    return 0;
}