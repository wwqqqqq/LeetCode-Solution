class Solution {
public:
    int distance(vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }
    int distance(int x, int y) {
        return x * x + y * y;
    }
    int parent(int n) {
        return (n-1) / 2;
    }
    int left(int n) {
        return n * 2 + 1;
    }
    void swap(vector<vector<int>>& heap, int i1, int i2) {
        int t1 = heap[i1][0];
        int t2 = heap[i1][1];
        heap[i1][0] = heap[i2][0];
        heap[i1][1] = heap[i2][1];
        heap[i2][0] = t1;
        heap[i2][1] = t2;
    }
    void heapify_upward(vector<vector<int>>& heap, int index) {
        if(index == 0)
            return;
        if(heap.size() == 0)
            return;
        int p = parent(index);
        int pvalue = distance(heap[p]);
        int value = distance(heap[index]);
        if(value > pvalue) {
            swap(heap, index, p);
            return heapify_upward(heap, p);
        }
    }
    void heapify_downward(vector<vector<int>>& heap, int index) {
        int c = left(index);
        if(c >= heap.size())
            return;
        if(c + 1 < heap.size()) {
            // then index node has a right child, too
            if(distance(heap[c]) < distance(heap[c+1]))
                c++;
        }
        if(distance(heap[c]) > distance(heap[index])) {
            swap(heap, c, index);
            return heapify_downward(heap, c);
        }
    }
    void heapInsert(vector<vector<int>>& heap, int x, int y) {
        vector<int> point = {x, y};
        heap.push_back(point);
        heapify_upward(heap, heap.size()-1);
    }
    void heapUpdate(vector<vector<int>>& heap, int x, int y) {
        if(heap.size() == 0)
            return;
        if(distance(x, y) >= distance(heap[0]))
            return;
        heap[0][0] = x;
        heap[0][1] = y;
        heapify_downward(heap, 0);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        // we can a maximum heap
        vector<vector<int>> heap;
        // a maximum heap is that heap[0] is always the maximum value of the vector
        // if we are able to construct and maintain a maximum heap, the value of which are the distance between each points to the origin.
        // then, when a new point come in, we compare it to heap[0]. if the distance is smaller than heap[0], then the new point is know the K closest points to the origin
        if(K >= points.size())
            return points;
        int i;
        for(i = 0; i < K; i++) {
            heapInsert(heap, points[i][0], points[i][1]);
        }
        for(; i < points.size(); i++) {
            heapUpdate(heap, points[i][0], points[i][1]);
        }
        return heap;
    }
};