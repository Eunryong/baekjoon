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
int arr[1001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> T;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    while (T--) {
        int x, y;
        cin >> x >> y;
        int sum = 0;
        for (int i = x; i < y; i++) {
            sum += abs(arr[i] - (i != 0 ? arr[i - 1] : 0));
        }
        cout << sum << "\n";
    }
    return 0;
}