// 힙은 완전이진트리의 한 형태, 힙 속성을 만족하는 자료구조, 이진 힙
// 힙속성 : 최대 힙속성, 최소 힙속성으로 나뉘어짐
// 최대 힙속성 : 부모노드의 키 값은 자식노드의 키 값보다 항상 크거나 같다.
// 최소 힙속성 : 부모노드의 키 값은 자식노드의 키 값보다 항상 작거나 같다.

//루트 노드는 항상 최대값이나 최소값을 가짐.
//힙은 배열이나 벡터로 구현

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MaxHeap
{
    private:
        vector<int> vec;

public:
	MaxHeap() : vec(1) {}

	void push(int value) //새로운 원소 넣기
	{
		vec.push_back(value);
		heapify_up(vec.size() - 1); //힙 조건을 만족하는지 확인
	}

	void pop()
	{
		vec[1] = vec.back();
		vec.pop_back();
		heapify_down(1);
	}

	int top() const { return vec[1]; }

	void clear() { vec.clear(); vec.push_back(0); }
	int size() { return vec.size() - 1; }
	bool empty() { return vec.size() == 1; }

	void print()
	{
		for (auto n : vec)
			cout << n << ", ";
		cout << endl;
	}

private:
	int parent(int i) { return i / 2; } //부모 노드 인덱스 가리키는함수
	int left(int i) { return 2 * i; } //왼쪽 노드 인덱스 가리키는함수
	int right(int i) { return 2 * i + 1; }//오른쪽 노드 인덱스 가리키는함수

	void heapify_up(int i) //새 원소 삽입시 마지막 노드부터 위로 올라가면서 힙속성 만족시키도록 조정하는 함수
	{
		if (i > 1 && vec[i] > vec[parent(i)]) {
			swap(vec[i], vec[parent(i)]);
			heapify_up(parent(i));
		}
	}

	void heapify_down(int i) //루트노드에서 시작해서 아래로 내려가면서 힙속성을 만족시키도록 조정하는 함수
	{
		int largest = i;

		if (left(i) < vec.size() && vec[left(i)] > vec[largest]) {
			largest = left(i);
		}

		if (right(i) < vec.size() && vec[right(i)] > vec[largest]) {
			largest = right(i);
		}

		if (largest != i) {
			swap(vec[i], vec[largest]);
			heapify_down(largest);
		}
	}
};

int main()
{
    MaxHeap heap;
	heap.push(10);
	heap.push(5);
	heap.push(15);
	heap.push(7);
	heap.push(3);
	heap.push(9);
	heap.push(14);
	heap.push(8);
	heap.push(2);
	heap.push(4);
	heap.print();

	while (!heap.empty()) {
		cout << heap.top() << ", ";
		heap.pop();
	}
	cout << endl;

    return 0;
}
