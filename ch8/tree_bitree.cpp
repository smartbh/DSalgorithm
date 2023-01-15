#include <iostream>
#include <queue>
#include <vector>

//트리
//차수(degree) = 자식노드의 개수를 뜻
//레벨 = 루트에서 얼마나 떨어져 있는지, 루트는 0레벨에서 시작
//높이 = 루트에서 떨어져서 가장 멀리 떨어져 있는 노드의 레벨 0 1,2,3 = 높이 4. 가장 큰 레벨값에 +1
//서브트리 = 부분트리, 특정 노드를 새로 루트기준으로 해당 노드의 후손들만 이용해서 만든 노드

//이진트리
//모든 노드가 최대 두개의 자식을 갖는 트리 = 모든 노드의 차수가 2이하
//모든 노드가 2개의 서브트리를 갖고있음
//정이진 트리(full,) = 자식노드가 0개거나 2개 둘중 하나인 이진트리, 리프노드는 자식이 없게됨
//포화 이진트리(perfect) = 모든 레벨에서 노드가 가득(자식이 모두 2개)인 이진트리, 높이가 h일시 노드 개수는 2^h-1개
//완전이진트리 (complete) = 마지막 레벨을 제외한 모든 노드는 자식이 가득 차있고 마지막 레벨의 노드들은 왼쪽부터 자식이 채워져 있을때

//이진트리 구현
//완전이진트리는 배열로 효율적으로 구현가능, 일반적으론 연결리스트 사용
/*
--------------------
|       data        |
|                   |
--------------------
|   left   |  right |
|          |        |
---------------------
*/

struct Node
{
    char data;
    Node* left;
    Node* right;

    Node(char d) : data(d), left(nullptr), right(nullptr) {}//생성자
};


//트리 순회
//정해진 순서에 따라 모든 노드를 한번씩 방문하는 방법
/*
1. 전위순회 재귀함수로 해야

2. 중위순회
3. 후위순회
깊이우선

4. 레벨 순서 순회 -너비우선
*/

//전위
void preorder(Node* root)
{
    if(root) //만약 현재 노드가 null이 아니면
    {
        std::cout << root->data << ", "; //현재노드 화면 출력
        preorder(root->left);
        preorder(root->right);
    }        
}

//중위순회
void inorder(Node* root)
{
    if(root)
    {
        inorder(root->left);
        std::cout << root->data << ", "; //현재노드 화면 출력
        inorder(root->right);
    }
}

//후위순회

void postorder(Node* root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        std::cout << root->data << ", "; //현재노드 화면 출력
    }
}


//레벨 순서 순회, 큐를 사용하여 구현
void levelorder(Node* root)
{
    std::queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        auto curr = q.front();
        q.pop();

        std::cout << curr->data << ", ";
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}

//이진트리 삭제
//삭제는 후위 순회 방식과 똑같이 해주면됨

void deleteNode(Node* root)
{
    if(root)
    {
        deleteNode(root->left);
        deleteNode(root->right);
        delete root;
    }
}

int main()
{
    Node* root = new Node('A');

    root->left = new Node('B');
    root->right = new Node('C');

    root->left->left = new Node('D');
    root->left->right = new Node('E');

    root->right->right = new Node('F');


    preorder(root);
    std::cout << std::endl;
    inorder(root);
    std::cout << std::endl;
    postorder(root);
    std::cout << std::endl;
    levelorder(root);
    //new로 만들어서 메모리 누수가 생김, delete를 나중에 해줘야함

    deleteNode(root);
}