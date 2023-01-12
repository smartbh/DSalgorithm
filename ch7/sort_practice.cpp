#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    //기본 stl로 제공하는 정렬 sort는 오름차순 정렬
    int arr[5] = {4,2,3,5,1};

    //sort(arr, arr+5); //배열의 이름 = 포인터, 배열의 이름에 크기를 더해야 원하는 만큼 정렬 가능
    //C언어 스타일의 정렬방법

    sort(begin(arr),end(arr)); //std::begin, std::end. 같은 배열 정렬이어도 이건 c++스타일
    //배열인 arr대신 vec과 같은 vector를 넣어서 정렬도 가능

    for(auto n : arr)
        cout << n << ", ";

    cout << endl;

    vector<string> vec = {"orange","banana", "apple", "lemon"};

    sort(vec.begin(), vec.end());

    for(auto n : vec)
        cout << n << ", ";

    
}