#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct
{
    char dname[10],fname[10][10];
    int fcnt;
}dir;

void main()
{
    int i,ch;
    char f[30];
    dir.fcnt = 0;
    printf("Enter Name of Directory:");
    scanf("%s",dir.dname);
    while(1)
    {
   	 printf("\n1.Create File\n2.Delete File\n3.Search File\n4.Display Files\n5.Exit\nEnter Your Choice:");
   	 scanf("%d",&ch);
   	 switch(ch)
   	 {
   		 case 1: printf("\nEnter the Name of the File to Create:");
   			 scanf("%s",dir.fname[dir.fcnt]);
   			 dir.fcnt++;
   			 break;
   		 case 2: printf("\nEnter the Name of the File to Delete:");
   			 scanf("%s",f);
   			 for(i=0;i<dir.fcnt;i++)
   			 {
   				 if(strcmp(f, dir.fname[i])==0)
   				 {
   					 printf("\nDeleted File %s",f);
   					 strcpy(dir.fname[i],dir.fname[dir.fcnt-1]);
   					 break;
   				 }
   			 }
   			 if(i==dir.fcnt)
   				 printf("\nFile %s Not Found!",f);
   			 else
   				 dir.fcnt--;
   			 break;
   		 case 3: printf("\nEnter the Name of the File to Search:");
   			 scanf("%s",f);
   			 for(i=0;i<dir.fcnt;i++)
   			 {
   				 if(strcmp(f, dir.fname[i])==0)
   				 {
   					 printf("\nFile %s Found ", f);
   					 break;
   				 }
   			 }
   			 if(i==dir.fcnt)
   				 printf("\nFile %s Not Found!",f);
   			 break;
   		 case 4: if(dir.fcnt==0)
   				 printf("\nDirectory is Empty!");
   			 else
   			 {
   				 printf("\nThe Files are:");
   				 for(i=0;i<dir.fcnt;i++)
   					 printf("\n%s",dir.fname[i]);
   			 }
   			 break;
   		 default: exit(0);
   	 }   	 
    }
}
