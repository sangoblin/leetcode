class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (n < 3)  return n;
        
        int slow = 1, fast = 2;
        for ( ; fast < n; ++fast)
            if (A[fast] != A[slow-1])
                A[++slow] = A[fast];


        return slow+1;
    }
};
