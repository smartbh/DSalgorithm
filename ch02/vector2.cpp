#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> vec1{1,2,3,4};

    cout << vec1.capacity() << ":" << vec1.size() << endl;
    
    vec1.push_back(5);

    cout << vec1.capacity() << ":" << vec1.size() << endl;

    vec1.push_back(6);

    cout << vec1.capacity() << ":" << vec1.size() << endl;

    vec1.insert(vec1.begin(), 0);

    cout << vec1.capacity() << ":" << vec1.size() << endl;

    for(int i = 0; i< vec1.size(); i++){
        cout << vec1[i] << ", ";
    }

    cout<<endl; //7

    vec1.push_back(8); //8

    vec1.push_back(9); // 9

    for(int i = 0; i< vec1.size(); i++){
        cout << vec1[i] << ", ";
    }

    cout << vec1.capacity() << ":" << vec1.size() << endl;

    vec1.erase(vec1.begin()+1, vec1.begin()+3);

    cout << vec1.capacity() << ":" << vec1.size() << endl;

    for(int i = 0; i< vec1.size(); i++){
        cout << vec1[i] << ", ";
    }

    cout<<endl;

    //capacity는 한번 늘어날때 기본적으로 2배늘어남
    //
}