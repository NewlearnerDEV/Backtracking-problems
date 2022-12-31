#include<stdio.h>
int x[10];
void display(int n)
{
    for(int i=1;i<=n;i++)
    {
        printf("%d",x[i]);
    }
    printf("\n");
}
int place(int k,int i)
{
    for(int j=1;j<k;j++)
    {
        if(x[j]==i||k-j==i-x[j]||j-k==i-x[j])
        {
            return 0;
        }
    }
    return 1;
}
void nqueen(int k,int n)
{
    for(int i=1;i<=n;i++)
    {
        if(place(k,i))
        {
            x[k]=i;
            if(k==n)
            {
                display(n);
                exit(0);
            }
            else{
                nqueen(k+1,n);
            }
        }
    }
}
int main()
{
    nqueen(1,5);
}