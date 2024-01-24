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
int arr[1000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    fill_n(arr, 1000, 1);
    for (int i = 0; i < N; i++) {
        int tmp, S, B;
        cin >> tmp >> S >> B;
        string s = to_string(tmp);
        for (int j = 100; j < 1000; j++) {
            if (!arr[j])
                continue;
            string e = to_string(j);
            int st = 0, ba = 0;
            if (e[0] == '0' || e[1] == '0' || e[2] == '0') {
                arr[j] = 0;
                continue;
            }
            if (e[0] == e[1] || e[0] == e[2] || e[1] == e[2]) {
                arr[j] = 0;
                continue;
            }
            for (int k = 0; k < 3; k++) {
                if (s[k] == e[k]) {
                    st++;
                } else if (s[k] != e[k] && s.find(e[k]) != string::npos) {
                    ba++;
                }
            }
            if (st != S || ba != B) {
                arr[j] = 0;
            }
        }
    }
    int ans = 0;
    for (int i = 100; i < 1000; i++) {
        if (arr[i])
            ans ++;
    }
    cout << ans;
    return 0;
}