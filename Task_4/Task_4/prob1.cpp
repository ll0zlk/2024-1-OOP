#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Point {
public:
	int x;
	int y;
	Point() = default;
	Point(int a, int b) : x(a), y(b) {}
};

class Rect {
private:
	Point ll;
	Point ru;
public:
	Rect(Point a, Point b) : ll(a), ru(b) {} // 생성자

	Point getLeftLower() const {
		return ll;
	}

	Point getRightUpper() const {
		return ru;
	}

	int area() const { // 사각형 넓이
		int width = abs(ru.x - ll.x);
		int height = abs(ru.y - ll.y);
		return width * height;
	}

	bool intersect(Point center, int radius) const { // 추가된 원과 교차 여부
		// 사각형 중심과 원 중심 사이 거리
		int distX = abs((ll.x + ru.x) / 2 - center.x);
		int distY = abs((ll.y + ru.y) / 2 - center.y);

		// 1. 사각형 너비/높이 절반 + 반지름 합한 게 중심 사이 거리보다 크면 겹침
		if (distX <= (ru.x - ll.x) / 2 + radius && distY <= (ru.y - ll.y) / 2 + radius)
			return true;
		// 2. 원의 중심이 사각형 안에 있으면 겹침
		if ((center.x - ll.x) * (center.x - ru.x) <= 0 && (center.y - ll.y) * (center.y - ru.y) <= 0)
			return true;
		// 3. 각 꼭짓점과 원 중심 사이의 거리가 반지름보다 작거나 같으면 겹침
		if ((center.x - ll.x) * (center.x - ll.x) + (center.y - ll.y) * (center.y - ll.y) <= radius * radius)
			return true; // 왼쪽 아래 점
		if ((center.x - ru.x) * (center.x - ru.x) + (center.y - ll.y) * (center.y - ll.y) <= radius * radius)
			return true; // 오른쪽 아래 점
		if ((center.x - ll.x) * (center.x - ll.x) + (center.y - ru.y) * (center.y - ru.y) <= radius * radius)
			return true; // 왼쪽 위 점
		if ((center.x - ru.x) * (center.x - ru.x) + (center.y - ru.y) * (center.y - ru.y) <= radius * radius)
			return true; // 오른쪽 위 점

		// 아니면 안 겹침
		return false;
	}
};

class Circle {
private:
	Point center;
	int radius;
public:
	Circle(Point c, int r) : center(c), radius(r) {} // 생성자

	Point getCenter() const {
		return center;
	}

	int getRadius() const {
		return radius;
	}

	double area() const { // 원 넓이
		return 3.141592 * radius * radius;
	}

	bool intersect(Point otherC, int otherR) const { // 추가된 원과 교차 여부
		// 두 원 중심 사이 거리 (제곱 형태)
		int distX = center.x - otherC.x;
		int distY = center.y - otherC.y;
		int distSq = distX * distX + distY * distY;
		// 두 원 반지름 합 (제곱 형태)
		int radiusSq = (otherR + radius) * (otherR + radius);

		// 두 원 중심 사이 거리가 두 원 반지름 합보다 작거나 같으면 겹침
		return (distSq <= radiusSq);
	}
};

// 넓이를 기준으로 정렬 후 정보를 출력하기 위한 클래스 설정
class Shapes {
public:
	double area;
	string type;
	string info;
	Shapes(double a, string t, string i) : area(a), type(t), info(i) {}
};

// sort 함수를 위한 넓이 기준 비교 함수
bool compare(Shapes& a, Shapes& b) {
	return a.area < b.area;
}

int main() {
	ifstream inFile("input1.txt");

	int n;
	inFile >> n;

	vector<Rect> rects;
	vector<Circle> circles;

	for (int i = 0; i < n; i++) {
		char type;
		inFile >> type;

		if (type == 'R') {
			int x1, x2, y1, y2;
			inFile >> x1 >> x2 >> y1 >> y2;
			Point ll(x1, y1);
			Point ru(x2, y2);
			rects.push_back(Rect(ll, ru));
		}
		else if (type == 'C') {
			int x, y, r;
			inFile >> x >> y >> r;
			Point center(x, y);
			circles.push_back(Circle(center, r));
		}
	}

	// 추가된 원의 정보
	int cx, cy, cr;
	inFile >> cx >> cy >> cr;

	Point addCenter(cx, cy);
	Circle addCircle(addCenter, cr);

	inFile.close();

	vector<Shapes> intersectShapes;

	for (const auto& rect : rects) {
		if (rect.intersect(addCenter, cr)) // 사각형과 추가된 원이 겹치는지
			intersectShapes.push_back(Shapes(rect.area(), "R", to_string(rect.getLeftLower().x) + " " + to_string(rect.getRightUpper().x) + " " + to_string(rect.getLeftLower().y) + " " + to_string(rect.getRightUpper().y)));
	}

	for (const auto& circle : circles) {
		if (circle.intersect(addCenter, cr)) // 원과 추가된 원이 겹치는지
			intersectShapes.push_back(Shapes(circle.area(), "C", to_string(circle.getCenter().x) + " " + to_string(circle.getCenter().y) + " " + to_string(circle.getRadius())));
	}

	sort(intersectShapes.begin(), intersectShapes.end(), compare);

	for (const auto& s : intersectShapes) {
		cout << s.type << " " << s.info << endl;
	}

	return 0;
}