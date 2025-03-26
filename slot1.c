#include<stdio.h>
#include<unistd.h>
int main()
{
int i,j,k,res,pno;
printf("Enter the no of resourses:");
scanf("%d",&res);
printf("Enter the no of processes :");
scanf("%d",&pno);
int available[res];
printf("Enter the available matrix ");
for(i=0;i<res;i++)
{
scanf("%d",&available[i]);
}
printf("The available matrix is\n ");
                      
for(i=0;i<res;i++)
{
printf("\t %d",available[i]);
}
printf("\nEnter the allocated matrix :");
 int allocation[10][10];
for(i=0;i<pno;i++)
{
for(j=0;j<res;j++)
{
scanf(" %d",&allocation[i][j]);
}
}
printf("The allocation matrix is :\n");
for(i=0;i<pno;i++)
{
for(j=0;j<res;j++)
{
printf(" \t %d ",allocation[i][j]);
}
printf("\n");
}
printf("\nEnter the maximum matrix :"); int Max[10][10];
for(i=0;i<pno;i++)
{
for(j=0;j<res;j++)
{
scanf(" %d",&Max[i][j]);
}
}
printf("The max matrix is :\n"); for(i=0;i<pno;i++)
{
for(j=0;j<res;j++)
{
printf("\t %d",Max[i][j]);
}
printf("\n");
}
int need[10][10];
for(i=0;i<pno;i++)
{
for(j=0;j<res;j++)
{
need[i][j]=Max[i][j]-allocation[i][j];
}
}
printf("The need matrix is :\n"); for(i=0;i<pno;i++)
{
for(j=0;j<res;j++)
{
printf("\t %d",need[i][j]);
}
printf("\n");
}
}
