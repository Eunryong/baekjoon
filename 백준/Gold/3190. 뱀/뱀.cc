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

int N, K, L;
int arr[101][101];
int d = 0;
#define right 0
#define up 1
#define left 2
#define down 3 
list<pair<int, int> > li;
int ans = 1;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
bool check(int x, int y) {
    if (x < 1 || y < 1 || x > N || y > N)
        return false;
    for (int i = 0; i < li.size(); i++) {
        pair<int, int> p = li.front();
        if (p.first == x && p.second == y)
            return false;
        li.push_back(li.front());
        li.pop_front();
    }
    return true;
}

bool move() {
    int nx = li.front().first;
    int ny = li.front().second;
    if (!check(nx + dx[d], ny + dy[d])) {
        cout << ans;
        return false;
    }
    li.push_front({nx + dx[d], ny + dy[d]});
    if (!arr[nx + dx[d]][ny + dy[d]])
        li.pop_back();
    arr[nx + dx[d]][ny + dy[d]] = 0;
    ans++;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    cin >> K;
    for (int i = 1; i <= K; i++) {
        int x, y;
        cin >> x >> y;
        arr[x][y] = 1;
    }
    cin >> L;
    li.push_back({1, 1});
    queue<pair<int, char> > q;
    for (int i = 1; i <= L; i++) {
        int t;
        char c;
        cin >> t >> c;
        q.push({t, c});
    }
    while (1) {
        int t = -1;
        char c;
        if (!q.empty()) {
            t = q.front().first;
            c = q.front().second;
            q.pop();
        }
        if (t != -1) {
            while (1) {
                if (!move())
                    return 0;
                if (t + 1 == ans) break;
            }
            if (c == 'L') {
                d = (d + 1) % 4;
            } else if (c == 'D') {
                d = (4 + d - 1) % 4;
            }
        } else {
            while (1) {
                if (!move())
                    return 0;
            }
        }
    } 
    return 0;
}