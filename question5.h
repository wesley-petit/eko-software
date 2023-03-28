#pragma once

#include <vector>
#include "Point.h"

/// <summary>
/// Add N random points between 0 and 1
/// </summary>
/// <param name="Points"></param>
/// <param name="N"></param>
void AddRandomPoints(std::vector<Point2D>& Points, size_t N);

/// <summary>
/// Sort a vector of points from the closet to th origin using an euclidian distance
/// </summary>
/// <param name="Points"></param>
/// <param name="Origin"></param>
void SortPointsByDistanceFromP(std::vector<Point2D>& Points, const Point2D Origin);

void EnsurePointsAreSortedByDistanceFromP(std::vector<Point2D>& Points, const Point2D Origin);

/// <summary>
/// Print all points of an array
/// </summary>
/// <param name="Points"></param>
void PrintPoints(const std::vector<Point2D>& Points);

void PointsExercise(size_t N, const Point2D& P);

void doQuestion5();
