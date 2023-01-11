#include <iostream>
#include <vector>
#include <stack>

using namespace std;

string reverse(const string& str)
{
    stack<char> stk;
    
    for(char c: str)
    {
        stk.push(c);
    }

    string res;

    while(!stk.empty())
    {
        res += stk.top();
        stk.pop();
    }

    return res;

}

template <typename T>
void reverse(vector<T>& vec)
{

    stack<T, vector<T>> stk(vec);//아래 세줄을 한번에 사용

    /*
    stack<T> stk;
    for(const auto& e : vec)
        stk.push(e);
    */

    for( int i = 0; i < vec.size(); i++)
    {
        vec[i] = stk.top();
        stk.pop();
    }

}


int main(){
    string str1 = "HELLO";
    string str2 = "ALGORITHM";

    cout << str1 << " -> " << reverse(str1) << endl;
    cout << str2 << " -> " << reverse(str2) << endl;

    //vector<int> vec {10,20,30,40,50};
    vector<string> vec {"Jone","loves","Jane"};

    reverse<string>(vec);

    for(auto e : vec)
    {
        cout << e << ", ";
    }

    cout << endl;
}