class Solution {
public:
    void adjustHeap(vector<int>& heap, int ind) {
        if(ind <= 0)
            return;
        int p = (ind - 1) / 2;
        if(heap[p] < heap[ind]) {
            int t = heap[p];
            heap[p] = heap[ind];
            heap[ind] = t;
            adjustHeap(heap, p);
        }
    }
    void initialHeap(vector<int>& heap) {
        int size = heap.size();
        for(int i = size - 1; i>=0; i--) {
            adjustHeap(heap, i);
        }
    }
    void adjustDownHeap(vector<int>& heap) {
        int i = 0;
        while(i < heap.size()) {
            int c1 = i * 2 + 1;
            int c2 = i * 2 + 2;
            int c;
            if(c1 >= heap.size())
                break;
            else if(c2 >= heap.size())
                c = c1;
            else
                c = (heap[c1] < heap[c2])?c2:c1;
            if(heap[i] < heap[c]) {
                int temp = heap[i];
                heap[i] = heap[c];
                heap[c] = temp;
                i = c;
            }
            else
                break;
        }
    }
    double largestSumOfAverages(vector<int>& A, int K) {
        double sum = 0;
        for(auto iter = A.begin(); iter < A.end(); iter++)
            sum += *iter;
        int size = A.size() - K + 1;
        vector<int> heap(A.begin(), A.begin() + size);
        initialHeap(heap);
        for(int i = size; i < A.size(); i++) {
            if(A[i] >= heap[0])
                continue;
            heap[0] = A[i];
            adjustDownHeap(heap);
        }
        double sum2 = 0;
        for(auto iter = heap.begin(); iter < heap.end(); iter++)
            sum2 += *iter;
        sum += sum2 / size - sum2;
        return sum;
    }
};