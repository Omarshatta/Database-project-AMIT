#ifndef SDB_H
#define SDB_H

#include "STD.h"

#define MAX_STUDENTS 10
#define MIN_STUDENTS 3

typedef struct SimpleDb
{
    uint32 Student_ID;
    uint32 Student_year;

    uint32 Course1_ID;
    uint32 Course1_grade;

    uint32 Course2_ID;
    uint32 Course2_grade;

    uint32 Course3_ID;
    uint32 Course3_grade;

} student;


/* Check whether the database is full */
bool SDB_IsFull(void);

/* Get the number of students currently stored */
uint8 SDB_GetUsedSize(void);

/* Add a new student to the database */
bool SDB_AddEntry(void);

/* Delete a student using his ID */
void SDB_DeletEntry(uint32 id);

/* Read and print student information using ID */
bool SDB_ReadEntry(uint32 id);

/* Get all student IDs */
void SDB_GetList(uint8 *count, uint32 *list);

/* Check whether an ID exists */
bool SDB_IsIdExist(uint32 id);

#endif