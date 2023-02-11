#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>

//해싱이란
//키를 함수에 넣어서 계산한후 나온 결과를 주소로 활용하여 값에 접근할수있게 하는 방법
//보안 분야에서 사용되거나 자료구조에서 저장된 정보를 보다 빠르게 검색하기위해 해시테이블을 만드는 방식

class hash_set
{
    private:
        int sz;  
        std::vector<std::list<int>> data;
        //만약 리스트가 아니라 key, value를 쌍으로 갖는 해시=맵 구조로 만들고싶으면
        //std::pair를 사용하면된다.
        // ex) 
        //std::vector<std::list<std::pair<std::string, int>>> data;
        //이 방식이 hash map 구조, 현재는 hash_set 구조
    public:
        hash_set(int n) : sz(n), data(sz) {} //생성자
        int hash(int key) {return key % sz;} //키를 해시값으로 변경하는 내용, 이번 해시함수는 키값을 사이즈만큼 나누는것
        

        void insert(int value) {data[hash(value)].push_back(value);} 
        //bool find(int value) { return (data[hash(value)] == value);} 
        bool find(int value) 
        {
            auto& entries = data[hash(value)];
            return std::find(entries.begin(), entries.end(), value) != entries.end();
        }
        //void erase(int value) {data[hash(value)] = -1;}
        void erase(int value)
        {
            auto& entries = data[hash(value)];
            auto it = std::find(entries.begin(), entries.end(), value);
            if(it != entries.end())
                entries.erase(it);
        }

        void print()
        {
            for(int i = 0; i<sz; i++)
            {
                std::cout << i << " : ";
                for(auto n : data[i])
                {
                    std::cout << n << ", ";
                }
                std::cout << std::endl;
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
    num_set.insert(200); // 4
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

    value = 300;

    if(num_set.find(value))
        std::cout << value << " is found!" << std::endl;
    else
        std::cout << value << " is not found!" << std::endl;

    num_set.print();

    return 0;
}