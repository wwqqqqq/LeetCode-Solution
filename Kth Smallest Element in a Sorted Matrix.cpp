class Solution {
public:
    int select(vector<int>& array, int beg, int end, int k) {
        int mid = (beg + end) / 2;
        int pivot = array[mid];
        array[mid] = array[beg];
        array[beg] = pivot;
        int i = beg+1;
        int j = beg;
        for(; i <= end; i++) {
            if(array[i] >= pivot)
                continue;
            else {
                j++;
                if(i != j) {
                    int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }
        if(j != beg) {
            array[beg] = array[j];
            array[j] = pivot;
        }
        // the index of pivot in array[beg..end] is j - beg + 1
        int index = j - beg + 1;
        if(index < k) {
            // we should look for our result in array[j..end]
            return select(array, j+1, end, k-index);
        }
        else if(index > k){
            // look for the result in array[beg..j]
            return select(array, beg, j-1, k);
        }
        return pivot;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> array;
        for(int i = 0; i < matrix.size(); i++)
            array.insert(array.end(), matrix[i].begin(), matrix[i].end());
        return select(array, 0, array.size()-1, k);
    }
};