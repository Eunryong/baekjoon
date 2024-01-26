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
void solve(int idx) {
    if (idx == M) {
        for (int i = 0; i < M; i++) {
            cout << v[arr[i] - 1] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i <= N; i++) {
        arr[idx] = i;
        solve(idx + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    solve(0);
    return 0;
}