#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstdio>

using namespace std;

const int MAX_NO_OF_QUE = 60;
const int MAX_NO_OF_ANS = 10;
const int MAX_QUE_LENGTH = 1024;
const int MAX_ANS_LENGTH = 128;

struct Answer
{
	char option[4];
	char answerOption[MAX_ANS_LENGTH + 1];
	bool isRight;
};

struct Question
{
	char type[5];
	char question[MAX_QUE_LENGTH + 1];
	struct Answer ans[MAX_NO_OF_ANS];
};

struct Question questions[MAX_NO_OF_QUE] = { {} };

int main()
{
	FILE* sfptr = fopen("quiz2.txt", "r");
	int i = 0;
	
	if (!sfptr)
	{
		cout << "invalide file" << endl;
	}
	else
	{
		struct Question temp[MAX_NO_OF_QUE] = { {} };
		//int ignore = 0;
		int indexController = -1;
		int answerIndexController = 0;
		char ch = '\0';

		do
		{
			ch = fgetc(sfptr);
			putchar(ch);
			fseek(sfptr, -1, SEEK_CUR);

			if (ch == '{')
			{
				indexController++;
				answerIndexController = 0;
				(fscanf(sfptr, "%4[^\n] %[^\n]\n",
					temp[indexController].type, temp[indexController].question) == 0);
			}
			else if (ch == '[')
			{
				 fscanf(sfptr, "%3[^\n]%[^\n]\n",
					temp[indexController].ans[answerIndexController].option, temp[indexController].ans[answerIndexController].answerOption);
				answerIndexController++;
			}
			else if (ch == '\n')
			{
				fseek(sfptr, 2, SEEK_CUR);
			}
			else
			{
				cout << "End Of File";
			}
			/*switch (ch)
			{
			case '{':
				int ignore = (fscanf(sfptr, "%4[^\n] %[^\n]\n",
					temp[i].type, temp[i].question) == 0);
				break;
			case '[':
				int idnore = (fscanf(sfptr, "%3[^\n] %[^\n]\n",
					temp[i].ans[answerIndexController].option, temp[i].ans[answerIndexController].answerOption) == 0);
				answerIndexController++;
				break;
			case '\n':
				if (countNewLine == 0)
				{
					fseek(sfptr, 2, SEEK_CUR);
					countNewLine++;
				}
				else if (countNewLine == 1)
				{
					countNewLine = 0;
					i++;
					answerIndexController = 0;
				}
			default:
				fseek(sfptr, 3, SEEK_CUR);
				break;
			}*/
		} while (ch != EOF);

		for (i = 0; i < MAX_NO_OF_QUE; i++)
		{
			questions[i] = temp[i];
		}	
	}
	if (sfptr) fclose(sfptr);

	int index = 0;

	do {
		cout << endl << "Enter Index : ";
		cin >> index;
		cout << endl;

		cout << "Question Number : " << index + 1 << endl;
		puts(questions[index].type);
		puts(questions[index].question);
		for (int j = 0; j < MAX_NO_OF_ANS; j++)
		{
			cout << j + 1 << ".-> ";
			puts(questions[index].ans[j].answerOption);
		}
	} while (index != 10);
	return 0;
}

/*int main()
{
	FILE* sfptr = fopen("quiz2.txt", "r");

	if (!sfptr)
	{
		cout << "invalide file" << endl;
	}
	else
	{
		struct Question temp[MAX_NO_OF_QUE] = { {} };
		int i = 0;
		int ignore = 0;
		int answerIndexController = 0;
		char ch = '\0';
		int countNewLine = 0;

		do
		{
			ch = fgetc(sfptr);
			putchar(ch);
			fseek(sfptr, -1, SEEK_CUR);

			switch (ch)
			{
			case '{':
				int ignore = (fscanf(sfptr, "%4[^\n] %[^\n]\n",
					temp[i].type, temp[i].question) == 0);
				break;
			case '[':
				int idnore = (fscanf(sfptr, "%3[^\n] %[^\n]\n",
					temp[i].ans[answerIndexController].option, temp[i].ans[answerIndexController].answerOption) == 0);
				answerIndexController++;
				break;
			case '\n':
				if (countNewLine == 0)
				{
					fseek(sfptr, 2, SEEK_CUR);
					countNewLine++;
				}
				else if (countNewLine == 1)
				{
					countNewLine = 0;
					i++;
					answerIndexController = 0;
				}
			default:
					fseek(sfptr, 3, SEEK_CUR);
				break;
			}
		} while (ch != EOF);
		for (i = 0; i < 7; i++)
		{

			puts(temp[i].type);
			puts(temp[i].question);
			for (int j = 0; j < MAX_NO_OF_ANS; j++)
			{
				cout << j + 1 << ".-> ";
				puts(temp[i].ans[j].answerOption);
			}
		}
	}

	if (sfptr) fclose(sfptr);
	
	int index = 0;

	cout << endl << "Enter Index";
	cin >> index;

	printQuestion(index);

	return 0;
}

void printQuestion(int index)
{
	cout << "Question Number : " << index + 1 << endl;
	puts(questions[index].type);
	puts(questions[index].question);
	for (int j = 0; j < MAX_NO_OF_ANS; j++)
	{
		cout << j + 1 << ".-> ";
		puts(questions[index].ans[j].answerOption);
	}
}*/