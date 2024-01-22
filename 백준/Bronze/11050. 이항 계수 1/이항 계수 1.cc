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

int N, K;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    float ans = 1;

    for (int i = 0; i < K; i++) {
        ans *= (N - i);
        ans /= (K - i);
    }
    cout << ans;

    return 0;
}