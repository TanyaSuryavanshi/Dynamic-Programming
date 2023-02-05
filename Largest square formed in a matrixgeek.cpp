//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(vector<vector<int>>& mat,int i,int j,int &maxi){
        if(i>=mat.size() || j>=mat[0].size())
            return 0;
            
        int right=solve(mat,i,j+1,maxi);
        int diagonal=solve(mat,i+1,j+1,maxi);
        int down=solve(mat,i+1,j,maxi);
        if(mat[i][j]==1){
            int ans=1+min(right,min(diagonal,down));
            maxi=max(maxi,ans);
            return ans;
        }
        else{
            return 0;
        }
    }
    int solvemem(vector<vector<int>>& mat,int i,int j,int &maxi,vector<vector<int>>& dp){
        if(i>=mat.size() || j>=mat[0].size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];   
        int right=solvemem(mat,i,j+1,maxi,dp);
        int diagonal=solvemem(mat,i+1,j+1,maxi,dp);
        int down=solvemem(mat,i+1,j,maxi,dp);
        if(mat[i][j]==1){
            dp[i][j]=1+min(right,min(diagonal,down));
            maxi=max(maxi,dp[i][j]);
            return dp[i][j];
        }
        else{
            return dp[i][j]=0;
        }
    }
    int solvetab(vector<vector<int>>& mat,int &maxi){
        int row=mat.size();
        int col=mat[0].size();
        vector<vector<int>> dp(row+1,vector<int>(col+1,0));
        for(int i=row-1;i>=0;i--){
            for(int j=col-1;j>=0;j--){
                int right=dp[i][j+1];
                int diagonal=dp[i+1][j+1];
                int down=dp[i+1][j];
                if(mat[i][j]==1){
                    dp[i][j]=1+min(right,min(diagonal,down));
                    maxi=max(maxi,dp[i][j]);
                    
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return dp[0][0];
    }
    int solvespace(vector<vector<int>>& mat,int &maxi){
        int row=mat.size();
        int col=mat[0].size();
        
        vector<int> curr(col+1,0);
        vector<int> next(col+1,0);
        for(int i=row-1;i>=0;i--){
            for(int j=col-1;j>=0;j--){
                int right=curr[j+1];
                int diagonal=next[j+1];
                int down=next[j];
                if(mat[i][j]==1){
                    curr[j]=1+min(right,min(diagonal,down));
                    maxi=max(maxi,curr[j]);
                    
                }
                else{
                    curr[j]=0;
                }
            next=curr;
            }
        return next[0];
        }
        
    }
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int maxi=0;
        //return solve(mat,0,0,maxi);
        //vector<vector<int>> dp(n,vector<int>(m,-1));
        //return solvemem(mat,0,0,maxi,dp);
        return solvespace(mat,maxi);
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
