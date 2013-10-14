class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (n <= 0)     return 0;
        
        int cnt = 1, total = 1, idx = 1, prev = A[0];
        for (int i=1; i<n; ++i)
        {
            if (A[i] == prev)
            {
                if (++cnt <= 2)
                {
                    A[idx++] = A[i];
                    ++total;
                }
            }
            else
            {
                cnt = 1;
                ++total;
                prev = A[i];
                A[idx++] = A[i];
            }
        }
        return total;
    }
};
