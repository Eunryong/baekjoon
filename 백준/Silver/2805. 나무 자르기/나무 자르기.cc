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

long long N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    vector<long long> v;
    for (long long i = 0; i < N; i++) {
        long long tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    long long ans = 0;
    long long en = v[N - 1];
    long long st = 1;
    while (st <= en) {
        long long sum = 0;
        long long mid = (st + en) / 2;
        for (long long i = 0; i < N; i ++) {
            if (v[i] - mid > 0) sum += v[i] - mid;
        }
        if (sum >= M) {
            ans = mid;
            st = mid + 1; 
        } else {
            en = mid - 1;
        }
    }
    cout << ans;
    return 0;
}