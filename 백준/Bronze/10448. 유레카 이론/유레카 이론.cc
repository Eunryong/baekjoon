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
int arr[1001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        for (int k = 0; k * (k + 1) / 2 < tmp; k++) {
            if (!arr[k]) {
                arr[k] = k * (k + 1) / 2;
            }
        }
        int ans = 0;
        int j = 1;
        while (arr[j] < tmp && arr[j]) {
            int k = 1;
            while (arr[k] + arr[j] < tmp && arr[j] && arr[k]) {
                int l = 1;
                while (arr[l] + arr[k] + arr[j] <= tmp && arr[j] && arr[k] && arr[l]) {
                    if (arr[l] + arr[k] + arr[j] == tmp)
                        ans = 1;
                    l++;
                }
                k++;
            }
            j++;
        }
        cout << ans << "\n";
    }

    return 0;
}