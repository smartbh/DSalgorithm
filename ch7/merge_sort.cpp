#include <iostream>

using namespace std;

//병합정렬과 퀵정렬은 분할정복에 의한 알고리즘이다
//재귀방식을 사용함

int buff[256];

//병합
void merge(int data[],int left, int mid, int right)
{
    int i = left, j = mid +1, k = left;
    while(i<=mid && j <= right)
    {
        if(data[i] <= data[j])
            buff[k++] = data[i++];
        else
            buff[k++] = data[j++];
    }
    //i 또는 j가 각 부분배열의 끝에 도달할시 해당 while 루프는 종료

    while(i<=mid)
    {
        buff[k++] = data[i++];
    }
    while(j<=right)
    {
        buff[k++] = data[j++];
    }

    //두가지 while 루프는 혹시라도 위의 작업이후
    // 빠진 원소가 있을때를 대비한 루프들

    for(int x = left; x<=right; x++)
    {
        data[x] = buff[x];
    }

}

void merge_sort(int data[], int left, int right)
{
    if(left < right)
    {
        int mid = (left + right)/2;
        merge_sort(data, left, mid);
        merge_sort(data,mid+1,right);
        merge(data, left, mid, right);
    }
}

int main()
{
    int data[] = {2, 6,7,4,1,8,5,3,6,8,9,2,1,9,0,4,3,2};
    merge_sort(data,0,17);

    for(auto n : data)
        cout << n << ", ";
    
    cout << endl;

    return 0;
}