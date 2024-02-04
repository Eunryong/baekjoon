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
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
using namespace std;
int N, ans;
int vis[16];
void nQueen(int size) {
    if (size > N) {
        ans++;
        return;
    }
    for (int i = 1; i <= N; i++) {
        bool c = 0;
        for (int j = 1; j < size; j++) {
            if (vis[j] == i || abs(vis[j] - i) == abs(size - j)) {
                c = 1;
            } 
        }
        if (c == 0) {
            
            vis[size] = i;
            nQueen(size + 1);
            vis[size] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    nQueen(1);
    cout << ans;
    return 0;
}