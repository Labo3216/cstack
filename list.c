/**************************************************************/
/* Program: liste.c                                           */
/* Author: Sami Metoui samimetoui@gmail.com                   */
/* Description: list collection fuctions                      */
/* License: GPL 3 (http://www.gnu.org/licenses/gpl.html)      */
/**************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "list.h"


int main()
{
    return;
}

/******************************************************/
/*Function findNode(): Find node in list              */
/*Input: node, integer value to find                  */
/*Output: Found node or NULL                          */
/******************************************************/

t_node* findNode(t_node* p, int n)
{

    while(p != NULL) {
        if(p->value == n) return p;
        p=next(p);
    }

    return NULL;
}

/******************************************************/
/*Function first(): return first node from list       */
/*Input: node                                         */
/*Output: first node from list                        */
/******************************************************/
t_node* first(t_node*p)
{
    if(p == NULL) return NULL;
    while(p->prev != NULL) p=previous(p);
    return p;
}

/******************************************************/
/*Function last(): return last node from list         */
/*Entrée: noeud                                       */
/*Output: last node from liste                        */
/******************************************************/
t_node* last(t_node*p)
{
    if(p == NULL) return NULL;
    while(p->next != NULL) p=next(p);
    return p;
}

/*********************************************/
/*Function next(): retun next node from list */
/*Input: node                                */
/*Output: next node                          */
/*********************************************/
/*inline t_node* next(t_node* p)
{

    if(p != NULL) {
        p = p->next;
    }

    return p;
} obsolete */

/******************************************************/
/*Function previous(): retun previous node from list  */
/*Input: node                                         */
/*Output: previous                                    */
/******************************************************/
/*inline t_node* previous(t_node* p)
{

    if(p != NULL) {
        p = p->prev;
    }

    return p;
} obsolete */

/***********************************************/
/*Function insert(): Insert node to list       */
/*Input: node, integer value to insert         */
/***********************************************/
void insert(t_node** p, int e)
{
    t_node* curr;

    curr = malloc(sizeof(t_node));
    curr->value = e;

    if((*p) == NULL) {
        curr->next=NULL;
        curr->prev=NULL;
    }
    else {
        curr->next = (*p);
        (*p)->prev = curr;
        curr->prev = NULL;
    }

    (*p)=curr;

    return;
}

/*************************************************/
/*Function append(): append node to list         */
/*Input: node, integer value to append           */
/*************************************************/
void append(t_node** p, int e)
{
    t_node* ptr;
    t_node* curr;

    curr = malloc(sizeof(t_node));
    curr->value = e;

    if ((*p)==NULL)
    {
        curr->next=NULL;
        curr->prev=NULL;
        (*p)=curr;
    }
    else
    {
        ptr=last(*p);
        ptr->next=curr;
        curr->next=NULL;
        curr->prev=ptr;
    }

    return;
}

/*************************************************/
/*Function removeNode(): remove node from list   */
/*Input: list, node to remove                    */
/*Output: -1 if error ioccure                    */
/*************************************************/
int removeNode(t_node** p, t_node* r)
{
    t_node* curr=r;

    if((*p) == NULL || r == NULL)
    {
        //printf("List empty\n");
        return -1;
    }
    if(curr->prev == NULL)
    {
        if(curr->next == NULL)
        {
            (*p)=NULL;      //list contain only 1 element
        }
        else
        {
            (curr->next)->prev=NULL;
            curr=next(curr);
            *p=curr;
        }

    }
    else
    {
        curr=previous(curr);
        if ((curr->next)->next==NULL)
        {
            curr->next=NULL;    //last element from liste
        }
        else
        {
            ((curr->next)->next)->prev=curr;
            curr->next=(curr->next)->next;
        }
    }
    free(r);
    return 0;
}

/**************************************************/
/*Function displayList(): Diplay the list content */
/*Input: list (first node)                        */
/**************************************************/
void displayList(t_node* p)
{

    while(p!=NULL)
    {
        displayNode(p);
        p=next(p);
    }
    printf("\n");
    return;
}

/*******************************************/
/*Function displayNode(): Display node     */
/*Input: node to display                   */
/*******************************************/
void displayNode(t_node* p)
{
    //printf("(%x) ",(unsigned int)p->prev);
    printf("%d ",p->value);
    //printf("(%x) - ",(unsigned int)p->next);
}
