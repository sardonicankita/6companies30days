
class Solution {
public:
    
    bool fun(int i_sub , int i_ele , vector<int> &subsum , vector<int> &nums , long long &T , int  K, vector<int> &vis )
    {
        int n = nums.size();
        // ith subset is filleded completely 
        if( subsum[i_sub] == T) 
        {
            // check i+1 ... kth partition fullfill with sum = tot/k
            if( i_sub == K-1 ) // all k partition filled completey 
             return true ;

            // 0 to ith filling done  if i...k-1 true then ans is ture

            return fun(i_sub + 1 ,n-1,subsum , nums,T , K  ,vis);
        }

        for( int i = i_ele ; i >= 0 ; --i )
        {
            if(vis[i]) continue;
            // filling elments from 0....i_ele elements in i_sub th partition 
            int temp = subsum[i_sub] + nums[i];
            if(temp <= T )
            {
                vis[i] =1 ; 
                subsum[i_sub] += nums[i];

                int x = fun(i_sub,i-1,subsum,nums,T,K,vis);
                vis[i] = 0 ;
                subsum[i_sub] -= nums[i];

                if(x) return true;
            }
        }

        return false;

    }   
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> vis(n,0) , subsum(k,0) ;
        long long  T = 0 ;
        for(auto x : nums ) T += x;
        if( k == 1 ) return true;  // only one partion then sum is always equal . 
         
        if( T%k) return false; // it indicates each partion has sum fraction and fraction sum of partition is not possible ( partion contain only interger number ) 

        if( k > n ) return false; // max number partion with sum > 0  then 1 partition must contain atleast 1 element . so max partion are n . 

        T = T/k;
        
        subsum[0] = nums[n-1]; // initalization : if last element is in one of the partion that contain answer .
        vis[n-1] =1 ; 
        return fun(0,n-1,subsum,nums,T,k,vis);
    }
};