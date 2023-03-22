#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void file_as_file();
void file_as_terminal();
void file_as_printer();

void file_readText(char path[]);
void file_readBin(char path[]);

void file_writeText(char path[]);
void file_writeBin(char path[]);

int main() {
	srand(time(0));
	int arr[6][9],sum = 0;
	int r = 1,index=0;
	FILE* file;
	char str[1000] = "";


	for (int i = 0; i < 6; i++)
	{
		for (int i2 = 0; i2 < 9; i2++)
		{
			int randNum = rand() % 10;
			str[index] = i2+49;
			index++;
			str[index] = ' ';
			index++;
			if (i == i2)
			{
				r = 0;
			}
			if (r == 1)
			{
				sum += arr[i][i2];

			}
		}
		str[index] = '\n';
		index++;
		r = 1;
	}

	file = fopen("j1.txt", "w");
	fprintf(file, str);
	fclose(file);

	int ba[6][9];
	file = fopen("j1.txt","r");
	fread(ba,sizeof(arr[0]),6,file);
	for  (int i  = 0; i  < 6; i++)
	{
		for (int i2 = 0; i2 < 9; i2++)
		{
			printf("%d\t",ba[i][i2]);
		}
		r = 1;
		puts("");
	}
	
	fclose(file);
	printf("sum = %d",sum);
	return 0;
}


void file_as_file()
{
	FILE* fp;

	fp = fopen("file.txt", "w");
	fprintf(fp, "Це текст, який буде записаний у файл\n");
	fclose(fp);
}
void file_as_terminal()
{
	printf("Введіть ваше ім'я: ");

	char name[50];
	scanf("%s", name);

	printf("Привіт, %s!\n", name);
}
void file_as_printer()
{
	FILE* fp;

	fp = fopen("/dev/lp0", "w");
	fprintf(fp, "Текст, який буде роздрукований на принтері\n");
	fclose(fp);
}

void file_readText(char path[])
{
	printf("read\n");
	FILE* fp;
	char str[100];

	fp = fopen(path, "r");
	if (fp == NULL) {
		printf("Open error ");
		return;
	}

	while (fgets(str, 100, fp) != NULL) {
		printf("%s", str);
	}

	fclose(fp);
}

void file_writeText(char path[])
{
	printf("write, %s \n", path);
	FILE* fp;

	fp = fopen(path, "w");
	if (fp == NULL) {
		printf("Open error");
		return;
	}

	fprintf(fp, "New text to file\n");
	fclose(fp);
}
void file_readBin(char path[])
{
	printf("read, %s \n", path);

	FILE* fp;
	int num;

	//fp = fopen("file.bin", "rb");
	fp = fopen(path, "rb");

	if (fp == NULL) {
		printf("Open error");
		return -1;
	}

	while (fread(&num, sizeof(int), 1, fp) == 1) {
		printf("%d ", num);
	}

	fclose(fp);
}
void file_writeBin(char path[])
{
	FILE* fp;
	int nums[] = { 1, 2, 3, 4, 5 };

	fp = fopen(path, "wb");
	if (fp == NULL) {
		printf("Open Error");
		return -1;
	}

	fwrite(nums, sizeof(int), 5, fp);

	fclose(fp);
}
