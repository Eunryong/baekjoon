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
int N, T;
int arr[4][100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> T;
    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        for (int j = 1; j <= 3; j++) {
            if (j == t) {
                arr[j][i] = (i != 0 ? arr[j][i - 1] : 0) + 1;
            } else {
                arr[j][i] = (i != 0 ? arr[j][i - 1] : 0);
            }
        }
    }
    while (T--) {
        int x, y;
        cin >> x >> y;
        for (int i = 1; i <= 3; i++) {
            cout << arr[i][y - 1] - (x > 1 ? arr[i][x - 2] : 0) << " ";
        }
        cout << "\n";
    }
    return 0;
}