#ifndef _BSTREE_H_
#define _BSTREE_H_

typedef int element;

typedef struct btreenode{
	element data;
	struct btreenode* llink, * rlink;
} TreeNode;

// void init_node(TreeNode*); // <- I think this only makes things more compicated....

// return the address of the node with the specified element as data (NULL if there isn't one)
TreeNode* find(TreeNode*, element);

// return the address of the parent of the specified node from the specified tree. (NULL on failure)
TreeNode* find_parent(TreeNode*, TreeNode*);

// Make a node from the specified element, and insert it under the specified node (if applicable)
TreeNode* tinsert(TreeNode*, element);

// Find a node with the specified element from the specified tree, and remove it from the tree.Does nothing on failure.
TreeNode* tremove(TreeNode*, element);

// Count the number of nodes.
int count(TreeNode*);

// Print all nodes in ascending order, using inorder traversing.
void printall(TreeNode*);

#endif