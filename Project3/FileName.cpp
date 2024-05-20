#include <iostream>
#include <cstring>
#pragma warning(disable : 4996) 
using namespace std;
/*Дано текстовий файл. Видалити з нього останній рядок. Результат записати в інший файл.*/
int main()
{
	const char* inputFilePath = "input.txt";
	const char* outputFilePath = "output.txt";

	FILE* inputFile = fopen(inputFilePath, "r");
	FILE* outputFile = fopen(outputFilePath, "w");
	if (inputFile != nullptr && outputFile != nullptr)
	{
		int lineCount = 0;
		const int MAX_LINE_LENGTH = 555;
		const char* line[MAX_LINE_LENGTH];
		while (!feof(inputFile))
		{
			for (int i = 0; line[i] != '\0'; ++i)
			{
				if (*line[i] == '\n')
				{
					lineCount += 1;
				}
			}
		}
		fclose(inputFile);
		fclose(outputFile);
		for (int i = 0; i < lineCount - 1; i++)
		{
			fputs(line[i], outputFile);
		}
	}
	else
	{
		cout << "Error";
		fclose(inputFile);
		fclose(outputFile);
	}
}
/*Дано текстовий файл. Знайти довжину найдовшого рядка.*/
int main()
{
	const char* filePath = "data.txt";
	FILE* file = fopen(filePath, "r");
	int max = INT_MIN;
	
	const int MAX_LINE_LENGTH = 555;
	char line[MAX_LINE_LENGTH];
	if (file != nullptr)
	{
		while (!feof(file))
		{
			int length = strlen(line);
			if (length > 0 && (line[length - 1] == '\n' || line[length - 1] == '\r')) 
			{
				length--;
			}
			if (length > max) 
			{
				max = length;
			}
		}
		if (max == INT_MIN) 
		{
			printf("File is empty or an error occurred\n");
		}
		else {
			printf("The length of the longest line is: %d\n", max);
		}
		fclose(file);

		return 0;
	}
	else
	{
		cout << "Error";
		fclose(file);
	}
}
