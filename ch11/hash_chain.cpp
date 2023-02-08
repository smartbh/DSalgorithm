#include <iostream>
#include <vector>
#include <list>

//해싱이란
//키를 함수에 넣어서 계산한후 나온 결과를 주소로 활용하여 값에 접근할수있게 하는 방법
//보안 분야에서 사용되거나 자료구조에서 저장된 정보를 보다 빠르게 검색하기위해 해시테이블을 만드는 방식

class hash_set
{
    private:
        int sz;  
        std::vector<int> data;
    public:
        hash_set(int n) : sz(n), data(sz, -1) {}
        int hash(int key) {return key % sz;} //키를 해시값으로 변경하는 내용, 이번 해시함수는 키값을 사이즈만큼 나누는것

        void insert(int value) {data[hash(value)] = value;} 
        bool find(int value) { return (data[hash(value)] == value);}
        void erase(int value) {data[hash(value)] = -1;}

        void print()
        {
            for(auto n : data)
            {
                std::cout << n << " ,";
            }
            std::cout << std::endl;
        }
};

int main()
{
    hash_set num_set(7);

    num_set.insert(10); //3
    num_set.insert(100); // 2
    num_set.insert(15); // 1
    num_set.insert(20); // 6
    num_set.insert(999); // 5
    num_set.insert(300); // 6, 20을 300이 덮어씌워 버렸다. << 충돌현상
    //충돌 현상을 해결하기 위해서 체이닝, 오픈 어드레싱 같은 방법을 사용한다.

    /*
    체이닝 : 해시 테이블의 특정 위치에서 하나의 키를 저장하는것이 아닌, 하나의 연결리스트를 저장하는 방식
            개별 체이닝(separate chaining)이란 기법.
            각각의 인덱스가 하나의 정수값을 가지는게 아닌 연결리스트의 시작지점이 됨 벡터나 배열내에 연결리스트가 들어가는것
    
    */


    int value = 10;

    if(num_set.find(value))
        std::cout << value << " is found!" << std::endl;
    else
        std::cout << value << " is not found!" << std::endl;

    value = 200;

    if(num_set.find(value))
        std::cout << value << " is found!" << std::endl;
    else
        std::cout << value << " is not found!" << std::endl;

    num_set.print();

    return 0;
}