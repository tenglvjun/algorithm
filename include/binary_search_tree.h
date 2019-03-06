#if !defined(__BINARY_SEARCH_TREE__)
#define __BINARY_SEARCH_TREE__

class BinaryTreeNode
{
  public:
    BinaryTreeNode(const int value);
    virtual ~BinaryTreeNode();

  public:
    BinaryTreeNode &operator=(const BinaryTreeNode &node);

  public:
    BinaryTreeNode *Left() const;
    void Left(BinaryTreeNode *left);
    BinaryTreeNode *Right() const;
    void Right(BinaryTreeNode *right);
    BinaryTreeNode *Parent() const;
    void Parent(BinaryTreeNode *parent);
    int Value() const;
    void Value(const int v);

  protected:
    BinaryTreeNode *m_left;
    BinaryTreeNode *m_right;
    BinaryTreeNode *m_parent;
    int m_value;
};

class BinarySearchTree
{
  public:
    BinarySearchTree();
    virtual ~BinarySearchTree();

  public:
    void AddNode(const int v);
    void RemoveNode(const int v);

  protected:
    void Clear();
    void RemoveSubTree(BinaryTreeNode *node);

  protected:
    BinaryTreeNode *m_root;
};

#endif // __BINARY_SEARCH_TREE__
