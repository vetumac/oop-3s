//============================================================================
// Name        : oop-3s-1kr.cpp
// Author      : Alexey Suslov
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;

class Word {
private:
	char word[30];
	int pages[10];
	int pagesCount;
public:
	Word();
	Word(char[30]);
	int* getPages();
	int getPagesCount();
	char* getWord();
	void out();
	int compareTo(Word);
	bool equalsWord(Word);
};

Word::Word() {
	cout << "Input word: ";
	cin >> word;
	cout << "Input pages with word count <= 10: ";
	cin >> pagesCount;
	for (int i = 0; i < pagesCount; i++) {
		cout << "Input pages with word : ";
		cin >> pages[i];
	}
}

Word::Word(char anotherWord[30]) {
	strcpy(word, anotherWord);
}

int* Word::getPages() {
	return pages;
}

int Word::getPagesCount() {
	return pagesCount;
}

char* Word::getWord() {
	return word;
}

void Word::out() {
	cout << "Word: " << word << endl;
	cout << "Pages with word count : " << pagesCount << endl;
	cout << "Pages with word : ";
	for (int i = 0; i < pagesCount; i++) {
		cout << pages[i] << " ";
	}
	cout << endl;
}

int Word::compareTo(Word thatWord) {
	int thatWordLen = strlen(thatWord.word);
	int thisWordLen = strlen(word);

	int i = 0;
	while (i < thisWordLen && i < thatWordLen) {
		if (word[i] < thatWord.getWord()[i]) return -1;
		if (word[i] > thatWord.getWord()[i]) return 1;
		i++;
	}
	if (thisWordLen < thatWordLen) return -1;
	if (thisWordLen > thatWordLen) return 1;
	return  0;
}

bool Word::equalsWord(Word thatWord) {
	return compareTo(thatWord) == 0 ? true : false;
}

void quickSort(Word a[], int first, int last)
{
    int i = first, j = last;
    Word x = a[(first + last) / 2];
    do {
        while (a[i].compareTo(x) < 0) i++;
        while (a[j].compareTo(x) > 0) j--;

        if(i <= j) {
            if (i < j) swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (i < last)
        quickSort(a, i, last);
    if (first < j)
        quickSort(a, first, j);
}

int main() {
	// create array of Words
	int wordsCount;
	cout << "Input word count: ";
	cin >> wordsCount;
	Word words[wordsCount];
	int minPageCount;
	cout << "Input minimum page with word count (N) <= 10: ";
	cin >> minPageCount;

	// a)
	cout << "Words in more then N pages: ";
	for (int i = 0; i < wordsCount; i++) {
		if (words[i].getPagesCount() > minPageCount) {
			words[i].out();
		}
	}

	// b)
	quickSort(words, 0, wordsCount - 1);
	for (int i = 0; i < wordsCount; i++) {
		words[i].out();
	}

	// c)
	char word[30];
	cout << "Input word to compare: ";
	cin >> word;
	Word* wordNew = new Word(word);
	for (int i = 0; i < wordsCount; i++) {
		if (words[i].equalsWord(*wordNew)) {
			words[i].out();
		}
	}

	return 0;
}
