#include "biblio.h"


int main(void) {
    int option;

    //create a list
    list l = {.in_list = NULL};

    do {
        menu();
        while (input_option(&option) != true) 
            menu();

        if (option == 0) {
            continue;
        } else if (option == 1) {
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
            print_all_list(&l);

        } else {
            printf("Invalid number\n");
        }

    } while (option != 0);

    free_memory(&l);

    return 0;
}