#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[5001];
    long ans = 3000000001;
    int idx1, idx2, idx3;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            long sum = arr[i] + arr[j];
            int st = j + 1;
            int en = n - 1;
            while (st < en) {
                int mid = (st + en) / 2;
                if (abs(sum + arr[mid]) < ans) {
                    ans = abs(sum + arr[mid]);
                    idx1 = i;
                    idx2 = j;
                    idx3 = mid;
                }
                if (sum + arr[mid] <= 0) st = mid + 1;
                else en = mid;
            }
            if (abs(sum + arr[st]) < ans) {
                    ans = abs(sum + arr[st]);
                    idx1 = i;
                    idx2 = j;
                    idx3 = st;
            }
        }
    }
    cout << arr[idx1] << " " << arr[idx2] << " " << arr[idx3];
}
