#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


//최소비용 경로 : 2차원 행렬 각 셀에 정수값 비용이 적혀있을때, 행렬의 좌상단에서 우하단까지 이동하기 위한 최소비용을 계산하는 문제.
//이동은 오른쪽 또는 아래쪽 방향으로만 가능
//즉 (x,y)에 도달하기 위해선 (x-1,y)나 (x,y-1)을 꼭 거쳐야한다 (오른쪽이나 아래로만 이동가능하기때문)

//최소 비용을 C(x,y)라고 정의하면 수식으로는
//C(x,y) = min(C(x-1,y), C(x,y-1)) + m(x,y) 로 정의할수있다.

int solution(vector<vector<int>> m)
{
    int rows = (int)m.size();
    int cols = (int)m[0].size();

    vector<vector<int>> dp(rows, vector<int> (cols, 0));   

    for(int y =0; y <rows; y++)
    {
        for(int x = 0; x<cols; x++)
        {
            if(x == 0 && y ==0) dp[y][x] = m[y][x];
            else if(x == 0) dp[y][x] = dp[y-1][x] + m[y][x];
            else if(y == 0) dp[y][x] = dp[y][x-1] + m[y][x];
            else    dp[y][x] = min(dp[y-1][x], dp[y][x -1]) + m[y][x];
        }
    }

    return dp[rows - 1][cols -1];
}

int main()
{
    vector<vector<int>> m = {
        {2,7,5,4},
        {5,3,6,8},
        {7,8,7,4},
        {8,1,9,5}
    };

    cout << "Minimum cost : " << solution(m) << endl;
}