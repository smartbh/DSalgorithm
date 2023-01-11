#include <iostream>
#include <chrono>

using namespace std;

int sum_recursive(int n){
    if(n == 1 )
        return 1;
    else
        return n + sum_recursive(n-1);
}

int sum_iterative(int n){
    int s = 0;
    for(int i = 1; i<=n; i++){
        s += i;
    }
    
    return s;
}

int main(){
    
    {
        auto start = chrono::system_clock::now();

        volatile int s = 0;

        for (int i = 1; i<=20000; i++){
            s = sum_recursive(i);
        }

        auto end = chrono::system_clock::now();
        auto mesc = chrono::duration<double>(end - start).count() * 1000;
        cout << "sum recursion() : " << mesc <<"ms"<<endl;
    }

    {
        auto start = chrono::system_clock::now();

        volatile int s = 0;

        for (int i = 1; i<=20000; i++){
            s = sum_iterative(i);
        }

        auto end = chrono::system_clock::now();
        auto mesc = chrono::duration<double>(end - start).count() * 1000;
        cout << "sum iterative() : " << mesc <<"ms"<<endl;
    }

}