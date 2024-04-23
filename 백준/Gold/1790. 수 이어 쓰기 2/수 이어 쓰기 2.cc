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
int N, k;
long long cnt[13];
long long c;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> k;
    int max_len = to_string(N).length();
    long long sum = 0;
    int i = 1;
    for (i = 1; i <= max_len && sum <= k; i++) {
        cnt[i] = i * 9 * pow(10, i - 1);
        if (sum + cnt[i] < k) {
           sum += cnt[i];
        } else {
            break;
        }
    }
    int len = i;
    c = k - sum;
    int num = (c + len - 1) / len;
    int mod = (c + len - 1) % len;
    long long n = (pow(10, len - 1) - 1 + num);
    if (n > N) {
        cout << -1;
        return 0;
    }
    string s = to_string(n);
    cout << s[mod];

    return 0;
}
