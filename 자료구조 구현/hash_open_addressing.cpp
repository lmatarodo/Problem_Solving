#include <bits/stdc++.h>
using namespace std;

const int M = 1000003;
const int a = 1000;
const int EMPTY = -1;
const int OCCUPY = 0;
const int DUMMY = 1;
int status[M]; // EMPTY / OCCUPY / DUMMY, 각 
string key[M];
int val[M];

int my_hash(string& s){
  int h = 0;
  for(auto x : s)
    h = (h * a + x) % M;
  return h;
}

// key[idx] == k인 idx를 반환, 만약 k가 존재하지 않을 경우 -1을 반환
// key에 대응되는 value를 반환하는게 아니라 인덱스를 반환함에 주의
int find(string k){
    int idx = my_hash(k); // 클러스터의 시작 주소를 해시 값으로 찾음
    while (status[idx] != EMPTY) { // 빈 칸이 나올 때까지 탐색을 이어나감
        if (status[idx] == OCCUPY && key[idx] == k) return idx;
        // 만약 해당 칸이 점유 상태이고 키 값이 우리가 찾는 키 값이라면 해당 인덱스를 반환
        // 나중에 erase 구현 시에 status만 DUMMY로 바꿀 예정이므로 꼭 점유 상태인지 확인해야함 
        idx = (idx + 1) % M; // 다음 인덱스 값으로 이동
    }
    return -1; // 탐색을 끝낸 후에 찾지 못했다면 -1 반환
}

void insert(string k, int v){
    int idx = find(k); // find 함수로 해시 테이블에 이미 해당 키를 가진 원소가 있었는지 탐색
    if (idx != -1) { // 만약 해당 키를 가진 원소가 잇었다면
        val[idx] = v; // 값만 바꿔주고 함수 종료
        return;
    }
    idx = my_hash(k); // 해당 원소의 해시 값으로 이동
    // 새로운 원소를 넣을 곳은 상태가 EMPTY이거나 DUMMY이면 됨
    while (status[idx] == OCCUPY) // 따라서 상태가 점유일 때 동안 다음 칸으로 계속 이동
        idx = (idx + 1) % M;
    key[idx] = k; // 빈 칸이 나오면
    val[idx] = v; // 해당 칸에 키와 값을 채워줌
    status[idx] = OCCUPY; // 해당 칸의 상태를 점유로 변경
}

void erase(string k){
    int idx = find(k); // find 함수로 삭제할 원소가 있는지 검색
    if (idx != -1) status[idx] = DUMMY; 
    // 만약 삭제할 원소가 해시테이블 안에 있었다면 해당 칸을 DUMMY로 만듬
}

void test(){
  insert("orange", 724); // ("orange", 724)
  insert("melon", 20); // ("orange", 724), ("melon", 20)
  assert(val[find("melon")] == 20);
  insert("banana", 52); // ("orange", 724), ("melon", 20), ("banana", 52)
  insert("cherry", 27); // ("orange", 724), ("melon", 20), ("banana", 52), ("cherry", 27)
  insert("orange", 100); // ("orange", 100), ("melon", 20), ("banana", 52), ("cherry", 27)
  assert(val[find("banana")] == 52);
  assert(val[find("orange")] == 100);
  erase("wrong_fruit"); // ("orange", 100), ("melon", 20), ("banana", 52), ("cherry", 27)
  erase("orange"); // ("melon", 20), ("banana", 52), ("cherry", 27)
  assert(find("orange") == -1);
  erase("orange"); // ("melon", 20), ("banana", 52), ("cherry", 27)
  insert("orange", 15); // ("melon", 20), ("banana", 52), ("cherry", 27), ("orange", 15)
  assert(val[find("orange")] == 15);
  insert("apple", 36); // ("melon", 20), ("banana", 52), ("cherry", 27), ("orange", 15), ("apple", 36)
  insert("lemon", 6); // ("melon", 20), ("banana", 52), ("cherry", 27), ("orange", 15), ("apple", 36), ("lemon", 6)
  insert("orange", 701);  // ("melon", 20), ("banana", 52), ("cherry", 27), ("orange", 701), ("apple", 36), ("lemon", 6)
  assert(val[find("cherry")] == 27);
  erase("xxxxxxx");
  assert(find("xxxxxxx") == -1);
  assert(val[find("apple")] == 36);
  assert(val[find("melon")] == 20);
  assert(val[find("banana")] == 52);
  assert(val[find("cherry")] == 27);
  assert(val[find("orange")] == 701);
  assert(val[find("lemon")] == 6);  
  cout << "good!\n";  
}

int main(){
  fill(status, status+M, EMPTY);
  test();
}