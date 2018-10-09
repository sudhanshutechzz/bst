#include <iostream>
#include<cstdlib>

using namespace std;
struct node
{
    int key;
    struct node *left;
    struct node *right;

};
struct node* newnode(int data)
{
 struct node* node=(struct node*)malloc(sizeof(struct node));
 node->key=data;
 node->left=NULL;
 node->right=NULL;
 return node;
}
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->key<<endl;
        inorder(root->right);
    }
}
struct node* insert(struct node* node,int key)
{
 if(node==NULL)
        return newnode(key);
 if(key<node->key)
    node->left=insert(node->left,key);
 else if(key>node->key)
    node->right=insert(node->right,key);
 return node;
}
struct node* find(struct node* node,int key)
{
 if(node==NULL||node->key==key)
        return node;
 if(node->key<key)
    return find(node->right,key);
 else if(node->key>key)
    return find(node->left,key);

}
struct node* minvaluenode(struct node* node)
{
 struct node* current=node;
 while(current->left!=NULL)
        current=current->left;
 return current;
}
struct node* deletenode(struct node * root,int key)
{
 if(root==NULL)
        return root;
 if(key<root->key)
    root->left=deletenode(root->left,key);
 else if(key>root->key)
    root->right=deletenode(root->right,key);
 else
 {
     if(root->left==NULL)
     {
         struct node* temp=root->right;
         free(root);
         return temp;
     }
     else if(root->right==NULL)
     {
         struct node*temp=root->left;
         free(root);
         return temp;
     }
     struct node* temp=minvaluenode(root->right);
     root->key=temp->key;
     root->right=deletenode(root->right,temp->key);

 }
 return root;
}

int main()
{struct node *root=NULL,*x;
int key;
    root=insert(root,50);
    insert(root,30);
    insert(root,20);
    insert(root,40);
    insert(root,70);
    insert(root,60);
    insert(root,80);
    inorder(root);
    cout<<"delete 20"<<endl;
    root=deletenode(root,20);
    inorder(root);


}
