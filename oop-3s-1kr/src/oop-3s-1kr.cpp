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
	char word[4];
	int pages[10];
	int pagesCount;
public:
	Word();
	int* getPages();
	int getPagesCount();
	char* getWord();
	void out();
	int compareTo(Word);
};

Word::Word() {
	cout << "Input word: " << endl;
	cin >> word;
	cout << "Input pages with word count <= 10: " << endl;
	cin >> pagesCount;
	for (int i = 0; i < pagesCount; i++) {
		cout << "Input pages with word count" << endl;
		cin >> pages[i];
	}
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
	cout << "Pages with word count: " << pagesCount << endl;
	for (int i = 0; i < pagesCount; i++) {
		cout << "Pages with word count: " << pages[i] << " " << endl;
	}
	cout<<endl<<endl;
}

int Word::compareTo(Word thatWord) {
	int thatWordLen = strlen(thatWord.word);
	int thisWordLen = strlen(word);

	if (thisWordLen < thatWordLen) return -1;
	if (thisWordLen > thatWordLen) return 1;

	int i = 0;
	while (i < thisWordLen && i < thatWordLen) {
		if (word[i] < thatWord.word[i]) return -1;
		if (word[i] > thatWord.word[i]) return 1;
		i++;
	}
	return  0;
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
	int wordsCount;
	cout << "Input word count: " << endl; cin>>wordsCount;

	Word *words;
	words = new Word[wordsCount];

	int minPageCount;
	cout << "Input minimum page with word count (N) <= 10: " << endl;
	cin >> minPageCount;

	cout << "Words in more then N pages:" << endl;
	for (int i = 0; i < wordsCount; i++) {
		if (words[i].getPagesCount() > minPageCount) {
			words[i].out();
		}
	}

	quickSort(words, 0, wordsCount - 1);

	for (int i = 0; i < wordsCount; i++) {
		words[i].out();
	}

	return 0;
}
