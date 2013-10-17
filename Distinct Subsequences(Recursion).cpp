class Solution {
public:
    int len1, len2;
    
    int numDistinctKernel(int sI, int tI, string& S, string& T, vector<vector<int> >& visited)
    {
        if (tI >= len2)
           return 1;

        if (sI >= len1)
            return 0;
            
        if (visited[sI][tI] != -1)    return visited[sI][tI];
        int found = 0;
        for (int i=sI; i<len1; ++i)            
                if (S[i] == T[tI])
                    found += numDistinctKernel(i+1, tI+1, S, T, visited);
        visited[sI][tI] = found;
        return found;
    }
    
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        len1 = S.size();
        len2 = T.size();
        if (len1 < len2)    return 0;
        vector<vector<int> > visited(len1, vector<int>(len2, -1));
        return numDistinctKernel(0, 0, S, T, visited);
    }
};
