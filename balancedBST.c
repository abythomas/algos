#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* left;
  struct Node* right;
};

int count=0;
int a[1000];

struct Node *newNode(int item)
{
    struct Node *temp =  (struct Node *)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* insert(struct Node* node, int key)
{
    if (node == NULL) return newNode(key);
    if (key < node->data)
        node->left  = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    return node;
}


void storenodes(struct Node *root){
  if(root==NULL)
  {
    return;
  }
  storenodes(root->left);
  a[count]=root->data;
  count++;
  storenodes(root->right);
}

struct Node* createBalancedBST(int start, int end)
{
    struct Node *root =  (struct Node *)malloc(sizeof(struct Node));
    if (start > end)
        return NULL;
    int mid = (start + end)/2;
    root->data=a[mid];
    root->left  = createBalancedBST(start, mid-1);
    root->right = createBalancedBST(mid+1, end);
    return root;
}


struct Node* balance_BST(struct Node *root){
  storenodes(root);
  root=createBalancedBST(0,count-1);
  return root;
}

void preorder(struct Node *root)
{
  if(root==NULL)
  {
    return;
  }
  printf("%d",root->data);
  preorder(root->left);
  preorder(root->right);
}

int max(int a, int b)
{
  if(a > b)
  {
    return a;
  }
  return b;
}

int height(struct Node* root)
{
  if(root==NULL)
  {
    return 0;
  }
  else {
    return 1+max(height(root->left),height(root->right));
  }
}

void printGivenLevel(struct Node* root, int level)
{
    if (root == NULL && level==1){
      printf("* ");
      return;
    }
    if(root==NULL && level>1)
    {
      printGivenLevel(NULL, level-1);
      printGivenLevel(NULL, level-1);
      return;
    }
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

void printLevelOrder(struct Node* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
    {
        printGivenLevel(root, i);
        printf("\n");
    }
}



int main()
{
  int i,n,c;
  struct Node *root=NULL;
  printf("Enter node values (0 to stop) :\n");
  scanf("%d",&i);
  while(i!=0){
  root=insert(root,i);
  scanf("%d",&i);
  }
  printf("\n***Unbalanced Tree***\n\n");
  printLevelOrder(root);
  printf("\n");
  printf("Balancing...\n");
  root=balance_BST(root);
  printf("***Balanced Tree***\n\n");
  printLevelOrder(root);
  printf("\n");
}
