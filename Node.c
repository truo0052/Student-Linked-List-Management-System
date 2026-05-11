/* Node.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"
#include <ctype.h>


/* Helper function to create a student */
static student_t *create_student(const char *first, const char *last) {
    student_t *student = (student_t *)malloc(sizeof(student_t));
    if (student == NULL) {
        printf("Failed to allocate memory for student\n");
        return NULL;
    }

    strncpy(student->first_name, first, NAME_LENGTH - 1);
    student->first_name[NAME_LENGTH - 1] = '\0';
    strncpy(student->last_name, last, NAME_LENGTH - 1);
    student->last_name[NAME_LENGTH - 1] = '\0';

    return student;
}

/* Helper function to create a node */
static node_t *create_node(student_t *student) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    if (node == NULL) {
        printf("Failed to allocate memory for node\n");
        return NULL;
    }
    node->student = student;
    node->next = NULL;
    return node;
}

/* Add node to the front of the list */
node_t *add_front(node_t *head, student_t *s) {
    node_t *n = create_node(s);
    if (n == NULL) {
        return head;
    }

    n->next = head;
    return n;
}

/* Add node to the back of the list */
node_t *add_back(node_t *head, student_t *s) {
    node_t *n = create_node(s);
    node_t *curr;

    if (n == NULL) {
        return head;
    }

    if (head == NULL) {
        return n;
    }

    curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = n;
    return head;
}

/* Delete node from the front of the list */
node_t *delete_front(node_t *head) {
    node_t *tmp;

    if (head == NULL) {
        return NULL;
    }

    tmp = head->next;
    free(head->student);
    free(head);
    return tmp;
}

/* Delete node from the back of the list */
node_t *delete_back(node_t *head) {
    node_t *curr;
    node_t *prev;

    if (head == NULL) {
        return NULL;
    }

    /* If only one node in the list */
    if (head->next == NULL) {
        free(head->student);
        free(head);
        return NULL;
    }

    /* Traverse to the last node */
    curr = head;
    prev = NULL;
    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }

    /* Delete the last node */
    free(curr->student);
    free(curr);
    prev->next = NULL;

    return head;
}

/* Delete the second node from the list */
node_t *delete_second(node_t *head) {
    node_t *tmp;

    if (head == NULL || head->next == NULL) {
        /* List is empty or has only one node */
        return head;
    }

    tmp = head->next;           /* second node */
    head->next = tmp->next;     /* first node points to third node */
    free(tmp->student);
    free(tmp);

    return head;
}

/* Print all nodes in the list */
void print_list(node_t *head) {
    node_t *curr = head;

    while (curr != NULL) {
        printf("Student: %s %s\n",
               curr->student->first_name,
               curr->student->last_name);
        curr = curr->next;
    }
}

/* Free all nodes in the list */
void free_list(node_t *head) {
    node_t *tmp;
    while (head != NULL) {
        tmp = head->next;
        free(head->student);
        free(head);
        head = tmp;
    }
}

/* Count number of nodes in the list */
int countNodes(node_t *head) {
    int count = 0;
    node_t *current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int rline(char str[], int n) {
    int ch, i = 0;

    while (isspace(ch = getchar())) {}
    while (ch != '\n' && ch != EOF) {
        if (i < n) {
            str[i++] = ch;
        }
        ch = getchar();
    }
    str[i] = '\0';
    return i;
}