int fcnt(vector<vector<int>>& mt, int nm)
{
    int n = mt.size(), m = mt[0].size();
    int ro = 0, cl = m - 1, cnt = 0;
    
    while (ro < n && cl >= 0)
    {
        if (mt[ro][cl] <= nm)
        {
            cnt += (cl+1);
            ro++;
        }
        else
            cl--;
    }
    return cnt;
}

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mt, int k)
    {
        int n = mt.size(), m = mt[0].size();
        int lo = mt[0][0], hi = mt[n-1][m-1], mid;
        
        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            if (fcnt(mt, mid) < k && fcnt(mt, mid+1) >= k)
            {
                mid++;
                break;
            }
            else if (fcnt(mt, mid) >= k && fcnt(mt, mid - 1) < k)
                break;
            else if (fcnt(mt, mid) >= k)
                hi = mid - 1;
            else if (fcnt(mt, mid) < k)
                lo = mid + 1;
            
        }
        return mid;
    }
};