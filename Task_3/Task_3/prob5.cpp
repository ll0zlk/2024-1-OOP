#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
	int x, y;
};

struct Segment {
	Point start, end;
};

void drawLine(vector<vector<int>>& grid, const vector<Segment>& segments) {
	for (const auto& segment : segments) {
		if (segment.start.y == segment.end.y) {		// 수평 선분
			for (int x = segment.start.x; x <= segment.end.x; x++) {
				if (grid[segment.start.y][x] >= 1) {
					grid[segment.start.y][x] = 2;	// 교차점으로 표시
					continue;
				}
				grid[segment.start.y][x] = 1;	// 선분 그리기
			}
		}
		else {	// 수직 선분
			for (int y = segment.start.y; y <= segment.end.y; y++) {
				if (grid[y][segment.start.x] >= 1) {
					grid[y][segment.start.x] = 2;	// 교차점으로 표시
					continue;
				}
				grid[y][segment.start.x] = 1;	// 선분 그리기
			}
		}
	}
}

void intersect(vector<vector<int>>& grid, vector<Point>& intersections) {
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			if (grid[i][j] == 2) {
				intersections.push_back({ j, i });
			}
		}
	}
}

bool compare(const Point& p1, const Point& p2) {
	if (p1.x == p2.x) {
		return p1.y < p2.y;
	}
	return p1.x < p2.x;
}

int main() {
	int n;
	cin >> n;

	vector<Segment> segments(n);
	int max_x = 0, max_y = 0;
	for (int i = 0; i < n; i++) {
		cin >> segments[i].start.x >> segments[i].start.y >> segments[i].end.x >> segments[i].end.y;
		max_x = max(max_x, max(segments[i].start.x, segments[i].end.x));
		max_y = max(max_y, max(segments[i].start.y, segments[i].end.y));
	}

	vector<vector<int>> grid(max_y + 1, vector<int>(max_x + 1, 0));	// 그리드 만들기
	vector<Point> intersections;

	drawLine(grid, segments);
	intersect(grid, intersections);

	sort(intersections.begin(), intersections.end(), compare);

	for (const auto point : intersections) {
		cout << "[" << point.x << ", " << point.y << "]" << endl;
	}

	return 0;
}