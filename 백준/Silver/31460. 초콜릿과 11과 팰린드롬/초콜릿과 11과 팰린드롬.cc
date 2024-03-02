#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <cmath>
using namespace std;
int T;
int n;
int arr[10001];
bool e;

bool check() {
    int a = 0, b = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2) {
            a += arr[i];
        } else {
            b += arr[i];
        }
        if (i != n - 1)
            sum += arr[i];
    }
    if ((a - b) % 11 == 0) return true;
    return false;
}

void dfs(int s) {
    if (s >= (n + 1) / 2 || e) {
        if (!e && check()) {
            for (int i = 0; i < n; i++) {
                cout << arr[i];
            }
            cout << "\n";
            e = 1;
        }
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (s == 0 && i == 0) continue;
        arr[s] = i;
        arr[n - s - 1] = i;
        dfs(s + 1);
        if (e) return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        e = 0;
        cin >> n;
        if (n == 1) {
            cout << "0\n";
        } else {
            dfs(0);
            if (e == 0) cout << -1 << "\n";
            fill(arr, arr + 10001, 0);
        }
    }
    return 0;
}