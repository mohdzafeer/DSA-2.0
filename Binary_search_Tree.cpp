#include <iostream>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        node *left;
        node *right;
    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

node* insertIntoBST(node* root,int d){
    // base case
    if(root==NULL){
        root=new node(d);
        return root;
    }

    if(d>root->data){
        // right part me insert krna h
        root->right=insertIntoBST(root->right,d);
    }
    else{
        // left me insert krna h
        root->left=insertIntoBST(root->left,d);
    }
    return root;
}

void takeInput(node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root=insertIntoBST(root,data);
        cin>>data;
    }
}

void levelOrderTraversal(node *root)
{
    // level order traversal func revoked
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();

        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int minVal(node* root){
    node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp->data;
}
int maxVal(node* root){
    node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp->data;
}

node* deleteFromBST(node* root,int val){
    // base case
    if(root==NULL)
        return root;
    
    if(root->data==val){
        // 0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        // 1 child
        // left child
        if(root->left !=NULL && root->right==NULL){
            node*temp=root->left;
            delete root;
            return temp;
        }
        // right child
        if(root->right !=NULL && root->left==NULL){
            node*temp=root->right;
            delete root;
            return temp;
        }


        // 2 child

        if(root->left != NULL && root->right!=NULL){
            int mini=minVal(root->right);
            root->data=mini;
            root->right=deleteFromBST(root->right,mini);
            return root;
        }

    }else if(root->data > val){
        root->left = deleteFromBST(root->left,val);
        return root;
    }else{
        root->right=deleteFromBST(root->right,val);
        return root;
    }
}

int main(){
    node* root=NULL;
    cout<<"ENter data to create BST"<<endl;
    takeInput(root);
    cout<<"Printing BST"<<endl;
    levelOrderTraversal(root);
    cout<<"Miniumum val = "<<minVal(root)<<endl;
    cout<<"Maximum val = "<<maxVal(root)<<endl;
    
    root=deleteFromBST(root,30);
    cout<<"Printing BST"<<endl;
    levelOrderTraversal(root);

    return 0;
}