#include <iostream>
#include <algorithm>
using namespace std;

int heap[100005];
int sz = 0; // heap에 들어있는 원소의 수

void push(int x){
    heap[++sz] = x; // 힙에 들어있는 원소의 수를 증가시킨 후 원소를 삽입
    int idx = sz;
    while (idx != 1) { // 새로 삽입한 원소가 루트 노드로 갈 때까지
        if (heap[idx] >= heap[idx / 2]) break; // 부모가 더 작거나 같으면 만족하므로 종료
        swap(heap[idx], heap[idx / 2]); // 두 원소를 바꿈
        idx /= 2;
    }
}

int top(){
    return heap[1];
}

void pop(){
    heap[1] = heap[sz--];
    int idx = 1;
    while (2 * idx <= sz) { // 왼쪽 자식이 있는 동안 반복
        int left = 2 * idx; int right = 2 * idx + 1;
        int min_child = left; // 일단 왼쪽 자식을 제일 작다고 가정

        if (right <= sz && heap[right] < heap[left]) 
            min_child = right; // 만약 오른쪽 자식이 존재하고 더 작다면 교체 대상 변경

        // 부모가 자식들 중 최솟값보다 작거나 같다면 힙 성질 만족, 중단
        if (heap[idx] <= heap[min_child]) break;
        
        // 아니라면 부모와 최솟값 자식을 교체
        swap(heap[idx], heap[min_child]);
        idx = min_child; // 인덱스를 자식 위치로 갱신
    }
}

void test(){
  push(10); push(2); push(5); push(9); // {10, 2, 5, 9}
  cout << top() << '\n'; // 2
  pop(); // {10, 5, 9}
  pop(); // {10, 9}
  cout << top() << '\n'; // 9
  push(5); push(15); // {10, 9, 5, 15}
  cout << top() << '\n'; // 5
  pop(); // {10, 9, 15}
  cout << top() << '\n'; // 9
}

int main(){
  test();
}