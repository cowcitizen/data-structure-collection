/**
 * Binary Search Tree implementation using recursion.
 * Assumes that no two nodes with the same data can exist in the same tree.
 */

#include<stdio.h>
#include<stdlib.h>
#include "bstree.h"

TreeNode* find(TreeNode* t, element e){
	if(t == NULL) return NULL;
	else if(t->data == e) return t;
	else if(t->llink == NULL && t->rlink == NULL){
		return NULL; // Search has failed!
	} else {
		TreeNode* l, * r;

		l = find(t->llink, e);
		r = find(t->rlink, e);

		if(l == NULL) return r; // return the non-NULL one (if there is one)
		else return l;
	}
}

TreeNode* find_parent(TreeNode* tree, TreeNode* node){
	// slightly bad naming; `tree` is the current node being inspected
	if(tree == node) return NULL;
	else if(tree->llink == node || tree->rlink == node) return tree;
	else{
		if(tree->data > node->data) return find_parent(tree->llink, node);
		else return find_parent(tree->rlink, node);
	}
}

TreeNode* tinsert(TreeNode* t, element e){
	if(t == NULL){
		TreeNode* newnode = (TreeNode*)malloc(sizeof(TreeNode));
		newnode->data = e;
		newnode->llink = NULL;
		newnode->rlink = NULL;
		return newnode;
	}
	if(t->data == e){
		return NULL; // It is a duplicate value. Failed to insert.
	} else if(t->data > e){
		if(t->llink == NULL){
			TreeNode* newnode = (TreeNode*)malloc(sizeof(TreeNode));
			newnode->data = e;
			newnode->llink = NULL;
			newnode->rlink = NULL;
			t->llink = newnode;
			return newnode;
		} else {
			return tinsert(t->llink, e);
		}
	} else { // if t->data < e
		if(t->rlink == NULL){
			TreeNode* newnode = (TreeNode*)malloc(sizeof(TreeNode));
			newnode->data = e;
			newnode->llink = NULL;
			newnode->rlink = NULL;
			t->rlink = newnode;
			return newnode;
		} else {
			return tinsert(t->rlink, e);
		}
	}
}

TreeNode* tremove(TreeNode* t, element e){
	TreeNode* removed = find(t, e);
	if(removed == NULL){
		return t; // Tried to remove nonexistent data.
	} else {
		// find the parent of *removed, and do appropriate action depending on the number of children.
		TreeNode* parent = find_parent(t, removed);
		
		if(removed->llink != NULL && removed->rlink != NULL){
			// find the nearest value... could be done w/ the while loop.
			TreeNode* lnear, * rnear;

			// find the node with the biggest value on the left subtree
			lnear = removed->llink;
			while(lnear->rlink != NULL){
				lnear = lnear->rlink;
			}

			// find the node with the smallest value on the right subtree
			rnear = removed->rlink;
			while(rnear->llink != NULL){
				rnear = rnear->llink;
			}
			
			// if lnear is the more close node
			if(removed->data - lnear->data < rnear->data - removed->data){
				if(parent != NULL){
					if(parent->data > removed->data) parent->llink = lnear;
					else parent->rlink = lnear;
				}
				lnear->rlink = rnear;
				free(removed);
				if(parent == NULL) return lnear; // return the new head if the head changes
			} else {
				if(parent != NULL){
					if(parent->data > removed->data) parent->llink = rnear;
					else parent->rlink = rnear;
				}
				rnear->llink = lnear;
				free(removed);
				if(parent == NULL) return rnear;
			}
		} else if(removed->llink == NULL && removed->rlink == NULL){
			if(parent != NULL){ // clear the link from parent.
				if(parent->data > removed->data) parent->llink = NULL;
				else parent->rlink = NULL;
			}
			free(removed);
			if(parent == NULL){
				return NULL; // Return NULL if it was the last node in the tree.
			}
		} else if(removed->llink != NULL && removed->rlink == NULL){
			TreeNode* newhead = NULL;
			if(parent != NULL){
				if(parent->data > removed->data) parent->llink = removed->llink;
				else parent->rlink = removed->llink;
			} else {
				newhead = removed->llink;
			}
			free(removed);
			if(parent == NULL) return newhead;
		} else { // removed->llink == NULL && removed->rlink != NULL
			TreeNode* newhead = NULL;
			if(parent != NULL){
				if(parent->data > removed->data) parent->llink = removed->rlink;
				else parent->rlink = removed->rlink;
			} else {
				newhead = removed->rlink;
			}
			free(removed);
			if(parent == NULL) return newhead;
		}
	}
	return t;
}

int count(TreeNode* t){
	if(t == NULL){return 0;}
	else{
		return 1 + count(t->llink) + count(t->rlink);
	}
}

void printall(TreeNode* t){
	if(t == NULL) return;
	else{
		printall(t->llink);
		printf("%d ", t->data); // TODO change if element type is different
		printall(t->rlink);
	}
}