#include <stdio.h>
#include "SDB.h"

/*
 * Global database array.
 * It can store a maximum of MAX_STUDENTS students.
 */
static student database[MAX_STUDENTS];

/*
 * Keeps track of the number of students currently stored.
 */
static uint8 studentCount = 0;


/*
 * SDB_IsFull
 *
 * Checks whether the database has reached its maximum capacity.
 *
 * Return:
 *      true  -> database is full
 *      false -> database still has free space
 */
bool SDB_IsFull(void)
{
    if (studentCount >= MAX_STUDENTS)
    {
        return true;
    }

    return false;
}


/*
 * SDB_GetUsedSize
 *
 * Returns the current number of students stored
 * in the database.
 */
uint8 SDB_GetUsedSize(void)
{
    return studentCount;
}


/*
 * SDB_IsIdExist
 *
 * Searches the database for a student ID.
 *
 * Return:
 *      true  -> ID exists
 *      false -> ID does not exist
 */
bool SDB_IsIdExist(uint32 id)
{
    uint8 i;

    for (i = 0; i < studentCount; i++)
    {
        if (database[i].Student_ID == id)
        {
            return true;
        }
    }

    return false;
}


/*
 * SDB_AddEntry
 *
 * Adds a new student to the database.
 *
 * First, the function checks whether the database is full.
 * Then it asks the user to enter all required student data.
 *
 * The student ID must be unique because two students
 * cannot have the same ID.
 *
 * Return:
 *      true  -> student added successfully
 *      false -> student was not added
 */
bool SDB_AddEntry(void)
{
    student newStudent;

    if (SDB_IsFull())
    {
        printf("\nDatabase is FULL!\n");
        return false;
    }

    printf("\n========== Add Student ==========\n");

    printf("Enter Student ID: ");
    scanf("%u", &newStudent.Student_ID);

    /* Check that the ID is not already used */
    if (SDB_IsIdExist(newStudent.Student_ID))
    {
        printf("Error: This Student ID already exists!\n");
        return false;
    }

    printf("Enter Student Year: ");
    scanf("%u", &newStudent.Student_year);

    printf("Enter Course 1 ID: ");
    scanf("%u", &newStudent.Course1_ID);

    printf("Enter Course 1 Grade: ");
    scanf("%u", &newStudent.Course1_grade);

    printf("Enter Course 2 ID: ");
    scanf("%u", &newStudent.Course2_ID);

    printf("Enter Course 2 Grade: ");
    scanf("%u", &newStudent.Course2_grade);

    printf("Enter Course 3 ID: ");
    scanf("%u", &newStudent.Course3_ID);

    printf("Enter Course 3 Grade: ");
    scanf("%u", &newStudent.Course3_grade);

    /*
     * Store the new student at the next available position.
     */
    database[studentCount] = newStudent;

    studentCount++;

    printf("\nStudent added successfully!\n");

    return true;
}


/*
 * SDB_DeletEntry
 *
 * Deletes a student using the given ID.
 *
 * After finding the student, all elements after it
 * are shifted one position to the left so that there
 * are no gaps in the database.
 */
void SDB_DeletEntry(uint32 id)
{
    uint8 i;
    uint8 found = 0;

    for (i = 0; i < studentCount; i++)
    {
        if (database[i].Student_ID == id)
        {
            found = 1;

            /*
             * Shift all students after the deleted
             * student one position to the left.
             */
            for (; i < studentCount - 1; i++)
            {
                database[i] = database[i + 1];
            }

            studentCount--;

            printf("\nStudent with ID %u deleted successfully.\n", id);
            break;
        }
    }

    if (!found)
    {
        printf("\nStudent ID %u was not found.\n", id);
    }
}


/*
 * SDB_ReadEntry
 *
 * Searches for a student using the given ID.
 * If found, all student information is printed.
 *
 * Return:
 *      true  -> student exists
 *      false -> student does not exist
 */
bool SDB_ReadEntry(uint32 id)
{
    uint8 i;

    for (i = 0; i < studentCount; i++)
    {
        if (database[i].Student_ID == id)
        {
            printf("\n========== Student Data ==========\n");

            printf("Student ID      : %u\n", database[i].Student_ID);
            printf("Student Year    : %u\n", database[i].Student_year);

            printf("Course 1 ID     : %u\n", database[i].Course1_ID);
            printf("Course 1 Grade  : %u\n", database[i].Course1_grade);

            printf("Course 2 ID     : %u\n", database[i].Course2_ID);
            printf("Course 2 Grade  : %u\n", database[i].Course2_grade);

            printf("Course 3 ID     : %u\n", database[i].Course3_ID);
            printf("Course 3 Grade  : %u\n", database[i].Course3_grade);

            printf("==================================\n");

            return true;
        }
    }

    printf("\nStudent ID %u was not found.\n", id);

    return false;
}


/*
 * SDB_GetList
 *
 * Stores all student IDs inside the array provided
 * by the caller.
 *
 * count -> receives the number of IDs
 * list  -> receives all student IDs
 */
void SDB_GetList(uint8 *count, uint32 *list)
{
    uint8 i;

    if (count == NULL || list == NULL)
    {
        return;
    }

    *count = studentCount;

    for (i = 0; i < studentCount; i++)
    {
        list[i] = database[i].Student_ID;
    }
}