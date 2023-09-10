// rechner_mit_rest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



int main()
{
	int eingabe_zahl = 0;
	printf("Bitte gib eine Zahl ein: ");
	scanf("%d", &eingabe_zahl);
	if ((eingabe_zahl % 2) == 0)
	{
		printf("%d ist teilbar durch folgende Zahlen und all deren Vielfachen teilbar:\n1\n2", eingabe_zahl);
		for (int i = 3; i < 8; i = i + 2)
		{
			if ((eingabe_zahl % i) == 0)
			{
				printf("\n%d\n", i);
			}
		}
		printf("\nund natuerlich durch sichs selbst %d", eingabe_zahl);
	}
	else if ((eingabe_zahl % 2) != 0)
	{
		for (int kleinster_teiler = 3; kleinster_teiler < 10; kleinster_teiler = kleinster_teiler + 2)
		{
			if (eingabe_zahl % kleinster_teiler == 0)
			{
				printf("%d ist teilbar durch:\n1\n%d\nall deren Vielfachen\nund natuerlich durch sich selbst \n%d\n", eingabe_zahl, kleinster_teiler, eingabe_zahl);
				kleinster_teiler = kleinster_teiler + 10;
			}
			if (kleinster_teiler == 9)
			{
				printf("Hier handelt es sich um eine Primzahl die nur durch 1 und sich selbst teilbar ist");
			}
		}	
	}
 
}

