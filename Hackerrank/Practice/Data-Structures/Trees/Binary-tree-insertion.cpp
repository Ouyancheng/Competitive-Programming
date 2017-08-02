
/*
struct node
{
    int data;
    node* left;
    node* right;
}*/

void LevelOrder(node * root)
{
   std::vector<node *> l;
    int h = 0;
    l.push_back(root);
    while(h < l.size()) {
        node * n = l[h++];
        if(n->left) l.push_back(n->left);
        if(n->right) l.push_back(n->right);
        cout << n->data << " ";
    }
}
