#include <bits/stdc++.h>  
int solve(vector<int> &nums,int n){
    if(n<0)
        return 0;
    if(n==0)                         //only one 1 value in nums
        return nums[0];
    int incl=solve(nums,n-2)+nums[n];
    int exclu=solve(nums,n-1)+0;

    return max(incl,exclu);
    
}
int solvemem(vector<int> &nums,int n,vector<int> &dp){
    if(n<0)
        return 0;
    if(n==0)                         //only one 1 value in nums
        return nums[0];
    if(dp[n]!=-1)
        return dp[n];
    int incl=solvemem(nums,n-2,dp)+nums[n];
    int exclu=solvemem(nums,n-1,dp)+0;

    dp[n]= max(incl,exclu);
    return dp[n];
    
}
int solvetab(vector<int> &nums){
    int n=nums.size();
    vector<int> dp(n,0);

    dp[0]=nums[0];

    for(int i=1;i<n;i++){
        int incl=dp[i-2]+nums[i];
        int exclu=dp[i-1]+0;
        dp[i]= max(incl,exclu);
    }
    return dp[n-1];
}
int solvespace(vector<int> &nums){
    int n=nums.size();
    int prev1=nums[0];
    int prev2=0;

    for(int i=1;i<n;i++){
        int incl=prev2+nums[i];
        int exclu=prev1+0;
        int ans= max(incl,exclu);
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}
int maximumNonAdjacentSum(vector<int> &nums){
    //int n=nums.size();
    //int ans=solve(nums,n-1); //right to left
    //return ans;
    //vector<int> dp(n,-1);
    //return solvemem(nums,n-1,dp);
    return solvespace(nums);
}

//time complexity of recursive+memoization=0(n)
//space complexity of recursive+memoization=0(n)+O(n)

//tabulation time and space complexity = O(n)
//space optimization=O(1)
