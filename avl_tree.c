struct treeNode {
	int data;
	int ht;
	struct treeNode *left, *right;
};
struct treeNode* newNode(int data) {
	struct treeNode *node = (struct treeNode*)malloc(sizeof(struct treeNode));
	node->data = data;
	node->ht = 1;
	node->left = NULL;
	node->right = NULL;
	return node;
}
int height(struct treeNode *node) {
	if (node == NULL)
		return 0;
	return node->ht;
}
int getbalance(struct treeNode *node) {
	if (node == NULL)
		return 0;
	return height(node->left) - height(node->right);
}
struct treeNode *rotateLeft(struct treeNode *x) {
	struct treeNode *y;
	y = x->right;
	x->right = y->left;
	y->left = x;
	x->ht = max(height(x->left), height(x->right)) + 1;
	y->ht = max(height(y->left), height(y->right)) + 1;
	return y;
}
struct treeNode *rotateRight(struct treeNode *y) {
	struct treeNode *x;
	x = y->left;
	y->left = x->right;
	x->right = y;
	x->ht = max(height(x->left), height(x->right)) + 1;
	y->ht = max(height(y->left), height(y->right)) + 1;
	return x;
}
struct treeNode *insert(struct treeNode *node, int data){
	if (node == NULL) {
		node = newNode(data);
		return node;
	}
	if (data < node->data)
		node->left = insert(node->left, data);
	else if (data > node->data)
		node->right = insert(node->right, data);
	node->ht = max(height(node->left), height(node->right)) + 1;
	int balance = getbalance(node);
	if (balance > 1 && data < node->left->data)//Left-Left
		return rotateRight(node);
	else if (balance < -1 && data > node->right->data)//Right-Right
		return rotateLeft(node);
	else if (balance > 1 && data > node->left->data) {//Left-Right
		node->left = rotateLeft(node->left);
		return rotateRight(node);
	}
	else if (balance < -1 && data < node->right->data) {//Right-Left
		node->right = rotateRight(node->right);
		return rotateLeft(node);
	}
	return node;
}
struct treeNode *minValueNode(struct treeNode *node) {
	struct treeNode *current = node;
	while (current->left)
		current = current->left;
	return current;
}
struct treeNode *deleteNode(struct treeNode *node, int data) {
	struct treeNode *temp;
	if (node == NULL) {
		return node;
	}
	if (data < node->data)
		node->left = deleteNode(node->left, data);
	else if (data > node->data)
		node->right = deleteNode(node->right, data);
	else {
		if (node->left == NULL || node->right == NULL) {
			temp = node->left ? node->left : node->right;
			if (temp == NULL) {
				free(node);
				node = NULL;
			}
			else {
				node->data = temp->data;
				node->ht = temp->ht;
				node->left = node->right = NULL;
				free(temp);
			}
		}
		else {
			temp = minValueNode(node->right);
			node->data = temp->data;
			node->right = deleteNode(node->right, temp->data);
		}
	}
	if (node == NULL) return NULL;
	node->ht = max(height(node->left), height(node->right)) + 1;
	int balance = getbalance(node);
	if (balance > 1 && getbalance(node->left)>=0)//Left-Left
		return rotateRight(node);
	else if (balance < -1 && getbalance(node->right)<=0)//Right-Right
		return rotateLeft(node);
	else if (balance > 1 && getbalance(node->left) < 0) {//Left-Right
		node->left = rotateLeft(node->left);
		return rotateRight(node);
	}
	else if (balance < -1 && getbalance(node->right)>0) {//Right-Left
		node->right = rotateRight(node->right);
		return rotateLeft(node);
	}
	return node;
}

struct treeNode *root = NULL;
int main() {
	root = insert(root,1);
	root = insert(root, 2);
	root = insert(root, 3);
	root = insert(root, 4);
	root = insert(root, 5);
	root = insert(root, 6);
	root = insert(root, 7);
	root = deleteNode(root, 4);
	root = deleteNode(root, 7);
	root = deleteNode(root, 6);
	return 0;
}