#include <iostream>
#include <array>

using namespace std;

int main(){

    array<int,5> scores = {1,2,3,4,5};
    int sum = 0;

    for(int i = 0; i<scores.size(); i++){
        sum += scores[i];
    }

    float m = (float)sum/scores.size();

    cout << "average : " << m << endl;
    
    return 0;
}