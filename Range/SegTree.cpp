#include<bits/stdc++.h>
#include<cassert>
#define sz(x) ((int)(x).size())
using namespace std;

using ll = long long;
template<class T>
using vec = vector<T>;

struct SegTree {
public:
    // ===== Customization =====

    using Node = ll;  // ::Node
    inline static const Node ID = 0;

    Node merge(const Node& a, const Node& b) const {
        return a + b;
    }

    void modify(int pos, const Node& x) {
        modify(pos, [&](Node& a) {
            a = x;
        }, 1, 0, n - 1);
    }

    Node query(int ql, int qr) const {
        return query(ql, qr, 1, 0, n - 1);
    }

    // ===== Public Interface =====

    SegTree() = default;

    explicit SegTree(const vec<Node>& a) {
        build(a);
    }

    void assign(int n) {
        assign(n, Node{});
    }

    void assign(int n, const Node& x) {
        assert(n >= 0);
        build(vec<Node>(n, x));
    }

    void build(const vec<Node>& a) {
        n = sz(a);
        tree.assign(4ULL * n, ID);

        if (n > 0) build(a, 1, 0, n - 1);
    }

    template<class F>
    int find_front(int ql, int qr, const F& check) const {
        Node acc = ID;
        return find<false>(ql, qr, acc, check, 1, 0, n - 1);
    }

    template<class F>
    int find_back(int ql, int qr, const F& check) const {
        Node acc = ID;
        return find<true>(ql, qr, acc, check, 1, 0, n - 1);
    }

    template<class F>
    void visit_front(int ql, int qr, const F& f) const {
        visit<false>(ql, qr, f, 1, 0, n - 1);
    }

    template<class F>
    void visit_back(int ql, int qr, const F& f) const {
        visit<true>(ql, qr, f, 1, 0, n - 1);
    }

private:
    // ===== Core Implementation =====
  
    int n = 0;
    vec<Node> tree;

    void build(const vec<Node>& a, int idx, int left, int right) {
        if (left == right) {
            tree[idx] = a[left];
            return;
        }

        int mid = left + (right - left) / 2;

        build(a, idx * 2, left, mid);
        build(a, idx * 2 + 1, mid + 1, right);

        tree[idx] = merge(tree[idx * 2], tree[idx * 2 + 1]);
    }

    template<class F>
    void modify(int pos, const F& f, int idx, int left, int right) {
        assert(left <= pos && pos <= right);

        if (left == right) {
            f(tree[idx]);
            return;
        }

        int mid = left + (right - left) / 2;

        if (pos <= mid) modify(pos, f, idx * 2, left, mid);
        else modify(pos, f, idx * 2 + 1, mid + 1, right);

        tree[idx] = merge(tree[idx * 2], tree[idx * 2 + 1]);
    }

    Node query(int ql, int qr, int idx, int left, int right) const {
        if (ql > qr) return ID;

        assert(left <= ql && qr <= right);

        if (ql == left && qr == right)
            return tree[idx];

        int mid = left + (right - left) / 2;

        if (qr <= mid) return query(ql, qr, idx * 2, left, mid);
        if (ql > mid) return query(ql, qr, idx * 2 + 1, mid + 1, right);

        return merge(query(ql, mid, idx * 2, left, mid), query(mid + 1, qr, idx * 2 + 1, mid + 1, right));
    }
    
    template<bool rev = false, class F>
    void visit(int ql, int qr, const F& f, int idx, int left, int right) const {
        if (ql > qr) return;

        assert(left <= ql && qr <= right);

        if (ql == left && qr == right) {
            f(tree[idx]);
            return;
        }

        int mid = left + (right - left) / 2;

        if (qr <= mid) visit<rev>(ql, qr, f, idx * 2, left, mid);
        else if (ql > mid) visit<rev>(ql, qr, f, idx * 2 + 1, mid + 1, right);
        else {
            if constexpr (rev) {
                visit<rev>(mid + 1, qr, f, idx * 2 + 1, mid + 1, right);
                visit<rev>(ql, mid, f, idx * 2, left, mid);
            }
            else {
                visit<rev>(ql, mid, f, idx * 2, left, mid);
                visit<rev>(mid + 1, qr, f, idx * 2 + 1, mid + 1, right);
            }
        }
    }

    template<bool rev = false, class F>
    int find(int ql, int qr, Node& acc, const F& check, int idx, int left, int right) const {
        if (ql > qr) return -1;

        assert(left <= ql && qr <= right);

        if (ql == left && qr == right) {
            Node next = rev ? merge(tree[idx], acc) : merge(acc, tree[idx]);

            if (!check(next)) {
                acc = next;
                return -1;
            }

            if (left == right) return left;
        }

        int mid = left + (right - left) / 2;

        if (qr <= mid) return find<rev>(ql, qr, acc, check, idx * 2, left, mid);
        if (ql > mid) return find<rev>(ql, qr, acc, check, idx * 2 + 1, mid + 1, right);

        if constexpr (rev) {
            int res = find<rev>(mid + 1, qr, acc, check, idx * 2 + 1, mid + 1, right);
            if (res != -1) return res;

            return find<rev>(ql, mid, acc, check, idx * 2, left, mid);
        }
        else {
            int res = find<rev>(ql, mid, acc, check, idx * 2, left, mid);
            if (res != -1) return res;

            return find<rev>(mid + 1, qr, acc, check, idx * 2 + 1, mid + 1, right);
        }
    }
};