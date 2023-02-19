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

    for(int y = 1; y<n; y++) //y좌표, 1부터 시작하는 이유는 0,0의 자리는 변화시키지 않겠다는 의미기 때문
    {   
        for(int x = 0; x <=y ; x++) //x좌표
        {
            if(x == 0 ) dp[y][x] = dp[y-1][x] + triangle[y][x]; //정수 삼각형 왼쪽 가장자리
            else if(x == y) dp[y][x] = dp[y-1][x-1] + triangle[y][x]; //정수 삼각형의 우측 가장자리
            else dp[y][x] = max(dp[y-1][x-1], dp[y-1][x]) + triangle[y][x];

        }
    }

    return *max_element(dp[n-1].begin(), dp[n-1].end() );
}

int main()
{
    vector<vector<int>> triangle = {{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}};
    cout << solution(triangle) << endl;
}