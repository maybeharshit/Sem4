#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node into the binary tree
void insert(Node** root, int data)
{
    Node* newNode = createNode(data);
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    // Level order traversal to find the appropriate place
    // for insertion
    Node* temp;
    Node* queue[100];
    int front = -1, rear = -1;
    queue[++rear] = *root;

    while (front != rear) {
        temp = queue[++front];

        //  Insert new node as the left child
        if (temp->left == NULL) {
            temp->left = newNode;
            return;
        }
        // if left child is not missing push it to the queue
        else {
            queue[++rear] = temp->left;
        }
        // Insert new node as the right child
        if (temp->right == NULL) {
            temp->right = newNode;
            return;
        }
        // if right child is not missing push it to the
        // queue
        else {
            queue[++rear] = temp->right;
        }
    }
}

// Function to find the Closest Common Ancestor (CCA) of two nodes
struct Node* findCCA(struct Node* root, int n1, int n2) {
    // Base case: if the root is NULL, return NULL
    if (root == NULL) {
        return NULL;
    }

    // If either n1 or n2 matches the root's data, return the root
    if (root->data == n1 || root->data == n2) {
        return root;
    }

    // Recursively search for n1 and n2 in the left and right subtrees
    struct Node* leftCCA = findCCA(root->left, n1, n2);
    struct Node* rightCCA = findCCA(root->right, n1, n2);

    // If both left and right subtrees return non-NULL, then the current node is the CCA
    if (leftCCA != NULL && rightCCA != NULL) {
        return root;
    }

    // Otherwise, return the non-NULL value (either leftCCA or rightCCA)
    return (leftCCA != NULL) ? leftCCA : rightCCA;
}

// Function to display the tree (in-order traversal)
void displayTree(struct Node* root) {
    if (root == NULL) {
        return;
    }
    displayTree(root->left);
    printf("%d ", root->data);
    displayTree(root->right);
}

int main() {
    struct Node* root = NULL;
    int n, data, n1, n2;

    // Input the number of nodes in the tree
    printf("Enter the number of nodes in the binary tree: ");
    scanf("%d", &n);

    // Input the nodes of the tree
    printf("Enter the nodes of the binary tree:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insertNode(root, data);
    }

    // Display the tree (in-order traversal)
    printf("In-order traversal of the binary tree: ");
    displayTree(root);
    printf("\n");

    // Input the two nodes for which CCA needs to be found
    printf("Enter the two nodes to find their Closest Common Ancestor: ");
    scanf("%d %d", &n1, &n2);

    // Find the CCA of the two nodes
    struct Node* cca = findCCA(root, n1, n2);
    if (cca != NULL) {
        printf("Closest Common Ancestor of %d and %d is %d\n", n1, n2, cca->data);
    } else {
        printf("Closest Common Ancestor not found\n");
    }

    return 0;
}
