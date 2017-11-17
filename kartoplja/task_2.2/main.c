/*
При выборочной сортировке происходит поиск наименьшего элемента в массиве. Когда
наименьший элемент найден, его меняют местами с первым элементом массива. Затем
процесс повторяется для подмассива, начинающегося со второго элемента массива.
Каждый проход по массиву приводит к помещению одного элемента на подходящее для
него место. Если обрабатываемый массив содержит только один элемент, массив
считается отсортированным.
Указание. Напишите рекурсивную функцию selectionSort для выполнения этого
алгоритма.
Входные данные: целочисленные элементы массива, записанные по одному в каждой строке.
Количество элементов не меньше 1.
Выходные данные: отсортированный массив.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int * readFromFile(void);
void selectionSort(int *numbers,int length, int min);
void writeToFile(int *sortNumbers, int length);

int count = 0;
int isValid;

int main(int argc, char** argv)
{
    int *inputNums = readFromFile();
    
    if(isValid == 0)
    {
        selectionSort(inputNums,count, 0);
        writeToFile(inputNums, count);  
        free(inputNums);
    }
    else
    {
        free(inputNums);
    }
    return 0;
}

int * readFromFile(void)
{
    FILE *inputFile;
    inputFile = fopen("C:\\Temp\\input.txt", "r");

    if(inputFile == NULL)
    {
        printf("File not found\n");
    }
    else
    {
        fseek(inputFile, 0, SEEK_END);
        unsigned int size = ftell(inputFile);
        
        int *numbers = (int*) malloc(size);
        isValid = 0;
        
        if(size == 0)
        {
            isValid = -1;
            printf("File is empty\n");
            fclose(inputFile);
        }
        else
        {
            fseek(inputFile, 0, SEEK_SET);
            int i =0;
            while (!feof(inputFile) && !ferror(inputFile))
            {
                fscanf(inputFile, "%d\n", &numbers[i]);   
                count++;
                i++;
                if(count > size)
                {
                    isValid = -1;
                    printf("File contains wrong string\n");
                    break;
                }
                else
                {  
                }
            }
                        
            fclose(inputFile);
        }
        return numbers;
    }
}

void selectionSort(int *numbers, int length, int min)
{
    int index;
    int m = numbers[min];

    for (int j = min; j < length; j++)
    {
        if (numbers[j] <= m)
        {
            index = j;
            m = numbers[j];
	}
    }

    int temp = numbers[index];
    numbers[index] = numbers[min];
    numbers[min] = temp;

    if(min < length - 1)
    {
       selectionSort(numbers, length,  min+1);
    }
}

void writeToFile(int *numbers, int length)
{
    FILE *file = fopen("c:\\Temp\\output.txt", "w");

    if(file == NULL)
    {
        printf("File was not created\n");

    } else
    {
        for(int i = 0; i < length; i++)
        {
            fprintf(file, "%d\n", numbers[i]);
        }
        fclose(file);
    }
}
