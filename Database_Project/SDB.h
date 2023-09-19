#ifndef _SDB_
#define _SDB_

#include "STD.h"

//Prototypes
bool SDB_IsFull();
uint16 SDB_GetUsedSize();
bool SDB_AddEntry();
void SDB_DeleteEntry(uint32);
bool SDB_ReadEntry(uint32);
void SDB_GetList(uint8*,uint32*);
bool SDB_IsIdExist(uint32);

void SDB_APP();
void SDB_action(uint8);

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
}student;


#endif // _SDB_
