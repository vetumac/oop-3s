//============================================================================
// Name        : oop-3s-1kr.cpp
// Author      : Alexey Suslov
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Word {
	char word[];
	int pages[10];
	int pagesCount;
public:
	Word();
	int* getPages();
	int getPagesCount();
	char* getWord();
	void out();
};

Word::Word() {
	cout<<"Input word: "; cin>>word;
	cout<<"Input pages with word count <= 10: "; cin>>pagesCount;
	for (int i = 0; i < pagesCount; i++) {
		cout<<"Input pages with word count"; cin>>pages[i];
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
	cout<<"Word: "<<word<<endl;
	cout<<"Pages with word count: "<<pagesCount<<endl;
	for (int i = 0; i < pagesCount; i++) {
		cout<<"Pages with word count: "<<pages[i]<<" ";
	}
	cout<<endl<<endl;
}

int main() {
	int wordsCount;
	cout<<"Input word count: "; cin>>wordsCount;

	Word *words;
	words = new Word[wordsCount];

	int minPageCount;
	cout<<"Input minimum page with word count (N) <= 10: "; cin>>minPageCount;

	cout<<"Words in more then N pages:"<<endl;
	for (int i = 0; i < wordsCount; i++) {
		if (words[i].getPagesCount() > minPageCount) {
			words[i].out();
		}
	}

	return 0;
}


