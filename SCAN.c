#include<stdio.h>
#include<stdlib.h>
int main()
{
 int RQ[100],i,j,n,TotalHeadMovement=0,initial,size,move;
 printf("Enter the number of Requests\n");
 scanf("%d",&n);
 printf("Enter the requests sequence\n");
 for(i=0;i<n;i++)
 scanf("%d",&RQ[i]);
 printf("Enter the initial head position\n");
 scanf("%d",&initial);
 printf("Enter the total disk Size\n");
 scanf("%d",&size);
 printf("Enter the head movement direction for high 1 for low 0\n");
 scanf("%d",&move);
 
 for(i=0;i<n;i++)
 {
  for(j=0;j<n-i-1;j++)
  {
   if(RQ[j]>RQ[j+1])
   {
    int temp;
    temp=RQ[j];
    RQ[j]=RQ[j+1];
    RQ[j+1]=temp;
   }
   
  }
 }
 
 int index;
 for(i=0;i<n;i++)
 {
  if(initial<RQ[i])
  {
   index=i;
   break;
  }
 }
 
 
 if(move==1)
 {
  for(i=index;i<n;i++)
  {
   TotalHeadMovement=TotalHeadMovement+abs(RQ[i]-initial);
   initial=RQ[i];
 }
 
 TotalHeadMovement=TotalHeadMovement+abs(size-RQ[i-1]-1);
 initial=size-1;
 for(i=index-1;i>=0;i--)
 {
  TotalHeadMovement=TotalHeadMovement+abs(RQ[i]-initial);
  initial=RQ[i];
  
 }
 }
 
 else
 {
   for(i=index-1;i>n;i++)
   {
   TotalHeadMovement=TotalHeadMovement+abs(RQ[i]-initial);
    initial=RQ[i];
   }
   
   TotalHeadMovement=TotalHeadMovement+abs(RQ[i+1]-0);
   initial=0;
   for(i=index;i<n;i++)
   {
     TotalHeadMovement=TotalHeadMovement+abs(RQ[i]-initial);
     initial=RQ[i];
     
   }
 }
 
 printf("Total Head movements is %d",TotalHeadMovement);
 return 0;
 }

