class Solution {
public:
    int abs(int n) {
        if(n < 0) return (-n);
        return n;
    }
    int leftIndex(int n) {
        return n * 2 + 1;
    }
    int rightIndex(int n) {
        return n * 2 + 2;
    }
    int parentIndex(int n) {
        return (n - 1) / 2;
    }
    void shiftUp(vector<int>& heap, int i) {
        while(i > 0) {
            int p = parentIndex(i);
            if(heap[p] < heap[i]) {
                int temp = heap[p];
                heap[p] = heap[i];
                heap[i] = temp;
            }
            i = p;
        }
    }
    void shiftDown(vector<int>& heap, int i) {
        while(leftIndex(i) < heap.size()) {
            int c = leftIndex(i);
            if(c + 1 < heap.size() && heap[c+1] > heap[c])
                c = c + 1;
            if(heap[i] >= heap[c])
                break;
            int temp = heap[i];
            heap[i] = heap[c];
            heap[c] = temp;
            i = c;
        }
    }
    /*void initHeap(vector<int>& heap) {
        int k = heap.size();
        for(int i = heap.size() - 1; i > 0; i--) {
            int p = parentIndex(i);
            if(heap[p] < heap[i])
                shiftDown(heap, p);
        }
    }*/
    void insertElement(vector<int>& heap, int e) {
        heap.push_back(e);
        shiftUp(heap, heap.size()-1);
    }
    void update(vector<int>& heap, int e) {
        int k = heap.size();
        heap[0] = e;
        shiftDown(heap, 0);
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        // First, find all distances
        // Second, find the k-th smallest one
        // use a heap to store k elements
        int count = 0;
        vector<int> heap;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                int distance = abs(nums[i] - nums[j]);
                if(count < k)
                    insertElement(heap, distance);
                else {
                    if(distance < heap[0])
                        update(heap, distance);
                }
                count++;
            }
        }
        return heap[0];
    }
};