class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string res = "/";
        path += '/';
        int len = path.size(), cur = 0, start = 1, existed = 0, cnt = 0;
        stack<int> loc;
        for (int i=1; i<len; ++i)
        {
            if (res[cur] == '/')
                while (path[i]=='/' && i<len)
                    ++i;
                
                if (i>=len)
                    break;
                switch (path[i])
                {
                    case '/':   res += '/';
                                cur++;
                                start = cur-cnt;
                                cnt = 0;
                                loc.push(start);     
                                ++existed;
                                break;
                    case '.':   if (i+1<len && path[i+1]=='/')
                                {
                                    ++i;
                                    break;
                                }
                                else if (i+2<len && path[i+1]=='.' && path[i+2]=='/')
                                {
                                        if (existed >= 1)
                                        {
                                            --existed;
                                            res.erase(res.begin()+start, res.end());          
                                            loc.pop();
                                            start = !loc.empty()?loc.top():1;
                                            cur = res.size()-1;                                            
                                        }
                                        i += 2;
                                        break;
                                }
                    default:    res += path[i];
                                ++cur;
                                ++cnt;
                }
        }

        if (res.size()>1 && *res.crbegin()=='/')
            res.pop_back();
        return res;
    }
};
