#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *lelf, *right;
} Node;

// function prototypes
Node *createNode(int data);
void init(Node **root);
void insert(Node *root, int data); 
void inorder(Node *root);
void preorder(Node *root);
void postorder(Node *root);


// main
int main()
{
    Node *root = NULL;
    int choice, data;
    init(&root);
    while (1)
    {
        printf("\n1.Insertion 2.Preorder 3.Inorder 4.Postorder 5.Quit\n");
        printf("Enter your choice ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to insert ");
            scanf("%d", &data);
            insert(root, data);
            break;
        case 2:
            printf("The preorder elements are ");
            preorder(root);
            break;
        case 3:
            printf("The inorder elements are ");
            inorder(root);
            break;
        case 4:
            printf("The postorder elements are ");
            postorder(root);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}

// function definitions
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->lelf = NULL;
    newNode->right = NULL;
    return newNode;
}

void init(Node **root)
{
    printf("Enter the root node: ");
    int data;
    scanf("%d", &data);
    *root = createNode(data);
}

void insert(Node *root, int data)
{
    if (data > root->data)
    {
        if (root->right == NULL)
        {
            root->right = createNode(data);
            printf("%d is inserted at the right\n", data);
        }
        else
        {
            insert(root->right, data);
        }
    }
    else
    {
        if (root->lelf == NULL)
        {
            root->lelf = createNode(data);
            printf("%d is inserted at the left\n", data);
        }
        else
        {
            insert(root->lelf, data);
        }
    }
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->lelf);
        printf("%d  ", root->data);
        inorder(root->right);
    }
}

void preorder(Node *root)
{
    if (root != NULL)
    {
        printf("%d  ", root->data);
        preorder(root->lelf);
        preorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->lelf);
        postorder(root->right);
        printf("%d  ", root->data);
    }
}