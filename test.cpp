#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        map<long long, long long> hash;
        for (long long i = 0; i < n; i++)
        {
            hash[s[i]]++;
        }

        long long size_new = n - k;
        long long count_1 = 0;
        long long count_odd = 0;

        if (hash.size() == 1)

            if (size_new % 2 == 0)
            {
                for (auto &it : hash)
                {
                    if (it.second % 2 != 0)
                    {
                        count_1++;
                    }

                    else
                    {
                        continue;
                    }
                }

                if (count_1 == k)
                {
                    cout << "Yes" << endl;
                }
                else
                {
                    cout << "No" << endl;
                }
            }
            else
            {
                for (auto &it : hash)
                {
                    if (it.second % 2 != 0)
                    {
                        count_odd++;
                    }

                    else
                    {
                        continue;
                    }
                }
                if (count_odd - k == 1)
                {
                    cout << "Yes" << endl;
                }
                else
                {
                    cout << "No" << endl;
                }
            }
    }
}
