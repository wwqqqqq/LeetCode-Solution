class Solution {
public:
    int abs(int x) {
        if(x < 0)
            return -x;
        return x;
    }
    int parent(int n) {
        return (n - 1) / 2;
    }
    int leftChild(int n) {
        return n * 2 + 1;
    }
    void upwardUpdate(vector<int>& heap, int n) {
        if(n == 0)
            return;
        int p = parent(n);
        if(heap[n] > heap[p]) {
            int temp = heap[n];
            heap[n] = heap[p];
            heap[p] = temp;
            upwardUpdate(heap, p);
        }
    }
    void downwardUpdate(vector<int>& heap, int n) {
        int child = leftChild(n);
        if(child < heap.size()) {
            if(child + 1 < heap.size() && heap[child+1] > heap[child])
                child++;
            if(heap[n] < heap[child]) {
                int temp = heap[n];
                heap[n] = heap[child];
                heap[child] = temp;
                downwardUpdate(heap, child);
            }
        }
    }
    void heapInsert(vector<int>& heap, int e) {
        heap.push_back(e);
        upwardUpdate(heap, heap.size()-1);
    }
    void heapUpdate(vector<int>& heap, int e) {
        if(heap.size() == 0)
            return;
        if(e >= heap[0])
            return;
        heap[0] = e;
        downwardUpdate(heap, 0);
    }
    int largestSumAfterKNegations(vector<int>& A, int K) {
        if(A.size() == 0)
            return 0;
        int count_negative = 0;
        for(int i = 0; i < A.size(); i++) {
            if(A[i] < 0)
                count_negative++;
        }
        
        if(count_negative <= K) {
            int sum = 0;
            for(int i = 0; i < A.size(); i++) {
                sum += abs(A[i]);
            }
            if((K - count_negative) % 2 == 0) {
                return sum;
            }
            // find the minimum absolute value of A
            int min = abs(A[0]);
            for(int i = 0; i < A.size(); i++) {
                if(min > abs(A[i]))
                    min = abs(A[i]);
            }
            return sum - 2 * min;
        }
        // can only change K negative elements to positive
        // use the big-end heap to maintain the K smallest elements in vector A
        vector<int> heap;
        int count = 0;
        for(int i = 0; i < A.size(); i++) {
            if(A[i] < 0) {
                count++;
                if(count <= K) {
                    heapInsert(heap, A[i]);
                }
                else {
                    heapUpdate(heap, A[i]);
                }
            }
        }
        int sum_K = 0;
        for(int i = 0; i < K; i++) {
            sum_K -= heap[i];
        }
        // sum_K is the sum of the absolute value of every element in the vector heap
        int sum = 0;
        for(int i = 0; i < A.size(); i++) {
            sum += A[i];
        }
        return sum + 2 * (sum_K);
    }
};