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
#include <set>
using namespace std;

int N, K;
vector<int> s;

bool solve(long long i) {
    long long sum = 0;
    for (int k = 0; k < s.size(); k++)
        sum += s[k] / i;
    return sum >= N;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> K >> N;
    for (int i = 0; i < K; i++) {
        int tmp;
        cin >> tmp;
        s.push_back(tmp);
    }

    long long st = 1;
    long long m = 2147483647;
    while (st < m) {
        long long mid = (st + m + 1) / 2;
        if (solve(mid)) st = mid;
        else m = mid - 1;
    }
    cout << st;
    return 0;
}