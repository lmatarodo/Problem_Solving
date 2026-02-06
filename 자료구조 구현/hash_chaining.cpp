#include <iostream>
using namespace std;

const int M = 1000003;
const int a = 1000;

const int MX = 500005; // 최대 삽입 횟수
int head[M]; // 각 M개의 연결리스트에 대해 시작 주소를 의미
int pre[MX];
int nxt[MX];
string key[MX];
int val[MX];
int unused = 0; // 새 원소를 추가할 인덱스를 나타내기 위한 변수

int my_hash(string& s){
  int h = 0;
  for(auto x : s)
    h = (h * a + x) % M;
  return h;
}

// key[idx] == k인 idx를 반환, 만약 k가 존재하지 않을 경우 -1을 반환
// key에 대응되는 value를 반환하는게 아니라 인덱스를 반환함에 주의
int find(string k){
    int hashIndex = my_hash(k); // 우선 해당하는 문자열이 어느 해시 테이블 인덱스에 위치하는지 추적
    int idx = head[hashIndex]; // 해당 해시 테이블의 시작주소
    while (idx != -1) { // idx가 리스트의 끝이 아닐때, 즉 -1이 아닐 때까지 반복
        if (key[idx] == k) return idx; // 만약 해당하는 키 값을 찾았으면 해당 인덱스를 반환
        idx = nxt[idx]; // 해시 테이블의 다음 원소로 이동
    }
    return -1;
}

void insert(string k, int v){
    int idx = find(k); // 먼저 해당 키가 이미 해시 테이블에 존재하는지 확인
    if (idx != -1) { // 민액 이미 해시 테이블에 존재했다면,
        val[idx] = v; // 해당 인덱스에서의 값만 교체하고
        return; // 함수를 종료한다.
    }
    int h = my_hash(k);
    key[unused] = k;
    val[unused] = v; // 아직 사용되지 않은 인덱스 번호의 키, 값에 적절한 값들을 채워넣는다.
    if (head[h] != 1) { // 만약 기존에 해시 테이블에 원소가 있었다면,
        pre[head[h]] = unused; // 기존 해시 테이블 시작 원소의 이전 원소를 새 원소로 변경
        nxt[unused] = head[h]; // 새 원소의 다음 원소를 원래의 시작 원소로 변경
    }
    head[h] = unused; // 해당 해시 테이블의 시작 주소를 새 원소의 인덱스로 변경
    unused++; // 새 원소를 추가할 인덱스 증가
}

void erase(string k){
    int idx = find(k); // 삭제할 키가 들어있는 원소
    if (idx == -1) return; // 만약 해시 테이블에 해당 키를 가지고 있는 원소가 없으면 함수 종료
    if (nxt[idx] != -1) pre[nxt[idx]] = pre[idx]; 
    // 만약 삭제할 원소의 다음 원소가 있었다면 다음 원소의 이전 원소를 삭제할 원소의 이전 원소로 변경
    if (pre[idx] != -1) nxt[pre[idx]] = nxt[idx];
    // 만약 삭제할 원소의 이전 원소가 있었다면 이전원소의 다음 원소를 삭제할 원소의 다음 원소로 변경
    int h = my_hash(k); 
    if (head[h] == idx) head[h] = nxt[idx];
     // 만약 삭제하는 위치가 해시 테이블의 시작 주소였다면, 해당 해시 테이블의 시작 주소를 삭제하는 원소의 다음 원소로 변경해주어야함
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
  fill(head, head+M, -1);
  fill(pre, pre+MX, -1);
  fill(nxt, nxt+MX, -1);
  test();
}