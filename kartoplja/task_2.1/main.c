/*
Напишите программу, которая определяет, является ли квадрат магическим.
Указание. Используйте в реализации двумерный массив.
Входные данные: в первой строке файла записано целое число  N – порядок магического квадрата.
В следующих N строках записанопо N целых чисел через пробел.
Выходные данные: cлово ‘YES’, если квадрат является магическим, ‘NO’ – иначе.
*/

#include <stdio.h>
#include <stdlib.h>

int ** readFromFile(int *isValid, int *squaireLength);
void writeToFile(int isMagic);
int checkMagic(int **inputArr, int squaireLength);

int main(int argc, char** argv) {
    int isValid;
    int squaireLength;

    int **inputArr = readFromFile(&isValid, &squaireLength);

    if(isValid > 0)
    {
        int isMagic = checkMagic(inputArr, squaireLength);
        writeToFile(isMagic);

        int i;
        for(i = 0; i < squaireLength; i++)
        {
            free(inputArr[i]);
        }
        free(inputArr);
    }
    else
    {
        free(inputArr);
    }

    return 0;
}

int ** readFromFile(int *isValid, int *squaireLength)
{
    int i, j;
    int count = 0;
    int temp;
    int **inputArr;

    FILE *inputFile;
    inputFile = fopen("C:\\Temp\\input.txt", "r");
    *isValid = 1;

    if(inputFile == NULL)
    {
        printf("File not found\n");
        *isValid = -1;
    }
    else
    {
        fseek(inputFile, 0, SEEK_END);
        long int size = ftell(inputFile);

        if(size == 0)
        {
            printf("File is empty\n");
            fclose(inputFile);

            *isValid = -1;
        }
        else
        {
            fseek(inputFile, 0, SEEK_SET);

            while (!feof(inputFile) && !ferror(inputFile))
            {
                fscanf(inputFile, "%d", &temp);
                count++;
                if(count > size)
                {
                    printf("File contains wrong string\n");
                    *isValid = -1;
                    break;
                }
            }
            if(count <= size)
            {
                fseek(inputFile, 0, SEEK_SET);
                fscanf(inputFile, "%d\n", squaireLength);
                inputArr = (int**) calloc(squaireLength[0], sizeof(int));

                for(i = 0; i < squaireLength[0]; i++)
                {
                    inputArr[i] = (int*) calloc(squaireLength[0], sizeof(int));
                    for(j = 0; j < squaireLength[0]; j++)
                    {
                        fscanf(inputFile, "%d\n", &inputArr[i][j]);
                    }
                }

                fclose(inputFile);
            }
        }
    }
    return inputArr;
}

int checkMagic(int **inputArr, int squaireLength)
{
    int lineSumm = 0;
    int columnSumm = 0;
    int diagSumm1 = 0;
    int diagSumm2 = 0;
    int i, j;

    for(i = 0; i < squaireLength; i++)
    {
        diagSumm2 += inputArr[i][squaireLength - 1 - i];



        diagSumm1 += inputArr[i][i];
    }

    if(diagSumm1 == diagSumm2)
    {
        for(i = 0; i < squaireLength; i++)
        {
            for(j = 0; j < squaireLength; j++)
            {
                lineSumm += inputArr[i][j];
            }

            if(lineSumm == diagSumm1)
            {
                lineSumm = 0;
            }
            else
            {
                return -1;
            }
        }

        for(i = 0; i < squaireLength; i++)
        {
            for(j = 0; j < squaireLength; j++)
            {
                columnSumm += inputArr[j][i];
            }

            if(columnSumm == diagSumm1)
            {
                columnSumm = 0;
            }
            else
            {
                return -1;
            }
        }
    }
    else
    {
        return  -1;
    }
}

void writeToFile(int isMagic)
{
    FILE *file = fopen("c:\\Temp\\output.txt", "w");

    if(file == NULL)
    {
        printf("File was not created\n");
    }
    else
    {
        if(isMagic > 0 )
        {

            fprintf(file, "YES");
        }
        else
        {
            fprintf(file, "NO");
        }
        fclose(file);
    }
}
