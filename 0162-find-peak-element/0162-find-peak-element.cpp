class Solution {
public:
    int findPeakElement(vector<int>& ans)
    {
        if (ans.size() == 1)
            return 0;
        int lo  = 0, hi = ans.size()-1, mid;
        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            if (mid == 0)
            {
                if (ans[mid] > ans[mid+1])
                    break;
                else
                    lo = mid + 1;
            }
            else if (mid == ans.size() - 1)
            {
                if (ans[mid] > ans[mid-1])
                    break;
                else
                    hi = mid - 1;
            }
            else if (ans[mid] > ans[mid-1] && ans[mid] > ans[mid+1])
                break;
            else if (ans[mid] < ans[mid-1])
                hi = mid - 1;
            else if (ans[mid] < ans[mid+1])
                lo = mid + 1;
        }
        return mid;
    }
};