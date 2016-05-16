/*********************************************************/
/* ‪File: liste.h                                         */
/* Author: Sami Metoui samimetoui@gmail.com              */
/* Description: list header file                         */
/* License: GPL 3 (http://www.gnu.org/licenses/gpl.html) */
/*********************************************************/

#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#define next(x) x->next
#define previous(x) x->prev

void insert(t_node**, int);
void append(t_node**, int);
//t_node* next(t_node*);
//t_node* previous(t_node*);
void displayList(t_node*);
void displayNode(t_node*);
int removeNode(t_node**, t_node*);
t_node* first(t_node*);
t_node* last(t_node*);
t_node* findNode(t_node*, int);

#endif // LIST_H_INCLUDED