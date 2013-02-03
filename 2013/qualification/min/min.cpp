#include <iostream>
#include <set>
#include <map>
#include <queue>

using namespace std;

#define MAX_K 1000005
#define MAX_N 1000000005;

typedef unsigned long long ull;

int T;

int n;
int k;

int a;
int b;
int c;
int r;

ull m[MAX_K * 2 + 2];
queue<ull> current;
map<ull, ull> count;

int testcase()
{
    cin >> n >> k;
    cin >> a >> b >> c >> r;

    while(!current.empty())
    {
        current.pop();
    }
    count.clear();

    m[0] = a;
    current.push(a);
    count[a]++;

    for (int i = 1; i < k; i++)
    {
        m[i] = (b * m[i - 1] + c) % r;
        current.push(m[i]);
        count[m[i]]++;
    }

    ull continue_point = 0;

    for(ull i = k; i < (k + 1) * 2; i++)
    {
        for(ull number = continue_point;; number++)
        {
            auto pos = count.find(number);
            if(pos == count.end() || pos->second == 0)
            {
                ull first_value = current.front();
                count[first_value]--;

                continue_point = min(number, first_value);
                current.pop();

                m[i] = number;

                current.push(number);
                count[number]++;
                break;
            }
        }
    }

    return m[k + (n - k - 1) % (k + 1)];
}

int main()
{
    cin >> T;
    for(int c = 1; c <= T; c++)
    {
        cout << "Case: #" << c << ": " << testcase() << endl;
    }
}