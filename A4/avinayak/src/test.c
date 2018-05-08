#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTreeAPI.h"
#include "Integer.h"

int main(){

  // Test 1
   printf("Testing createBinTree\n");
   Tree* tree = createBinTree(&compareData, &destroyData);
   if(tree != NULL)printf("The tree is successfully created\n");

  // Test 2
   printf("Testing createTreeNode\n");
   TreeNode* node = createTreeNode((TreeDataPtr)2);
   if(node!=NULL && node->data == (TreeDataPtr)2){
      printf("The node is successfully created and it has the value 2 in it\n");
   }

   //Test 3
   printf("Testing addToTree\n");
   addToTree(tree, (TreeDataPtr)2);
   if(tree->root !=NULL){
      if(tree->root->data == (TreeDataPtr)2)printf("Successfully entered 2 into the tree as the root node\n");
   } else printf("Test Failed\n");

   
   addToTree(tree, (TreeDataPtr)3);
   if(tree->root->right!=NULL){
      if(tree->root->right->data == (TreeDataPtr)3)printf("Successfully entered 3 into the tree as the right child node\n");
   } else printf("Test Failed\n");
   

   return 0;
}
