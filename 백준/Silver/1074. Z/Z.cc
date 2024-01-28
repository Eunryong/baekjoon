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

int N, r, c;

int solve(int x, int y, int s) {
    if (s == 1) {
        return 2 * x + y;
    }
    int half = s / 2;
    if (x < half && y < half)
        return solve(x, y, half);
    else if (x < half && y >= half)
        return half * half + solve(x, y - half, half);
    else if (x >= half && y < half)
        return 2 * half * half + solve(x - half, y, half);
    else if (x >= half && y >= half)
        return 3 * half * half + solve(x - half, y - half, half);   
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> r >> c;
    int s = pow(2, N);
    cout << solve(r, c, s);

    return 0;
}