/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!node)  return nullptr;
        map<int, UndirectedGraphNode*> record;
        queue<UndirectedGraphNode *> cand;
        cand.push(node);
        UndirectedGraphNode *res = new UndirectedGraphNode(node->label);
        record[res->label] = res;

        while (!cand.empty())
        {
            UndirectedGraphNode *cur = cand.front();
            cand.pop();
            
            UndirectedGraphNode *tmp = record[cur->label];
            
            int len = cur->neighbors.size();
                
            for (int i=0; i<len; ++i)
                if (record.find(cur->neighbors[i]->label) == record.end())
                {
                    cand.push(cur->neighbors[i]);
                    UndirectedGraphNode *tmpnbor = new UndirectedGraphNode(cur->neighbors[i]->label);
                    tmp->neighbors.push_back(tmpnbor);
                    record[tmpnbor->label] = tmpnbor;
                }
                else
                    tmp->neighbors.push_back(record[cur->neighbors[i]->label]);
        }
        
        return res;
    }
};
