#include<stdio.h>
#include<iostream>
using namespace std;
struct Knapsack
{
    int weight;
    int value;
    float rate;
};
void swap_Knapsack(Knapsack *k1,Knapsack *k2)
{
    Knapsack *temp;
    *temp=*k2;
    *k2=*k1;
    *k1=*temp;
}
void bubble_sort(Knapsack K[],int n)
{
    int i,j,f=0;
    Knapsack temp;
    for(i=0;i<n;i++)
    {
        f=0;
        for(j=0;j<n-i-1;j++)
        {
            if(K[j].rate>K[j+1].rate)
            {
                swap_Knapsack(&K[j],&K[j+1]);
                f=1;


            }
            if(f==0)
                break;

        }
    }
}
int main()
{
    int t,n,k,i;
    cin>>t;
    while(t--)
    {
        float max_sum=0.0;
        cin>>n>>k;
        Knapsack K[n];
        float sol[n]={0.0};
        for(i=0;i<n;i++)
        {
            cin>>K[i].value>>K[i].weight;
            K[i].rate=K[i].value/K[i].weight;
        }
        bubble_sort(K,n);
        int kt=k;
        for(int i=0;i<n;i++)
        {
            if(kt>K[i].weight)
            {
                sol[i]=K[i].weight*K[i].rate;
                kt=kt-K[i].weight;
            }
            else
            {
                sol[i]=(kt)*K[i].rate;
                break;
            }
        }

        for(i=0;i<n;i++)
            max_sum=max_sum+sol[i];
            printf("%0.2f\n",(float)max_sum);


    }
    return 0;
}
