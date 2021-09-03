#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct head {
    char name[MAX];
    int phone_number;

    struct head* next;
} head;

typedef struct list {
    head* in_list;
} list;


bool input_option(int *);
bool input_number(long int *);
bool add_number(list *, const char *, const int );

void menu();
void free_memory(list *);


#endif