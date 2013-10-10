class Solution {
public:
    bool isNumKernel(string&& s, bool num, bool point)
    {
        if (s.size()==1)
        {
            if(isdigit(s[0]) || (s[0]=='.' && num && !point))   return true;
            else return false;
        }
        
        if (isdigit(s[0])) return isNumKernel(s.substr(1), true, point);
        else if (s[0]=='.' && !point)   return isNumKernel(s.substr(1), num, true);
        else return false;
    }
    
    bool isNumber(const char *s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        stringstream numCan(s);
        string first, second;
        numCan >> first >> second;
        if (first.empty() || !second.empty())  return false;
        
        int len = first.size();
        
        size_t epos = first.find('e');
        if (epos == first.size()-1)     return false;
        else if (epos <= first.size()-2)
        {
            string tmp = first.substr(epos+1);
            int len = tmp.size();
            if (len==1 && !isdigit(tmp[0]))     return false;
            if (!isdigit(tmp[0]) && (tmp[0]!='+' && tmp[0]!='-'))
                return false;
            for (int i=1; i<len; ++i)
                if (!isdigit(tmp[i]))
                    return false;
        }
        
        second = first.substr(0, epos);
        len = second.size();
        if (len == 0)   return false;
        else if (len==1) return isdigit(second[0])?true:false;
        if (second[0]=='+' || second[0]=='-')
            return isNumKernel(second.substr(1), false, false);
        else if (second[0] == '.')
            return isNumKernel(second.substr(1), false, true);
        else if (isdigit(second[0]))
            return isNumKernel(second.substr(1), true, false);
        else 
            return false;
    }
};
