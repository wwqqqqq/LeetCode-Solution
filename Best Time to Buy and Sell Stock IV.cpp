class Solution {
public:
    void cutPairs(vector<int>& prices, vector<pair<int,int>>& pairs) {
        if(pairs.size()==1) {
            pairs.erase(pairs.begin());
            return;
        }
        else if(pairs.size()==0)
            return;
        // cut one
        auto iter1 = pairs.begin();
        int loss1 = prices[iter1->second] - prices[iter1->first];
        for(auto iter = pairs.begin();iter!=pairs.end();iter++) {
            int loss = prices[iter->second] - prices[iter->first];
            if(loss<loss1) {
                loss1 = loss;  
                iter1 = iter;
            }
        }
        //merge two
        auto iter2 = pairs.begin();
        auto temp = iter2 + 1;
        int loss2 = prices[iter2->second] - prices[temp->first];
        for(auto iter = pairs.begin();iter!=pairs.end();iter++) {
            temp = iter + 1;
            if(temp==pairs.end())
                break;
            int loss = prices[iter->second] - prices[temp->first];
            if(loss<loss2) {
                loss2 = loss;
                iter2 = iter;
            }
        }
        if(loss2 >= loss1) {
            pairs.erase(iter1);
        }
        else {
            temp = iter2 + 1;
            temp->first = iter2->first;
            pairs.erase(iter2);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        if(k==0)
            return 0;
        if(k<0)
            return 0;
        vector<pair<int,int>> pairs;
        int increase = 0;
        int decrease = 0;
        int i = 0;
        while(i+1<prices.size()) {
            int m1, m2;
            while(i+1<prices.size() && prices[i+1]<=prices[i])
                i++;
            m1 = i;
            while(i+1<prices.size() && prices[i+1]>=prices[i])
                i++;
            m2 = i;
            if(m1!=m2)
                pairs.push_back(make_pair(m1, m2));
        }
        while(pairs.size()>k) {
            cutPairs(prices, pairs);
        }
        int sum = 0;
        for(int i=0;i<pairs.size();i++) {
            sum += prices[pairs[i].second] - prices[pairs[i].first];
        }
        return sum;
    }
};