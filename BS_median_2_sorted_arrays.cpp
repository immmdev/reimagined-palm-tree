#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> nums_1(n);
        vector<int> nums_2(k);
        for (int i = 0; i < n; i++)
        {
            cin >> nums_1[i];
        }
        for (int i = 0; i < k; i++)
        {
            cin >> nums_2[i];
        }

        // vector<int> nums_3;

        int i = 0, j = 0;
        int cnt = 0;
        int nk = n + k;
        int reqind1 = nk / 2;
        int reqind2 = nk / 2 - 1;
        int el1 = -1;
        int el2 = -1;
        while (i < n && j < k)
        {
            if (nums_1[i] > nums_2[j])
            {
                if (cnt == reqind1)
                    el1 = nums_2[j];
                if (cnt == reqind2)
                    el2 = nums_2[j];
                j++;
                cnt++;
            }
            else
            {
                if (cnt == reqind1)
                    el1 = nums_1[i];
                if (cnt == reqind2)
                    el2 = nums_1[1];
                i++;
                cnt++;
            }
        }

        while (i < n)
        {
            if (cnt == reqind1)
                el1 = nums_1[i];
            if (cnt == reqind2)
                el2 = nums_1[1];
            i++;
            cnt++;
        }

        while (j < k)
        {
            if (cnt == reqind1)
                el1 = nums_2[j];
            if (cnt == reqind2)
                el2 = nums_2[j];
            j++;
            cnt++;
        }

        if(nk%2==1){
            cout<<el2<<endl;
        } else {
            cout<<(double)(((double)el1+(double)el2)/2.0)<<endl;
        }
    }

   
}