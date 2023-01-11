#include <iostream>

using namespace std;

int gcd(int a, int b){ //최대공약수
    //유클리드 알고리즘, 유클리드 호제법을 사용
    if(b == 0)
        return a;
    else
        return gcd(b, a%b);
}

int main(){
    cout << gcd(24,18);
}