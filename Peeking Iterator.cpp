// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.

class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
    int data = 0;
    bool has_data = false;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    if(Iterator::hasNext()) {
            data = Iterator::next();
            has_data = true;
        }
        else return;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return data;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        int result = data;
	    if(Iterator::hasNext()) {
            data = Iterator::next();
        }
        else has_data = false;
        return result;
	}

	bool hasNext() const {
	    return has_data;
	}
};