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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        int sum = 0;
        int flag = 0;
        for (int j = 0; j < tmp.size(); j++) {
            if (tmp[j] == '(') {
                sum++;
            } else if (sum) {
                sum--;
            } else if (sum == 0) {
                flag = 1;
            }
        }
        if (sum == 0 && flag == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}