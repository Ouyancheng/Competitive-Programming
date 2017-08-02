/*  
   class Node
      public  int frequency; // the frequency of this tree
       public  char data;
       public  Node left, right;
    
*/ 

void decode(String S ,Node root)
    {
    int i = 0;
    Node abs = root;
    while(i <= S.length()) {
        if(root==null) break;
        if(root.left==null && root.right==null) {
            System.out.print(root.data);
            root = abs;
            continue;
        }
        if(i == S.length()) break;
        if(S.charAt(i++)=='0')
            root=root.left;
        else
            root=root.right;
    }
}
