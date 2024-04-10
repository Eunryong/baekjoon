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
int N;
int arr[5][5];
int res[5][5];
int tmp[5][5];
long long B;

void multiply(int tmp2[5][5]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            long long sum = 0;
            for (int k = 0; k < N; k++) {
                sum += res[i][k] * tmp2[k][j];
                sum %= 1000;
            }
            tmp[i][j] = sum;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            res[i][j] = tmp[i][j];
        }
    }
}

void solve(long long cnt) {
    if (cnt > 1) {
        if (cnt % 2) {
            solve(cnt / 2);
            multiply(res);
            solve(1);
        } else {
            solve(cnt / 2);
            multiply(res);
        }
    } else if (cnt == 1) {
        multiply(arr);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> B;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
        res[i][i] = 1;
    }
    solve(B);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}