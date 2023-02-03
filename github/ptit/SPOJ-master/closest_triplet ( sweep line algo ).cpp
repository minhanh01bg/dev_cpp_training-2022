#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
template<class T> inline int size(const T&c) { return c.size();}

long long maxi = 1000000000;
double INF = 1e20;

struct Point {
  double x,y;
  Point() {}
  Point(double x,double y):x(x),y(y) {}
};

inline Point middle(const Point &a, const Point &b) {
  return Point((a.x+b.x)/2, (a.y+b.y)/2);
}

struct compareX {
  inline bool operator()(const Point &a, const Point &b) {
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
  }
} compareX;

struct compareY {
  inline bool operator()(const Point &a, const Point &b) {
    if(a.y != b.y) return a.y < b.y;
    return a.x < b.x;
  }
} compareY;

double sqr(double x) { return x * x; }

double dist(const Point &a, const Point &b) {
  return sqrt(double(sqr(a.x-b.x) + sqr(a.y-b.y)));
}

double perimeter(const Point &a,
                        const Point &b,
                        const Point &c) {
  return dist(a,b) + dist(b,c) + dist(c,a);
}

double process_points(int n, const Point points[],const vector<Point> &pointsByY) {
  if(n<3) return INF;
  int left = n/2;
  int right = n-left;
  Point split = middle(points[left-1], points[left]);
  vector<Point> YseepLeft, YseepLeftRight;
  YseepLeft.reserve(left);
  YseepLeftRight.reserve(right);
  for(int i=0;i<n;i++) {
    if(compareX(pointsByY[i], split))
      YseepLeft.push_back(pointsByY[i]);
    else
      YseepLeftRight.push_back(pointsByY[i]);
  }
  double res = INF;
  res = min(res, process_points(left, points, YseepLeft));
  res = min(res, process_points(right, points+left, YseepLeftRight));
  static vector<Point> SweepClosest;
  int margin = (res > INF/2) ? 2*maxi : int(res/2);
  SweepClosest.clear();
  SweepClosest.reserve(n);
  int start = 0;
  for(int i=0;i<n;++i) {
    Point p = pointsByY[i];
    if(abs(p.x - split.x) > margin) continue;
    while(start < size(SweepClosest) && p.y - SweepClosest[start].y > margin)
    ++start;
    for(int i=start;i<size(SweepClosest);++i) {
      for(int j=i+1;j<size(SweepClosest);++j) {
        res = min(res, perimeter(p, SweepClosest[i],
                                 SweepClosest[j]));
      }
    }
    SweepClosest.push_back(p);
  }
  return res;
}

double process_points(vector<Point> &points) {
  sort(points.begin(), points.end(), compareX);
  vector<Point> pointsByY = points;
  sort(pointsByY.begin(), pointsByY.end(), compareY);
  return process_points(size(points), &points[0], pointsByY);
}

int main() {
  int t,i,j;
  double x,y,result;
  for(i=0; ;++i) {
    int n;
    scanf("%d", &n);
    if(n==-1)
    break;
    vector<Point> points;
    points.reserve(n);
    for(j=0;j<n;++j) {
      scanf("%lf %lf", &x, &y);
      points.push_back(Point(2*x-maxi,2*y-maxi));
    }
    result = process_points(points);
    printf("%.3lf\n",result/2.0);
  }
}
