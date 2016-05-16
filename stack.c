/**************************************************************/
/* Program: stack.c                                           */
/* Author: Sami Metoui samimetoui@gmail.com                   */
/* Description: stack collection fuctions                     */
/* License: GPL 3 (http://www.gnu.org/licenses/gpl.html)      */
/**************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "list.h"
#include "stack.h"

int main()
{
    return;
}

/*********************************************/
/* Fuction: push() putsh integer in stack    */
/* Input: node, value to push                */
/*********************************************/

void push(t_node** p, int e)
{
    append(p,e);
}

/**********************************************/
/* Fuction: pop() pop integer from stack      */
/* Input: stack pointer                       */
/* Output: popped value or -1 if error occure */
/**********************************************/

int pop(t_node** p)
{
    int e;
    t_node* ptr;
    ptr=last(*p);
    if(ptr==NULL) printf("Stack is empty!\n");
    else
    {
        e=ptr->value;
        removeNode(p,ptr);
        return e;
    }

    return -1;
}


