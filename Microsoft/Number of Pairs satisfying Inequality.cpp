#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;

typedef tree<pair<int,int>, null_type, less_equal<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
         ordered_set os; 
        /* We are creating ordered_set of pair to make element unique,
           since same element can't be inserted in set, every element has a unique index
           which will solve this problem
        */
        
        int n = nums1.size();
        vector<int> d(n);  // this array will store our difference
        for(int i = 0; i < n; i++) {
            d[i] = nums1[i] - nums2[i];
        }
        
        
        long long count = 0;
        for(int i = n-1; i >= 0; i--) {
            pair<int,int> search = {d[i] - diff, INT_MIN};     // key to apply lower_bound
            int smaller = os.order_of_key(search); // order_of_key returns no. of element smaller than key
            count += os.size() - smaller; // remaining element are greater than key
            os.insert({d[i], i});  // inserting the curr d[i] and its index
        }
        return count;
    }
};