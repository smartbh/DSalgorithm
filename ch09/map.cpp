#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<string, int> fruits;

    fruits.insert({"apple", 1000});
    fruits.insert({"banana", 1500});
    //fruits["orange"]; //이렇게 초기화해줄수도 있음 대신 value 값은 0으로 초기화
    fruits["orange"] = 1500; //이렇게 value값을 초기화 해줄수도 있다.
    fruits["grape"] = 2000;
    fruits["lemon"] = 1000;
    

    for(const auto &p : fruits)
    {
        cout << "(" <<p.first << "'s price is  " << p.second << " won "<< ")" <<endl;
    }

    for(auto [name, price ] : fruits) //이런식으로 받을수도 있음
    {
        cout << "(" << name << "'s price is  " << price << " won "<< ")" <<endl;
    }

    return 0;
}