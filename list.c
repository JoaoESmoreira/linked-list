#include <stdio.h>
#include <stdbool.h>

bool input_option(int *);
void menu();


int main(void) {
    int option;

    do {
        menu();
        while (input_option(&option) != true) 
            menu();

        printf("O numero intruduzido foi: %d.\n", option);

        if (option == 1) {
            // add contactos


        } else if (option == 2) {
            // ver lista


        }

    } while (option != 0);

    return 0;
}


bool input_option(int *op) {
    char aux;
    
    int res = scanf("%d%c", op, &aux);

    if (res < 1 || (res == 2 && aux != '\n') ) {
        scanf("%*[^\n]%*c", op);
        printf("Numeros invalidos\n");
        return false;
    }
    return true;
}

void menu() {
    printf("Intruduza: 0 - para sair\n"
           "Intruduza: 1 - para adicionar um contacto\n"
           "Intruduza: 2 - para consultar a lista\n");
}