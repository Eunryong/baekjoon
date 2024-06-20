#include <iostream>
#include <limits.h>
using namespace std;
int arr[100001];
int main() {
    int n;
    int ans = INT_MAX, idx1 = -1, idx2 = -1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int st = i + 1;
        int en = n - 1;
        int cur = INT_MAX;
        while (st < en) {
            int mid = (st + en) / 2;
            if (abs(arr[i] + arr[mid]) < ans) {
                ans = abs(arr[i] + arr[mid]);
                idx1 = i;
                idx2 = mid;
            }
            if (abs(arr[i] + arr[mid]) < cur) {
                if (arr[i] + arr[mid] < 0) {
                    st = mid + 1;
                } else {
                    en = mid;
                }
            } else {
                st = mid;
                break;
            }
        }
        if (abs(arr[st] + arr[i]) < ans) {
            ans = abs(arr[st] + arr[i]);
            idx1 = i;
            idx2 = st;
        }
    }
    cout << arr[idx1] << " " << arr[idx2];
}