#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct file{
char name[10];
int start;
int size;
int status;
}f[10];
struct node
{
int  info;
char a[10];
struct node *next;
struct node *prev;
}*start,*temp,*new,*t,*s;

int fno=1,sz,st,fb=0;
char fn[10];

char   name[10];
int size,d;
int i,ch;
void  createBlock()
{
printf("Enter the total  block of Disk : ");
scanf("%d",&d);
start=temp=NULL;
for(i=0;i<d;i++)
{
new=(struct node*)malloc(sizeof(struct node));

new->next=NULL;
new->prev=NULL;
strcpy(new->a,"F");
new->info=i;
if(start==NULL)
{ 
 start=temp=new;
}
else
{
new->prev=temp;
temp->next=new;
temp=new;
}
}
}


void contain()
{
temp =start;
while(temp!=NULL)
{
printf("%d \t",temp->info );    
temp=temp->next;
}
temp=start;
printf("\n");    
while(temp!=NULL)    
       {
       printf("%s \t ",temp->a);
       temp=temp->next;
       }
}

void Add()
{    
               printf("\n Enter FileName & Size : " ) ;
               scanf("%s%d",fn,&sz);
               fb=0;
               temp=start;
               while(temp!=NULL)
               {
              		 if (strcmp(temp->a,"A")==0)
                   	{
                     	fb=0;
                     }
                   if (strcmp(temp->a,"A")!=0) 
                   	{   
                       if(fb==0)
                       {
                       s=temp;
                       fb++;
                       }
                       else 
                       		fb++;
                     }
                       if(fb==sz)
                       {
                       break;
                       }
                       temp=temp->next;
               }    
                               if(fb < sz)
                               {
                               printf("\n Inefficient Memory for file %s \n",fn);
                               fb=0;
                               }
                               else
                               {
                               	fno++;
                               	strcpy(f[fno].name,fn);
                               	f[fno].size=sz;
                               	f[fno].start=s->info;
                               	f[fno].status=1;
                               }
                               while(fb>0)
                               {
                               	strcpy(s->a,"A");
                               	s=s->next;
                               	fb--;
                               }      
}
                                
void Delete()
{
printf(" Enter file name to Delete:");
scanf("%s",fn);
for(i=0;i<=fno;i++)
{
	if(strcmp(f[i].name,fn)==0)
	{
		sz=f[i].size;
		st=f[i].start;
		f[i].status=0;
		f[i].start=1;
		break;
	}
}
temp=start;
while(temp->next!=NULL)
{
	if(temp->info==st)
	{
		break;
	}
	else
	{
		temp=temp->next;
	}
}
while(sz>0)
{
	strcpy(temp->a,"f");
	temp=temp->next;
	sz--;
}         
}

void files()
{
	printf("\n______________________________________________________________\n");
	printf("Fname\t Size\t Start\t Status\n");
	printf("\n______________________________________________________________\n");
	{
		for(i=0;i<=fno;i++)
		{
		if(f[i].status!=0)
			printf("%s\t%d\t%d\t%d\n",f[i].name,f[i].size,f[i].start,f[i].status);
		}
	}
	printf("\n______________________________________________________________\n");
}
void main()
{
	do
	{
		printf("\n 1.Create Blocks\n 2.Add\n 3.Delete\n 4.Files\n 5.Contains\n 6.Exit\n");
		printf("\n enter Your Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				createBlock();
			break;
			
			case 2: 
				Add();
			break;
			
			case 3:
				Delete();
			break;
			
			case 4: 
				files();
			break;
			
			case 5:
				contain();
			break;
			
		}
		
	
	}while(ch!=6);
}








