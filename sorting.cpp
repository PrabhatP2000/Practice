#include<bits/stdc++.h>
using namespace std;
void swap(vector<int>&v,int i,int j)
{
    int temp=v[i];
    v[i]=v[j];
    v[j]=temp;
}

// int partition(vector<int>&v,int low,int high)
// {
//     int pivot=v[low];
//     int i=low;
//     int j=high;

//     while(i<j)
//     {
//         while(v[i]<=pivot)i++;
//         while(v[j]>pivot)j--;
//         if(i<j)
//         {
//             swap(v,i,j);
//         }
//     }
//     swap(v,low,j);
//     return j;
// }


// void quickSort(vector<int>&v,int low,int high)
// {
//     if(low<high)
//     {
//         int pivot=partition(v,low,high);
//         quickSort(v,low,pivot-1);
//         quickSort(v,pivot+1,high);
//     }
// }

void merge(vector<int>&v,int left,int mid,int right)
{
    int i=left;
    int j=mid+1;
    int k{left};
    int b[v.size()];
    while(i<=mid && j<=right)
    {
        if(v[i]<v[j])
        {
            b[k++]=v[i++];
        }
        else
        {
            b[k++]=v[j++];
        }
    }

    for(;i<=mid;i++)
    b[k++]=v[i];

    for(;j<=right;j++)
    b[k++]=v[j];

    for(int z=left;z<=right;z++)
    {
        v[z]=b[z];
    }
}

void mergeSort(vector<int>&v,int left,int right)
{
    if(left<right)
    {
        int mid=(left+right)/2;
        mergeSort(v,left,mid);
        mergeSort(v,mid+1,right);
        merge(v,left,mid,right);
    }
}

int main()
{
    vector<int>v{1,3,5,675,34,5435,345,345,3453,45,4,1,23,0};
    //Bubble Sort

    // for(int i=0;i<v.size()-1;i++)
    // {
    //     for(int j=0;j<v.size()-1-i;j++)
    //     {
    //         if(v[j]>v[j+1])
    //         {
    //             swap(v,j,j+1);
    //         }
    //     }
    // }

    //Insertion Sort
    // for(int i=1;i<v.size();i++)
    // {
    //     int x=v[i];
    //     int j=i-1;

    //     while(j>-1 && v[j]>x)
    //     {
    //         v[j+1]=v[j];
    //         j--;
    //     }
    //     v[j+1]=x;
    // }

    //Selection Sort
    // int k{};
    // for(int i=0;i<v.size()-1;i++)
    // {
    //     for(int j=k=i;j<v.size();j++)
    //     {
    //         if(v[j]<v[k])
    //         {
    //             k=j;
    //         }

    //     }
    //     swap(v,k,i);
    // }

    //Quick Sort
    // quickSort(v,0,v.size()-1);

    //Merge Sort

    mergeSort(v,0,v.size()-1);

    for(int x:v)
    {
        cout<<x<<" ";
    }
}
