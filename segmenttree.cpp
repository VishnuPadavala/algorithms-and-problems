#include <bits/stdc++.h>
using namespace std;

class segmentTree {
private:
    vector<int> segtree;
    int n;

public:
    segmentTree(int n) {
        this->n = n;
        segtree.resize(4 * n);
    }

    // Build the segment tree
    void build(int index, int start, int end, vector<int>& arr) {
        if (start == end) {
            segtree[index] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(2 * index + 1, start, mid, arr);
        build(2 * index + 2, mid + 1, end, arr);
        segtree[index] = segtree[2 * index + 1] + segtree[2 * index + 2];
    }

    // Range Sum Query
    int rangesum(int ql, int qr, int start, int end, int index) {
        // no overlap
        if (qr < start || ql > end) {
            return 0;
        }
        // total overlap
        if (ql <= start && end <= qr) {
            return segtree[index];
        }
        // partial overlap
        int mid = (start + end) / 2;
        int left = rangesum(ql, qr, start, mid, 2 * index + 1);
        int right = rangesum(ql, qr, mid + 1, end, 2 * index + 2);
        return left + right;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    segmentTree s(n);
    s.build(0, 0, n - 1, arr);

    int l, r;
    cout << "Enter query range (l r): ";
    cin >> l >> r;

    cout << "Range sum = " << s.rangesum(l, r, 0, n - 1, 0) << endl;

    return 0;
}
