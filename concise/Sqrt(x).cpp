class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        double xn=0., xn_1=1.;
        
        while (static_cast<int>(xn)-static_cast<int>(xn_1))
        {
            xn = xn_1;
            xn_1 = xn/2+x/(2*xn); 
        }
        
        return static_cast<int>(xn);
    }
};
