// Домашнее_Задание_№1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <ctime>

unsigned sdvigrigth(unsigned a, int n, int L) 
{

	unsigned maska = 0; 
	for (int i = 0; i<L; i++)
	{
		maska <<= 1; 
		maska += 1; 
	}
	unsigned b = a & maska; 
	b <<= (n - L); 
	a >>= L; 
	return a | b; 
}

unsigned sdvigleft(unsigned a, int n, int L) 
{
	unsigned maska = 0; 
	for (int i = 0; i<L; i++)
	{
		maska <<= 1; 
		maska += 1; 
	}
	maska <<= (n - L); 

	unsigned b = a & maska; 
	b >>= (n - L);
	a <<= L; 
	return a | b; 
}


void ShifrDeshifr(unsigned char *in, unsigned char *out, int len, int key, bool flag)
{

	int n = len / 4;
	int m = len % 4;
	if (m) n++;
	unsigned char *s = in, *s2 = out;
	unsigned a, b, gamma;
	srand(key);
	int k;
	for (int i = 0; i < n; i++, s += 4, s2 += 4)
	{
		if (i == n - 1 && m) k = m * 8;
		else k = 32;
		a = 0;
		memcpy(&a, s, k / 8);
		if (!flag) a = sdvigrigth(a, k, 3);
		gamma = rand();
		gamma <<= 16;
		gamma += rand();
		switch (k)
		{
		case 24: gamma &= 0xffffff; break;
		case 16: gamma &= 0xffff; break;
		case 8:  gamma &= 0xff;
		}
		b = a ^ gamma;
		if (flag) b = sdvigleft(b, k, 3);
		memcpy(s2, &b, k / 8);

	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	char StrIn[256];
	char StrShifr[256];
	char StrOut[256];
	printf("Str="); fflush(stdin);
	gets(StrIn);
	int len = strlen(StrIn);
	int key1, key2;
	printf("key1="); scanf("%d", &key1);

	ShifrDeshifr((unsigned char *)StrIn, (unsigned char *)StrShifr, len, key1, true);

	printf("Posle shifr:");
	for (int i = 0; i < len; i++)
		printf("\nChar=%c Code=%d", StrShifr[i], StrShifr[i]);
	printf("\nkey2="); scanf("%d", &key2);

	ShifrDeshifr((unsigned char *)StrShifr, (unsigned char *)StrOut, len, key2, false);
	StrOut[len] = 0;

	printf("\nPosle deshfr:\n%s\n", StrOut);
	system("pause");

	return 0;
}
