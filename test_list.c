/* test routine for <list.h> */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "include/list.h"

void printfList(List L) {
    Position header = L->next;

    while (header != NULL) {
    	printf("%d\t", header->value);
    	header = header->next;
    }
    putchar('\n');
    
}

int main() {
    List L = malloc(sizeof(struct Node));
    L->next = NULL;

    if (isEmpty(L))
    	puts("Empty\n");
    else
    	puts("Not empty\n");
   
    insert(3, L, L);
    Position last = L->next;
    /* test inserting */
    insert(5, L, last);
    last = last -> next;
    insert(2, L, last);
    last = last -> next;
    
    printfList(L);

    /* test isEmpty again */
    if (isEmpty(L))
    	puts("Empty\n");
    else
    	puts("Not empty\n");

    if (isLast(last))
    	printf("Last is %d\n", last->value);

    /* test finding */
    Position p = find(5, L);
    printf("Found place's value %d\n", p->value);
    
    /* test deleting */
    delete(5, L);
    printfList(L);

    insert(9, L, last);
    last = last->next;

    p = findPrevious(9, L);
    printf("Previous Position's value %d\n", p->value);

    /* test getting header */
    p = header(L);
    assert(p == L);

    /* test getting first */
    p = first(L);
    printf("First node value: %d\n", p->value);

    /* test advancing method */
    p = advance(p);
    printf("First node adancing, now %d\n", p->value);

    /* test retrieving */
    printf("Last value retieved: %d\n", retrieve(last));

    /* test deleteList */
    deleteList(L);
    if (L == NULL)
    	printf("Delete List Done\n");

    return 0;
}
