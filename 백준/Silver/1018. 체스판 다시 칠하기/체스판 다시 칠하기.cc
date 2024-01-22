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

int N, M;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    vector<string> v;
    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    int ans = 32;
    for (int i = 0; i <= N - 8; i++) {
        for (int j = 0; j <= M - 8; j++) {

            int sum = 0;
            int sum_other = 0;
            for (int k = i; k < i + 8; k++) {
                for (int l = j; l < j + 8; l++) {
                    if (((k - i) % 2 == 0 && (l - j) % 2 == 0) || (((k - i) % 2 && (l - j) % 2))) {
                        if (v[i][j] != v[k][l]){
                            sum++;
                        } else if (v[i][j] == v[k][l]) {
                            sum_other++;
                        }
                    } else {
                        if (v[i][j] == v[k][l])
                            sum++;
                        else if (v[i][j] != v[k][l])
                            sum_other++;
                    }
                }
            }
            // cout << "sum : " << sum << " sum_other : " <<sum_other << "\n";
            sum = min(sum, sum_other);
            ans = min(sum, ans);

        }
    }
    cout << ans;

    return 0;
}