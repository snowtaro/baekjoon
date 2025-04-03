#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, m, k;
vector<long long> arr;
vector<long long> segTree;

void build(int node, int start, int end) {
    if (start == end) {
        segTree[node] = arr[start - 1];
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
    }
}

long long query(int node, int start, int end, int L, int R) {
    if (R < start || end < L) return 0;
    if (L <= start && end <= R) return segTree[node];

    int mid = (start + end) / 2;
    long long leftSum = query(2 * node, start, mid, L, R);
    long long rightSum = query(2 * node + 1, mid + 1, end, L, R);

    return leftSum + rightSum;
}

void update(int node, int start, int end, int idx, long long newValue) {
    if (start == end) {
        arr[idx - 1] = newValue;
        segTree[node] = newValue;
    } else {
        int mid = (start + end) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, newValue);
        } else {
            update(2 * node + 1, mid + 1, end, idx, newValue);
        }
        segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    arr.resize(n);
    segTree.resize(4 * n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    build(1, 1, n);

    int a, b;
    long long c;
    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;

        if (a == 1) {
            update(1, 1, n, b, c);
        } else if (a == 2) {
            cout << query(1, 1, n, b, c) << '\n';
        }
    }
}
