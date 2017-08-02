/*
   class Node 
       int data;
       Node left;
       Node right;
*/

void l(Node r) {
    if(r==null) return;
    l(r.left);
    System.out.print(r.data+" ");
}

void r(Node r) {
    if(r==null) return;
    System.out.print(r.data + " ");
    r(r.right);
}

void top_view(Node root)
{
  l(root);
  if(root != null) r(root.right);
}