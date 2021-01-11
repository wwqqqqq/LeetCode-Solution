class SparseVector {
public:
    vector<pair<int,int>> values;
    int dimension;
    
    SparseVector(vector<int> &nums) {
        dimension = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                values.push_back(pair<int,int>(i,nums[i]));
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        if (vec.dimension != dimension)
            return 0;
        int result = 0;
        int i = 0, j = 0;
        while (i < values.size() && j < vec.values.size()) {
            if (values[i].first == vec.values[j].first) {
                result += values[i].second * vec.values[j].second;
                i++;
                j++;
            }
            else if (values[i].first > vec.values[j].first) {
                j++;
            }
            else {
                i++;
            }
        }
        return result;
    }
    
    // follow up
    int dotProduct(vector<int>& vec) {
        // not sure if vec is dense or sparse
        if (dimension != vec.size()) {
            return 0;
        }
        int result = 0;
        for (int i = 0; i < values.size(); i++) {
            int index = values[i].first;
            int v = values[i].second;
            result += v * vec[index];
        }
        return result;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);