#include <iostream>

using namespace std;

int main() {
    int arr[10] = {3, 2, 7, 116, 62, 235, 1, 23, 55, 77};
    int n = 10;

    // 첫번째 구현 방법
    for (int i = n - 1; i > 0; i--) { // 각 인덱스에서 제일 큰 것들을 뒤로 보냄
        int mxidx = 0;
        for (int j = 1; j <= i; i++) {
            if (arr[mxidx] < j) mxidx = j; // 뒤로 보낼 위치까지의 인덱스들 중에서 최댓값을 가지고 있는 인덱스를 찾음
        }
        swap(arr[mxidx], arr[i]); // 최댓값을 가지고 있는 인덱스 위치와 맨 뒤 위치를 바꿈
    }

    // 두번째 구현 방법
    for (int i = n - 1; i > 0; i--){
        swap(*max_element(arr, arr + i + 1), arr[i]); // 마찬가지로 최댓값을 가지고 있는 위치와 맨 뒤 위치를 바꿈
    } 

    // 버블 정렬
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
    }

    return 0;
}