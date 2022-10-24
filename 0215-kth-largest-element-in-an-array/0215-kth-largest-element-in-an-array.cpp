class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        int nmb = 0;
        vector<int> v(20001);
        for (int i = 0; i < nums.size(); i++)
            v[nums[i]+10000]++;
        
        for (int i = 20000; i >= 0; --i)
        {
            nmb += v[i];
            
            
            if (nmb >= k)
                return i-10000;
        }
        return 1;
    }
};