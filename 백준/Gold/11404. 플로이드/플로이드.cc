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
int d[101][101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i<= N; i++) {
        fill(d[i], d[i] + N + 1, 999999999);
    }
    for (int i = 1; i<= M; i++) {
        int s, e, dist;
        cin >> s >> e >> dist;
        d[s][e] = min(d[s][e], dist);
    }
    for (int i = 1; i <= N; i++) 
        d[i][i] = 0;
    
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (d[i][j] == 999999999) cout << "0 ";
            else cout << d[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}