#pragma once

#include <iostream>
#include <cassert>

/// <summary>
/// Convert an image of RGB to GREY of size X and Y.
/// </summary>
/// <param name="pImage">Pointer to a unsigned integer 32 array of pixels</param>
/// <param name="SizeX"></param>
/// <param name="SizeY"></param>
void ConvertIntoGreyScale(void* pImage, size_t SizeX, size_t SizeY)
{
	uint32_t* pImageConverted = (uint32_t*)pImage;
	assert(pImageConverted != nullptr && "Invalid type in image");

	for (size_t i = 0; i < SizeX * SizeY; i++)
	{
		// Extract all components
		uint8_t R = (*pImageConverted >> 16) & 0xFF;
		uint8_t G = (*pImageConverted >> 8) & 0xFF;
		uint8_t B = *pImageConverted & 0xFF;

		// Print rgb channels
		std::cout << "RGB : " << pImageConverted[i] << " " << static_cast<unsigned int>(R) << " " << static_cast<unsigned int>(G) << " " << static_cast<unsigned int>(B) << "\n";

		// Use luminosity formula to convert rgb to grey
		uint8_t Grey = R * 0.2989 + G * 0.587 + B * 0.114;
		*pImageConverted = 0x00000000 | (Grey << 16) | (Grey << 8) | Grey;

		pImageConverted++;
	}
}

void PrintImage(const uint32_t* Image, size_t Size)
{
	for (size_t i = 0; i < Size; i++)
		std::cout << Image[i] << "  ";
}

void doQuestion2()
{
	std::cout << "Question 2\n";
	
	// Degine image and size
	const int WIDTH = 3;
	const int HEIGHT = 2;
	const int SIZE = WIDTH * HEIGHT;
	uint32_t Image[SIZE] = { 0x00FF00FF, 0x00FF0000, 0x00FF0000, 0x00FFFFFF, 0x00FF0000, 0x00FFFFFF };

	std::cout << "Input : \n";
	PrintImage(Image, SIZE);
	std::cout << "\n";

	ConvertIntoGreyScale(Image, WIDTH, HEIGHT);
	
	std::cout << "Output : \n";
	PrintImage(Image, SIZE);
	std::cout << "\n";

	std::cout << "\n";
}