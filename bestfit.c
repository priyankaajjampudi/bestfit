#include<stdio.h>
int memlayout[10];
void sort(int m)
{
      int i,j,temp;
      for(i=0;i<m;i++)
      {
          for(j=i+1;j<m;j++)
          {
              if(memlayout[j]<memlayout[i])
              {
                     temp=memlayout[i];
                     memlayout[i]=memlayout[j];
                     memlayout[j]=temp;
              }
           }
      }
}

int bestfit(int m, int r)
{
    int i,flag=0,temp;
    for(i=0;i<m;i++)
   {
        temp=memlayout[i];
        if(r<=memlayout[i])
         {
              memlayout[i]=memlayout[i]-r;
              printf("%d is allocated in  %d kb segment\n",r,temp);
              flag=1;
              break;
          }
    }
if(flag==1)
      return 1;
else
      return 0;
}
int main()
{
     int request[10],i,c=0,m,n,check;
     printf("enter no of memory partitions and requests");
    scanf("%d%d",&m,&n);
    printf("read memeory layout ");
    for(i=0;i<m;i++)
        scanf("%d",&memlayout[i]);
    printf("read request");
    for(i=0;i<n;i++)
        scanf("%d",&request[i]);
    sort(m);
   for(i=0;i<n;i++)
    {
       check=bestfit(m,request[i]);
        if(check==1)
             c++;
     }
printf("%d are requests are serviced",c); 
}


