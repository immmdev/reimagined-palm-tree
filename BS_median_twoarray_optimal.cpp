#include <bits/stdc++.h>
using namespace std;
// Q- median of two sorted arrays 
// TC-O(min(logn,logm))
// SC- O(1)
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n1, n2;
        cin >> n1 >> n2;
        vector<int> nums_1(n1);
        vector<int> nums_2(n2);
        for (int i = 0; i < n1; i++)
        {
            cin >> nums_1[i];
        }
        for (int i = 0; i < n2; i++)
        {
            cin >> nums_2[i];
        }

        if (n1 > n2)
        {
            swap(nums_1, nums_2);
            swap(n1, n2);
        }

        int low = 0;
        int high = n1;
        int n = n1 + n2;
        int left = (n + 1) / 2;
         long double ans;
        while (low <= high)
        {
            int mid1 = (low + high) / 2;
            int mid2 = left - mid1;

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if (mid1 < n1)
                r1 = nums_1[mid1];
            if (mid2 < n2)
                r2 = nums_2[mid2];
            if (mid1 - 1 >= 0)
                l1 = nums_1[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = nums_2[mid2 - 1];
           
            if (l1 <= r2 && l2 <= r1)
            {
                if (n % 2 == 0)
                {
                    ans = (long double)(max(l1, l2) + min(r1, r2)) / 2.0;
                }
                else
                {
                    ans = max(l1, l2);
                }
                break;
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
         cout << ans << endl;
    }
}
