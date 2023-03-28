#include "Point.h"
#include <cmath>

float Point2D::getEuclidianDistance(const Point2D& B) const
{
	return sqrt(pow((B.X - X), 2) + pow((B.Y - Y), 2));
}