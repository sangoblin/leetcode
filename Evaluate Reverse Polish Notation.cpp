class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int len = tokens.size();
        stack<int> operand;
        
        if (0==len) return 0;
        
        for (int i=0; i<len; ++i)
        {
            if ("+"!=tokens[i] && "-"!=tokens[i] && "*"!=tokens[i] && "/"!=tokens[i])
                operand.push(stoi(tokens[i]));
            else
            {
                int second = operand.top();
                operand.pop();
                int first = operand.top();
                operand.pop();
                switch (tokens[i][0])
                {
                    case '+':  first += second; break;
                    case '-':  first -= second; break;
                    case '*':  first *= second; break;
                    case '/':  first /= second; break;
                }
                operand.push(first);
            }
        }
        return operand.top();
    }
};
