#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        deque<long long> A;
        long long a, b;
        cin >> a >> b;
        string k;
        cin >> k;
        for (long long i = 0; i < b; i++)
        {
            if (k[i] == '1')
                A.push_back(i);
        }
        long long sum = 0;
        for (long long i = b; i < a; i++)
        {
            if (k[i] == '1')
                A.push_back(i);
            if (!A.empty() && i == A.front() + b)
            {
                sum += A.size() * 2 - 1;
                A.pop_front();
            }
        }
        while (!A.empty())
        {
            sum += A.size() * 2 - 1;
            A.pop_front();
        }
        // cout<<sum<<endl;
        long long sum2 = a * a;
        long long x = __gcd(sum, sum2);
        if (sum == 0)
            cout << "0/1" << endl;
        else
            cout << sum / x << '/' << sum2 / x << endl;
    }
}
