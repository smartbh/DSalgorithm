#include <iostream>

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

class DoubleLinkedList
{
private:
    int count;
    Node* header;
    Node* trailer;

public:
    DoubleLinkedList(){
        count = 0;
        header = new Node {0,NULL,NULL};
        trailer = new Node {0,NULL,NULL};
        header->next = trailer;
        trailer->prev = header;
    };
    ~DoubleLinkedList(){
        while(!empty()){
            pop_front();
        }

        delete header;
        delete trailer;
    }

    void insert(Node* p, int val){
        Node* new_node = new Node {val, p->prev, p }; //data, prev, next 순
        new_node->prev->next = new_node;
        new_node->next->prev = new_node;
        count++;
    }
    void erase(Node* p){
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        count--;
    }

    void push_front(int val){
        insert(header->next, val);
    }

    void push_back(int val){
        insert(trailer, val);
    }

    void pop_front(){
        if(!empty()){
            erase(header->next);
        }
    }
    void pop_back(){
        if(!empty()){
            erase(trailer->prev);
        }
    }

    void print_all(){
        Node* curr = header->next;

        while(curr != trailer){
            std::cout << curr->data << ", ";
            curr = curr->next;
        }

        std::cout << std::endl;
    }

    void print_reverse(){
        Node* curr = trailer->prev;
        while(curr != header){
            std::cout << curr->data << ", ";
            curr = curr->prev;
        }

        std::cout << std::endl;
    }

    bool empty(){
        return count == 0;
    }

    int size(){
        return count;
    }
};

int main(){
    DoubleLinkedList dl;

    dl.push_back(1);
    dl.push_back(2);
    dl.push_back(3);

    dl.print_all();
    dl.print_reverse();

    dl.pop_front();
    dl.pop_back();
    dl.print_all();
    dl.print_reverse();

    dl.push_front(100);
    dl.push_back(400);
    dl.print_all();
    dl.print_reverse();

}