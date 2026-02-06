#include <iostream>
#include <list>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void insert(int addr, int num){
    dat[unused] = num; // 새롭게 추가되는 원소의 데이터 값을 채워넣음
    pre[unused] = addr; // 새 원소의 이전 원소를 추가되는 위치로 변경
    nxt[unused] = nxt[addr]; // 새 원소의 다음 원소를 추가되는 위치의 다음 원소로 변경
    if (nxt[unused] != -1) pre[nxt[unused]] = unused; // 만약 추가되는 위치의 다음 원소가 있었다면, 추가되는 위치의 다음 원소가 가리키는 이전 원소를 새 원소로 변경
    nxt[addr] = unused; // 추가되는 위치의 다음 원소를 새 원소로 변경
    unused++;
}

void erase(int addr){   
    nxt[pre[addr]] = nxt[addr]; // 삭제할 위치의 이전 원소가 가리키고 있는 다음 원소를 삭제할 원소의 다음의 원소로 변경
    if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr]; 
    // 삭제할 위치가 가리키고 있는 다음원소가 있었다면, 그 다음 원소의 이전 원소를 삭제되는 원소 이전 원소로 변경
}

void traverse(){
  int cur = nxt[0];
  while(cur != -1){
    cout << dat[cur] << ' ';
    cur = nxt[cur];
  }
  cout << "\n\n";
}

void insert_test(){
  cout << "****** insert_test *****\n";
  insert(0, 10); // 10(address=1)
  traverse();
  insert(0, 30); // 30(address=2) 10
  traverse();
  insert(2, 40); // 30 40(address=3) 10
  traverse();
  insert(1, 20); // 30 40 10 20(address=4)
  traverse();
  insert(4, 70); // 30 40 10 20 70(address=5)
  traverse();
}

void erase_test(){
  cout << "****** erase_test *****\n";
  erase(1); // 30 40 20 70
  traverse();
  erase(2); // 40 20 70
  traverse();
  erase(4); // 40 70
  traverse();
  erase(5); // 40
  traverse();
}

int main(void) {
  fill(pre, pre+MX, -1);
  fill(nxt, nxt+MX, -1);
  insert_test();
  erase_test();

  list<int> L = {1,2};
  auto t = L.begin();
  L.push_front(10);
  cout << *t << "\n";
  L.push_back(5);
  L.insert(t, 6);
  t++;
  t = L.erase(t);

  cout << *t << "\n";
  for(auto i: L) cout << i << " ";
  cout << "\n";
  for (auto it = L.begin(); it != L.end(); it++) {
    cout << *it << ' ';
  }

}