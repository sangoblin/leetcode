class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int cur = m+n-1;
        while (cur>=0 && m>=1 && n>=1)
        {
            if (A[m-1]>=B[n-1])
                A[cur--] = A[(m--)-1];
            else
                A[cur--] = B[(n--)-1];
        }
        while (m)
            A[cur--] = A[(m--)-1];
        while (n)
            A[cur--] = B[(n--)-1];
    }
};
