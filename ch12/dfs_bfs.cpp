#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

const int N = 6;
bool gVisited[N] = {}; //방문했는지 체크하는 배열

//그래프 순회 : 하나의 정점에서 시작하여 모든 정점을 한번씩 방문하는 작업
// 많은 문제들이 그래프 순회 방법으로 해결 가능
//ex) 최단거리 검사 or 두 정점 사이의 연결 경로가 있는지 검사
//대표적인 그래프 순회 방법들로는 DFS, BFS가 있음 각각 깊이우선탐색, 너비우선탐색
//깊이 : 보통 재귀나 스택을 이용해 구현
//너비 : 보통 큐를 이용하여 현

//재귀로 구현
void dfs_recursion(const vector<vector<int>>& adj_list, int start)
{
    if(gVisited[start])
        return;
    gVisited[start] = true; //방문하면 트루로 바꿈
    cout << start << ", ";

    for(int v : adj_list[start])  
        dfs_recursion(adj_list,v);
}

//스택으로 구현
vector<int> dfs_stack(const vector<vector<int>> adj_list, int start)
{
    vector<bool> visited(adj_list.size(), false); //adjlist의 크기만큼 만들고 전부 false로 초기화
    vector<int> visit_order; //방문 순서 기록 벡터

    stack<int> stk; //비어있는 스택 하나 생성
    stk.push(start);

    while(!stk.empty())
    {
        int v = stk.top();
        stk.pop();
        if(visited[v])
            continue;
        visited[v] = true; //정점 v를 방문
        visit_order.push_back(v); //이 위치에 특정한 동작을 하게 하고싶으면 여기에 추가

        for(int a : adj_list[v])
        {
            if(!visited[a])
                stk.push(a);
        }

    }

    return visit_order;
}

//bfs구현하기
//큐로 구현
vector<int> bfs(const vector<vector<int>>& adj_list, int start)
{
    vector<bool> visited(adj_list.size(), 0);
    vector<int> visited_order;

    queue<int> que;
    que.push(start);

    while(!que.empty())
    {
        int v = que.front();
        que.pop();  

        if(visited[v]) continue;

        visited[v] = true;
        visited_order.push_back(v);

        for(int a : adj_list[v])
        {
            if(!visited[a])
                que.push(a);
        }
    }

    
    return visited_order;
}


int main()
{
    vector<vector<int>> adj_list = {
        {1,3,4},{0,2,4},{1,5},
        {0,4},{0,1,3},{2}
    };

    dfs_recursion(adj_list,0);
    dfs_stack(adj_list,0);
    cout << endl;

    auto dfs_order = dfs_stack(adj_list,0);
    auto bfs_order = bfs(adj_list, 0);

    cout << "bfs : ";
    for(int a : bfs_order)
    {
        cout << a << ", ";
    }
    cout << endl;

    cout << "dfs : ";
    for(int a : dfs_order)
    {
        cout << a << ", ";
    }
    cout << endl;


    return 0;
}