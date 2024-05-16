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
	Rect(Point a, Point b) : ll(a), ru(b) {} // ������

	Point getLeftLower() const {
		return ll;
	}

	Point getRightUpper() const {
		return ru;
	}

	int area() const { // �簢�� ����
		int width = abs(ru.x - ll.x);
		int height = abs(ru.y - ll.y);
		return width * height;
	}

	bool intersect(Point center, int radius) const { // �߰��� ���� ���� ����
		// �簢�� �߽ɰ� �� �߽� ���� �Ÿ�
		int distX = abs((ll.x + ru.x) / 2 - center.x);
		int distY = abs((ll.y + ru.y) / 2 - center.y);

		// 1. �簢�� �ʺ�/���� ���� + ������ ���� �� �߽� ���� �Ÿ����� ũ�� ��ħ
		if (distX <= (ru.x - ll.x) / 2 + radius && distY <= (ru.y - ll.y) / 2 + radius)
			return true;
		// 2. ���� �߽��� �簢�� �ȿ� ������ ��ħ
		if ((center.x - ll.x) * (center.x - ru.x) <= 0 && (center.y - ll.y) * (center.y - ru.y) <= 0)
			return true;
		// 3. �� �������� �� �߽� ������ �Ÿ��� ���������� �۰ų� ������ ��ħ
		if ((center.x - ll.x) * (center.x - ll.x) + (center.y - ll.y) * (center.y - ll.y) <= radius * radius)
			return true; // ���� �Ʒ� ��
		if ((center.x - ru.x) * (center.x - ru.x) + (center.y - ll.y) * (center.y - ll.y) <= radius * radius)
			return true; // ������ �Ʒ� ��
		if ((center.x - ll.x) * (center.x - ll.x) + (center.y - ru.y) * (center.y - ru.y) <= radius * radius)
			return true; // ���� �� ��
		if ((center.x - ru.x) * (center.x - ru.x) + (center.y - ru.y) * (center.y - ru.y) <= radius * radius)
			return true; // ������ �� ��

		// �ƴϸ� �� ��ħ
		return false;
	}
};

class Circle {
private:
	Point center;
	int radius;
public:
	Circle(Point c, int r) : center(c), radius(r) {} // ������

	Point getCenter() const {
		return center;
	}

	int getRadius() const {
		return radius;
	}

	double area() const { // �� ����
		return 3.141592 * radius * radius;
	}

	bool intersect(Point otherC, int otherR) const { // �߰��� ���� ���� ����
		// �� �� �߽� ���� �Ÿ� (���� ����)
		int distX = center.x - otherC.x;
		int distY = center.y - otherC.y;
		int distSq = distX * distX + distY * distY;
		// �� �� ������ �� (���� ����)
		int radiusSq = (otherR + radius) * (otherR + radius);

		// �� �� �߽� ���� �Ÿ��� �� �� ������ �պ��� �۰ų� ������ ��ħ
		return (distSq <= radiusSq);
	}
};

// ���̸� �������� ���� �� ������ ����ϱ� ���� Ŭ���� ����
class Shapes {
public:
	double area;
	string type;
	string info;
	Shapes(double a, string t, string i) : area(a), type(t), info(i) {}
};

// sort �Լ��� ���� ���� ���� �� �Լ�
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

	// �߰��� ���� ����
	int cx, cy, cr;
	inFile >> cx >> cy >> cr;

	Point addCenter(cx, cy);
	Circle addCircle(addCenter, cr);

	inFile.close();

	vector<Shapes> intersectShapes;

	for (const auto& rect : rects) {
		if (rect.intersect(addCenter, cr)) // �簢���� �߰��� ���� ��ġ����
			intersectShapes.push_back(Shapes(rect.area(), "R", to_string(rect.getLeftLower().x) + " " + to_string(rect.getRightUpper().x) + " " + to_string(rect.getLeftLower().y) + " " + to_string(rect.getRightUpper().y)));
	}

	for (const auto& circle : circles) {
		if (circle.intersect(addCenter, cr)) // ���� �߰��� ���� ��ġ����
			intersectShapes.push_back(Shapes(circle.area(), "C", to_string(circle.getCenter().x) + " " + to_string(circle.getCenter().y) + " " + to_string(circle.getRadius())));
	}

	sort(intersectShapes.begin(), intersectShapes.end(), compare);

	for (const auto& s : intersectShapes) {
		cout << s.type << " " << s.info << endl;
	}

	return 0;
}