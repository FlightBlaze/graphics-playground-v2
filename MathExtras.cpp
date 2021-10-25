#include <MathExtras.h>

float lerpf(float a, float b, float t)
{
	return a + t * (b - a);
}

float invlerpf(float a, float b, float v)
{
	return (v - a) / (b - a);
}

float remapf(float iMin, float iMax, float oMin, float oMax, float v)
{
	float t = invlerpf(iMin, iMax, v);
	return lerpf(oMin, oMax, t);
}

// Point in triangle test with barycentric coordinate system
// http://totologic.blogspot.com/2014/01/accurate-point-in-triangle-test.html
// https://blackpawn.com/texts/pointinpoly/

bool barycentricIsPointInTriangle(glm::vec2 v1, glm::vec2 v2, glm::vec2 v3, glm::vec2 point) {
	float denominator = ((v2.y - v3.y) * (v1.x - v3.x) + (v3.x - v2.x) * (v1.y - v3.y));
	float a = ((v2.y - v3.y) * (point.x - v3.x) + (v3.x - v2.x) * (point.y - v3.y)) / denominator;
	float b = ((v3.y - v1.y) * (point.x - v3.x) + (v1.x - v3.x) * (point.y - v3.y)) / denominator;
	float c = 1 - a - b;

	return 0 <= a && a <= 1 && 0 <= b && b <= 1 && 0 <= c && c <= 1;
}

//glm::vec2 perpendicularClockwise(glm::vec2 v)
//{
//	return glm::vec2(v.y, -v.x);
//}
//
//glm::vec2 perpendicularCounterClockwise(glm::vec2 v)
//{
//	return glm::vec2(-v.y, v.x);
//}

//float sameSide(glm::vec2 v1, glm::vec2 v2, glm::vec2 point)
//{
//	return (v2.y - v1.y) * (point.x - v1.x) + (-v2.x + v1.x) * (point.y - v1.y);
//}

bool isPointInTriange(glm::vec2 a, glm::vec2 b, glm::vec2 c, glm::vec2 point)
{
	//bool side1 = sameSide(a, b, point) >= 0;
	//bool side2 = sameSide(b, c, point) >= 0;
	//bool side3 = sameSide(c, a, point) >= 0;
	//return side1 && side2 && side3;
	return barycentricIsPointInTriangle(a, b, c, point);
}
