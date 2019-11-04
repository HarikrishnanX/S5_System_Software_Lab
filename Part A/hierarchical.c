#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node
{
    char name[128];
    bool isDir;
    struct node *p;
    struct node *c[100];
    int i;
} * head, *curr;

void ls()
{
    if (curr->i == 0)
    {
        printf("\nEmpty directory!");
        return;
    }
    for (int i = 0; i < curr->i; i++)
    {
        if (curr->c[i]->isDir)
            printf("\n*%s*  ", curr->c[i]->name);
        else
            printf("\n%s  ", curr->c[i]->name);
    }
}

void touch(bool d)
{
    printf("\nEnter Name:");
    char fname[128];
    scanf("%s", fname);
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    strcpy(temp->name, fname);
    temp->isDir = d;
    temp->p = curr;
    curr->c[curr->i] = temp;
    curr->i = (curr->i) + 1;
}

void cd()
{
    printf("\nEnter Directory Name:");
    char dname[128];
    scanf("%s", dname);
    for (int i = 0; i < curr->i; i++)
    {
        if (!strcmp(curr->c[i]->name, dname) && curr->c[i]->isDir == true)
        {
            curr = curr->c[i];
            return;
        }
    }
    printf("\nDirectory Not Found!");
}

void cdup()
{
    if (curr->p == NULL)
    {
        printf("\nYou are at the Root Directory");
        return;
    }
    curr = curr->p;
}

void rm(bool d)
{
    printf("\nEnter Name of File or Directory to Delete:");
    char name[128];
    scanf("%s", name);
    for (int i = 0; i < curr->i; i++)
    {
        if (!strcmp(curr->c[i]->name, name) && ((d && curr->c[i]->isDir == true) || (!d && curr->c[i]->isDir == false)))
        {
            int t = i;
            while (t < (curr->i) - 1)
            {
                curr->c[t] = curr->c[t + 1];
                t++;
            }
            curr->i = (curr->i) - 1;
            printf("\nSuccessfully Deleted.");
            return;
        }
    }
    printf("\nNot found");
}

void main()
{
    int in;
    head = (struct node *)malloc(sizeof(struct node));
    strcpy(head->name, "root");
    head->isDir = true;
    head->p = NULL;
    head->i = 0;
    curr = head;
    while (true)
    {
        printf("\nYou are in %s directory.\n*****************************************\n1.Show everything in this Directory\n2.Change Directory\n3.Go to Parent Directory\n4.Create New File\n5.Delete File\n6.Create New Directory\n7.Delete Directory\n8.Exit\nEnter your choice:", curr->name);
        scanf("%d", &in);
        switch (in)
        {
        case 1:
            ls();
            break;
        case 2:
            cd();
            break;
        case 3:
            cdup();
            break;
        case 4:
            touch(false);
            break;
        case 5:
            rm(false);
            break;
        case 6:
            touch(true);
            break;
        case 7:
            rm(true);
            break;
        default:
            exit(0);
        }
    }
}
