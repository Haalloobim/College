#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long 
using namespace std; 

typedef struct bstnode_t {
    int key; 
    struct bstnode_t *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;


BSTNode* __bst__createNode(int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value) {
    if (root == NULL) 
        return __bst__createNode(value);

    if (value < root->key)
        root->left = __bst__insert(root->left, value);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value);
    
    return root;
}

BSTNode* __bst__search(BSTNode *root, int value) {
    while (root != NULL) {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

BSTNode* __bst__findMinNode(BSTNode *node) {
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    
    return currNode;
}

BSTNode* __bst__remove(BSTNode *root, int value) {
    if (root == NULL) return NULL;

    if (value > root->key) 
        root->right = __bst__remove(root->right, value);
    else if (value < root->key) 
        root->left = __bst__remove(root->left, value);
    else {
        
        if (root->left == NULL) {
            BSTNode *rightChild = root->right;
            free(root);
            return rightChild;
        }
        else if (root->right == NULL) {
            BSTNode *leftChild = root->left;
            free(root);
            return leftChild;
        }

        BSTNode *temp = __bst__findMinNode(root->right);
        root->key     = temp->key;
        root->right   = __bst__remove(root->right, temp->key);
    }
    return root;
}

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

bool bst_find(BST *bst, int value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, int value) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
}

void bst_remove(BST *bst, int value) {
    if (bst_find(bst, value)) {
        bst->_root = __bst__remove(bst->_root, value);
        bst->_size--;
    }
}

int level(BSTNode *root, int target, int lvl){
    if (root){
        if (root->key < target){
            return level(root->right, target, lvl + 1);
        }
        if (root->key > target){
            return level(root->left, target, lvl + 1);
        }
    }
    return lvl;
}

BSTNode* SearchLCA(BSTNode* root, int mins, int maks){
	if (!root) return NULL; 
	if (root->key > maks){
		return SearchLCA(root->left, mins, maks); 
	}
	if (root->key < mins){
		return SearchLCA(root->right, mins, maks); 
	}
	return root; 
}

int main(){
    fastio; 
    BST set;
    bst_init(&set);
    int t; 
    cin >> t;  
    while (t--){
		int numb; 
		cin >> numb; 
		bst_insert(&set, numb); 
    }
    
    int q;
    cin >> q; 
    while(q--){
        int n, maks = -1, min = 2147483646; 
        cin >> n; 
        while(n--){
            int numb; 
            cin >> numb; 
            if (numb < min){
            	min = numb;
			}
			if (numb > maks){
				maks = numb;
			}
        }
        BSTNode* ans = SearchLCA(set._root,min, maks);
		cout << ans->key << " " << level(set._root, ans->key, 0) << endl; 
     } 

    return 0; 
}

/*
12
5 2 3 9 7 25 6 8 20 22 21 23
2
2
20 23
3
8 21 23
# 20 3
# 9 1

12
90 43 182 12 64 98 200 38 60 70 281 80
1
5
12 70 60 64 38
# 43 1
*/
