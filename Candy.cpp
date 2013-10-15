class Solution {
public:

    int candy(vector<int> &ratings) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (ratings.empty())    return 0;
        
        int len = ratings.size();
        vector<int> A(len, 0);
        
        int idx = min_element(ratings.begin(), ratings.end())-ratings.begin(), cur;
        A[idx] = 1;
        for (cur = idx-1; cur>=0; --cur)
        {
            int cnt = 1;
            for (int j=cur-1; j>=0; --j)
                if (ratings[j]<ratings[j+1])
                    ++cnt;
                else    break;
            A[cur] = ratings[cur]>ratings[cur+1]?max(A[cur+1]+1, cnt):cnt;
            while (cur>=1 && ratings[cur]>ratings[cur-1])
                A[--cur] = --cnt;
        }
        
        for (cur = idx+1; cur<len; ++cur)
        {
            int cnt = 1;
            for (int j=cur+1; j<len; ++j)
                if (ratings[j-1]>ratings[j])
                    ++cnt;
                else    break;
            A[cur] = ratings[cur]>ratings[cur-1]?max(A[cur-1]+1, cnt):cnt;
            while (cur<len-1 && ratings[cur]>ratings[cur+1])
                A[++cur] = --cnt;
        }
        
        return accumulate(A.begin(), A.end(), 0);
    }
};
