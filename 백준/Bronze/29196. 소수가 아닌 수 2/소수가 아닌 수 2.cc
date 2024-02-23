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
double d;

int gcd(int a, int b) {
    int r;
    while(b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> d;
    int n = d * 1000000000;
    if (n != d * 1000000000) {
        cout << "NO\n";
        return 0;
    }
    int a = gcd(n, 1000000000);
    cout << "YES\n";
    cout << fixed;
    cout.precision(0);
    cout <<  n / a << " " << 1000000000 / a;
    
    return 0;
}