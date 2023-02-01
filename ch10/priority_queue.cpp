#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

template <typename T>

void print_priotiry(T q)
{

    while(!q.empty())
    {
        cout << q.top() << ", ";
        q.pop();
    }
    cout << endl;
}

class Student
{
public:
    string name;
    int score;
    bool operator < (const Student& st) const
    {
        return score < st.score;
    }
};

int main(){
    vector<int> vec {0,1,2,3,4};

    priority_queue<int> pq1;

    for(auto n : vec)
    {
        pq1.push(n);
    }

    print_priotiry(pq1);

    priority_queue<int, vector<int>, greater<int>> pq2(vec.begin(), vec.end());

    
    print_priotiry(pq2);

    priority_queue<Student> students;
    students.push({"Amelia", 80});
    students.push({"Sophia", 40});
    students.push({"Olivia", 30});
    students.push({"George", 60});

    while(!students.empty())
    {
        auto& n = students.top();
        cout << n.name << " (" <<n.score<<")"<<endl;
        students.pop();
    }
    cout << endl;

    return 0;
}