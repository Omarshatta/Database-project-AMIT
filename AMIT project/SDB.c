#include <stdio.h>
#include "SDB.h"


static student database[MAX_STUDENTS];


static uint8 studentCount = 0;



bool SDB_IsFull(void)
{
    if (studentCount >= MAX_STUDENTS)
    {
        return true;
    }

    return false;
}


uint8 SDB_GetUsedSize(void)
{
    return studentCount;
}



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

    
    database[studentCount] = newStudent;

    studentCount++;

    printf("\nStudent added successfully!\n");

    return true;
}



void SDB_DeletEntry(uint32 id)
{
    uint8 i;
    uint8 found = 0;

    for (i = 0; i < studentCount; i++)
    {
        if (database[i].Student_ID == id)
        {
            found = 1;

            
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