#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long 
using namespace std; 

bool flag = 0; 

typedef struct bstnode_t {
    int key;
    struct bstnode_t 
        *left, *right, *parent;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode* __bst__createNode(BSTNode *root, int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->parent = root;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, BSTNode *node, int value) {
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

void cari(BSTNode *root, ll value) {
	BSTNode *temp = root; 
	ll sum;
    if(temp) {
    	if(temp->key == value){
    		flag = 1; 
    		return; 
		}
    	if (temp->left){
    		sum = temp->key + temp->left->key; 
    		if (sum == value){
    			flag = 1; 
    			return; 
			}
		}
		if (temp->right){
    		sum = temp->key + temp->right->key; 
    		if (sum == value){
    			flag = 1; 
    			return; 
			}
		}
        if(temp->parent) {
            if(temp->left) {
                sum = temp->key + temp->parent->key + temp->left->key;
                if((sum == value)){
                    flag = 1;
                    return; 
                }
            }
            if(temp->right) {
                sum = temp->key + temp->parent->key + temp->right->key;
                if((sum == value)) {
                    flag = 1;
                    return; 
                } 
            }
        }
        if(temp->left && temp->right) {
            sum = temp->key + temp->left->key + temp->right->key;
            if((sum == value )) {
                flag = 1;
                return; 
            }
        }
        cari(temp->left, value);
        cari(temp->right, value);
    }
}


int main(){
    fastio;
    BST set;
    bst_init(&set);
    ll n, t;
    cin >> n; 
    while(n--){
        ll x;
        cin >> x;
        bst_insert(&set, x);
    }
    cin >> t; 
	cari(set._root, t);
	if (flag){
		cout << "Monggo Lewat...\n";
		return 0; 
	}
	cout << "Wani Piro?\n";  

    return 0;
}

/*
5
21 12 30 16 8
36
Monggo Lewat

10
50 35 67 75 55 12 43 53 83 60
227
Wani Piro?

10
50 35 67 75 55 12 43 53 83 60
225
Monggo Lewat
*/

