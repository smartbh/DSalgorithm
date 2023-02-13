#include <iostream>
#include <vector>

using namespace std;

//그래프 경로 중 특정 정점이 중복되지 않는 경로를 단순경로라 한다.
//트리는 사이클이 없는 그래프라 볼수있다.
//인접행렬은 그래프의 노드끼리 엣지로 연결된 상태를 이중행렬로 표현한것
//무방향 그래프는 인접행렬이 대칭적인 모습을 보이고 방향그래프는 인접행렬이 대칭적인 모습을 보이지 않음
//그래프의 정점 개수가 적고, 엣지가 많을때는 인접행렬이 유리함 O(N^2) 복잡도


//아래는 전부 그래프 구현 방법들이다.

/*
인접행렬 구현 예시
vector<vector<int>> adjust_matrix =
{
    {0,1,0,1,1,0},
    {1,0,1,0,1,0},
    {0,1,0,0,0,1},
    {1,0,0,0,1,0},
    {1,1,0,1,0,0},
    {0,0,1,0,0,0}
};
*/

//인접 리스트로도 표현할수있다.
//인접 리스트로 표현할시에는 O(N + M)의 복잡도를 갖는다. N : 정점, M : 엣지 수  
//벡터 속 list 구조로 표현할수 있으나, c++에선 인접행렬 구현과 같이 벡터만으로 구현하는게 더 효율적

/*
인접 리스트 구현 예시
vector<vector<int>> adj_list =
{
    {1,3,4},
    {0,2,4},
    {1,5},
    {0,4},
    {0,1,3},
    {2}
};
*/

//모든 엣지를 (v,w) 를 리스트 또는 배열로 표현할수있음
//공간 복잡도는 O(M) 이며 M은 엣지의 개수이다.

/*
에지 리스트 구현 예시
vector<vector<int>> edge_list =
{
    {0,1},{0,3},{0,4},
    {1,0},{1,2},{1,4},
    {2,1},{2,5},
    {3,0},{3,4},
    {4,0},{4,1},{4,3},
    {5,2},
};
*/

vector<vector<int>> get_adj_list(const vector<vector<int>>& adj_matrix)
{
    vector<vector<int>> adj_list(adj_matrix.size()); //행을 같은 크기로 만들게 생성자로 생성 

    for(int u =0; u<adj_matrix.size(); u++)
    {
        for(int v = 0; v< adj_matrix[u].size(); v++)
        {
            if(adj_matrix[u][v] == 1)
                adj_list[u].push_back(v);
        }
    }

    return adj_list;
}

int main()
{
    
    vector<vector<int>> adjust_matrix =
    {
        {0,1,0,1,1,0},
        {1,0,1,0,1,0},
        {0,1,0,0,0,1},
        {1,0,0,0,1,0},
        {1,1,0,1,0,0},
        {0,0,1,0,0,0}
    };


    vector<vector<int>> adj_list =  get_adj_list(adjust_matrix);
    for(const auto & l : adj_list)
    {
        for(const auto n : l)
            cout << n << ", ";
        
        cout << endl;
    }

    return 0;
}