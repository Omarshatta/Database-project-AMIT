#include <stdio.h>
#include "SDB.h"


/*
 * SDB_action
 *
 * Receives the user's choice and calls the corresponding
 * database function.
 *
 * This separates the user interface from the database
 * implementation and follows the modular programming concept.
 */
void SDB_action(uint8 choice)
{
    uint32 id;
    uint8 count;
    uint8 i;

    /*
     * Array used to store the list of student IDs.
     * Maximum size is MAX_STUDENTS.
     */
    uint32 list[MAX_STUDENTS];


    switch (choice)
    {
        case 1:

            /*
             * Add a new student.
             */
            SDB_AddEntry();

            break;


        case 2:

            /*
             * Get the number of students currently
             * stored in the database.
             */
            printf("\nNumber of students in database: %u\n",
                   SDB_GetUsedSize());

            break;


        case 3:

            /*
             * Ask for an ID and display its information.
             */
            printf("\nEnter Student ID: ");
            scanf("%u", &id);

            SDB_ReadEntry(id);

            break;


        case 4:

            /*
             * Get all student IDs and print them.
             */
            SDB_GetList(&count, list);

            printf("\n========== Student IDs ==========\n");

            if (count == 0)
            {
                printf("Database is empty.\n");
            }
            else
            {
                for (i = 0; i < count; i++)
                {
                    printf("Student %u: %u\n", i + 1, list[i]);
                }
            }

            printf("=================================\n");

            break;


        case 5:

            /*
             * Check whether a specific ID exists.
             */
            printf("\nEnter Student ID: ");
            scanf("%u", &id);

            if (SDB_IsIdExist(id))
            {
                printf("Student ID %u exists in the database.\n", id);
            }
            else
            {
                printf("Student ID %u does NOT exist.\n", id);
            }

            break;


        case 6:

            /*
             * Delete a student using his ID.
             */
            printf("\nEnter Student ID to delete: ");
            scanf("%u", &id);

            SDB_DeletEntry(id);

            break;


        case 7:

            /*
             * Check whether the database is full.
             */
            if (SDB_IsFull())
            {
                printf("\nDatabase is FULL.\n");
            }
            else
            {
                printf("\nDatabase is NOT full.\n");
                printf("Current students: %u/%d\n",
                       SDB_GetUsedSize(), MAX_STUDENTS);
            }

            break;


        default:

            printf("\nInvalid choice! Please choose from 0 to 7.\n");

            break;
    }
}


/*
 * SDB_APP
 *
 * Main application function.
 *
 * It continuously displays the menu and waits for
 * the user to choose an operation.
 *
 * The loop continues until the user enters 0.
 */
void SDB_APP(void)
{
    uint8 choice;

    do
    {
        printf("\n\n====================================\n");
        printf("       STUDENT DATABASE SYSTEM\n");
        printf("====================================\n");

        printf("1. Add entry\n");
        printf("2. Get used size in database\n");
        printf("3. Read student data\n");
        printf("4. Get list of all student IDs\n");
        printf("5. Check if ID exists\n");
        printf("6. Delete student data\n");
        printf("7. Check if database is full\n");
        printf("0. Exit\n");

        printf("====================================\n");
        printf("Enter your choice: ");

        scanf("%hhu", &choice);

        if (choice != 0)
        {
            SDB_action(choice);
        }

    } while (choice != 0);


    printf("\nThank you for using Student Database System!\n");
}