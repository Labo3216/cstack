/*********************************************************/
/* File: node.h                                          */
/* Author: Sami Metoui samimetoui@gmail.com              */
/* Description: node structure                           */
/* License: GPL 3 (http://www.gnu.org/licenses/gpl.html) */
/*********************************************************/

#ifndef NOEUD_H_INCLUDED
#define NOEUD_H_INCLUDED

struct s_node {
    int value;
    struct s_node* prev;
    struct s_node* next;
};

typedef struct s_node t_node;

#endif // NOEUD_H_INCLUDED