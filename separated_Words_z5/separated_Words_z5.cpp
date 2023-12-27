//Наибольшее и наименьшее слово
#include <string>
#include <iostream>
#include <vector>
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	using namespace std;
	cout << "Введите строку: " << endl;
	string str;
	getline(cin, str);
	cout << "Введите разделяющий символ: ";
	char separator[] = " ";
	cin >> separator;
	int maxLength{ 0 };
	int minLength = 2 ^ 32;
	int checkChar{ 0 };
	str.push_back(*separator);
	vector <char> longWord;
	vector <char> shortWord;
	vector < vector <char>> allLongWords;
	vector < vector <char>> allShortWords;

	for (unsigned int i = 0; i < str.length(); i++) {
		if (str[i] != *separator) {
			checkChar++;
		}
		else {
			if (checkChar < minLength) {
				minLength = checkChar;
			}
			if (checkChar > maxLength) {
				maxLength = checkChar;
			}
			checkChar = 0;
		}
	}

	for (unsigned int i = 0; i < str.length(); i++) {
		if (str[i] != *separator) {
			longWord.push_back(str[i]);
			shortWord.push_back(str[i]);
		}
		else {
			if (longWord.size() == maxLength) {
				allLongWords.push_back(longWord);
			}
			if (shortWord.size() == minLength) {
				allShortWords.push_back(shortWord);
			}
			longWord.clear();
			shortWord.clear();
		}
	}


	cout << "Максимальная длина слова: " << maxLength << endl << "Самые длинные слова: ";

	for (int i = 0; i < allLongWords.size(); i++) {
		for (int j = 0; j < maxLength; j++) {
			cout << allLongWords[i][j];
		}
		if (i != allLongWords.size() - 1) {
			cout << ", ";
		}
		else {
			cout << "." << endl;
		}
	}

	cout << "Минимальная длина слова: " << minLength << endl << "Самые короткие слова: ";

	for (int i = 0; i < allShortWords.size(); i++) {
		for (int j = 0; j < minLength; j++) {
			cout << allShortWords[i][j];
		}
		if (i != allShortWords.size() - 1) {
			cout << ", ";
		}
		else {
			cout << "." << endl;
		}
	}


	return 0;
}