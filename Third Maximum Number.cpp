class Solution {
public:
    void heapify(vector<int>& heap ) {
        if(heap.size() == 1)
            return;
        else if(heap.size() == 2) {
            if(heap[0] > heap[1]) {
                int temp = heap[1];
                heap[1] = heap[0];
                heap[0] = temp;
            }
            return;
        }
        int child = (heap[1] < heap[2])? 1:2;
        if(heap[child] < heap[0]) {
            int temp = heap[0];
            heap[0] = heap[child];
            heap[child] = temp;
        }
    }
    int thirdMax(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        vector<int> heap;
        for(int i = 0; i < nums.size(); i++) {
            if(heap.size() == 3 && heap[0] >= nums[i])
                continue;
            int j;
            for(j = 0; j < heap.size(); j++)
                if(nums[i] == heap[j])
                    break;
            if(j < heap.size())
                continue;
            if(heap.size() < 3) {
                heap.push_back(nums[i]);
                heapify(heap);
            }
            else {
                heap[0] = nums[i];
                heapify(heap);
            }
        }
        if(heap.size() >= 3)
            return heap[0];
        if(heap.size() == 2) {
            return (heap[0] < heap[1])?heap[1]:heap[0];
        }
        if(heap.size() == 1)
            return heap[0];
        return 0;
    }
};