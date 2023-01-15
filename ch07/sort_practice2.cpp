#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


//함수 포인터 방법
bool abbs_cmp(const int a, const int b)
{
    return abs(a) < abs(b);
}

class Person
{
public:
    string name;
    int age;

    bool operator < (const Person& a) const
    {
        return this->age < a.age;
    }

    void print() const
    {
        cout << name << ", " << age << endl;
    }

};



int main()
{
    //함수 객체/클래스 방법

    struct AbsCmp
    {  
        inline bool operator()(int a, int b) const
        {
            return abs(a) < abs(b);
        }
        /* data */
    };


    
    vector<int> nums = {10,3,-2,5,-7};

    //sort(begin(nums), end(nums), abbs_cmp);
    //sort(begin(nums), end(nums), AbsCmp());
    //람다표현식으로 함수 객체/클래스 사용해보기
    sort(begin(nums), end(nums), [](int a, int b) { return abs(a) < abs(b); });
    //전부 오름차순

    //sort(begin(nums), end(nums), greater<>()); //내림차순


    for( auto p : nums)
        cout << p << ", ";

        cout << endl;

    vector<Person> v;
    v.push_back({"Amelia",29});
    v.push_back({"Noah",25});
    v.push_back({"Olivia",31});
    v.push_back({"Sophia",40});
    v.push_back({"George",35});

    sort(begin(v),end(v));  
    
    for(auto n : v)
        n.print();
    

    return 0;
}