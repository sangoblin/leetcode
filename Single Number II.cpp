class Solution {
public:
    const int bits = sizeof(int)*8;
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int cnt[bits], res = 0;
        memset(cnt, 0, sizeof(int)*bits);
        for (int i=0; i<n; ++i)
        {
            unsigned int idx = 0, tmp = A[i];
            while (tmp != 0)
            {
                cnt[idx] += tmp&0x01;
                tmp >>= 1;
                if (cnt[idx] == 3)
                    cnt[idx] = 0;
                ++idx;
            }
        }
        for (int i=0; i<bits; ++i)
            res += cnt[i]?(1<<i):0;
        return res;
    }
};
