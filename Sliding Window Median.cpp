class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        // simple method: O(n^2 logk)
        // do the numbers have a range or are they just 32-bit integers?
        // another method: maintain two heaps, store the larger half of the window and the smaller half of the window
        // the smaller half of the window -> maximum heap
        // the large half of the window -> minimum heap
        // use a set to store numbers that is in the smaller half
        // delete the number that just gets out of the window from the heaps
        // if the h1.size() < h2.size(), insert new number into h1, otherwise h2
    }
};