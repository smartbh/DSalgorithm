#include <iostream>

#define MAX_QUEUE 10

template <typename T>

class CircularQueue
{
public:
    CircularQueue(int sz = MAX_QUEUE) //생성자
    {
        arr = new T[sz];
        front_index = 0;
        rear_index = -1;
        count = 0;
        capacity  = sz;
    }

    ~CircularQueue(){ //소멸자
        delete [] arr;
    }

    void enqueue(const T& e){ //데이터 삽입
        if(full()){ //삽입시 꽉 찼는지 확인
            std::cout << "Overflow Error !!" << std::endl;
            return;
        }
        rear_index = (rear_index + 1 ) % capacity;
        arr[rear_index] = e;
        count++;
    }

    void dequeue(){
        if(empty()){
            std::cout << "Underflow Error !!" << std::endl;
            return;
        }

        front_index = (front_index + 1) % capacity;
        count--;
    }

    const T& front() const { return arr[front_index]; }
    bool empty() const { return count == 0; }
    int full() const { return count == capacity; }
    int size() const { return count; }

private:
    T* arr;
    int front_index;
    int rear_index;
    int capacity;
    int count;

};


using namespace std;

int main(){

    CircularQueue<int> q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.dequeue();
    q.dequeue();
    q.enqueue(60);
    q.enqueue(70);
    
    q.enqueue(80);

    while(!q.empty()){
        auto& e = q.front();
        cout << e << ", ";
        q.dequeue();
    }
    cout << endl;

}
