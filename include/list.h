/* List Header file */

typedef int ElementType;	/* default type is `int` */

#ifndef _LIST_H_
#define _LIST_H_

typedef struct Node {
    ElementType value;
    struct Node *next;
} *List, *Position;

List makeEmpty(List L);
int isEmpty(List L);
int isLast(Position p);
/* find value X */
Position find(ElementType X, List L);
/* delete node with value X */
void delete(ElementType X, List L);
/* find previous position of value X */
Position findPrevious(ElementType X, List L);
/* insert a value into list, right after the position */
void insert(ElementType X, List L, Position p);
/* delete the whole list */
void deleteList(List L);
/* header of the list (dummy header) */
Position header(List L);
/* first node */
Position first(List L);
/* the node of node P */
Position advance(Position P);
/* get the value of node P */
ElementType retrieve(Position P);

#endif
