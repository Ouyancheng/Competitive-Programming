/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/
    void go(Node * root,vector<int> &a) {
        if(root == 0) return;
        go(root->left,a);
        a.push_back(root->data);
        go(root->right,a);
    }
   bool checkBST(Node* root) {
       vector<int> a;
       go(root,a);
       for(int i = 1; i < a.size(); i++) {
           if(a[i] <= a[i-1]) {
               return false;
           }
       }
      return true;
   }
