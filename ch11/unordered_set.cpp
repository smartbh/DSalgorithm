#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set<string> words;
    words.insert("car");
    words.insert("radio");
    words.insert("orange");
    words.insert("ear");
    
    string word = "radio";

    if(words.find(word) != words.end())
        cout << word << " is found! " << endl;
    else
        cout << word << " is not found! " << endl;
    
    vector<int> numbers {1,5,3,1,5,7,4,5,6,3,2,7,3,6,2};
    unordered_set<int> num_set(numbers.begin(), numbers.end()); 
    //생성자 중에 반복자를 받아서 생성하는 방법이 있음(반복문으로 다 안넣어도 됨)
    //std set과는 달리 정렬되지 않고 들어오는 순서대로 들어옴
    //이 방법은 중복되지 않은 수만 들어감
    //중복된 수도 넣고 싶으면 unordered_multiset을 써야함
    //set말고 map도 unordered_map을 사용 가능하며 전반적인 방식은 set과 같음

    return 0;
}