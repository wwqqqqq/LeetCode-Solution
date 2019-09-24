class Solution {
public:
    int left(int n) {
        return n * 2 + 1;
    }
    int right(int n) {
        return 2 * (n + 1);
    }
    int parent(int n) {
        return (n - 1) / 2;
    }
    int abs(int x) {
        if(x < 0)
            return (-x);
        return x;
    }
    bool larger(int e1, int e2, int x) {
        int d1 = abs(e1 - x);
        int d2 = abs(e2 - x);
        if(d1 > d2 || (d1 == d2 && e1 > e2))
            return true;
        return false;
    }
    void heapsort(vector<int>& heap, int n, int x) {
        int child = left(n);
        if(child < heap.size()) {
            if(child + 1 < heap.size()) {
                if(larger(heap[child+1], heap[child], x))
                    child++;
            }
            if(larger(heap[child], heap[n], x)) {
                int t = heap[child];
                heap[child] = heap[n];
                heap[n] = t;
                heapsort(heap, child, x);
            }
        }
    }
    void heapinsert(vector<int>& heap, int e, int x) {
        if(larger(e, heap[0], x))
            return;
        heap[0] = e;
        heapsort(heap, 0, x);
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if(arr.size() <= k) {
            sort(arr.begin(), arr.end());
            return arr;
        }
        if(k == 0) {
            vector<int> result;
            return result;
        }
        // big-end heap to store all the difference between array[i] and x
        vector<int> heap(k, 0);
        for(int i = 0; i < k; i++) {
            heap[i] = arr[i];
        }
        // INITIALIZATION: sort the heap
        for(int i = heap.size()-1; i >= 0; i--)
            heapsort(heap, i, x);
        // examine the rest of arr
        for(int i = k; i < arr.size(); i++) {
            heapinsert(heap, arr[i], x);
        }
        // now we get the big-end heap of k nearest element
        sort(heap.begin(), heap.end());
        return heap;
    }
};