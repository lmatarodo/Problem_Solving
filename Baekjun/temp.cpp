#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<string> v;

bool cmp(string& A, string& B) {

  if (A.length() != B.length()) {
    return A.length() < B.length();
  }

  int Acnt = 0;
  int Bcnt = 0;
  for (int i = 0; i < A.length(); i++) {
    if (isdigit(A[i])) Acnt += A[i] - '0';
    if (isdigit(B[i])) Bcnt += B[i] - '0';
  }

  if (Acnt != Bcnt) return Acnt < Bcnt;

  return A < B; // 시전 순 정렬?

}

int main() {

  cin >> n;

  for (int i = 0; i < n; i++) {
    string ipt; cin >> ipt;
    v.push_back(ipt);
  }

  sort(v.begin(), v.end(), cmp);

  for (int i = 0; i < n; i++) 
    cout << v[i] << "\n";
  

  return 0;
}