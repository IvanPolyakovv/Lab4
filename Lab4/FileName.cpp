#include <iostream>
#include <fstream>

using namespace std;

int menu()
{
	cout << "1. Removes unnecessary spaces, removes unnecessary punctuation marks, corrects the letter case if required\n" <<
		"2. Displays the words of the sequence in reverse order\n" <<
		"3. Displays the same sequence on the screen, replacing numbers in all words with letters of the Latin alphabet, the numbers of which in the alphabet are equal to the digit being replaced.\n" <<
		"4. Finds all the substrings that the user will enter in the existing string\n";
	cout << "Enter your choice: ";
	return 0;
}

void deleteSpaces(char* inputText, char* newText)
{
	int i = 0, j = 0;
	while(inputText[i] != '\0')
	{
		if (inputText[i] == inputText[i + 1] && inputText[i] == ' ')
		{
			newText[j] = inputText[i + 1];
			j++;
			i += 2;
		}
		else 
		{
			newText[j] = inputText[i];
			j++;
			i++;
		}
	}
	newText[i] = '\0';
	cout << "The new string: \n";
	cout << newText;
}

void changeRegister(char* inputText, char* newText)
{
	cout << "You entered: ";
	cout << inputText << '\n';
	int i = 1, j = 1;
	newText[0] = inputText[0];
	while (inputText[i] != '\0')
	{
		if ((inputText[i - 1] >= 65 && inputText[i - 1] <= 90) && (inputText[i] >= 65 && inputText[i] <= 90))
		{
			newText[j] = inputText[i] + 32;
		}
		else if ((inputText[i - 1] >= 97 && inputText[i - 1] <= 122) && (inputText[i] >= 65 && inputText[i] <= 90))
		{
			newText[j] = inputText[i] + 32;
		}
		else
		{
			newText[j] = inputText[i];
		}
		i++;
		j++;
	}
	newText[i] = '\0';
	cout << "The new string: ";
	cout << newText << '\n';
}

void deletePunctuationMarks(char* inputText, char* newText)
{
	cout << "You entered: \n";
	cout << inputText;
	int i = 0, j = 0;
	while (inputText[i] != '\0')
	{
		if ((inputText[i] == '-' || inputText[i] == ',' || inputText[i] == ':' || inputText[i] == '"') && (inputText[i + 1] == '-' || inputText[i + 1] == ',' || inputText[i + 1] == ':' || inputText[i + 1] == '"'))
		{
			newText[j] = inputText[i];
			j++;
			i += 2;
		}
		else
		{
			newText[j] = inputText[i];
			j++;
			i++;
		}
	}
	newText[i] = '\0';
	cout << "The new string: \n";
	cout << newText;
}

void reverseWords(char* inputText)
{
	int j, i;
	i = 0;
	while (inputText[i] != '\0')
	{
		if (inputText[i] == ' ')
		{
			for (j = i - 1; j >= 0; j--)
			{
				cout << inputText[j];
			}
			cout << ' ';
		}
		i++;
	}
}

void numbersToLetters(char* inputText, char* newText)
{
	int i;
	i = 0;
	while (inputText[i] != '\0')
	{
		if (inputText[i] >= 48 && inputText[i] <= 57)
		{
			newText[i] = inputText[i] + 17;
		}
		else
		{
			newText[i] = inputText[i];
		}
		i++;
	}
	newText[i] = '\0';
	cout << newText;
}

void lineSearch(char* inputText, char* pattern) {
	int inputSize = strlen(inputText);
	int patternSize = strlen(pattern);

	for (int i = 0; i <= inputSize - patternSize; i++)
	{
		int j;
		for (j = 0; j < patternSize; j++)
			if (inputText[i + j] != pattern[j])
				break;

		if (j == patternSize)
			cout << "Pattern found at Index " << i + 1 << "\n";
	}
}

int main()
{
	const int length = 51;
	char text[length];
	char newText[length];
	cout << "                                                  ] Enter the text before ']': \n";
	cin.getline(text, 51);
	cout << "You entered: " << text << '\n';
	menu();
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "1. Delete excess spaces\n2. Delete excess punctuation marks\n3. Change register if it's necessary\nEnter your choice: ";
		int choice2;
		cin >> choice2;
		switch (choice2)
		{
		case 1:
			deleteSpaces(text, newText);
			break;
		case 2:
			deletePunctuationMarks(text, newText);
			break;
		case 3:
			changeRegister(text, newText);
			break;
		default:
			cout << "Error";
		}
		break;
	case 2:

		reverseWords(text);
		break;
	case 3:
		numbersToLetters(text, newText);
		break;
	case 4:
		cout << "Enter the pattern: ";
		char pattern[51];
		cin.getline(pattern,51);
		lineSearch(text, pattern);
		break;
	default:
		cout << "Error";
	}
	return 0;
}