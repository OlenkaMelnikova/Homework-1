// home.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <ctime>

using namespace std;
int  Value(int b, int Gamma)
{
	return(b^Gamma);
}
int cyclic_shift(int b_Gamma)
{
	return ((b_Gamma << 4) | (b_Gamma >> 28));
}
int reverse_cyclic_shift(int b_result)
{
	return ((b_result >> 4) | (b_result << 28));
}
int reverse_Value(int b_pre_Gamma, int Gamma)
{
	return(b_pre_Gamma^Gamma);
}
int main()
{
	char lenght[122];
	int key;
	cout << "Input: " << endl;
	cin.getline(lenght, 122);
	cout << "Input key: " << endl;
	cin >> key;
	cin.clear();
	srand(key);
	int vrb = rand();
	int Gamma = vrb % 122;
	int n = 1;
	for (int i = 0; lenght[i] != '\0'; ++i)
		n++;
	char *Phrase = (char *)malloc(n * sizeof(char));
	for (int i = 0; i < n; ++i)
		Phrase[i] = lenght[i];
	int *variable = (int *)malloc(n * sizeof(int));
	cout << "Value: "<<endl ;
	for (int i = 0; i < n; ++i) {
		variable[i] = Value(Phrase[i], Gamma);
		putchar(variable[i]);
	}
	cout << endl << "Cyclic_shift: "; 
	for (int i = 0; i < n; ++i) {
		variable[i] = cyclic_shift(variable[i]);
		putchar(variable[i]);
	}
	cout << endl << "Reverse_cyclic_shift: ";
	for (int i = 0; i < n; ++i) {
		variable[i] = reverse_cyclic_shift(variable[i]);
		putchar(variable[i]);
	}
	cout << endl << "Reverse_Value: ";
	for (int i = 0; i < n; ++i){
		variable[i] = reverse_Value(variable[i], Gamma);
		putchar(variable[i]);
	}
	cout << "\n";
	system("pause");
	return 0;
}


