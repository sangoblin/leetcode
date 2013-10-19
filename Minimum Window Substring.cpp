class Solution {
private:
    class compare
    {
    public:
        bool operator () (const pair<int, char>& l, const pair<int, char>& r)
        {
            return l.first>r.first;
        }
    };
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (S.size() < T.size())    return "";
        unordered_map<char, int> cnts, back;
        priority_queue<pair<int, char>, vector<pair<int, char> >,  compare> idxstart;
        bool found = false;
        int start = -1, minL = INT_MAX;
        string res = "";
        
        int len1 = S.size(), len2 = T.size();
        
        for (int i=0; i<len2; ++i)
            ++cnts[T[i]];
        int style = cnts.size(), cur = 0;
        
        for (int i=0; i<len1; ++i)
        {
            if (cnts.find(S[i]) != cnts.end())
            {
                start = start==-1?i:start;
                idxstart.push(make_pair(i, S[i]));
                ++back[S[i]];
                if (back[S[i]] > cnts[S[i]])
                {
                    if (idxstart.top().second == S[i])
                    {
                        idxstart.pop();
                        --back[S[i]];
                        
                        while (!idxstart.empty())
                        {
                            start = idxstart.top().first;
                            if (back[S[start]] > cnts[S[start]])
                            {
                                --back[S[start]];
                                idxstart.pop();
                            }
                            else
                                break;
                        }
                    }
                }
                else if (back[S[i]] == cnts[S[i]])
                    ++cur;
            }
            
            if (cur == style)
            {
                if (i-start+1 < minL)
                {
                    minL = i-start+1;
                    res = S.substr(start, i-start+1);
                }
                idxstart.pop();
                --back[S[start]];
                --cur;
                start = -1;
                while (!idxstart.empty())
                {
                    start = idxstart.top().first;
                    if (back[S[start]] > cnts[S[start]])
                    {
                        --back[S[start]];
                        idxstart.pop();
                    }
                    else
                        break;
                }
            }
        }
        return res;
    }
};
