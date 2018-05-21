#!/usr/bin/python

class Node:
    def __init__(self,key):
        self.val=key
        self.left=None
        self.right=None
        self.height=1

class AVL:
    def insert(self,root,key):                                                  #insert a node into the BST and balance it
        if not root:
            return Node(key)
        elif key<root.val:
            root.left=self.insert(root.left,key)
        else:
            root.right=self.insert(root.right,key)

        root.height=1+max(self.getHeight(root.left),self.getHeight(root.right))

        balance=self.getBalance(root)

        if balance > 1 and key < root.left.val:
            return self.rotateRight(root)

        if balance < -1 and key > root.right.val:
            return self.rotateLeft(root)

        if balance > 1 and key > root.left.val:
            root.left = self.rotateLeft(root.left)
            return self.rotateRight(root)

        if balance < -1 and key < root.right.val:
            root.right = self.rotateRight(root.right)
            return self.rotateLeft(root)

        return root

    def getHeight(self,root):
        if not root:
            return 0
        return root.height

    def getBalance(self,root):
        if not root:
            return 0
        return self.getHeight(root.left)-self.getHeight(root.right)

    def preOrder(self, root):
        if not root:
            return
        print root.val,
        self.preOrder(root.left)
        self.preOrder(root.right)

    def rotateLeft(self,root):
        z=root.right
        T=z.left
        z.left=root
        root.right=T
        root.height = 1 + max(self.getHeight(root.left),
                         self.getHeight(root.right))
        z.height = 1 + max(self.getHeight(z.left),
                         self.getHeight(z.right))
        return z

    def rotateRight(self, root):
        y = root.left
        T3 = y.right
        y.right = root
        root.left = T3
        root.height = 1 + max(self.getHeight(root.left),
                        self.getHeight(root.right))
        y.height = 1 + max(self.getHeight(y.left),
                        self.getHeight(y.right))
        return y

print("Enter -1 to stop")
i=int(input())
tree=AVL()
root=None
while(i!=-1):
    root=tree.insert(root,i)
    i=int(input())
tree.preOrder(root)
