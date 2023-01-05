class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        if(nums.size()==1)return 0;

        int sum=0, original_sum=0;

        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            original_sum += (nums[i]*i);  //when rotation is 0
        }

        int maxSum=original_sum;

        for(int i=nums.size()-1; i>0; i--){
            //F(i)=orginal_sum+sum-(last element*nums.size())
            original_sum=original_sum+sum-nums.size()*nums[i];
            maxSum= max(original_sum, maxSum);
        }
        return maxSum;
    }
};