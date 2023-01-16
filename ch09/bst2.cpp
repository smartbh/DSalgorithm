#include <iostream>

//이진탐색트리의 삭제
//자료의 삭제는 해당 노드를 삭제하고 BST 속성을 만족시킬수 있게 해당 노드를 다른 노드로 대체해야함
//1. 자식노드가 없다? : 그냥 삭제하고 링크 제거 (간편)
//2. 자식 노드가 하나 : 해당 노드를 삭제하고 해당노드의 부모 노드 포인터가 자식노드를 가리키게 바꿈
//3. 자식 노드가 두개 : 후속 노드** 값을 현재 노드에 복사하고 후속노드를 삭제한다.
//후속 노드 : 현재노드 다음으로 큰 수를 가진 자식노드 (현재노드의 오른쪽 서브트리 노드중 가장 작은 수)


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
            delete_all_tree(root);
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

        void erase(int value)
        {
            root = erase_impl(root, value);
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
        void delete_all_tree(Node* node)
        {
            if (node) {
                delete_all_tree(node->left);
                delete_all_tree(node->right);
                delete node;
            }
        }

        Node* erase_impl(Node* node, int value)
        {
            if(!node)
                return nullptr;
            if(value < node->data)
                node->left = erase_impl(node->left, value);
            else if(value > node->data)
                node->right = erase_impl(node->right, value);
            else
            {
                 if(node->left && node->right) //자식노드가 둘 다 있을경우
                 {
                    auto succ = successor(node);
                    node->data = succ->data;
                    node->right = erase_impl(node->right,succ->data);
                 }
                 else //자식노드가 하나거나 아예 없을경우
                 {
                    auto tmp = node->left ? node->left : node->right;
                    delete node;
                    return tmp;
                 }
            }

            return node;
        }

        Node* successor(Node* node)
        {
            auto curr = node->right;
            while(curr && curr->left)
                curr = curr->left;
            return curr;
        }
};

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

    bst.erase(4);
    bst.erase(5);
    bst.erase(14);

    bst.inorder(); std::cout<<std::endl;    

    bst.insert(15);
    bst.erase(10);
    bst.inorder(); std::cout<<std::endl;   
}