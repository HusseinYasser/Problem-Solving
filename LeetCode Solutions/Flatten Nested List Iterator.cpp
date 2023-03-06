/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    
    vector<NestedInteger> list;
    
    int i;
    
    vector<int> flattened;
    
    void flatten(int idx, vector<NestedInteger> nestedList, vector<int>& flattened)
    {
        if(idx == nestedList.size())
            return;
        if(nestedList[idx].isInteger())
        {
            flattened.push_back(nestedList[idx].getInteger());
            flatten(idx + 1, nestedList, flattened);
        }
        else
        {
            flatten(0, nestedList[idx].getList(), flattened);
            flatten(idx+1, nestedList, flattened);
        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        
        
        list = nestedList;
        i = 0;
        flatten(0, this->list, this->flattened);
    }
    
    int next() {
        return flattened[i++];
    }
    
    bool hasNext() {
        
        return i < flattened.size();
        
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
