class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        int len = num.size();
        if (len<3)   return res; 
        sort(num.begin(), num.end());
        for (int i=0; i<len-2; ++i)
            for(int j=i+1, k=len-1; j<k; )
            {
                int tmp = num[i]+num[j]+num[k];
                if (tmp > 0)
                    --k;
                else if (tmp < 0)
                    ++j;
                else
                {
                    res.push_back(vector<int>{num[i], num[j++], num[k--]});
                    while (j<k && num[j]==num[j-1])
                        ++j;
                    while (j<k && num[k]==num[k+1])
                        --k;
                }
            }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};
