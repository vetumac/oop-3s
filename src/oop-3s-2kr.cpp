//============================================================================
// Name        : oop-3s-2kr.cpp
// Author      : Alexey Suslov
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
using namespace std;

class BoolVector {
private:
	bool *element;
public:
	BoolVector(int n);
	BoolVector(const BoolVector& copy);
	BoolVector operator+(BoolVector ob);
	BoolVector operator*(BoolVector ob);
	BoolVector operator!();
	bool operator>(BoolVector ob);
	bool operator<(BoolVector ob);
	BoolVector operator=(BoolVector ob);
	void setElement(int n, bool value);
	bool getElement(int n);
	int getSize();
	void print();
	void randomFill();
};

BoolVector::BoolVector(const int n) {
	element = new bool[n + 1];
}

BoolVector::BoolVector(const BoolVector& copy) {
	const int vectorSize = sizeof(copy.element) + 1;
	element = new bool[vectorSize];
	for(int i = 0; i < vectorSize; i++)
		element[i] = copy.element[i];
}

BoolVector BoolVector::operator+(BoolVector ob) {
	const int vectorSize = sizeof(element) + 1;
	if (sizeof(ob.element) + 1 != vectorSize) {
		cout << "Error. Different vectors size ";
		return 0;
	}
	BoolVector result(vectorSize);
	for (int i = 0; i < vectorSize; i++)
		result.setElement(i, element[i] || ob.getElement(i));

	return result;
}

BoolVector BoolVector::operator*(BoolVector ob) {
	const int vectorSize = sizeof(element) + 1;
	if (sizeof(ob.element) + 1 != vectorSize) {
		cout << "Error. Different vectors size ";
		return 0;
	}
	BoolVector result(vectorSize);
	for (int i = 0; i < vectorSize; i++)
		result.setElement(i, element[i] && ob.getElement(i));

	return result;
}

BoolVector BoolVector::operator!() {
	const int vectorSize = sizeof(element) + 1;
	BoolVector result(vectorSize);
	for (int i = 0; i < vectorSize; i++)
		result.setElement(i, !element[i]);

	return result;
}

bool BoolVector::operator>(BoolVector ob) {
	const int vectorSize = sizeof(element) + 1;
	if (sizeof(ob.element) + 1 != vectorSize) {
		cout << "Error. Different vectors size ";
		return 0;
	}
	for (int i = 0; i < vectorSize; i++)
		if (element[i] < ob.getElement(i)) return false;

	return true;
}

bool BoolVector::operator<(BoolVector ob) {
	const int vectorSize = sizeof(element) + 1;
	if (sizeof(ob.element) + 1 != vectorSize) {
		cout << "Error. Different vectors size ";
		return 0;
	}
	for (int i = 0; i < vectorSize; i++)
		if (element[i] > ob.getElement(i)) return false;

	return true;
}

BoolVector BoolVector::operator=(BoolVector ob) {
	const int vectorSize = sizeof(element) + 1;
	if (sizeof(ob.element) + 1 != vectorSize) {
		cout << "Error. Different vectors size ";
		return 0;
	}
	for (int i = 0; i < vectorSize; i++)
		element[i] = ob.getElement(i);

	return *this;
}

void BoolVector::setElement(const int n, const bool value) {
	element[n] = value;
}

bool BoolVector::getElement(const int n) {
	return element[n];
}

int BoolVector::getSize() {
	return sizeof(element) + 1;
}

void BoolVector::print() {
	int size = sizeof(element) + 1;
	for(int i = 0; i < size; i++)
		cout << element[i];
}

void BoolVector::randomFill() {
	int size = sizeof(element) + 1;
	for(int i = 0; i < size; i++)
		element[i] = rand() % 2 == 0;
}

BoolVector customFunction(BoolVector a, BoolVector b) {
	const int vectorSize = a.getSize();
		if (b.getSize() != vectorSize) {
			cout << "Error. Different vectors size ";
			return 0;
		}
	BoolVector result(vectorSize);
	result = a + !b;
	return result;
}

int main() {
	const int N = 5;
	bool firstInput[N] = {true, false, false, true, false};
	BoolVector a(N);
	cout << "a = ";
	for (int i = 0; i < N; i++) {
		a.setElement(i, firstInput[i]);
		cout << a.getElement(i);
	}
	cout << endl;

	bool secondInput[N] = {true, true, false, true, true};
	BoolVector b(N);
	cout << "b = ";
	for(int i = 0; i < N; i++) {
		b.setElement(i, secondInput[i]);
		cout << b.getElement(i);
	}
	cout << endl;

	BoolVector c = a + b;
	cout << "c = a + b = ";
	c.print();
	cout << endl;

	BoolVector d = a * b;
	cout << "d = a * b = ";
	d.print();
	cout << endl;

	BoolVector e = !a;
	cout << "e = !a = ";
	e.print();
	cout << endl;

	bool f = a > b;
	cout << "f = a > b = ";
	cout << f;
	cout << endl;

	bool g = a < b;
	cout << "g = a < b = ";
	cout << g;
	cout << endl;

	a = b;
	cout << "a = b = ";
	a.print();
	cout << endl;

	int const M = 10;

	BoolVector vectotArray[M] = BoolVector(N);
	srand(1142);

	for(int i = 0; i < M; i++) {
		vectotArray[i].randomFill();
		vectotArray[i].print();
		cout << " -> ";
		customFunction(vectotArray[i], b).print();
		cout << endl;
	}

	return 0;
}
