/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

void printLeaves(Node* root,vector<int>&v) 
{ 
    if (root == NULL) 
        return; 
  
    printLeaves(root->left,v); 
  
    // Print it if it is a leaf node 
    if (!(root->left) && !(root->right)) 
        v.push_back(root->data);
  
    printLeaves(root->right,v); 
} 
  
// A function to print all left boundary nodes, except a leaf node. 
// Print the nodes in TOP DOWN manner 
void printBoundaryLeft(Node* root,vector<int>&v) 
{ 
    if (root == NULL) 
        return; 
  
    if (root->left) { 
  
        // to ensure top down order, print the node 
        // before calling itself for left subtree 
        v.push_back(root->data); 
        printBoundaryLeft(root->left,v); 
    } 
    else if (root->right) { 
        v.push_back(root->data); 
        printBoundaryLeft(root->right,v); 
    } 
    // do nothing if it is a leaf node, this way we avoid 
    // duplicates in output 
} 
  
// A function to print all right boundary nodes, except a leaf node 
// Print the nodes in BOTTOM UP manner 
void printBoundaryRight(Node* root,vector<int>&v) 
{ 
    if (root == NULL) 
        return; 
  
    if (root->right) { 
        // to ensure bottom up order, first call for right 
        // subtree, then print this node 
        printBoundaryRight(root->right,v); 
        v.push_back(root->data);
    } 
    else if (root->left) { 
        printBoundaryRight(root->left,v); 
        v.push_back(root->data); 
    } 
    // do nothing if it is a leaf node, this way we avoid 
    // duplicates in output 
} 
  
// A function to do boundary traversal of a given binary tree 




vector <int> printBoundary(Node *root)
{
    vector<int>v;
     if(!root)
     {
         return v;
     }
  
    v.push_back(root->data); 
  
    // Print the left boundary in top-down manner. 
    printBoundaryLeft(root->left,v); 
  
    // Print all leaf nodes 
    printLeaves(root->left,v); 
    printLeaves(root->right,v); 
  
    // Print the right boundary in bottom-up manner 
    printBoundaryRight(root->right,v); 
     
     return v;
     
     
     
     
     
}
