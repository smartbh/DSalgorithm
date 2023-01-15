#include <iostream>
#include <algorithm>

void linear_search(int data [], int n,int target) //이름, 크기 목표,
{
    for(int i = 0; i<n; i++)
    {
        if(data[i] == target)
        {
            std::cout << i+1 <<"번째 순서 "<< data[i] << std::endl;
            return;
        }
    }
    //못찾을시
    std::cout << "해당 요소가 없음" << std::endl;
    return;
}

//선형 탐색 -> 단순간단 but 비효율적 O(n) 복잡도

bool binary_search(int data[], int n, int target)
{
    int lower = 0;
    int upper = n-1;

    //예외처리
    if(data[lower] > target || data[upper] <target) //최솟값이 목표값보다 크거나 최대값이 목표값보다 작으면 -> 배열안에 요소가 없다.
        return false;

    while(lower <=upper)
    {
        int mid = (lower + upper)/2;

        if(data[mid] == target)
            return true;
        else if(data[mid] < target) //중간값이 목표값보다 작다 -> 최솟값을 중간값으로 올리기
            lower = mid + 1;
        else //중간값이 목표값보다 크다 -> 최대값을 중간값으로 내리기
            upper = mid -1;
    }

    return false;
}

//이진 탐색 -> 정렬된 배열 대상으로 탐색 시작, 검색범위를 반씩 줄여가며 하는 방식
//검색소도가 빠른 장점 but 이미 정렬 되어있는 배열상대로만 가능
//이진탐색 방법이 선형탐색보다 훨씬 빠름



int main()
{
    int data[] = {1,2,3,4,5,6,7,8,98,9,10,11,12,13,14,15};
    linear_search(data,16,10);

    std::sort(std::begin(data),std::end(data));

    bool res1 = binary_search(data,std::size(data),10);
    bool res2 = std::binary_search(std::begin(data),std::end(data),10);

    std::cout << res1 << std::endl;
    std::cout << res2 << std::endl;

    return 0;
}