#include <mutex>
#include <shared_mutex>
#include <thread>
#include <string>
#include <iostream>
#include<algorithm>
using namespace std;

struct Point
{
	int x;
	int y;
	int z = 0;
	Point& operator+(Point p)
	{
		x += p.x;
		y += p.y;
		z += p.z;
		return *this;
	}
	Point& operator-(Point p)
	{
		x -= p.x;
		y -= p.y;
		z -= p.z;
		return *this;
	}

	float dot(Point p)
	{
		return x * p.x + y * p.y + z * p.z;
	}
	Point& cross(Point b)
	{
		Point p;
		p.x = y * b.z - z * b.y;
		p.y = z * b.x - x * b.z;
		p.z = x * b.y - y * b.x;
		return p;
	}
};

struct Triangle
{
	Point a;
	Point b;
	Point c;
};



// 선분AB를 기준으로 두 점 P, Q가 같은쪽에 있는지를 검사한다.
bool isSameSide(Point a, Point b, Point p, Point q)
{
	Point ba = b - a;
	Point pa = p - a;
	Point qa = q - a;
	auto c1 = ba.cross(pa);
	auto c2 = ba.cross(qa);
	return c1.dot(c2) >= 0;
}



int main()
{
	Triangle t;
	t.a = { 0,0,0 };
	t.b = { -5,5,0 };
	t.c = { 5,5,0 };


	cout << isSameSide(t.a, t.b, t.c, { 2,1 }) << " " << isSameSide(t.b, t.c, t.a, { 2,1 }) << " " << isSameSide(t.c, t.a, t.b, { 2,1 });


	return 0;
}