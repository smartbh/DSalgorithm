#include <algorithm>
#include <iostream>

using namespace std;

void bubble_sort(int data[], int n)
{
    for(int i = 0; i<n-1; i++)
    {
        for(int j = n-1; j>i;j--)
        {
            if(data[j] < data[j-1])
                swap(data[j], data[j-1]);
        }
    }
}

void selection_sort(int data[], int n)
{
    
    for(int i = 0; i<n-1; i++)
    {
        int idx = i;
        for(int j = i+1; j<n;j++)
            if(data[j] < data[idx]) //다시 최솟값 찾기.
                idx = j;

        swap(data[i], data[idx]);
    }
}

//삽입정렬
void insert_sort(int data[], int n)
{
    for(int i = 1; i<n-1; i++)
    {
        int key = data[i]; //임시값 복사
        
    }
}

int main()
{   
    int data[] = {4,2,3,5,1};
    //bubble_sort(data,5);
    //selection_sort(data,5);

    for(auto n : data)
        cout << n << ", ";
    
    cout << endl; 

    return 0;
    
    섹스
}