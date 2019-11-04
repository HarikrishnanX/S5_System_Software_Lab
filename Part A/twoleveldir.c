#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct
{
    char dname[10], fname[10][10];
    int fcnt;
} dir[10];

void main()
{
    int i, ch, dcnt, k;
    char f[30], d[30];
    dcnt = 0;
    while (1)
    {
        printf("\n1.Create Directory\n2.Create File\n3.Delete File\n4.Search File\n5.Display\n6.Exit\nEnter Your Choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter Name of Directory:");
            scanf("%s", dir[dcnt].dname);
            dir[dcnt].fcnt = 0;
            dcnt++;
            printf("\nDirectory created");
            break;
        case 2:
            printf("\nEnter Name of the Directory:");
            scanf("%s", d);
            for (i = 0; i < dcnt; i++)
                if (strcmp(d, dir[i].dname) == 0)
                {
                    printf("\nEnter Name of the File to Create:");
                    scanf("%s", dir[i].fname[dir[i].fcnt]);
                    dir[i].fcnt++;
                    printf("\nFile created");
                    break;
                }
            if (i == dcnt)
                printf("\nDirectory %s Not Found!", d);
            break;
        case 3:
            printf("\nEnter Name of the Directory:");
            scanf("%s", d);
            for (i = 0; i < dcnt; i++)
            {
                if (strcmp(d, dir[i].dname) == 0)
                {
                    printf("\nEnter Name of the File to Delete:");
                    scanf("%s", f);
                    for (k = 0; k < dir[i].fcnt; k++)
                    {
                        if (strcmp(f, dir[i].fname[k]) == 0)
                        {
                            printf("\nFile %s Deleted", f);
                            dir[i].fcnt--;
                            strcpy(dir[i].fname[k], dir[i].fname[dir[i].fcnt]);
                            goto jmp;
                        }
                    }
                    printf("\nFile %s Not Found!", f);
                    goto jmp;
                }
            }
            printf("\nDirectory %s Not Found!", d);
        jmp:
            break;
        case 4:
            printf("\nEnter Name of the Directory:");
            scanf("%s", d);
            for (i = 0; i < dcnt; i++)
            {
                if (strcmp(d, dir[i].dname) == 0)
                {
                    printf("\nEnter the Name of the File to Search:");
                    scanf("%s", f);
                    for (k = 0; k < dir[i].fcnt; k++)
                    {
                        if (strcmp(f, dir[i].fname[k]) == 0)
                        {
                            printf("\nFile %s Found", f);
                            goto jmp1;
                        }
                    }
                    printf("\nFile %s Not Found!", f);
                    goto jmp1;
                }
            }
            printf("\nDirectory %s Not Found!", d);
        jmp1:
            break;
        case 5:
            if (dcnt == 0)
                printf("\nNo Directories!");
            else
            {
                printf("\nDirectory\tFiles");
                for (i = 0; i < dcnt; i++)
                {
                    printf("\n%s\t\t", dir[i].dname);
                    for (k = 0; k < dir[i].fcnt; k++)
                        printf("\t%s", dir[i].fname[k]);
                }
            }
            break;
        default:
            exit(0);
        }
    }
}
