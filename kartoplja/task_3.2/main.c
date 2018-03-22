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
#include "Binary_Tree.h"


int mainMenu(t_tree *tnode);
int * readFromFile(int *isValid, int *length, char *fileName);

int main(int argc, char **argv)
{
    int length;
    int isValid;
    char *treeFile = "C:\\Temp\\tree.txt";

    int *input = readFromFile(&isValid, &length, treeFile);

    if(isValid > 0)
    {
        t_tree *tnode;
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

int mainMenu(t_tree *root)
{
    t_tree *copy_tree;
    t_tree *other_tree;
    int copyIsCreate = 0;
    int otherIsCreate = 0;
    int otherLength;
    int isValid;
    int *otherInput;
    char *otherTreeFile = "C:\\Temp\\otherTree.txt";
    char choice = 0;

    printf("MENU:\n");
    printf("1 - INORDER\n");
    printf("2 - PREORDER\n");
    printf("3 - POSTORDER\n");
    printf("4 - ADD ELEMENT\n");
    printf("5 - DELETE ELEMENT\n");
    printf("6 - BUILD COPY OF TREE\n");
    printf("7 - BUILD OTHER TREE\n");
    printf("8 - INORDER FOR OTHER TREE\n");
    printf("9 - PREORDER FOR OTHER TREE\n");
    printf("P - POSTORDER FOR OTHER TREE\n");
    printf("D - DELETE ALL TREES\n");
    printf("Q - QUIT\n");

    scanf("%s", &choice);

    switch (choice)
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
            printf("Enter an element for adding\n");
            int addElement;
            scanf("%d", &addElement);
            addNode(root, addElement);
            return 1;
        case '5':
            printf("Enter an element for deleting\n");
            int deliteElement;
            scanf("%d", &deliteElement);
            root = deleteNode(root, deliteElement);
            return 1;
        case '6':
            copy_tree = root;
            printf("Copy of tree was built\n");
            copyIsCreate = 1;
            return 1;
        case '7':
            otherInput = readFromFile(&isValid, &otherLength, otherTreeFile);

            if(isValid > 0)
            {
                other_tree = buildTree(other_tree, otherInput, otherLength);
                printf("Other tree was built\n");
                otherIsCreate = 1;
            }
            else
            {
                printf("Other tree was not built. Try again\n");
            }
            return 1;
        case '8':
            if(otherIsCreate > 0)
            {
                infixPrint(other_tree);
                printf("\n");
            }
            else
            {
                printf("Other tree was not created\n");
            }
            return 1;
        case '9':
            if(otherIsCreate > 0)
            {
                prefixPrint(other_tree);
                printf("\n");
            }
            else
            {
                printf("Other tree was not created\n");
            }
            return 1;
        case 'P':
            if(otherIsCreate > 0)
            {
                postfixPrint(other_tree);
                printf("\n");
            }
            else
            {
                printf("Other tree was not created\n");
            }
            return 1;
        case 'D':
            deleteTree(root);
            deleteTree(copy_tree);
            printf("All trees were deleted\n");
            return -1;
        case 'Q':
            return -1;
        default:
            return 1;
    }
}

int * readFromFile(int *isValid, int *length, char *fileName)
{
    FILE *inputFile;
    inputFile = fopen(fileName, "r");

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
            *isValid = 1;
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
                    break;
                }
            }

            *length = count;
            fclose(inputFile);
            return input;
        }
    }
}
