#pragma once

// Represents a point in 2D space.
struct Point2D
{
	float X;
	float Y;

	float getEuclidianDistance(const Point2D& B) const;
};
