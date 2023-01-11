#include <iostream>
#include <numeric>


//using namespace std;

int gcd(int a, int b){ //최대공약수
    //유클리드 알고리즘, 유클리드 호제법을 사용
    if(b == 0)
        return a;
    else
        return gcd(b, a%b);
}

int lcm(int a, int b)
{
    // a * b == gcd(a,b) * lcm(a,b)
    // lcm(a,b) == (a * b) / gcd(a,b)

    return (a * b) / gcd( a, b);
}

int main()
{
    int gcd1 = gcd(10,15);
    int lcm1 = lcm(10,15);

    int gcd2 = gcd(10,15);
    //gcd(10,15);
    int lcm2 = lcm(10,15);

    std::cout << gcd1 << ", " << gcd2 << std::endl;
    std::cout << lcm1 << ", " << lcm2 << std::endl;
    return 0;
}