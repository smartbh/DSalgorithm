#include <iostream>
#include <set>
#include <string>

/*
컨테이너에는 순차, 연관, 순서없는, 컨테이너 어뎁터로 구성돼있다.

순차 : 벡터, 어레이, 리스트, 디큐, forward list(단방향 리스트)
연관 : 연관돼있는 애들끼리 정리해두는것, set, map, 멀티셋, 멀티맵등

set : 키값만 저장함
map : 키와 value 값 두개를 저장함.
set은 중복된 값을 저장하지 않지만 multiset은 중복값도 저장함.

set은 정렬을해서 키값을 저장하지만
unordered_set은 데이터를 정렬하지 않음(좀 빠름)

set은 O(log n)의 복잡도를 가짐
*/

using namespace std;

int main()
{
    set<int> odd; //홀수 정수값
    //set<int> odd {2,3,5,7,9}; 이렇게 초기화를 할수도 있음
    set<int, greater<>> even {2,4,6,8};


    odd.insert(1);
    odd.insert(7);
    odd.insert(5);
    odd.insert(3);
    odd.insert(9);


    even.insert(10);
    even.insert(2);

    if(even.find(4) != even.end()) //find 함수가 목표를 찾으면 해당위치의 반복자를 반환하고 목표값이 없으면 end를 반복함
    {
        cout << "4 is found!" << endl;
    }
    else
        cout << "4 is not found" << endl;
    for(auto n : odd)
    {
        cout << n << ", ";
    }
    cout << endl;

    for(auto n : even)
    {
        cout << n << ", ";
    }

    cout << endl;

    //using으로 쉽게 해보기 (귀찮음), typedef와 비슷
    using psi = pair<string,int>;

    //복합적 데이터 저장도 가능
    //문자열, 정수 쌍으로 된 데이터를 넣고싶다면
    set<pair<string, int>> managers {{"Amelia", 29},{"noa", 29},{"lee", 29},{"sex", 29}};

    managers.insert(make_pair("george", 15)); //insert할때 이렇게도 가능

    psi person1 = {"lee", 29};

    if(managers.find(person1) != managers.end())
    {
        cout << "해당 인물이 있다." << endl;
    }
    else
    {
        cout << "해당 인물이 없다." << endl;
    }

    managers.erase({"sex",29});
    managers.erase({"lee",40});

    for(const auto &n : managers)
    {
        cout << n.first << "(" << n.second << ")" << endl;
    }
}