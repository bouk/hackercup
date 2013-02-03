#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

typedef unsigned long long ull;

int T;
int N;
int K;
int a[10005];
ull fact[100001];

ull combinations(ull n, ull k)
{
    if(k > n)
    {
        return 0;
    }
    else
    {
        return (fact[n] / (fact[k] * fact[n - k] % 1000000007));
    }
}

void testcase(int t)
{
    cin >> N;
    cin >> K;

    for(int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    sort(a, a + N, greater<int>());
    ull total = 0;
    for (int i = 0; i < N; i++)
    {
        int n = N - i - 1;
        total = (total + a[i] * combinations(n, K - 1)) % 1000000007;
    }

    cout << "Case #" << t << ": " << total << endl;
}

int main(int argc, char const *argv[])
{
    cin >> T;
    fact[0] = 1;
    for(int i = 1; i < 10001; i++)
    {
        fact[i] = (i * fact[i - 1]) % 1000000007;
    }

    for(int t = 1; t <= T; t++)
    {
        testcase(t);
    }

    return 0;
}