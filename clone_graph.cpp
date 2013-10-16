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
        if (node == NULL) return NULL;
        
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode * > m;
        unordered_set<UndirectedGraphNode * > v;
        queue<UndirectedGraphNode * > q;
        
        m[node] = new UndirectedGraphNode(node->label);
        q.push(node);
        while (!q.empty())
        {
            UndirectedGraphNode *curr = q.front();
            q.pop();
            if (v.find(curr) == v.end())
            {
                for (UndirectedGraphNode *neighbor : curr->neighbors)
                {
                    if (m.find(neighbor) == m.end()) m[neighbor] = new UndirectedGraphNode(neighbor->label);
                    (m[curr]->neighbors).push_back(m[neighbor]);
                    q.push(neighbor);
                }
                v.insert(curr);
            }
        }
        
        return m[node];
    }
};
