#include <iostream>

using namespace std;

int partition(int data[], int left, int right)
{
    int pivot = data[left]; //맨 처음 피봇은 가장 좌측에 있는걸 기준
    int i = left +1 , j = right;

    while(true)
    {
        while(data[i] <= pivot && i <= right)
            i++; 
            //입력 원소값이 피벗보다 커지면 루프 탈출
            //i가 가리키는 값이 피벗보다 크다는 뜻
        while(data[j] > pivot && j >  left)
            j--;
            //입력 원소값이 피벗보다 작으면 루프 탈출
            //j가 가리키는 값이 피벗보다 작다는 뜻

        if( i< j)
            swap(data[i], data[j]);
        else
            break;
    }

    swap(data[left], data[j]);
    return j;
}

void quick_sort(int data[], int left, int right)
{
    if(left < right)
    {
        int p = partition(data, left, right);
        quick_sort(data, left, p-1); //좌측
        quick_sort(data, p+1, right);//우측
    }
}


int main()
{   
    int data[] = {2,3,5,7,8,9,3,5,7,2,4,7,4,3,2,1,6,7,0};

    quick_sort(data, 0, size(data) -1);
    for(auto n : data)
        cout << n << ", ";
    
    cout << endl;
    return 0;
}