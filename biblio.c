#include "biblio.h"


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

static void free_memory_rec(head *ptr) {
    if(ptr != NULL) {
        head *aux = ptr->next;
        free(ptr);
        
        return free_memory_rec(aux);
    }
    return;
}

void free_memory(list *l) {
    if (l->in_list != NULL) {

    head *aux = l->in_list;
    l->in_list = NULL;
    
    return free_memory_rec(aux);
    }
    return;
}

void print_all_list(list *l) {
    for (head *ptr = l->in_list; ptr->next != NULL; ptr = ptr->next) 
        printf("%20s : %10ld", ptr->name, ptr->phone_number);

}