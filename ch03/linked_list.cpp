#include <iostream>

struct Node{
    int data;
    Node* next;
};

class LinkedList{
    private:
        Node* head;
    
    public:
        LinkedList() : head(NULL){};

        ~LinkedList(){
            while(!empty()){
                pop_front();
            }
        }

        void push_front(int val){
            Node* new_node = new Node{val, NULL};
            
            if(head != NULL)
                new_node->next = head;

            head = new_node;        
        }

        void pop_front(){
            if(head == NULL)
                return;
            
            Node* first = head;
            head = head->next;
            delete first;
        }

        void print_all(){
            Node* curr = head;

            while(curr != NULL){
                std::cout << curr->data << ", ";
                curr = curr->next;
            }

            std::cout << std::endl;
        }

        bool empty(){
            return head == NULL;
        }

};

int main(){
    LinkedList ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.print_all();

    ll.pop_front();
    ll.print_all();

    ll.push_front(4);
    ll.print_all();

}