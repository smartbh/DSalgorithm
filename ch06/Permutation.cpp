#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>

void print_vector(const vector<T>& vec)
{
    for(const auto& e: vec)
        cout << e << " " ;
    
    cout << endl;
}

void permutation(vector<int>& vec, int k)
{
    if(k == vec.size()-1) //k가 만약 vec의 마지막 원소를 가리키면
    {
        print_vector(vec);
        return;
    }

    for(int i = k; i<vec.size(); i++)
    {
        swap(vec[k],vec[i]); //한번 스왑해주고
        permutation(vec, k+1); //해당 원소 위치일때 순열
        swap(vec[k], vec[i]); //원소 다시 원상복귀
    }//원상복귀를 안하면 반복되는 문제가 생김
}

int main()
{
    vector<int> vec {1,2,3,4};
    //permutation(vec, 0);

    sort(vec.begin(), vec.end());
    do{
        print_vector(vec);
    }while(next_permutation(vec.begin(), vec.end()));
    
    return 0;
}