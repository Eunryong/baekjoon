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
    vector<int> v;
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        int tmp;
        cin >> tmp;
        sum += tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    int i, j;
    for (i = 0; i < 9; i++) {
        int tmp = sum;
        for (j = 0; j < 9; j++) {
            if (i == j) continue;
            if (sum - v[i] - v[j] == 100) {
                for (int k = 0; k < 9; k++) {
                    if (k == i || k == j) continue;
                    cout << v[k] << "\n";
                }
                return 0;
            }
        }
    }
    

    return 0;
}