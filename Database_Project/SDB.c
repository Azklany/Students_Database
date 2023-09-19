#include "SDB.h"

uint16 num_of_students=0;
uint8 Isfull=0;
uint32 index;
student std[10];

// This function check if the database is full or not
bool SDB_IsFull()
{
    return (num_of_students==10)? true:false; // return true if the database is full and false if it not full
}

uint16 SDB_GetUsedSize()
{
    return  num_of_students; //return the number of student added in database
}

// This function to add the data of students
bool SDB_AddEntry()
{
    // first check if database is full or not
    if(!SDB_IsFull())
    {
StudentIdAgain:
        //Student ID
        printf("Enter Student ID    : ");
        scanf("%d",&std[num_of_students].Student_ID);
        if((int)std[num_of_students].Student_ID  < 0)
        {
            printf("Student ID you entered not valid!\n");
            return 0;
        }

        // check if is is exist or not
        if(SDB_IsIdExist(std[num_of_students].Student_ID))
        {
            printf("ID is already existed!\n");
            goto StudentIdAgain; // Enter the ID again
        }

        //Student Year
        printf("Enter Student Year  : ");
        scanf("%d",&std[num_of_students].Student_year);
        if((int)std[num_of_students].Student_year<0)
        {
            printf("Student Year you entered not valid!\n");
            return 0;
        }

        //Course1 ID
        printf("Enter Course1 ID    : ");
        scanf("%d",&std[num_of_students].Course1_ID);
        // check if the course1 id is valid or not
        if((int)std[num_of_students].Course1_ID<0)
        {
            printf("Course1 ID you entered not valid!\n");
            return 0;
        }

        //Course1 Grade
        printf("Enter Course1 Grade : ");
        scanf("%d",&std[num_of_students].Course1_grade);
        // check if the course1 grade is valid or not
        if((int)std[num_of_students].Course1_grade<0 || (int)std[num_of_students].Course1_grade>100)
        {
            printf("Course1 Grade you entered not valid!\n");
            return 0;
        }

        //Course2 ID
        printf("Enter Course2 ID    : ");
        scanf("%d",&std[num_of_students].Course2_ID);
        // check if the course2 id is valid or not
        if((int)std[num_of_students].Course2_ID<0)
        {
            printf("Course2 ID you entered not valid!\n");
            return 0;
        }

        //Course2 Grade
        printf("Enter Course2 Grade : ");
        scanf("%d",&std[num_of_students].Course2_grade);
        // check if the course2 grade is valid or not
        if((int)std[num_of_students].Course2_grade<0 || (int)std[num_of_students].Course2_grade>100)
        {
            printf("Course2 Grade you entered not valid!\n");
            return 0;
        }

        //Course3 ID
        printf("Enter Course3 ID    : ");
        scanf("%d",&std[num_of_students].Course3_ID);
        // check if the course3 id is valid or not
        if((int)std[num_of_students].Course3_ID<0)
        {
            printf("Course3 ID you entered not valid!\n");
            return 0;
        }

        //Course3 Grade
        printf("Enter Course3 Grade : ");
        scanf("%d",&std[num_of_students].Course3_grade);
        // check if the course3 grade is valid or not
        if((int)std[num_of_students].Course3_grade<0 || (int)std[num_of_students].Course3_grade>100)
        {
            printf("Course3 Grade you entered not valid!\n");
            return 0;
        }

        num_of_students++;
        return 1; /*Data Added Successfully*/
    }
    else
    {
        printf("Database is full!\n");
        return 0; /*Failed To Add Data*/
    }

}

// This function to delete the data of student
void SDB_DeleteEntry(uint32 id)
{
    num_of_students--;
    // move the DeletedEntry to the last index
    for(uint32 i=0; i<num_of_students; i++)
    {
        std[index]=std[index+1];
        index++;
    }
    printf("Data deleted successful!\n");
}

// This function to print the data of one student by ID
bool SDB_ReadEntry(uint32 id)
{
    // first check if id is exist or not
    if(SDB_IsIdExist(id))
    {
        printf("Student ID     : %d\n",std[index].Student_ID);
        printf("Student Year   : %d\n",std[index].Student_year);
        printf("Course_1 ID    : %d\n",std[index].Course1_ID);
        printf("Course_1 Grade : %d\n",std[index].Course1_grade);
        printf("Course_2 ID    : %d\n",std[index].Course2_ID);
        printf("Course_2 Grade : %d\n",std[index].Course2_grade);
        printf("Course_3 ID    : %d\n",std[index].Course3_ID);
        printf("Course_3 Grade : %d\n",std[index].Course3_grade);
        return 1; //Data printed Successfully!
    }
    else
        return 0; //The ID you enter is not exist
}

// This function to print the data of numbers of students by ID
void SDB_GetList(uint8* count,uint32* list)
{
    for(uint32 i=0; i<count; i++)
    {
        printf("*************************\n");
        printf("Student %d :\n\n",i+1);
        // send the student IDs to (SDB_ReadEntry_Function)
        SDB_ReadEntry(list[i]);
        printf("*************************\n");
    }
}

// This function to check if ID is exist or not
bool SDB_IsIdExist(uint32 id)
{
    uint8 flag=0;
    for(uint32 i=0; i<num_of_students; i++)
    {
        if(std[i].Student_ID==id)
        {
            flag=1;
            index=i;
        }
    }
    if(flag)
        return 1; // ID is exist
    else
        return 0; //// ID is not exist
}

