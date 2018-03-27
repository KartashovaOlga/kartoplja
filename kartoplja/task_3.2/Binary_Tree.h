typedef struct node
{
    int data;
    struct node * left;
    struct node * right;
}t_tree;


t_tree *addNode(t_tree *tnode, int data);
t_tree *buildTree(t_tree *tnode, int *input, int length);
void prefixPrint(t_tree *tree);
void infixPrint(t_tree *tnode);
void postfixPrint(t_tree *tnode);
void deleteTree(t_tree *tnode);
t_tree *copyTree(t_tree *tnode, t_tree *newTree);
t_tree *deleteNode(t_tree * tnode, int element);
int isEqual(t_tree *tnode1, t_tree *tnode2);


t_tree *addNode(t_tree *tnode, int data)
{
    if(tnode == NULL)
    {
        tnode = (struct node *)malloc(sizeof(struct node));
        tnode->data = data;
        tnode->left = tnode->right = NULL;
    }
    else if(data < tnode->data)
    {
        tnode->left = addNode(tnode->left, data);
    }
    else
    {
        tnode->right = addNode(tnode->right, data);
    }
    return tnode;
}

t_tree *buildTree(t_tree *tnode, int *input, int length)
{
    int i;
    tnode = NULL;

    for(i = 0; i < length; i++)
    {
        tnode = addNode(tnode, input[i]);
    }

    return tnode;
}

void prefixPrint(t_tree *tnode)
{
    if (tnode != NULL)
    {
        printf("%d ", tnode->data);
        prefixPrint(tnode->left);
        prefixPrint(tnode->right);
    }
}

void infixPrint(t_tree *tnode)
{
    if (tnode != NULL)
    {
        infixPrint(tnode->left);
        printf("%d ", tnode->data);
        infixPrint(tnode->right);
    }
}

void postfixPrint(t_tree *tnode)
{
    if (tnode != NULL)
    {
        postfixPrint(tnode->left);
        postfixPrint(tnode->right);
        printf("%d ", tnode->data);
    }
}

void deleteTree(t_tree *tnode)
{
    if(tnode != NULL)
    {
        deleteTree(tnode->left);
        deleteTree(tnode->right);
        free(tnode);
    }
}

t_tree *deleteNode(t_tree *tnode, int element)
{
    struct node *tree,*tree2;

    if(!tnode)
    {
        printf("There is no element\n");
        return tnode;
    }

    if(tnode->data == element)
    {
        if(tnode->left == tnode->right)
        {
            free(tnode);
            printf("Element was deleted\n");
            return NULL;
        }
        else if(tnode->left == NULL)
        {
            tree = tnode->right;
            free(tnode);
            printf("Element was deleted\n");
            return tree;
        }
        else if(tnode->right == NULL)
        {
            tree = tnode->left;
            free(tnode);
            printf("Element was deleted\n");
            return tree;
        }
        else if(tnode->left == NULL)
        {
            tree2 = tnode->right;
            tree = tnode->right;
            while(tree->left)
            {
                tree = tree->left;
            }
            tree->left = tnode->left;
            free(tnode);
            printf("Element was deleted\n");
            return tree2;
        }
        else
        {
            printf("Root can not be deleted\n");
            return tnode;
        }
    }
    else if(tnode->data < element)
    {
        tnode->right = deleteNode(tnode->right, element);
    }
    else
    {
        tnode->left = deleteNode(tnode->left, element);
    }

    return tnode;
}

t_tree *copyTree(t_tree *tnode, t_tree *newTree)
{
    if(tnode == NULL)
    {
        newTree = NULL;
        return NULL;
    }
    else
    {
    }

    newTree = (struct node *)malloc(sizeof(struct node));
    newTree->data = tnode->data;
    newTree->left = copyTree(tnode->left, newTree->left);
    newTree->right = copyTree(tnode->right, newTree->right);

    return newTree;
}

int isEqual(t_tree *tnode1, t_tree *tnode2)
{
    if (tnode1 == NULL && tnode2 == NULL)
    {
        return 1;
    }
    else if (tnode1 != NULL && tnode2 != NULL)
    {
        return( tnode1->data == tnode2->data &&
        isEqual(tnode1->left, tnode2->left) &&
        isEqual(tnode1->right, tnode2->right));
    }
    else
    {
        return 0;
    }
}