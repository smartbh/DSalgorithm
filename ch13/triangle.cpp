#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

//greedy 계획법을 쓰면 해결 불가능한 종류의 문제
//동적계획법을 사용해야하는 문제

int solution(vector<vector<int>> triangle)
{
    vector<vector<int>> dp = triangle;

    int n = triangle.size();

    for(int y = 1; y<n; y++)
    {   
        for(int x = 0; x <=y ; x++)
        {
            
        }
    }
}

int main()
{

}