#include <iostream>

using namespace std;

int n;
int arr[1000002];
int tmp[1000002];

void merge(int st, int en) {
    int mid = (st + en) / 2;
    int lidx = st;
    int ridx = mid;

    for (int i = st; i < en; i++) {
        if (lidx == mid) tmp[i] = arr[ridx++];
        else if (ridx == en) tmp[i] = arr[lidx++];
        else if (arr[lidx] > arr[ridx]) tmp[i] = arr[ridx++];
        else tmp[i] = arr[lidx++];
    }

    for (int i = st; i < en; i++) arr[i] = tmp[i];
}

void merge_sort(int st, int en) {
    if (en == st + 1) return;
    int mid = (st + en) / 2;
    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st, en);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    
    merge_sort(0, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';

    return 0;
}