#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NODE struct node
struct node
{
    int groupSize;
    char name[20];
    NODE *next;
};
NODE *head = (NODE *) NULL;
NODE *tail = (NODE *) NULL;

int duplicates(char find[])
{
    NODE *p;
    p = head;

    while (p != NULL)
    {
        if (strcmp(p->name, find) == 0)
        {
            return 1;
        }
        p = p->next;
    }
    return 0;
}

void add()
{
    char name[20];
    int size = 0;
    NODE *p;
    if ((p = (NODE *) malloc(sizeof(NODE))) == (NODE *) NULL)
    {
        printf("malloc error\n");
        exit(1);
    }


    if (head != NULL) //not empty
    {

        printf("What is your name\n");
        scanf("%s", name);
        if (duplicates(name) == 1)
        {
            printf("Name has been used already\n");
            return;
        }
        tail->next = p;
        tail = p;
        printf("How many people are in your group?\n");
        scanf("%i", &size);
        strcpy (p->name, name);
        p->groupSize = size;
    }
    if (head == NULL) //list empty
    {
        printf("What is your name\n");
        scanf("%s", name);
        printf("How many people are in your group?\n");
        scanf("%i", &size);
        head = tail = p;
        strcpy (p->name, name);
        p->groupSize = size;
        return;
    }

    return;
}

void delete()
{
    int x;
    int flag = 1;
    if(head == NULL)
    {
        printf("List empty\n");
        return;
    }
    printf("How big was your group?\n");
    scanf("%i",&x);
    NODE *temp,*prev;
    temp = prev = head;
    // Delete occurrences other than head
    while (x >= 0)
    {
        while (temp != NULL && temp->groupSize > x)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            if (flag == 1)
            {
                printf("No groups found\n");
            }
            return;
        }
        if (temp == head)
        {
            flag = 0;
            printf("%s was removed from list\n", head->name);
            x = x-temp->groupSize;
            head = temp->next;
            temp = head;
        } else
        {
            flag = 0;
            printf("%s was removed from list\n", temp->name);
            x = x-temp->groupSize;
            prev->next = temp->next;
            prev = temp;
        }
    }


}

void show()
{
    NODE *p;
    if (head == (NODE *) NULL)
    {
        printf("the list is empty\n");
        return;
    }
    p = head;
    while (p != NULL)
    {
        printf("Name: %s Group: %i\n", p->name, p->groupSize);
        p = p->next;
    }
    return;
}

void searchSize()
{
    int num;
    int flag = 0;
    if (head == (NODE *) NULL)
    {
        printf("the list is empty\n");
        return;
    }
    printf("what number would you like to search for?\n");
    scanf("%i", &num);
    NODE *p;
    p = head;
    while ((p != (NODE *) NULL))
    {
        if (p->groupSize <= num)
        {
            flag = 1;
            printf("%s has a group of %i\n", p->name, p->groupSize);
        }
        p = p->next;
    }
    if (flag == 0)
    {
        printf("No groups found\n");
    }

    return;
}


int main()
{

    int userInput;
    while (1)
    {
        printf("1: Add name and group number\n2: Delete Appointment\n3: List\n4: Find groups with specific size\n0: Quit\n");
        scanf("%i", &userInput);
        switch (userInput)
        {
            case 1:
                add();
                break;
            case 2:
                delete();
                break;
            case 3:
                show();
                break;
            case 4:
                searchSize();
                break;
            case 0:
                return 0;
            default:
                printf("Invalid\n");
                break;
        }
    }
}