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

int T, N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for (int i = 0; i < T; i++) {
        map<string, int> m;
        cin >> N;
        int sum = 1;
        for (int j = 0; j < N; j++) {
            string tmp, tmp2;
            cin >> tmp >> tmp2;
            m[tmp2]++;
        }
        map<string, int>::iterator it;
        for (it = m.begin(); it != m.end(); it++) {
            sum *= (it->second + 1);
        }
        cout << sum - 1 << "\n";
    }
    return 0;
}