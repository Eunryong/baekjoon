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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    int ans = 1000001;

    for (int i = 0; i < 100; i++) {
        int tmp = N - i;
        int sum = 0;
        while (tmp > 0) {
            sum += tmp % 10;
            tmp /= 10;
        }
        if (N == sum + N - i) {
            ans = min(ans, N-i);
        }
    }
    if (ans == 1000001) ans = 0;
    cout << ans;

    return 0;
}