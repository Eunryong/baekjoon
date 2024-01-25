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

int A,B,C;

long long solve(long long a, long long b) {
    if (b == 1)
        return a % C;
    if (b % 2 == 0)
        return solve(a * a % C, b / 2);
    else
        return solve(a * a % C, b / 2) * a % C;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> A >> B >> C;
    long long ans;
    ans = solve(A, B);
    cout << ans;
    return 0;
}