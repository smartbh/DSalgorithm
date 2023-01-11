#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node* prev;
    Node* next;
};


template <typename T>
class DoubleLinkedList
{
private:
    T count;
    Node<T>* header;
    Node<T>* trailer;

public:
    class iterator
    {
        private:
            Node<T>* ptr;
        
        public:
            iterator() : ptr(NULL) {}
            iterator(Node<T>* p) : ptr(p) {}

            T& operator*() { return ptr->data; }

            iterator& operator++() {  ptr = ptr->next; return *this;  } //++it
            iterator& operator--() {  ptr = ptr->prev; return *this;  } //--it

            bool operator==(const iterator& it) const{  return ptr == it.ptr;  }
            bool operator!=(const iterator& it) const{  return ptr != it.ptr;  }

            friend class DoubleLinkedList;
    };

    DoubleLinkedList(){
        count = 0;
        header = new Node<T> {T(),NULL,NULL};
        trailer = new Node<T> {T(),NULL,NULL};
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

    iterator begin() const
    {
        return iterator(header->next);
    }

    iterator end() const
    {
        return iterator(trailer);
    }

    void insert(const iterator& pos, const T& val){
        Node<T>* p = pos.ptr;
        Node<T>* new_node = new Node<T> {val, p->prev, p }; //data, prev, next 순
        new_node->prev->next = new_node;
        new_node->next->prev = new_node;
        count++;
    }
    void erase(const iterator& pos){
        Node<T>* p = pos.ptr;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        count--;
    }

    void push_front(const T& val){
        insert(begin(), val);
    }

    void push_back(const T& val){
        insert(end(), val);
    }

    void pop_front(){
        if(!empty()){
            erase(begin());
        }
    }
    void pop_back(){
        if(!empty()){
            erase(--end());
        }
    }

    void print_all(){
        Node<T>* curr = header->next;

        while(curr != trailer){
            std::cout << curr->data << ", ";
            curr = curr->next;
        }

        std::cout << std::endl;
    }

    void print_reverse(){
        Node<T>* curr = trailer->prev;
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

    iterator find(const T& val){
        Node<T>* curr = header->next;
        while(curr->data != val && curr != trailer)
        {
            curr = curr->next;
        }

        return iterator(curr);
    }
};

int main(){
    DoubleLinkedList<int> dl;

    dl.push_back(1);
    dl.push_back(2);
    dl.push_back(3);

    //dl.print_all();
    //dl.print_reverse();

    auto it = dl.find(2);
    if(it != dl.end())
    {
        dl.insert(it, 5);
    }

    for ( auto n : dl)
    {
        std::cout << n << ", ";
    }

    std::cout << std::endl;

}