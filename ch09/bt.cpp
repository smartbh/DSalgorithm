#include <iostream>

//이진탐색 트리
//모든 노드 N(서브 포함)의 키(데이터, key)값이 왼쪽은 N보다 작고, 오른쪽은 N보다 큰 값을 가진 노드들로
//정렬된 상태인 트리구조
/*
이진탐색트리는 탐색, 삽입, 삭제가 모두  O(log n)의 시간 복잡도를 가짐(효율적)
이진 탐색트리를 중위순회하면 오름차순으로 정렬할수있음




*/

//노드 구조체 짜기
struct Node
{
    int data;
    Node* left;
    Node* right;

    //구조체 생성자 만들어주기
    Node(int d) : data(d), 
        left(nullptr),right(nullptr){}
};

class BinarySearchTree
{
    private:
        Node* root = nullptr;
    public:
        ~BinarySearchTree()
        {
            delete_tree(root);
        };

        Node* find(int value)
        {
            return find_impl(root,value); //루트노드부터 시작
        }

        void insert(int value)
        {
             if(!root) //루트 노드가 비어있을시 바로 하나 생성
                root = new Node(value); //Node 구조체 생성자
             else//비어있지 않을시 다음 노드로 넘어가서 실행
                insert_impl(root, value);
        }

        void inorder()
        {
            inorder_impl(root);
        }
    
    private:
        void insert_impl(Node* curr, int value)
        {
            //좌, 우 노드가 될지 밸류값이랑 현재 노드 데이터 값으로 비교 하며 해야함
            if(value < curr->data) //들어갈 값이 현재 노드의 값보다 작을시 왼쪽으로
                if(!curr->left) //만약 노드의 왼쪽 노드가 없을시
                    curr->left = new Node(value); //왼쪽 자식 노드에 새로 만들어짐
                else //만약 왼쪽 자식 노드가 있을시
                    insert_impl(curr->left, value);// 재귀로 또 한번 더해줌
            else
                if(!curr->right)
                    curr->right = new Node(value);
                else
                    insert_impl(curr->right, value);// 재귀로 또 한번 더해줌
        }

        Node* find_impl(Node* curr, int value)
        {
            if(curr == nullptr) //현재 노드가 없다?
                return nullptr; //작업종료.

            if(value == curr->data) //만약 현재노드의 값이 바로 찾는값과 같으면
                return curr; //현재 노드 반환
            else //찾는 값과 다를시
            {
                if(value < curr->data) 
                    return find_impl(curr->left, value);
                else
                    return find_impl(curr->right, value);
            }
        }
        void inorder_impl(Node* root)
        {
            if(root != nullptr)
            {
                inorder_impl(root->left);
                std::cout << root->data << ", ";
                inorder_impl(root->right);
            }
        }
        void delete_tree(Node* node)
        {
            if (node) {
                delete_tree(node->left);
                delete_tree(node->right);
                delete node;
            }
        }
};

//이진탐색트리 클래스 짜기


int main()
{
    BinarySearchTree bst;
    bst.insert(10);     bst.insert(14);
    bst.insert(5);     bst.insert(7);
    bst.insert(18);     bst.insert(4);
    bst.insert(6);     bst.insert(20);
    bst.insert(16);

    bst.inorder(); std::cout << std::endl;

    if (bst.find(7)) std::cout << "7 찾음" << std::endl;
    else    std::cout<< "7 없음" << std::endl;

    if (bst.find(15)) std::cout << "15 찾음" << std::endl;
    else    std::cout<< "15 없음" << std::endl;

    return 0;   
}