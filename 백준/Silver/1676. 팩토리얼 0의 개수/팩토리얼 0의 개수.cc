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
    int ans = 0;
    if (N == 0) ans = 0;
    for (int i = 1; i <= N; i++) {
        int tmp = i;
        while (tmp % 5 == 0) {
            ans++;
            tmp /= 5;
        }
    }
    cout << ans;

    return 0;
}