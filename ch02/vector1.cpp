#include <iostream>
#include <vector>

//using namespace std;

int main(){

    //std::vector<int> v1(3,1);
    std::vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);

    std::vector<int> v2(10);//v2에 10개
    std::vector<int> v3(10,1);//v3에 10개 1로 초기화
    std::vector<int> v4 {10, 20, 30, 40, 50};

    //std::vector<int> v5 = v4; //v4를 v5에 복사
    std::vector<int> v5(v4); //둘다 같은 의미

    std::vector<int> v6(v4.begin(), v4.begin() + 3); //v4의 처음부터 3번째까지


    for(int i =0; i<v6.size(); i++){
        std::cout << v6[i] << std::endl;
    }


    //2차원 배열 벡터로 만들기
    std::vector<std::vector<int>> mat1(2, std::vector<int>(3)); //2x3 행렬

    std::vector<std::vector<int>> mat2{
        {1,2,3,},
        {4,5,6}
    }; //2x3 행렬
    
    for(int r = 0; r < mat2.size(); r++){
        for(int c= 0; c < mat2[r].size(); c++){
            std::cout << mat2[r][c] << ", ";
        }
        std::cout<<std::endl;
    }

}