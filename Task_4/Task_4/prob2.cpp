#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Point {
public:
	int x;
	int y;
	Point() = default;
	Point(int a, int b) : x(a), y(b) {}

	// �� �� ���� �Ÿ�
	double distSquared(Point otherP) {
		return (x - otherP.x) * (x - otherP.x) + (y - otherP.y) * (y - otherP.y);
	}
};

class Rect {
public:
	Point lu;
	Point rl;
	Rect() = default;
	Rect(Point a, Point b) : lu(a), rl(b) {}
};

// �ּ� �� ã�� �Լ�
void findMinCircle(vector<Rect>& rects, Point& center, double& radius) {
	// ��� �簢�� ������ ���� ����
	vector<Point> points;
	for (const auto& rect : rects) {
		points.push_back(rect.lu);
		points.push_back(rect.rl);
		points.push_back(Point(rect.lu.x, rect.rl.y));
		points.push_back(Point(rect.rl.x, rect.lu.y));
	}

	center = points[0];	// �ݺ� �ʱ� �߽� ����
	radius = 0;	// ������ �ʱ�ȭ
	for (int i = 0; i < points.size(); i++) {
		for (int j = i + 1; j < points.size(); j++) {
			Point newCenter((points[i].x + points[j].x) / 2, (points[i].y + points[j].y) / 2);
			double newRadius = points[i].distSquared(points[j]) / 2;

			bool isValid = true;
			for (const auto& p : points) {
				if (newCenter.distSquared(p) > newRadius) {	// �� �����ϴ� ���� �ƴϸ�
					isValid = false;
					break;
				}
			}
			if (isValid && newRadius > radius) {
				center = newCenter;
				radius = newRadius;
			}
		}
	}
}

int main() {
	ifstream infile("input2.txt");
	
	int N;
	infile >> N;

	vector<Rect> rects;
	for (int i = 0; i < N; i++) {
		int x1, x2, y1, y2;
		infile >> x1 >> x2 >> y1 >> y2;
		rects.push_back(Rect(Point(x1, y2), Point(x2, y1)));
	}

	Point center;
	double radius;
	findMinCircle(rects, center, radius);

	cout << center.x << " " << center.y << " " << radius << endl;

	return 0;
}