/*
Указание.   Напишите    модуль,  реализующий    структуру   данных   «Двоичное    дерево»
элементов   типа   int.  Реализуйте   следующие    операции    над  двоичным     деревом:
инициализация дерева, уничтожение дерева, добавление элемента, обход дерева (прямой,
обратный, концевой), поиск и удаление узла дерева.

Входные данные: в файле записаны целые числа – элементы поиска.
Выходные данные: обходы дерева, результат поиска заданного элемента, результат сравнения дерева
с его копией, обходы второго дерева, результат сравнения первого и второго дерева.
*/

#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node * left;
    struct node * right;
};

int mainMenu(struct node *tnode);
int * readFromFile(int *isValid, int *length);
struct node *addNode(struct node *tnode, int data);
struct node *buildTree(struct node *tnode, int *input, int length);
void prefixPrint(struct node *tree);
void infixPrint(struct node *tnode);
void postfixPrint(struct node *tnode);
void deleteTree(struct node *tnode);
struct node *deleteNode(struct node * tnode, int element);

int main(int argc, char **argv)
{
    int length;
    int isValid;

    int *input = readFromFile(&isValid, &length);

    if(isValid > 0)
    {
        struct node *tnode;
        tnode = buildTree(tnode, input, length);

        int isEnd = 1;

        while (isEnd > 0)
        {
            isEnd = mainMenu(tnode);
        }
        deleteTree(tnode);
        free(input);
    }
    else
    {
        free(input);
    }
    return 0;
}

int mainMenu(struct node *root)
{
    printf("MENU:\n");
    printf("1 - INORDER\n");
    printf("2 - PREORDER\n");
    printf("3 - POSTORDER\n");
    printf("4 - DELETE TREE\n");
    printf("5 - ADD ELEMENT\n");
    printf("6 - DELETE ELEMENT\n");
    printf("0 - QUIT\n");

    char choise = {0};
    scanf("%s", &choise);

    switch (choise)
    {
        case '1':
            infixPrint(root);
            printf("\n");
            return 1;
        case '2':
            prefixPrint(root);
            printf("\n");
            return 1;
        case '3':
            postfixPrint(root);
            printf("\n");
            return 1;
        case '4':
            deleteTree(root);
            return 1;
        case '5':
            printf("Enter an element to add\n");
            int addElement;
            scanf("%d", &addElement);
            addNode(root, addElement);
            return 1;
        case '6':
            printf("Enter an element to delete\n");
            int deliteElement;
            scanf("%d", &deliteElement);
            root = deleteNode(root, deliteElement);
            return 1;
        case '0':
            return -1;
        default:
            return 1;
    }
}

int * readFromFile(int *isValid, int *length)
{
    FILE *inputFile;
    inputFile = fopen("C:\\Temp\\input.txt", "r");

    if(inputFile == NULL)
    {
        printf("File not found\n");
        *isValid = -1;
    }
    else
    {
        fseek(inputFile, 0, SEEK_END);
        int size = ftell(inputFile);

        if(size == 0)
        {
            printf("File is empty\n");
            fclose(inputFile);

            *isValid = -1;
        }
        else
        {
            fseek(inputFile, 0, SEEK_SET);
            int count = 0;
            int *input = (int*)calloc(size/2, 4);

            while (!feof(inputFile) && !ferror(inputFile))
            {
                fscanf(inputFile, "%d\n", &input[count]);;
                count++;
                if(count > size)
                {
                    printf("File contains the wrong string\n");
                    *isValid = -1;
                }
            }

            *length = count;
            *isValid = 1;
            fclose(inputFile);
            return input;
        }
    }
}

struct node *addNode(struct node *tnode, int data)
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

struct node *buildTree(struct node *tnode, int *input, int length)
{
    int i;
    tnode = NULL;

    for(i = 0; i < length; i++)
    {
        tnode = addNode(tnode, input[i]);
    }

    return tnode;
}

void prefixPrint(struct node *tnode)
{
    if (tnode != NULL)
    {
        printf("%d ", tnode->data);
        prefixPrint(tnode->left);
        prefixPrint(tnode->right);
    }
}

void infixPrint(struct node *tnode)
{
    if (tnode != NULL)
    {
        infixPrint(tnode->left);
        printf("%d ", tnode->data);
        infixPrint(tnode->right);
    }
}

void postfixPrint(struct node *tnode)
{
    if (tnode != NULL)
    {
        postfixPrint(tnode->left);
        postfixPrint(tnode->right);
        printf("%d ", tnode->data);
    }
}

void deleteTree(struct node *tnode)
{
    if(tnode != NULL)
    {
        deleteTree(tnode->left);
        deleteTree(tnode->right);
        free(tnode);
    }
}

struct node *deleteNode(struct node *tnode, int element)
{
    struct node *tree,*tree2;

    if(!tnode)
    {
        printf("There is no this element\n");
        return tnode;
    }

    if(tnode->data == element)
    {
        if(tnode->left == tnode->right)
        {
            free(tnode);
            return NULL;
        }
        else if(tnode->left == NULL)
        {
            tree = tnode->right;
            free(tnode);
            return tree;
        }
        else if(tnode->right == NULL)
        {
            tree = tnode->left;
            free(tnode);
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
