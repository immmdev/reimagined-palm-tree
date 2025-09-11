#include<bits/stdc++.h>
using namespace std;

// Q :- finding minimum, maximum distance at which cow can be placed

// placing the cows at the paricular d apart
int possible(vector<int>nums,int d,int cows){
    int n=nums.size();
    // always placing first cow at 1st position
    int prev=nums[0];
    cows--;
    for(int i=1; i<n; i++){
        if(nums[i]-prev>=d){
            cows--;
            // storing pos of last placed cow
            prev=nums[i];
        }
        else{
            // if not skip the pos
            continue;
        }

    }
    // check if all the cows placed or not
    if(cows==0){
        return 1;
    } else {
        return 0;
    }
}

int main(){
    int n,c;
    cin>>n>>c;
    vector<int>nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }

    // sorting before searching
    sort(nums.begin(),nums.end());

    // range of the distances from min to max of array
    int low=nums[0];
    int high=nums[n-1];

    // applying bs 
    while(low<=high){
        int mid=(low+high)/2;
        // if possible serach for higher distance
        if(possible(nums,mid,c)){
            low=mid+1;
        
        // if not move to lower distances to check
        } else {
            high=mid-1;
        }
    }

    // at the end high will with changed polarity point out to ans
    cout<<high<<endl;

}

// TC O(nlogn+n*log(max-min))
// SC O(1);