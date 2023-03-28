#pragma once

#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
#include <algorithm>

/// <summary>
/// Return the k of the most common of input. K start at 1 for first position...
/// </summary>
/// <param name="Input"></param>
/// <param name="K"></param>
/// <returns></returns>
int NthMostCommon(std::vector<int>& Input, const int K)
{
	assert(0 < K && "K must be a strict positive for this algorithme");

	std::unordered_map<int, int> CountByInt;

	// Count / Register each integer
	for (const auto& Current : Input)
		CountByInt[Current]++;
	
	// Convert to a vector of pair because a map or unorderer map can not be sort by value
	std::vector<std::pair<int, int>> SortableCount;
	for (const auto& it : CountByInt)
		SortableCount.push_back(it);

	// Sort result to get the nth most common
	std::sort(SortableCount.begin(), SortableCount.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
		// Inverse sens placing the first as the most common
		return b.second < a.second;
	});
	
	//// Show sortable results
	//for (const auto& [input, count] : SortableCount)
	//	std::cout << "Int : " << input << " - Count " << count << "\n";

	if (static_cast<unsigned int>(K) <= SortableCount.size())
	{
		// -1 because K starts at 0
		return SortableCount[K - 1].first;
	}

	return -1;
}

void doQuestion4()
{
	std::cout << "Question 4\n";
	std::vector<int> Inputs({1, 2, 2, 3, 3, 3, 3, 4, 4, 4});
	const int MAX_NTH = 4;

	// Create a podium for each position
	for (size_t i = 1; i <= MAX_NTH; i++)
		std::cout << "In " << i << " Position : " << NthMostCommon(Inputs, i) << "\n";

	std::cout << "\n";
}