/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  int ll;
typedef unsigned long long int ull;
typedef unsigned int ul;
map<int,int> mp1;
//set<int> s1;
//set<char>::iterator t;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
};
struct Node *new_node(int num){
    Node *temp = (Node * )malloc(sizeof(Node));
    temp->key = num;
    temp->left = NULL;
    temp->right = NULL;
}
void inorder(Node *root)
{
if(root==NULL)
return ;
inorder(root->left);
cout<<root->key<<" ";
inorder(root->right);
}
void getPar(Node *root, int parent, Node **temp){
    if(root==NULL){
        return;
    }
    if(root->key==parent){
        (*temp) = root;
    }
    getPar(root->left,parent,temp);
    getPar(root->right, parent,temp);
}
