#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n1, n2, k;
        cin >> n1 >> n2 >> k;
        vector<int> a(n1);
        vector<int> b(n2);
        for (int i = 0; i < n1; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n2; i++)
        {
            cin >> b[i];
        }

        if (n1 > n2)
        {
            swap(a, b);
            swap(n1, n2);
        }
        int low = max(0, k - n2);
        int high = min(n1, k);
        int n = n1 + n2;
        // their must be k element at the left
        int left = k;

        while (low <= high)
        {
            int mid1 = (low + high) / 2;
            int mid2 = left - mid1;

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if (mid1 < n1)
                r1 = a[mid1];
            if (mid2 < n2)
                r2 = b[mid2];
            if (mid1 - 1 >= 0)
                l1 = a[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = b[mid2 - 1];

            if (l1 <= r2 && l2 <= r1)
            {

                return max(l1, l2);
            }
            else if (l1 > r2)
            {
                high = mid1 - 1;
            }
            else if (l2 > r1)
            {
                low = mid1 + 1;
            }
        }
    }
};