class Solution {
public:
    bool final = true;
    bool isMatch(const char *s, const char *p) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        final = true;
        
        if (!s && !p)   return true;
    
        if (*p == '*')
        {
            while (*p == '*')   ++p;
            if (*p == '\0')     return true;
            while (*s != '\0')
            {
               if (isMatch(s, p))   return true;
               if (final)   ++s;
               else break;
            }
            return false;
        }
        else if (*s=='\0')  
        {
            final = ('\0'==*p);
            return final;
        }
        else if (*p =='\0')     return *s=='\0';
        else if (*p=='?' || *p==*s)     return isMatch(s+1, p+1);
        else    return false;
    }
};
