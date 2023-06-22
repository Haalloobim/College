#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long 
using namespace std; 

bool flag = 0; 

typedef struct bstnode_t {
    ll key;
    struct bstnode_t 
        *left, *right, *parent;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned ll _size;
} BST;

BSTNode* __bst__createNode(BSTNode *root, ll value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->parent = root;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, BSTNode *node, ll value) {
    if (node == NULL)
        return __bst__createNode(root, value);
    if (value < node->key)
        node->left = __bst__insert(node, node->left, value);

    else if (value > node->key)
        node->right = __bst__insert(node, node->right, value);

    return node;
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

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

BSTNode* bst_find(BST *bst, int value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return NULL;

    if (temp->key == value)
        return temp;
    else
        return NULL;
}

void bst_insert(BST *bst, int value) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, bst->_root, value);
        bst->_size++;
    }
}

ll maks = 0;
void solve(BSTNode *root, vector<ll> &arr, ll level){
	if (root){
		ll idx = level ;
		arr[idx] = max(root->key, arr[idx]);
		maks = max(maks, level); 
		solve(root->left, arr, level + 1); 
		solve(root->right, arr, level + 1); 
	}
}



int main(){
    fastio;
    BST set;
    bst_init(&set);
    ll numb, count = 0;
    while(scanf("%lld", &numb) != EOF){
        bst_insert(&set, numb);
        count++; 
    }  
    vector <ll> arr(count, 0); 
    solve(set._root, arr ,0); 
    
    for(ll i = 0; i < count; i++){
    	if (arr[i] != 0){
    		cout << arr[i] << endl; 
    		continue;
		}	
	}

    return 0;
}



