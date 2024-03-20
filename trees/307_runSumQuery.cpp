class SegmentTree {
public:
    SegmentTree*    left = nullptr;  
    SegmentTree*    right = nullptr;
    int             sum;
    int             L;
    int             R;
    
    SegmentTree(int total, int l_index, int r_index) {
        sum = total;
        L = l_index;
        R = r_index;
    }

    static  SegmentTree*    build(vector<int>& nums, int l_index, int r_index) {
        if (l_index == r_index) {
            return (new SegmentTree(nums[l_index], l_index, r_index));
        }

        SegmentTree*    root = new SegmentTree(0, l_index, r_index);
        int             m_index = (l_index + r_index) / 2;

        root->left = SegmentTree::build(nums, l_index, m_index);
        root->right = SegmentTree::build(nums, m_index + 1, r_index);
        root->sum = root->left->sum + root->right->sum;

        return (root);
    }

    bool update(int index, int val) {
        if (index < L || index > R) {
            return false;
        } 
        else if (index == L && index == R) {
            sum = val;
            return true;
        }

        int m_index = (L + R) / 2;

        if (index > m_index) {
            right->update(index, val);
        } else {
            left->update(index, val);
        }
        sum = left->sum + right->sum;
        return (true);
    }

    int sumRange(int left, int right) {
        if (left > right || left < L || right > R) {
            return (-1);
        }
        else if (left == L && right == R) {
            return (sum);
        }

        int m_index = (L + R) / 2;

        if (right <= m_index) {
            return (this->left->sumRange(left, right));
        } 
        else if (left > m_index) {
            return (this->right->sumRange(left, right));
        } 
        else {
            return (this->left->sumRange(left, m_index) + this->right->sumRange(m_index + 1, right));
        }
    }
};

class NumArray {
public:
    NumArray(vector<int>& nums) {
        root = SegmentTree::build(nums, 0, nums.size() - 1);
    }

    void update(int index, int val) {
        root->update(index, val);
    }
    
    int sumRange(int left, int right) {
        return (root->sumRange(left, right));
    }

private:
    SegmentTree*    root = nullptr;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
