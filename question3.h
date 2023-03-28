#pragma once

#include <iostream>
#include <string.h>

char* CountMeOnce(const char* string1, const char* string2)
{
	// Contains num of each char in the first string1
	// We use a basic array, but it could be replace by a custom implementation of a map bringing more security and speed.
	int* MapChar = (int*)calloc(256, sizeof(int));
	char* Output = (char*)malloc(strlen(string2));

	for (size_t i = 0; i < strlen(string1); i++)
	{
		// Convert char to int to use as a key in a map container
		int Key = string1[i];
		MapChar[Key]++;
	}

	int CurrentCharIndex = 0;
	for (size_t i = 0; i < strlen(string2); i++)
	{
		int Key = string2[i];
		if (0 < MapChar[Key])
		{
			Output[CurrentCharIndex++] = string2[i];

			// Make sure the character appear only on the first occurance of both strings
			MapChar[Key] = 0;
		}
	}

	free(MapChar);

	Output[CurrentCharIndex] = '\0';
	return Output;
}

void doQuestion3()
{
	std::cout << "Size" << sizeof(char) ;

	const char* string1("aab$Cbb");
	const char* string2("Caa");

	std::cout << "Question 3" << "\n";
	std::cout << CountMeOnce(string1, string2) << "\n";
	std::cout << CountMeOnce(string2, string1) << "\n\n";
}