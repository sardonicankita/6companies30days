class Solution {
public:
    void merge(vector<int>&n, int l , int r, int mid){
        int s1=mid-l+1, s2=r-mid;
        vector<int>a(s1), b(s2);
        
        for(int i=0; i<s1; i++){
            a[i]=n[l+i];
        }
        
        for(int j=0; j<s2;j++){
            b[j]=n[mid+1+j];
        }
        
        int i=0, j=0, k=l;
        while(i<s1 &&  j<s2){
            if(a[i]<=b[j]){
                n[k++]=a[i++];
            }
            else{
                n[k++]=b[j++];
            }
        }
        
        while(i<s1){
             n[k++]=a[i++];
        }
        while(j<s2){
            n[k++]=b[j++];
        }
    }
    
    void divide(vector<int>& nums, int l, int h){
       if(l>=h)return;
             int mid=l+(h-l)/2;
            divide(nums, l, mid);
            divide(nums, mid+1, h);
            merge(nums, l, h, mid);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        divide(nums, 0, nums.size()-1);
        return nums;
        
    }
};