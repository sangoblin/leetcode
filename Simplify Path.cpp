class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string res = "/";
        path += '/';
        int len = path.size(), start = 1, cnt = 0;
        stack<int> loc;
        for (int i=1; i<len; ++i)
        {
            if (*res.crbegin() == '/')
                while (path[i]=='/' && i<len)
                    ++i;
                
                if (i>=len)
                    break;
                    
                switch (path[i])
                {
                    case '/':   res += '/'; start = res.size()-1-cnt; cnt = 0;
                                loc.push(start);     
                                break;
                    case '.':   if (i+1<len && path[i+1]=='/')
                                {
                                    ++i;
                                    break;
                                }
                                else if (i+2<len && path[i+1]=='.' && path[i+2]=='/')
                                {
                                        if (!loc.empty())
                                        {
                                            res.erase(res.begin()+start, res.end());          
                                            loc.pop();
                                            start = !loc.empty()?loc.top():1;                                           
                                        }
                                        i += 2;
                                        break;
                                }
                    default:    res += path[i]; ++cnt;
                }
        }

        if (res.size()>1 && *res.crbegin()=='/')    res.pop_back();
        
        return res;
    }
};
