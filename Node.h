#ifndef ASSIGNMENT_2_KT_NODE_H
#define ASSIGNMENT_2_KT_NODE_H
#define NAME_LENGTH 20
#include <stdlib.h>

/* Student structure */
typedef struct {
    char first_name[NAME_LENGTH];
    char last_name[NAME_LENGTH];
} student_t;

/* Node structure */
typedef struct node {
    student_t *student;     /* pointer to the student's data       */
    struct node *next;      /* pointer to the next node in the list */
} node_t, backup;
/* Function Prototypes */
node_t *add_front(node_t *head, student_t *s);
node_t *add_back(node_t *head, student_t *s);
node_t *delete_front(node_t *head);
node_t *delete_back(node_t *head);
node_t *delete_second(node_t *head);
void print_list(node_t *head);
void free_list(node_t *head);
int countNodes(node_t *head);
int rline(char str[], int n);


#endif