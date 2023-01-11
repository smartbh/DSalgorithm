#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> l1;
    l1.push_back(10); // 10
    l1.push_back(20); // 10 -> 20
    
    list<int> l2 {10,20,30,40}; // 초기화
    
    for(auto a : l2)
        cout << a << ", ";
    cout << endl;

    l2.splice(l2.end(), l1); //l2 뒤에 l1을 붙임 예상: 10,20,30,40,10,20
    //복사가 되는게 아니라 이동을 함
    //l1은 비게됨

    for(auto a : l2)
        cout << a << ", ";
    cout << endl;

    l2.sort(); //기본 오름차순 정렬, 10 10 20 20 30 40 으로 정렬될것

    
    for(auto a : l2)
        cout << a << ", ";
    cout << endl;

    l2.unique(); //연속된것 중 중복된것을 삭제하고 하나만 남김

    
    for(auto a : l2)
        cout << a << ", ";
    cout << endl;
}