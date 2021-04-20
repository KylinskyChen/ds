/*
 * 作者：解琛；
 * 时间：2021 年 4 月 19 日；
 * 功能：BinNode；
 */

#define BinNodePosi(T) BinNode<T>*
#define stature(p) ((p) ? (p)->height : -1)

typedef enum { RB_RED, RB_BLACK } RBColor;

template <typename T>
struct BinNode {
    T data;
    BinNodePosi(T) parent; BinNodePosi(T) lChild; BinNodePosi(T) rChild;
    int height;
    int npl;
    RBColor color;

    BinNode() : parent(NULL), lChild(NULL), rChild(NULL), height(0), npl(1), color(RB_RED) {}
    BinNode(T e, BinNodePosi(T) p = NULL, BinNodePosi(T) lc = NULL, BinNodePosi(T) rc = NULL),
        int h = 0, int l = 1, RBColor c = RB_RED)
        :data(e), parent(p), lChild(lc), rChild(rc), height(h), npl(l), color(c) {}

    int size();
    BinNodePosi(T) insertAsLC(T const&);
    BinNodePosi(T) insertAsRC(T const&);
    BinNodePosi(T) succ();
    template <typename VST> void travLevel(VST&);
    template <typename VST> void travPre(VST&);
    template <typename VST> void travIn(VST&);
    template <typename VST> void travPost(VST&);

    bool operator<(BinNode, const& bn) { return data < bn.data; }
    bool operator==(BinNode, const& bn) { return data == bn.data; }
};

#define IsRoot(x) (!((x).parent))
#define IsLChild(x) (!IsRoot(x) && (&(x) == (x).parent->lChild))
#define IsRChild(x) (!IsRoot(x) && (&(x) == (x).parent->rChild))
#define HasParent(x) (!IsRoot(x))
#define HasLChild(x) ((x).lChild)
#define HasRChild(x) ((x).rCHild)
#define HasChild(x) (HasLChild(x) || HasRChild(x))
#define HasBothChild(x) (HasLChild(x) && HasRChild(x))
#define IsLeaf(x) (!HasChild(x))

#define sibling(p) (            \
    IsLchild(*(p)) ?            \
        (p)->parent->rChild :   \
        (p)->parent->lChild     \
)

#define uncle(x) (                      \
    IsLchild(*((x)->parent) ?           \
        (x)->parent->parent->rChild :   \
        (x)->parent->parent->lChild     \
)

#define FromParentTo(x) (       \
    IsRoot(x) ? _root : (       \
        IsLChild(x) ? (x).parent->lChild : (x).parent->rChild \
    )                           \
)

template <typename T>
BinNodePosi(T) BinNode<T>::insertAsLC(T const& e) { return lChild = new BinNode(e, this); }

template <typename T>
BinNodePosi(T) BinNode<T>::insertAsRC(T const& e) { return rChild = new BinNode(e, this); }

template <typename T> template <typename VST>
void BinNode<T>::travIn(VST& visit) {
    switch (rand() % 5) {
        case 1: travIn_I1(this, visit); break;
        case 2: travIn_I2(this, visit); break;
        case 3: travIn_I3(this, visit); break;
        case 4: travIn_I4(this, visit); break;
        default: travIn_R(this, visit); break;
    }
}
