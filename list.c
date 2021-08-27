#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

bool input_option(int *);
void menu();

typedef struct head {
    char name[MAX];
    int phone_number;

    struct head* next;
} head;

typedef struct list {
    head* in_list;
} list;


bool add_number(list *l, const char *name, const int num);
bool input_number(long int *op);


int main(void) {
    int option;

    //create a list
    list l = {.in_list = NULL};

    do {
        menu();
        while (input_option(&option) != true) 
            menu();

        printf("O numero intruduzido foi: %d.\n", option);

        if (option == 1) {
            // add number phone
            char name[MAX];
            long int number;

            printf("type a name: \n");
            scanf("%50[^\n]%*c", name);
            
            printf("type a phone number: \n");
            while (input_number(&number) != true)
                printf("type a phone number: \n");
            
            bool boolean = add_number(&l, name, number);

            if (boolean == false)
                printf("Error to intruduce the number!\n");


        } else if (option == 2) {
            // see all list


        }

        // Do a else: printf("Invalid number\n");

    } while (option != 0);

    return 0;
}


bool input_option(int *op) {
    char aux;
    
    int res = scanf("%d%c", op, &aux);

    if (res < 1 || (res == 2 && aux != '\n') ) {
        scanf("%*[^\n]%*c", op);
        printf("Invalid numbers\n");
        return false;
    }
    return true;
}

bool input_number(long int *op) {
    char aux;
    
    int res = scanf("%ld%c", op, &aux);

    if (res < 1 || (res == 2 && aux != '\n') ) {
        scanf("%*[^\n]%*c", op);
        printf("Invalid numbers\n");
        return false;
    }
    return true;
}

void menu() {
    printf("Insert: 0 - to get out\n"
           "Insert: 1 - to add a phone number\n"
           "Insert: 2 - to check all list\n");
}


static head* creat_head(const char *name, const int num) {
    head *ptr = malloc(sizeof(head));
    if (ptr == NULL)
        return NULL;

    strcpy(ptr->name, name);
    ptr->phone_number = num;
    ptr->next         = NULL;

    return ptr;
}

static bool add_number_rec(head *ptr, const char *name, const int num) {
    if (ptr->next == NULL) {
        ptr->next = creat_head(name, num);
        if (ptr->next == NULL)
            return false;
        else
            return true;
    }

    return add_number_rec(ptr->next, name, num);
}

bool add_number(list *l, const char *name, const int num) {
    if (l->in_list == NULL) {
        l->in_list = creat_head(name, num);
        if (l->in_list == NULL)
            return false;
        else
            return true;
    }

    return add_number_rec(l->in_list, name, num);
}