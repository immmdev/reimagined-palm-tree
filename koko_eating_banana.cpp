#include<bits/stdc++.h>
using namespace std;

int timeTakenToEatBanana(vector<int>& piles, int k){
    int time = 0;
    int n=piles.size();
   for(int i=0; i<n; i++){
        time+=ceil((double)piles[i]/k);
   }
   return time;
}

int main(){
    int n;
    int h;
    cin>>n>>h;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    int low=1;
    int high=*max_element(nums.begin(),nums.end());
    int ans=high;

    while(low<=high){
        int mid=low+(high-low)/2;
        int time=timeTakenToEatBanana(nums,mid);
        if(time<=h){
            ans=min(ans,mid);
            high=mid-1;
        } else{
            low=mid+1;
        }
    }
    cout<<ans<<endl;
}


