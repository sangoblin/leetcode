class Solution {
public:
string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int T_table[256]={0}, n(S.size()), m(T.size());
        int curr_table[256]={0}, count=0, minw_L=INT_MAX, minw_B=n;
        for(int i=0; i<m; ++i) T_table[T[i]]++;
        for(int i=0, begin=0; i<n; ++i){
            if(++curr_table[S[i]]<=T_table[S[i]]) 
                ++count;
            if(count!=m) continue;
            while(T_table[S[begin]]==0 || curr_table[S[begin]]>T_table[S[begin]]) 
                --curr_table[S[begin++]];
            if(minw_L>i-begin+1){
                minw_B=begin;
                minw_L=i-begin+1;
            }
        }
        return S.substr(minw_B, minw_L);
    }
};
