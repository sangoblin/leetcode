class Solution {
public:
     int candy(vector<int> &ratings) {
         int len = ratings.size();
         vector<int> candies(len, 1);
         for (int i=1, k=1; i<len; ++i)
            if (ratings[i]>ratings[i-1])    candies[i] = ++k;
            else    k = 1;
        
         for (int i=len-2, k=1; i>=0; --i)
             if (ratings[i]>ratings[i+1])   candies[i] = max(candies[i], ++k);
             else   k = 1;
                
        return accumulate(candies.begin(), candies.end(), 0);
    }
};
