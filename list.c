#include "list.h"
#include <stdlib.h>
#include <stdio.h>

int i;
void print(list* L){
    node* now = *L;
    while (now != NULL){
        printf("%d -> ", now->value);
        now = now->next;
    }
    printf("NULL\n");
}

void push(list* L, int element){
node* new_node = (node*) malloc(sizeof(node));
new_node->value = element;
new_node->next = (*L);
(*L) = new_node;
}

void push_before(list* L, int num, int element){
    node *now = *L;
    if (now->value == num) push(L,element);
    else {
        while (now->next->value != num)
            now = now->next;
        node* new_node = (node*)malloc(sizeof(node));
        new_node->value = element;
        new_node->next = now->next;
        now->next = new_node;
    }
}

void push_after(list* L, int num, int element) {
    node *now = *L;
    while (now->value != num)
            now = now->next;
        node* new_node = (node*)malloc(sizeof(node));
        new_node->value = element;
        new_node->next = now->next;
        now->next = new_node;
    }

void push_end(list* L, int element){
    if ((*L) == NULL)
        {
        push(L, element); return;
    }

    node* new_node = (node*) malloc(sizeof(node));
    new_node->value = element;

    node* now = *L;
    while (now->next != NULL){
        now = now->next;
    }

    new_node->next = now->next;
    now->next = new_node;
}

int pop(list* L){
    int result = (*L)->value;
    node* second = (*L)->next;
    free(*L);
    *L = second;
    return result;
}

int pop_end(list* L){
    if ((*L)->next == NULL)
        return pop(L);

    node* now = *L;
    while (now->next->next != NULL){
        now = now->next;
    }
    int result = now->next->value;
    node* to_free = now->next;
    now->next = now->next->next;
    free(to_free);
    return result;
}

int pop_num(list* L, int num){
    node *now = *L;
    if (now->value == num)
        return pop(L);
    else {
        while (now->next->value != num)
            now = now->next;
        int results = now->next->value;
        node *t = now->next;
        now->next = now->next->next;
        free(t);
        return results;
    }
}

void menu(){
    const char* menu = "1: push \n"
                       "2: print\n"
                       "3: push_before\n"
                       "4: push_after\n"
                       "5: push_end\n"
                       "6: pop\n"
                       "7: pop_end\n"
                       "8: pop_num\n"
                       "9: individual\n"
                       ;
    printf("%s\n", menu);
}

void individual(list* L, int input, int find_value){
    node* now = *L;
    while (now != NULL){
        if (now->value == find_value){
            node* new_node = (node*) malloc(sizeof(node));
            new_node->value = input;
            new_node->next = now->next;
            now->next = new_node;
            now = now->next->next;
        } else {
            now = now->next;
        }
    }
}
