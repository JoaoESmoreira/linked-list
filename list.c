#include <stdio.h>
#include <stdbool.h>

#define MAX 50

bool input_option(int *);
void menu();


typedef struct no {
    char name[MAX];
    int phone_number;

    struct no* next;
    struct no* prev;
} no;

typedef struct list {
    no in_list;
} list;


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


        } else if (option == 2) {
            // see all lista


        }

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

void menu() {
    printf("Insert: 0 - to get out\n"
           "Insert: 1 - to add a number phone\n"
           "Insert: 2 - to check all list\n");
}