#include "binary_search_tree.h"
#include "macro.h"

BinaryTreeNode::BinaryTreeNode(const int value)
    : m_left(nullptr), m_right(nullptr), m_value(value), m_parent(nullptr)
{
}

BinaryTreeNode::~BinaryTreeNode()
{
}

BinaryTreeNode &BinaryTreeNode::operator=(const BinaryTreeNode &node)
{
    if (this == &node)
    {
        return *this;
    }

    m_left = node.Left();
    m_right = node.Right();
    m_parent = node.Parent();
    m_value = node.Value();

    return *this;
}

BinaryTreeNode *BinaryTreeNode::Left() const
{
    return m_left;
}

void BinaryTreeNode::Left(BinaryTreeNode *left)
{
    m_left = left;
}

BinaryTreeNode *BinaryTreeNode::Right() const
{
    return m_right;
}

void BinaryTreeNode::Right(BinaryTreeNode *right)
{
    m_right = right;
}

BinaryTreeNode *BinaryTreeNode::Parent() const
{
    return m_parent;
}

void BinaryTreeNode::Parent(BinaryTreeNode *parent)
{
    m_parent = parent;
}

int BinaryTreeNode::Value() const
{
    return m_value;
}

void BinaryTreeNode::Value(const int v)
{
    m_value = v;
}

BinarySearchTree::BinarySearchTree()
    : m_root(nullptr)
{
}

BinarySearchTree::~BinarySearchTree()
{
    Clear();
}

void BinarySearchTree::AddNode(const int v)
{
    BinaryTreeNode *n = new BinaryTreeNode(v);
    BinaryTreeNode *node = m_root;

    while (node)
    {
        if (node->Value() >= v)
        {
            if (node->Left() == nullptr)
            {
                n->Parent(node);
                node->Left(n);
                break;
            }
            else
            {
                node = node->Left();
            }
        }
        else
        {
            if (node->Right() == nullptr)
            {
                n->Parent(node);
                node->Right(n);
                break;
            }
            else
            {
                node = node->Right();
            }
        }
    }
}

void BinarySearchTree::RemoveNode(const int v)
{
    BinaryTreeNode *node = m_root;
    int value;

    while (node)
    {
        value = node->Value();
        if (value == v)
        {
            BinaryTreeNode *parent = node->Parent();

            if ((!node->Left()) && (!node->Right())) // leaf node
            {
                if (parent->Left() == node)
                {
                    parent->Left(nullptr);
                }
                else
                {
                    parent->Right(nullptr);
                }
            }
            else if ((!node->Left()) || (!node->Right())) // node only has one-side subtree
            {
                BinaryTreeNode *subNode = (node->Left()) ? node->Left() : node->Right();

                if (parent->Left() == node) // node is left sub-tree
                {
                    parent->Left(subNode);
                    subNode->Parent(parent);
                }
                else
                {
                    parent->Right(subNode);
                    subNode->Parent(parent);
                }
            }
            else // node has both-side subtrees
            {
                BinaryTreeNode *left = node->Left();
                BinaryTreeNode *right = node->Right();
                BinaryTreeNode *rightest_leaf = MostLeftLeaf(right);

                rightest_leaf->Left(left);
                left->Parent(rightest_leaf);

                right->Parent(parent);

                if (parent->Left() == node) // node is left sub-tree
                {
                    parent->Left(right);
                }
                else
                {
                    parent->Right(right);
                }

                parent->Left(right);
            }

            SAFE_DELETE(node);

            break;
        }

        if (value > v)
        {
            node = node->Left();
        }
        else
        {
            node = node->Right();
        }
    }
}

void BinarySearchTree::Clear()
{
    RemoveSubTree(m_root);
}

void BinarySearchTree::RemoveSubTree(BinaryTreeNode *node)
{
    if (!node)
    {
        return;
    }

    if (node->Left())
    {
        RemoveSubTree(node->Left());
    }

    if (node->Right())
    {
        RemoveSubTree(node->Right());
    }

    if ((node->Left() == nullptr) && (node->Right() == nullptr))
    {
        if (node->Parent()->Left() == node)
        {
            node->Parent()->Left(nullptr);
        }

        if (node->Parent()->Right() == node)
        {
            node->Parent()->Right(nullptr);
        }

        SAFE_DELETE(node);
    }
}

BinaryTreeNode *BinarySearchTree::MostLeftLeaf(BinaryTreeNode *node)
{
    BinaryTreeNode *ret = node;

    if (!ret)
    {
        return ret;
    }

    while (ret->Left())
    {
        ret = ret->Left();
    }

    return ret;
}

BinaryTreeNode *BinarySearchTree::MostRightLeaf(BinaryTreeNode *node)
{
    BinaryTreeNode *ret = node;

    if (!ret)
    {
        return ret;
    }

    while (ret->Right())
    {
        ret = ret->Right();
    }

    return ret;
}