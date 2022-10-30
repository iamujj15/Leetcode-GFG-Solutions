class Solution {
    bool prd(vector<int> v, int k, int mid)
    {
        int nm = 1, tsm = 0;
        for (int i = 0; i < v.size(); i++)
        {
            tsm += v[i];
            if (tsm > mid)
            {
                nm++;
                tsm = v[i];
                
                if (nm > k)
                    return false;
            }
        }
        return true;
    }
public:
    int splitArray(vector<int>& v, int k)
    {
        int mx = 0;
        for (auto i : v)
            mx = max(mx, i);
        
        int lo = mx, hi = 1e9, mid;
        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            //FFFFFTTTTTTT
            if (prd(v, k, mid) && !prd(v, k, mid-1))
                break;
            else if (!prd(v, k, mid) && prd(v, k, mid+1))
            {
                mid++;
                break;
            }
            else if (prd(v, k, mid))
                hi = mid - 1;
            else if (!prd(v, k, mid))
                lo = mid + 1;
        }
        return mid;
    }
};