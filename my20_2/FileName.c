#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "RUS");
    char filename[100];
    printf("������� ��� �����: ");
    scanf("%s", filename);
    FILE* inputFile = fopen(filename, "r");
    if (inputFile == NULL)
    {
        printf("������ ��� �������� ����� %s\n", filename);
        return 1;
    }
    char* dot = strrchr(filename, '.');
    if (dot != NULL) 
    {
        *dot = '\0';
    }
    char outputFilename[100];
    strcpy(outputFilename, filename);
    strcat(outputFilename, "parity1.dat");
    FILE* outputFile = fopen(outputFilename, "w");
    if (outputFile == NULL)
    {
        printf("������ ��� �������� ����� ��� ������\n");
        fclose(inputFile);
        return 1;
    }
    double number;
    int count = 0;
    while (fscanf(inputFile, "%lf", &number) != EOF)
    {
        if (count % 4 == 0)
        {
            number /= 2.0;
        }
        fprintf(outputFile, "%lf\n", number);

        count++;
    }
    fclose(inputFile);
    fclose(outputFile);
    printf("�������������� ��������� �������. ��������� ������� � ���� %s\n", outputFilename);
}