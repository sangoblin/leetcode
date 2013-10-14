class Solution {
public:

    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int high = 0, low = 0, tmp;
        
        for (int i=0; i<n; ++i)
        {
            tmp = high;
            high = (tmp^(low&A[i]))^(tmp&A[i]);
            low = (low^A[i])^(tmp&A[i]);
        }
        
        return low;
    }
};
