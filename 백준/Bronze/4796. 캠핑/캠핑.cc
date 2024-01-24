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
int L, P, V;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int i = 0;
    while (1) {
        int a;
        cin >> L >> P >> V;
        if (L == 0 && P == 0 && V == 0)
            return 0;
        if (V % P > L)
            a = L;
        else
            a = V % P;
        cout << "Case " << i + 1 << ": " << (V / P) * L + a << "\n"; 
        i++;
    }

    return 0;
}