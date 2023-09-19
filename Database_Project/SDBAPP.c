#include "SDB.h"

// this function to take from user the required option
void SDB_APP()
{
    uint8 choice;
    do
    {
        printf("=====================================================\n");
        printf("1. To add entry , enter 1 .\n");
        printf("2. To get used size in database , enter 2 .\n");
        printf("3. To read student data , enter 3 .\n");
        printf("4. To get the list of all student IDs , enter 4 .\n");
        printf("5. To check is Id is existed , enter 5 .\n");
        printf("6. To delete student data , enter 6 .\n");
        printf("7. To check is database is full , enter 7 .\n");
        printf("8. To exit , enter 0 .\n");
        printf("=====================================================\n");
        printf("Enter Choice : ");
        scanf("%d",&choice);

        // check if the choice is valid or not
        while(choice>7||choice<0)
        {
            printf("Please ,Enter valid choice!\n");
            printf("Enter Choice : ");
            scanf("%d",&choice);
        }
        printf("=====================================================\n");
        SDB_action(choice);
    }
    while(choice);

}

// // this function to implement the required option that user choosed
void SDB_action(uint8 choice)
{
    // extern the number_of_student from  SDB.c file
    extern uint16 num_of_students;
    uint32 id;
    uint8 count;
    uint32 list[10];

    switch(choice)
    {
    case 1 :
        if(SDB_AddEntry())
            printf("\nData Added Successfully!\n");
        else
            printf("Failed To Add Data!\n");
        printf("=====================================================\n");
        printf("Press any key to continue!\n");
        printf("=====================================================\n");
        getch();
        break;

    case 2 :
        printf("Number of student you added is : %d Student.\n",SDB_GetUsedSize());
        printf("=====================================================\n");
        printf("Press any key to continue!\n");
        printf("=====================================================\n");
        getch();
        break;

    case 3 :
        if(num_of_students==0)
            printf("You have not any students in your database yet!\n");
        else
        {
ReadAgain:
            printf("Enter the ID of the student : ");
            scanf("%d",&id);
            printf("\n");
            if(SDB_ReadEntry(id))
                printf("\nData printed Successfully!\n");
            else
            {
                printf("The ID you enter is not exist.\n");
                goto ReadAgain; // Enter the ID again
            }
        }
        printf("=====================================================\n");
        printf("Press any key to continue!\n");
        printf("=====================================================\n");
        getch();
        break;

    case 4 :
        if(num_of_students==0)
            printf("You have not any students in your database yet!\n");
        else
        {
CountAgain:
            printf("Enter number of student : ");
            scanf("%d",&count);
            // check if the number of student you want to print is more than the actual number in the database or not
            if(count>num_of_students)
            {
                printf("Sorry ,database has only %d student!\n",num_of_students);
                goto CountAgain; // Enter number of student you want to print again
            }
            for(uint32 i=0; i<count; i++)
            {
ListAgain:
                printf("Enter the IDs for student %d : ",i+1);
                scanf("%d",&list[i]);
                if(!SDB_IsIdExist(list[i]))
                {
                    printf("The ID you enter is not exist.\n");
                    goto ListAgain; // Enter student IDs again
                }
            }
            SDB_GetList(count,list);
        }
        printf("=====================================================\n");
        printf("Press any key to continue!\n");
        printf("=====================================================\n");
        getch();
        break;

    case 5 :
        printf("Enter the ID of the student : ");
        scanf("%d",&id);
        // check if the id is exist or nott
        if(SDB_IsIdExist(id))
            printf("The ID you enter is exist.\n");
        else
            printf("The ID you enter is not exist.\n");
        printf("=====================================================\n");
        printf("Press any key to continue!\n");
        printf("=====================================================\n");
        getch();
        break;

    case 6 :
        // check if the number of student is more than 3 or not
        if(num_of_students>3)
        {
DeleteIdAgain:
            printf("Enter the ID of the student : ");
            scanf("%d",&id);
            // check if the id is exist or nott
            if(SDB_IsIdExist(id))
                SDB_DeleteEntry(id);
            else
            {
                printf("The ID you enter is not exist.\n");
                goto DeleteIdAgain; // Enter the Id again
            }
        }
        else
            printf("Sorry ,Minimum database students is Three!\nYour database has %d student now!\n",num_of_students);
        printf("=====================================================\n");
        printf("Press any key to continue!\n");
        printf("=====================================================\n");
        getch();
        break;

    case 7 :
        if(SDB_IsFull())
            printf("The Database is full.\n");
        else
            printf("The Database is not full.\n");
        printf("=====================================================\n");
        printf("Press any key to continue!\n");
        printf("=====================================================\n");
        getch();
        break;

    default :
        printf("Program has finished !\n");
    }
}
