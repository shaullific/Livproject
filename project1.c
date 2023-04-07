#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LISTNO 1//Defines only one structure of livList structure
#define ITEMNO 200//Defines a maximum of 200 structures of livItem structure
void greetings();//Function for greeting the user

struct livItem//Defines the livItem structure which stores the list items
{
    char str[100];//Stores the list item as a string
};
struct livList //Defines the livList structure which stores the title of the list
{
    char title[30]; //Stores the title of the list as a string
};

int main()
{
    int choice;//Used to store the value of choice of operation to execute
    int pos; //Used to store the position of the item to add to the list
    int erase; //Used to store the position of the item to remove from the list
    int size = 0; //Used to store the value of the number of lists created
    int itemNo = 0; //Used to store the value of the number of items in the list
    int currPos = 0; //Used to store the value of the current position in the list
    int endLoop = 1;//Used to execute a loop
    struct livList list[LISTNO] = {0};//Initializes the livList structure to zero
    struct livItem item[ITEMNO] = {0};//Initializes all the livItem structures to zero
    system("cls");//Clears the screen
    printf("###################################TO DO LIST PROGRAM###################################\n");
    greetings();//Greets the user
    printf("**************************Welcome to my To Do List Program******************************\n");
    printf("Create your desired To Do List\n");//Creates a list with a title and adds items entered by the user into the list
    printf("Please enter the title of your List:");
    fgets(list[size].title, sizeof(list[size].title), stdin);
    list[size].title[strcspn(list[size].title, "\n")] = 0; //Removes the newline character at the end of the string
    fflush(stdin); //Flushes the input buffer
    printf("The name of your list is: %s\n", list[size].title);
    printf("Please enter the number of tasks you wish to add to your To Do List: ");
    scanf("%d", &itemNo);
    getchar();

    //Loop to get items from user and add to the list
    for (int b = 0; b < itemNo; b++)
    {
        printf("%d. ", b+1);
        printf("Enter task: ");
        fgets(item[b].str, sizeof(item[b].str), stdin);
        item[b].str[strcspn(item[b].str, "\n")] = 0; //Removes the newline character at the end of the string
        fflush(stdin);
    }
    printf("Your list has been created successfully!\n\n"); //Affirms the user that user's list has been created successfully
    printf("The following are operations one can perform on this program:\n"); //Informs the user about the operations that can be executed by the code
    printf("#1. Clear the list\n"); //Deletes all the contents of the list created by the user
    printf("#2. Display the items in the list\n"); //Displays all the items in the list together with its title
    printf("#3. Add an extra item into your list\n"); //Adds an extra item at the end of the list
    printf("#4. Add an extra item in a particular position in your list\n"); //Adds an extra item to the list at a particular position of interest
    printf("#5. Remove an item from your list\n"); //Removes an item from the list from a particular position of interest
    printf("#0. Exit the program\n"); //Ends the loop of the program and terminates the program

    do
    {
        printf("Please enter a choice you wish to execute(Between 0 and 5): ");
        scanf("%d", &choice);//Accepts input from user and stores it in int choice
        getchar();

        switch (choice)
        {
            //Used to end the loop
            case 0:
            endLoop = 0;
            printf("I appreciate you taking your time to use my program\n");
            printf("Have a wonderful day\n");
            printf("######################################PROGRAM TERMINATED######################################\n");
            break;

            //Erases all the tasks in the To Do List
            case 1:
            itemNo = 0;
            printf("Your list has been cleared successfully.\n");
            break;

            //Displays all the tasks present in the To Do List
            case 2:
            if (itemNo == 0) 
            {
                printf("You currently do not have any tasks in your list.\n");
                break;
            }
            printf("Title: %s\n", list[size].title);
            printf("-----------------------------\n");
            for (int d = 0; d < itemNo; d++)
            {
                printf("%d. %s\n", d+1, item[d].str);
            }
            break;

            //Adds an extra item at the end of the list
            case 3:
            itemNo++;
            printf("%d. ", itemNo);
            printf("Enter task: ");
            fgets(item[itemNo-1].str, sizeof(item[itemNo-1].str), stdin);
            item[itemNo-1].str[strcspn(item[itemNo-1].str, "\n")] = 0;
            printf("Your new task has been successfully added to your To Do List.\n");
            break;

            //Adds an extra item to the list at a particular position of interest
            case 4:
            if (itemNo == -1)
            {
                printf("Your task will be placed in the first position since there are no tasks in your list.\n");
                printf("Enter task: ");
                fgets(item[0].str, sizeof(item[0].str), stdin);
                item[0].str[strcspn(item[0].str, "\n")] = 0;
                break;
            }
            printf("Please enter the position which you wish to insert a new task : ");
            scanf("%d", &pos);
            pos = pos-1;
            getchar(); //Flushes the input buffer
            if(pos > itemNo || pos < 1)
            {
                printf("You cannot enter a task into a position that is not within the number of tasks in your list!\n");
                printf("Please retry the operation\n");
                break;
            }
            itemNo++;
            for (int h = itemNo-1; h > pos; h--)
            {
                strcpy(item[h].str, item[h-1].str);
            }
            printf("%d. ", pos+1);
            printf("Enter task: ");
            fgets(item[pos].str, sizeof(item[pos].str), stdin);
            item[pos].str[strcspn(item[pos].str, "\n")] = 0;
            printf("Your new task has been placed at your position of interest.\n");
            break;

            //Removes an item from the list from a particular position of interest
            case 5:
            if(itemNo == 0)
            {
                printf("Your list is currently empty! Please add a task to your list.\n");
            }
            printf("Enter the position of the item you would wish to remove: ");
            scanf("%d", &erase);
            erase = erase-1;
            getchar(); //Flushes the input buffer
            if(erase > itemNo || erase < 1)
            {
                printf("You cannot remove a task from a position that is not within the number of tasks in your list!\n");
                printf("Please retry the operation\n");
                break;
            }
            for (int k = erase; k < itemNo; k++)
            {
                strcpy(item[k].str, item[k+1].str);
            }
            itemNo--;
            printf("The item in position %d has been removed from the list successfully\n", erase+1);
            break;
        
            //Used to check whether the user has entered an invalid input
            default:
            printf("Please enter a valid input(Between 0 and 5)!\n");
        }
    } while (endLoop == 1);
    return 0;//Signifies the end of the program
}
//Function declaration for greeting the user
void greetings()
{
    printf("Hello user!\n");
}