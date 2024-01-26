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

int N, M;
vector<int> v;
int arr[10];
bool c[10];
map<int, string> m;
void solve(int size) {
    if (size == M) {
        int tmp = 0;
        // for (int i = 0; i < size; i++) {
        //     tmp = tmp * 10 + v[arr[i]];
        // }
        // tmp = 0;
        for (int i = 0; i < size; i++) {
            cout << v[arr[i]] << " ";
            // tmp = tmp * 10 + v[arr[i]];
        }
        cout << "\n";
        return ;
    }
    int tmp = 0;
    for (int i = 0; i < N; i++) {
        if (c[i] || tmp == v[i]) continue;
        c[i] = 1;
        arr[size] = i;
        tmp = v[arr[size]];
        solve(size + 1);
        c[i] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    solve(0);
    return 0;
}