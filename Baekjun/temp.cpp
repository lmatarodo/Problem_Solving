#include <unordered_set> // 헤더 포함

void unordered_multiset_example() {
  unordered_multiset<int> ms; // 선언
  ms.insert(-10); ms.insert(100); ms.insert(15); // 삽입, {-10, 100, 15}
  ms.insert(-10); ms.insert(15); // 원소의 중복이 허용 {-10, -10, 100, 15, 15}
  cout << ms.size() << '\n'; // 5 출력
  for (auto e : ms) cout << e << '\n'; // range-based for loop를 통해 값 출력 가능
  cout << ms.erase(15) << '\n'; // 안에 들어있는 15가 모두 지워짐, {-10, -10, 100}, 지워진 갯수인 2 반환
  ms.erase(ms.find(-10)); // 하나만 지우고 싶을때, { -10, 100}
  ms.insert(100); // {-10, 100, 100}
  cout << ms.count(100)<< '\n' 
  cout << s.erase(100) << '\n'; // erase의 인자로 넘겨준 값이 안에 들어있다면 1 반환 -> s = {-10, 15}
  cout << s.erase(20) << '\n'; // 만약 들어있지 않다면 0 반환
  if (s.find(15) != s.end()) cout << "15 in s\n"; // 값을 찾고 만약 없다면 s.end(반환)
  else cout << "15 not in s\n";
  cout << s.size() << '\n' // 2 출력
  cout << s.count(50) << '\n' // 0 출력 , 값이 들어있을 경우 1 출력
  for (auto e : s) cout << e << '\n'; // range-based for loop를 통해 값 출력 가능
}