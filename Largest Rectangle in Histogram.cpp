class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        height.push_back(0);
        int len = height.size(), sum = height[0];
        stack<int> ascend;
        ascend.push(0);
        for (int i=1; i<len; ++i)
            if (height[i] >= height[ascend.top()])
                ascend.push(i);
            else
            {
                while (!ascend.empty() && height[ascend.top()]>height[i])
                {
                    int tmp = ascend.top();
                    ascend.pop();
                    sum = max(sum, height[tmp]*(ascend.empty()?i:(i-ascend.top()-1)));
                }
                ascend.push(i);
            }
        return sum;
    }
};
