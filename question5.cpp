#pragma once

#include "question5.h"

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <limits>
#include <optional>

std::ostream& operator<<(std::ostream& os, const Point2D& point)
{
	os << '(' << point.X << ", " << point.Y << ')';
	return os;
}

void AddRandomPoints(std::vector<Point2D>& Points, size_t N)
{
	srand(time(NULL));

	for (size_t i = 0; i < N; i++)
	{
		float RandX = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
		float RandY = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);

		Points.push_back({ RandX, RandY });
	}
}

void SortPointsByDistanceFromP(std::vector<Point2D>& Points, const Point2D Origin)
{
	std::sort(Points.begin(), Points.end(), [Origin](Point2D& A, Point2D& B) {
		return Origin.getEuclidianDistance(A) < Origin.getEuclidianDistance(B);
	});
}

void EnsurePointsAreSortedByDistanceFromP(std::vector<Point2D>& Points, const Point2D Origin)
{
	// Testing euclidian function
	const Point2D A { 0, 0 };
	const Point2D B { 1, 1 };
	assert(std::fabs(A.getEuclidianDistance(B) - sqrt(2.0f)) < std::numeric_limits<float>::epsilon() && "Euclidian distance return an invalid result");

	// Testing if every items is correctly sorted
	std::optional<float> MinDistance;
	for (const auto& Current : Points)
	{
		float Distance(Origin.getEuclidianDistance(Current));
		if (MinDistance.has_value())
		{
			assert(MinDistance.value() < Distance && "Vector points wasn't correctly sort.");
		}
		
		MinDistance = Distance;
	}
}

void PrintPoints(const std::vector<Point2D>& Points)
{
	std::cout << "Pint points" << "\n";
	for (size_t i = 0; i < Points.size(); i++)
	{
		std::cout << "Point : " << i << " - Coordinate : " << Points[i] << "\n";
	}
}

// This function should appear as is, without any modification, in your answer to this exercise.
void PointsExercise(size_t N, const Point2D& P)
{
	std::vector<Point2D> Points;

	AddRandomPoints(Points, N);
	SortPointsByDistanceFromP(Points, P);
	EnsurePointsAreSortedByDistanceFromP(Points, P);
	
	PrintPoints(Points);
}

void doQuestion5()
{
	std::cout << "Question 5" << "\n";
	PointsExercise(5, {0, 0});
}