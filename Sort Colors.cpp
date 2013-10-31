class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int tail = n-1, head0 = 0, head1 = -1;
        
        while (head0 <= tail)
        {
            while (A[tail]==2 && tail>=head0)
                --tail;
            
            if (tail < head0)
                break;
            
            switch (A[head0])
            {
                case 0: if (head1 >= 0)
                            A[head1++] ^= A[head0] ^= A[head1] ^= A[head0];
                        ++head0;
                        break;
                case 1: head1 = (head1==-1)?head0:head1;
                        ++head0;
                        break;
                case 2: A[tail] ^= A[head0] ^= A[tail] ^= A[head0];
            }
        }
    }
};
