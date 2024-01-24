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

int N;

int dp_x[51][51];
int dp_y[51][51];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<string> v;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        v.push_back(tmp);
        fill_n(dp_x[i], N, 1);
        fill_n(dp_y[i], N, 1);
    }
    int ans = 0;
    for (int k = 0; k < N; k++) {
        for (int l = 0; l < N - 1; l++) {
            vector<string> v_tmp = v;
            swap(v_tmp[k][l], v_tmp[k][l + 1]);
            for(int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (i > 0 && v_tmp[i][j] == v_tmp[i - 1][j])
                        dp_x[i][j] = max(dp_x[i - 1][j] + 1, dp_x[i][j]);
                    if (j > 0 && v_tmp[i][j] == v_tmp[i][j - 1])
                        dp_y[i][j] = max(dp_y[i][j - 1] + 1, dp_y[i][j]);
                }
            }
            for (int i = 0; i < N; i++) {
                ans = max(ans, *max_element(dp_x[i], dp_x[i] + N));
                ans = max(ans, *max_element(dp_y[i], dp_y[i] + N));
                fill_n(dp_x[i], N, 1);
                fill_n(dp_y[i], N, 1);
            }
            swap(v_tmp[l][k], v_tmp[l+ 1][k]);
            for(int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (i > 0 && v_tmp[i][j] == v_tmp[i - 1][j])
                        dp_x[i][j] = max(dp_x[i - 1][j] + 1, dp_x[i][j]);
                    if (j > 0 && v_tmp[i][j] == v_tmp[i][j - 1])
                        dp_y[i][j] = max(dp_y[i][j - 1] + 1, dp_y[i][j]);
                }
            }
            for (int i = 0; i < N; i++) {
                ans = max(ans, *max_element(dp_x[i], dp_x[i] + N));
                ans = max(ans, *max_element(dp_y[i], dp_y[i] + N));
                fill_n(dp_x[i], N, 1);
                fill_n(dp_y[i], N, 1);
            }
        }
    }
    cout << ans;

    return 0;
}