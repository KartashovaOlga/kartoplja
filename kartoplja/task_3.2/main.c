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


void mainMenu(t_tree *tnode);
int * readFromFile(int *isValid, int *length, char *fileName);
void printResultOfComparing(int result);

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

        mainMenu(tnode);
        free(input);
    }
    else
    {
        free(input);
    }
    return 0;
}

void mainMenu(t_tree *root)
{
    t_tree *copyOfTree = NULL;
    t_tree *other_tree = NULL;
    int copyIsCreate = 0;
    int otherIsCreate = 0;
    int otherLength = 0;
    int isValid = 0;
    int *otherInput = NULL;
    int delTree = 0;
    int delCopy = 0;
    int delOther = 0;
    int isEnd = 1;
    char *otherTreeFile = "C:\\Temp\\otherTree.txt";
    char choice = 0;

    while (isEnd > 0)
    {
        printf("MENU:\n");
        printf("1 - INORDER\n");
        printf("2 - PREORDER\n");
        printf("3 - POSTORDER\n");
        printf("4 - ADD ELEMENT\n");
        printf("5 - DELETE ELEMENT\n");
        printf("6 - BUILD COPY OF DEFAULT TREE\n");
        printf("7 - BUILD OTHER TREE\n");
        printf("8 - INORDER FOR OTHER TREE\n");
        printf("9 - PREORDER FOR OTHER TREE\n");
        printf("P - POSTORDER FOR OTHER TREE\n");
        printf("C - COMPARE TRIES\n");
        printf("D - DELETE ALL TREES\n");
        printf("Q - QUIT\n");

        scanf("%s", &choice);

        switch (choice) {
            case '1':
                infixPrint(root);
                printf("\n");
                isEnd = 1;
                continue;
            case '2':
                prefixPrint(root);
                printf("\n");
                isEnd = 1;
                continue;
            case '3':
                postfixPrint(root);
                printf("\n");
                isEnd = 1;
                continue;
            case '4':
                printf("Enter an element for adding\n");
                int addElement;
                scanf("%d", &addElement);
                addNode(root, addElement);
                isEnd = 1;
                continue;
            case '5':
                printf("Enter an element for deleting\n");
                int deliteElement;
                scanf("%d", &deliteElement);
                root = deleteNode(root, deliteElement);
                isEnd = 1;
                continue;
            case '6':
                copyOfTree = copyTree(root, copyOfTree);
                printf("Copy of tree was built\n");
                copyIsCreate = 1;
                isEnd = 1;
                continue;
            case '7':
                otherInput = readFromFile(&isValid, &otherLength, otherTreeFile);

                if (isValid > 0) {
                    other_tree = buildTree(other_tree, otherInput, otherLength);
                    printf("Other tree was built\n");
                    otherIsCreate = 1;
                } else {
                    printf("Other tree was not built. Try again\n");
                }
                isEnd = 1;
                continue;
            case '8':
                if (otherIsCreate > 0)
                {
                    infixPrint(other_tree);
                    printf("\n");
                }
                else
                {
                    printf("Other tree was not created\n");
                }
                isEnd = 1;
                continue;
            case '9':
                if (otherIsCreate > 0)
                {
                    prefixPrint(other_tree);
                    printf("\n");
                }
                else
                {
                    printf("Other tree was not created\n");
                }
                isEnd = 1;
                continue;
            case 'C':
                printf("Choose tries for comparing:\n");
                printf("D - Default tree and Copy of default tree\n");
                printf("O - Other tree and Default tree\n");

                char decision = 0;
                int compareResult;

                printf("First tree\n");
                scanf("%s", &decision);

                if (decision == 'D' && copyIsCreate > 0)
                {
                    compareResult = isEqual(root, copyOfTree);
                    printResultOfComparing(compareResult);
                }
                else if (decision == 'O' && otherIsCreate > 0)
                {
                    compareResult = isEqual(root, other_tree);
                    printResultOfComparing(compareResult);
                }
                else
                {
                    printf("Error of comparing\n");
                }
                isEnd = 1;
                continue;
            case 'P':
                if (otherIsCreate > 0)
                {
                    postfixPrint(other_tree);
                    printf("\n");
                }
                else
                {
                    printf("Other tree was not created\n");
                }
                isEnd = 1;
                continue;
            case 'D':
                deleteTree(root);
                deleteTree(copyOfTree);
                deleteTree(other_tree);
                printf("All trees were deleted\n");
                otherIsCreate = 0;
                copyIsCreate = 0;
                delTree = 1;
                delCopy = 1;
                delOther = 1;
                isEnd = 1;
                continue;
            case 'Q':
                if (delTree > 0)
                {
                    deleteTree(root);
                }
                else
                {
                }

                if (delCopy > 0 && copyIsCreate > 0)
                {
                    deleteTree(copyOfTree);
                }
                else
                {
                }

                if (delOther > 0 && otherIsCreate > 0)
                {
                    deleteTree(other_tree);
                }
                else
                {
                }
                isEnd = 0;
                continue;
            case '0':
                prefixPrint(copyOfTree);
                printf("\n");
                isEnd = 1;
                continue;
            default:
                isEnd = 1;
                continue;
        }
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

void printResultOfComparing(int result)
{
    if(result == 1)
    {
        printf("Tries are equals\n");
    }
    else
    {
        printf("Tries are not equals\n");
    }
   }
