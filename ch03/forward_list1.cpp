#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
    forward_list<int> l1 {10,20,30,40};

    l1.push_front(40); // 40 10 20 30 40
    l1.push_front(30); // 30 40 10 20 30 40

    for( auto a : l1)
    {
        cout << a << ", ";
    }
    cout << endl;

    int cnt = distance(l1.begin(), l1.end());

    cout << cnt << endl;

    l1.remove(40); //이러면 40 두개 다 지워짐
    l1.remove_if([](int n ){ return n > 20; }); //람다식으로 이렇게 조건을 줄수도 있음

    for( auto a : l1)
    {
        cout << a << ", ";
    }
    cout << endl;
}