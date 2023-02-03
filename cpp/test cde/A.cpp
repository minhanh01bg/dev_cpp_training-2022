#include <bits/stdc++.h>

using namespace std;


signed main()
{
    int n;
    cin >> n;
    int x = 1, cnt = 1;
    int k = n;
    for (int i = 1; i <= n; i++)
    {
        bool check = false;
        int y = x;
        for (int j = 0; j < k; j++)
        {
            cout << "  ";
        }
        k--;
        for (int j = i; j <= y; j++)
        {
            if (j > 9)
            {
                check = true;
                break;
            }
            cout << j << " ";
        }
        if (check)
        {
            for (int z = 0; z < cnt; z++)
            {
                cout << z << " ";
            }
            cnt += 2;
        }
        if (check == true)
        {
            for (int j = cnt - 2; j >= 0; j--)
            {
                cout << j << " ";
            }
            for (int j = y - 1; j >= i; j--)
            {
                if (j > 9)
                {
                    continue;
                }
                cout << j << " ";
            }
        }
        else
        {
            for (int j = y - 1; j >= i; j--)
            {
                cout << j << " ";
            }
        }
        cout << endl;
        x += 2;
    }
}