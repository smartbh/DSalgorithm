#include <iostream>
#include <stack>

using namespace std;

bool check_parent(const string& s) //괄호 검사 함수
{
    stack<char> stk;
    for(char c : s)
    {
        if( c == '(' || c == '{' || c == '[' ){
            stk.push(c);
        }
        else{
            if(stk.empty() || 
                (stk.top() == '(' && c != ')') ||
                (stk.top() == '{' && c != '}') ||
                (stk.top() == '[' && c != ']'))
                return false;
            
            stk.pop();
        }
    }

    return stk.empty();
}

int main()
{
    //올바른 괄호
    cout << check_parent("(){}[]") << endl;
    cout << check_parent("((((()))))") << endl;
    cout << check_parent("(){[()]}") << endl;

    //올바르지 않은 괄호
    cout << check_parent("((({}))") << endl;
    cout << check_parent(")(") << endl;
    cout << check_parent("({)}") << endl;


}