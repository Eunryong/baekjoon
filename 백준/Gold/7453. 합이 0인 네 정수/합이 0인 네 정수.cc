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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    long arr[4][4001];
    cin >> n;
    long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> arr[j][i];
        }
    }
    vector<long> AB, CD;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            AB.push_back(arr[0][i] + arr[1][j]);
            CD.push_back(arr[2][i] + arr[3][j]);
        }
    }
    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());
    for (int i = 0; i < AB.size(); i) {
        long n = AB[i] * -1;
        int st = 0;
        int en = CD.size();
        while (st < en) {
            int mid = (st + en) / 2;
            if (n == CD[st]) {
                break;
            }
            if (n > CD[mid]) st = mid + 1;
            else en = mid;
        }
        long cnt = 0;
        while (cnt + i < AB.size() && AB[i] == AB[i + cnt]) {
            cnt++;
        }
        if (n == CD[st]) {
            int idx = st;
            long cnt2 = 0;
            while (idx > 0 && CD[st] == CD[idx]){
                idx--;
            }
            if (CD[st] != CD[idx]) {
                idx++;
            }
            while (cnt2 + idx < CD.size() && CD[idx] == CD[cnt2 + idx]) cnt2++;
            ans += cnt * cnt2;
        }
        i += cnt;

    }
    cout << ans;
    return 0;
}
// 2 30