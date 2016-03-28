#include <stdlib.h>

#include "include/list.h"

List makeEmpty(List L) {
    deleteList(L);
    Position header = malloc(sizeof(struct Node));
    header->next = NULL;

    return header;
}

int isEmpty(List L) {
    return L->next == NULL;
}

int isLast(Position P) {
    return P->next == NULL ? 1 : 0;
}

Position find(ElementType X, List L) {
    Position header = L->next;

    while(header != NULL) {
	if (header->value == X) {
	    break;
	}
	header = header->next;
    }
    return header;
}

void delete(ElementType X, List L) {
    Position previous = findPrevious(X, L);
    Position node = previous->next;

    previous->next = node->next;
    free(node);
}

Position findPrevious(ElementType X, List L) {
    Position pre = L, cur = L->next;

    while(cur->value != X && cur != NULL) {
	pre = cur;
	cur = cur->next;
    }
    if (cur == NULL) {
	return NULL;
    } else {
	return pre;
    }
}

void insert(ElementType X, List L, Position P) {
    Position next = P->next;
    Position node = malloc(sizeof(struct Node));
    node->value = X;
    P->next = node;
    node->next = next;
}

void deleteList(List L) {
    while(L != NULL) {
	/* in order to avoid memory leaking, `delteList` use O(N) time to free memory */
	Position next = L->next;
	free(L);
	L = next;
    }
}

Position header(List L) {
    return L;
}

Position first(List L) {
    return L->next;
}

Position advance(Position P) {
    return P->next;
}

ElementType retrieve(Position P) {
    return P->value;
}
