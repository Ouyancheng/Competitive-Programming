import java.util.*;

class Node<T extends Comparable<T>> {
	T data;
	int height;
	int size;
	Node<T> parent;
	Node<T> left;
	Node<T> right;

	public Node(T n,int h,int c,Node<T> p,Node<T> l,Node<T> r) {
		data = n;
		height = h;
		size = c;
		parent = p;
		left = l;
		right = r;
	}
}

class AVL<T extends Comparable<T>> {
  private Node<T> root;
  private boolean isBalanced;

  public AVL() {
    root = null;
    isBalanced = false;
  }
    
  public int size() {
      if(root == null) return 0;
      return root.size;
  }

  private static int max(int a,int b) {
    return (a > b) ? a : b;
  }

  private int size(Node<T> r) {
    return (r == null) ? 0 : r.size;
  }

  private int balanceFactor(Node<T> r) {
    return height(r.left) - height(r.right);
  }

  private Node<T> balance(Node<T> cur) {
    if(balanceFactor(cur) == 2) {
      // left case
      if(balanceFactor(cur.left) == -1) {
        // left-right case
        cur.left = rotateLeft(cur.left);
        cur = rotateRight(cur);
      } else {
        // left-left case
        cur = rotateRight(cur);
      }
    } else if (balanceFactor(cur) == -2) {
      // right case
      if(balanceFactor(cur.right) == 1) {
        // right-left case
        cur.right = rotateRight(cur.right);
        cur = rotateLeft(cur);
      } else {
        // right-right case
        cur = rotateLeft(cur);
      }
    }
    return cur;
  }
  
  private Node<T> rotateLeft(Node<T> par) { // par must not be null
    // Get tmp pointer to left cur first
    Node<T> cur = par.right;
    Node<T> gpar = par.parent;
    cur.parent = gpar;
    par.right = cur.left;
    cur.left = par;
    par.parent = cur;
    if(cur.left != null) cur.left.parent = par;
    par.height = 1 + max(height(par.left),height(par.right));
    cur.height = 1 + max(height(cur.left),height(cur.right));
    par.size = size(par.left) + size(par.right) + 1;
    cur.size = size(cur.left) + size(cur.right) + 1;
    return cur;
  }
  
  private Node<T> rotateRight(Node<T> par) { // par must not be null
    // Get tmp pointer to lowest cur first
    Node<T> cur = par.left;
    Node<T> gpar = par.parent;
    cur.parent = gpar;
    par.left = cur.right;
    cur.right = par;
    par.parent = cur;
    if(cur.right != null) cur.right.parent = par;
    par.height = 1 + max(height(par.left),height(par.right));
    cur.height = 1 + max(height(cur.left),height(cur.right));
    par.size = size(par.left) + size(par.right) + 1;
    cur.size = size(cur.left) + size(cur.right) + 1;
    return cur;
  }

  private Node<T> insert(T k,Node<T> cur) {
    if(cur == null) return new Node<T>(k,0,1,null,null,null);
    int res = k.compareTo(cur.data);
    if(res < 0) {
      cur.left = insert(k,cur.left); 
      cur.left.parent = cur;
    } else {
      cur.right = insert(k,cur.right);
      cur.right.parent = cur;
    }
    cur.height = 1 + max(height(cur.left),height(cur.right));
    cur.size = size(cur.left) + size(cur.right) + 1;
    return isBalanced ? balance(cur) : cur;
  }
  
  private int height(Node<T> r) {
    return (r == null) ? -1 : r.height;
  }

  public void insert(T k) {
    root = insert(k,root);
    //Printer.print(root);
  }
    
  public T select(int k) {
    return kthElement(k,root,0).data;
  }

  private Node<T> search(T k,Node<T> cur) {
    if(cur == null) return null;
    int res = k.compareTo(cur.data);
    if(res == 0) return cur;
    return (res < 0) ? search(k,cur.left) : search(k,cur.right);
  }

  public int search(T k) {
    Node<T> s = search(k,root);
    return (s != null) ? s.size : 0;
  }

  private Node<T> sucessor(Node<T> cur) {
    Node<T> t = cur;
    t = (t == null) ? null : t.right;
    while(t != null && t.left != null) {
      t = t.left;
    }
    if(t == null) {
      while(cur != null && cur.parent != null && cur.parent.data.compareTo(cur.data) < 0) {
        cur = cur.parent;
      }
      cur = (cur == null) ? null : cur.parent;
    }
    return (t == null) ? (cur == null) ? null : cur : t;
  }

  private Node<T> predecessor(Node<T> cur) {
    Node<T> t = cur;
    t = (t == null) ? null : t.left;
    while(t != null && t.right != null) {
      t = t.right;
    }
    if(t == null) {
      while(cur != null && cur.parent != null && cur.parent.data.compareTo(cur.data) > 0) {
        cur = cur.parent;
      }
      cur = (cur == null) ? null : cur.parent;
    }
    return (t == null) ? (cur == null) ? null : cur : t;
  }

  private Node<T> delete(T k,Node<T> cur) {
    if(cur == null) return null;
    int res = k.compareTo(cur.data);

    if(res != 0) {
      if(res < 0) cur.left = delete(k,cur.left);
      else cur.right = delete(k,cur.right);
      cur.height = 1 + max(height(cur.left),height(cur.right));
      cur.size = size(cur.left) + size(cur.right) + 1;
      return isBalanced ? balance(cur) : cur;
    }

    if(cur.left == null && cur.right == null) {
      return null;
    } else if(cur.left != null && cur.right != null) {
      Node<T> s = sucessor(cur);
      cur.data = s.data;
      cur.right = delete(s.data,cur.right);
      return cur;
    } else {
      if(cur.right != null) cur.right.parent = cur.parent;
      else cur.left.parent = cur.parent;
      return (cur.left == null) ? cur.right : cur.left;
    }
  }

  public void delete(T k) {
    root = delete(k,root);
    root.height = 1 + max(height(root.left),height(root.right));
    root.size = size(root.left) + size(root.right) + 1;
  }

  private int rank(T s,Node<T> cur) {
	  if(cur == null) return 0;
	  int res = s.compareTo(cur.data);
	  if(res > 0) {
		  return size(cur.left) + 1 + rank(s,cur.right);
	  } else if(res < 0) {
		  return rank(s,cur.left);
	  } else {
		  return 1 + size(cur.left);
	  }
  }

  private Node<T> kthElement(int k,Node<T> cur,int r) {
	  if(cur == null) return null;
	  r += size(cur.left) + 1;
	  if(k > r) return kthElement(k,cur.right,r);
	  else if(k < r) return kthElement(k,cur.left,r-size(cur.left)-1);
	  else return cur;
  }

  public int intCount(T s,T e) {
	  // Get the rank of the 2 interval bounds
	  int hi = rank(e,root), lo = rank(s,root);
	  Node<T> biggest = kthElement(size(root),root,0);
	  Node<T> smallest = kthElement(1,root,0);
	  if(biggest != null) if(s.compareTo(biggest.data) > 0) return 0;
	  if(smallest != null) if(e.compareTo(smallest.data) < 0) return 0;
	  Node<T> kthE = kthElement(hi,root,0);
	  Node<T> kthS = kthElement(lo,root,0);
	  if(kthS != null && s.compareTo(kthS.data) > 0) { lo++; }
	  if(kthE != null && e.compareTo(kthE.data)==0) { hi--; }
	  if(lo > hi) return 0;
	  return (lo == 0) ? hi - lo : hi - lo + 1;
  }

  public void postorder(Node<T> r) {
    if(r == null) return;
    postorder(r.left);
    postorder(r.right);
    System.out.print(r.data + " ");    
  }

  public void postorder() {
    postorder(root);
  }

  public void preorder(Node<T> r) {
    if(r == null) return;
    System.out.print(r.data + " ");    
    preorder(r.left);
    preorder(r.right);
  }

  public void preorder() {
    preorder(root);
  }
}

public class Solution {
    public static void main(String[] args) {
        AVL<Integer> t = new AVL<Integer>();
        Scanner in = new Scanner(System.in);
        in.nextInt();
        while(in.hasNextInt()) {
            t.insert(in.nextInt());
            double median = 0;
            if(t.size() % 2 == 0) {
                median = (double) (t.select(t.size()/2) + t.select(t.size()/2+1))/2;            
            } else {
                median = t.select(t.size()/2+1);
            }
            System.out.println(median);
        }
    }
}