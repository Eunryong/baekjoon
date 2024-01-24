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
    vector<int> v;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    int sum = 0;
    int ans = 0;
    while (sum != K) {
        int i = 0;
        while (i < N && v[i] <= K - sum) {
            i++;
        }
        if (i > 0) {
            sum += v[i - 1];
            ans++;
        } else if(v[0] == K - sum) {
            sum += v[0];
            ans++;
        }
    }
    cout << ans;

    return 0;
}