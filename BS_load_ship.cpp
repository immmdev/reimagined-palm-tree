#include <bits/stdc++.h>
using namespace std;

// function to return days taken to carry all good on varrying capacity per day
int days(vector<int>wt,int cap){
    int day=1; 
    int load=0;
    int n=wt.size();
    for(int i=0; i<n; i++){
        // if load exceeds capacity move it to next day load
        if(load+wt[i]>cap){
            load=wt[i];
            day++; 
        //  else keep increasing load on ship
        } else {
            load+=wt[i];
        }
    }
    // retun no of days taken to ship all goods on diff capacity
    return day;
}



int main()
{
    int n,d;
    cin >>n>>d;
    vector<int> nums(n);
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        sum+=nums[i];
    }

    int max_el=*max_element(nums.begin(),nums.end());
    int ans=-1;
    // Solution-1 (Linear search)
    // TC- O((sum-max)*n)
    // SC - O(1)
    // for(int i=high; i<=sum; i++){
    //     if(days(nums,i)<=d){
    //         ans=i;
    //         break;
    //     }
    // }

    // Solution-2 (Binary Search)
    // TC O(n*log(max-sum+1))
    // SC- O(1);
    int low=max_el;
    int high=sum;

    while(low<=high){
        int mid=(low+high)/2;
        if(days(nums,mid)<=d){
            ans=mid;
            high=mid-1;
        } else {
            low=mid+1;
        }
    }
    cout<<ans<<endl;
}