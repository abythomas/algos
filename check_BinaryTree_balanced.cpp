#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <map>
#include <vector>
#include <math.h>

using namespace std;

struct Node{
  int data;
  struct Node *left;
  struct Node *right;
};

struct Node* newNode(int data){
  struct Node *node=(struct Node *)malloc(sizeof(struct Node));
  node->left=NULL;
  node->right=NULL;
  node->data=data;
  return node;
} 

int height(struct Node* node)
{
   if(node == NULL)
       return 0;
   return 1 + max(height(node->left), height(node->right));
} 
 
int isBalanced(struct Node *root){
  if(root==NULL){
    return 1;
  }
  int lh,rh;
  lh=height(root->left);
  rh=height(root->right);
  if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right)){
    return 1;
  }
  else{
    return 0;
  }
}

int main() {
  struct Node *root=newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  //root->left->left->left = newNode(8);
  if(isBalanced(root)){
    cout<<"Balanced\n";
  }
  else{
    cout<<"Not Balanced\n";
  }
  return 0;
}
