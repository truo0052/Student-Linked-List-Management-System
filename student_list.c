
#include <stdio.h>
#include <string.h>
#include "Node.h"
#include <time.h>

void delay(int seconds);

int main(void) {
    node_t *head = NULL;
    student_t *student;
    char first[NAME_LENGTH], last[NAME_LENGTH];
    int i;

    printf("Linked List of Students\n");

    /* Add 3 students to the beginning */
    for (i = 1; i <= 3; i++) {
        printf("Enter first name for student %d: ", i);
        rline(first, NAME_LENGTH);
        printf("Enter last name for student %d: ", i);
        rline(last, NAME_LENGTH);

        student = (student_t *)malloc(sizeof(student_t));
        strncpy(student->first_name, first, NAME_LENGTH - 1);
        student->first_name[NAME_LENGTH - 1] = '\0';
        strncpy(student->last_name, last, NAME_LENGTH - 1);
        student->last_name[NAME_LENGTH - 1] = '\0';

        head = add_front(head, student);
    }

    delay(3);

    /* Add 3 students to the end */
    printf("\n");
    for (i = 1; i <= 3; i++) {
        printf("Enter first name for student %d: ", i);
        rline(first, NAME_LENGTH);
        printf("Enter last name for student %d: ", i);
        rline(last, NAME_LENGTH);

        student = (student_t *)malloc(sizeof(student_t));
        strncpy(student->first_name, first, NAME_LENGTH - 1);
        student->first_name[NAME_LENGTH - 1] = '\0';
        strncpy(student->last_name, last, NAME_LENGTH - 1);
        student->last_name[NAME_LENGTH - 1] = '\0';

        head = add_back(head, student);
    }

    /* Print current list */
    printf("\nCurrent list of students:\n");

    print_list(head);

    /* Delete first 3 students */
    for (i = 0; i < 3; i++) {
        head = delete_front(head);
    }
    printf("\nAfter deleting the first 3 students:\n");
    print_list(head);
    printf("\nAfter deleting the last 3 students:\n");
    print_list(head);
    printf("\nFinal list of students:\n");
    /* Delete the second student */
    head = delete_second(head);
    printf("\nAfter deleting the second student:\n");
    print_list(head);
    /* Delete last 3 students */
    for (i = 0; i < 3; i++) {
        head = delete_back(head);
    }


    /* Free the list */
    free_list(head);

    return 0;
}

void delay(int seconds) {
    clock_t start_time = clock();
    while (clock() < start_time + seconds * CLOCKS_PER_SEC);
}