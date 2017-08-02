/* Node is defined as :
 class Node 
    int data;
    Node left;
    Node right;
    
    */

static Node Insert(Node root,int value)
    {
    Node t = root;
    while(root!=null) {
        if(value < root.data) {
            if(root.left==null) {
                root.left=new Node();
                root.left.data=value;
                root.left.left=root.left.right=null;
                break;
            } else {
                root = root.left;
            }
        } else {
            if(root.right == null) {
                root.right=new Node();
                root.right.data=value;
                root.right.left=root.right.right=null;
                break;
            } else {
                root = root.right;
            }
        }
    }
        if(root == null) {
            t = new Node();
            t.data = value;
            t.left=t.right=null;
        }
    return t;
}