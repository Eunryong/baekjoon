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

void solve(int size, int idx) {
    if (size == M) {
        for (int i = 0; i < M; i++) {
            cout << v[arr[i]] << " ";
        }
        cout << "\n";
        return ;
    }
    int tmp = 0;
    for (int i = idx; i < N; i++) {
        if (tmp == v[i]) continue;
        arr[size] = i;
        tmp = v[i];
        solve(size + 1, i + 1);
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
    solve(0, 0);
    return 0;
}