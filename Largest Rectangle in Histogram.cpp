class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        height.push_back(0);
        int len = height.size(), sum = height[0], i = 1;
        stack<int> ascend;
        ascend.push(0);
        while (i<len)
        {
            if (ascend.empty() || height[i]>=height[ascend.top()])
                ascend.push(i++);
            else
            {
                    int tmp = ascend.top();
                    ascend.pop();
                    sum = max(sum, height[tmp]*(ascend.empty()?i:(i-ascend.top()-1)));
            }
        }
        return sum;
    }
};
