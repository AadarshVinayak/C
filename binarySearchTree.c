#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTreeAPI.h"



Tree * createBinTree(CompareFunc compare, DeleteFunc del){
   Tree *tree = malloc(sizeof(Tree));
   tree->root = NULL;
   tree->compareFunc = compare;
   tree->deleteFunc = del;
   return tree;
}


TreeNode* createTreeNode(TreeDataPtr data){
   TreeNode* node = malloc(sizeof(TreeNode));
   node->data = data;
   node->left = NULL;
   node->right=NULL;
   return node;
}

void addToTree(Tree* theTree, TreeDataPtr data){
   if(theTree->root==NULL){
      theTree->root = createTreeNode(data);
   } else {
      theTree->root = findInsertNode(theTree->root, data, theTree);
   }
}

TreeNode *findInsertNode(TreeNode* currentNode, TreeDataPtr data, Tree * tree){  	
   if(currentNode == NULL){
      return createTreeNode(data);
   }

   if(tree->compareFunc(currentNode->data, data)<0){
      currentNode->right = findInsertNode(currentNode->right, data, tree);
   } else if(tree->compareFunc(currentNode->data, data)>=0){
      currentNode->left = findInsertNode(currentNode->left, data, tree);
   }
   return currentNode;
}

TreeNode* find(TreeNode* currentNode, TreeDataPtr data, Tree* tree){
   if(currentNode == NULL)return NULL;
   if(tree->compareFunc(currentNode->data,data)==0){
      return currentNode->data;
   }else if(tree->compareFunc(currentNode->data,data)<0){
      return find(currentNode->right, data, tree);
   } else return find(currentNode->left, data, tree);
}

void removeFromTree(Tree* theTree, TreeDataPtr data){
   theTree->root = delete(theTree->root, data, tree);
}

treeNode* delete(TreeNode* node, TreeDataPtr data, Tree* tree){
   treeNode *temp;
   if(node ==NULL)return node;
   if(tree->compareFunc(node->data, data)<0){
       node->right = delete(node->right, data, tree);
   } else if(tree->compareFunc(node->data, data)>0){
       node->left = delete(node->left, data, tree);
   } else {
       if(node->right!=NULL && node->left!=NULL){
          temp = findMinimum(tree, node->right);
	  node->data = temp->data;
	  node->right = delete(node->right, temp->data, tree);
       } else {
          temp=node;
	  if(node->left==NULL){
             node= node->right;
	  } else if(node->right == NULL){
             node = node->left;
	  }
	  free(temp);
       }
   }
   return node;
}


TreeDataPtr findInTree(Tree* theTree, TreeDataPtr data){
   return find(theTree->root, data, theTree);
}

TreeDataPtr getRootData(Tree* tree){
   if(tree->root!=NULL)return tree->root->data;
   return NULL;
}

int isTreeEmpty(Tree* tree){
   if(tree!=NULL)return 1;
   return 0;
}

int isLeaf(TreeNode* treeNode){
   if(treeNode->left == NULL && treeNode->right==NULL)return 1;
   return 0;
}

int hasTwoChildren(TreeNode * treeNode){
   if(treeNode->left == NULL && treeNode->right==NULL)return 0;
   return 1;
}

int getHeight(TreeNode *treeNode){
   if(treeNode==NULL)return 0;
   int left = getHeight(treeNode->left);
   int right = getHeight(treeNode->right);
   if(left>right){
     return left+1;
   } else {
     return right+1;
   }
}
