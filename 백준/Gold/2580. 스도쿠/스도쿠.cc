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
int arr[9][9];
int S, e;
vector<pair<int, int> > v;
bool check(int x, int y, int n) {
    for (int i = 0; i < 9; i++) {
        if (arr[x][i] == n) return false;
    }
    for (int i = 0; i < 9; i++) {
        if (arr[i][y] == n) return false;
    }
    int R = x / 3 * 3;
    int C = y / 3 * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[R + i][C + j] == n) return false; 
        }
    }
    return true;
}

void solve(int n) {
    if (e) return;
    if (n == S) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << arr[i][j]<< " ";
            }
            cout << "\n";
        }
        e = 1;
        return;
    }
    int x = v[n].first;
    int y = v[n].second;
    for (int i = 1; i <= 9; i++) {
        if (check(x, y, i)) {
            arr[x][y] = i;
            solve(n + 1);
            arr[x][y] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> arr[i][j];
            if (!arr[i][j]) {
                S++;
                v.push_back({i, j});
            }
        }
    }
    solve(0);
    
    return 0;
}