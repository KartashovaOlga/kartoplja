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

int * openFile(void);
void selectionSort(int *array, int length, int min);
void writeToFile(int *array, int length);

int main(int argc, char** argv)
{
    int *array = openFile();
    
    return 0;
}

int * openFile(void)
{
    int i, count = 0;
    int s;

    FILE *inputFile;
    inputFile = fopen("C:\\Temp\\input.txt", "r");

    if(inputFile == NULL)
    {
        printf("File not found\n");
        return  NULL;
    }else
    {
        fseek(inputFile, 0, SEEK_END);
        unsigned int size = ftell(inputFile);

        if(size == 0)
        {
            printf("File is empty\n");
            fclose(inputFile);

            return 0;
        }else
        {
            fseek(inputFile, 0, SEEK_SET);
            
            while (!feof(inputFile) && !ferror(inputFile))
            {
                fscanf(inputFile, "%*d%*[^\n]%*[-]", &s);
                count++;
                if(count > size)
                {
                    printf("File contains wrong string\n");
                    break;
                }
            }
		
            if(count <= size)
            {
             	int *arr = (int*) malloc(count*sizeof(int));
            	fseek(inputFile, 0, SEEK_SET);

            	for(i = 0; i < count; i++)
            	{
                	fscanf(inputFile, "%d\n", &arr[i]);
            	}

            	fclose(inputFile);

            	selectionSort(arr, count, 0);
            	writeToFile(arr, count);
            
            	return arr;  
            }else
            {
                return 0;
            } 
        }
    }
}

void selectionSort(int *array, int length, int min)
{
    int index;
    int m = array[min];

    for (int j = min; j < length; j++)
    {
        if (array[j] <= m)
        {
            index = j;
            m = array[j];
	}
    }

    int temp = array[index];
    array[index] = array[min];
    array[min] = temp;

    if(min < length - 1)
    {
       selectionSort(array, length, min+1);
    }
}


void writeToFile(int *array, int length)
{
    FILE *file = fopen("c:\\Temp\\output.txt", "w");

    if(file == NULL)
    {
        printf("File was not created\n");

    } else
    {
        for(int i = 0; i < length; i++)
        {
            fprintf(file, "%d\n", array[i]);
        }

        fclose(file);
    }
}
