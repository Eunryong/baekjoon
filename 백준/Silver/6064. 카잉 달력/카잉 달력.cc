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
int N, M, x, y, T;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> M >> N >> x >> y;
        vector<int> v;
        int ans = -1;
        for (int i = 0; i < lcm(M, N) / M; i++) {
            int tmp = i * M + x;
            v.push_back(tmp);
            if (tmp % N == y % N) {
                ans = tmp;
                break ;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}