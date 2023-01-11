#include <iostream>

using namespace std;

int main(){
    int scores[5] = {1,2,3,4,5};
    //가급적 배열도 중괄호로 초기화 해줘야
    int sum = 0;
    int ar_size = sizeof(scores)/sizeof(int);
    //배열의 크기 구하는 간단수식

    for(int i = 0; i<ar_size; i++){
        sum += scores[i];
    }

    float m = float(sum)/ar_size;

    cout << "Mean Scroe : " << m <<endl;

    return 0;
    
}