#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<int> stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    //10, 20, 30 순으로 쌓임 제일 위에 30
    stk.pop();
    // 30제거

    cout << stk.top() << endl;
    stk.push(40);

    while(!stk.empty()){
        auto& e = stk.top();
        cout << e << ", " ;
        stk.pop();
    }
    cout << endl;
}