#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define pb push_back
#define eb emplace_back
#define cl(C) C.clear()
#define cint cpp_int
#define all(C) C.begin(), C.end()
#define Begin()   \
	int N;        \
	cin >> N;     \
	cin.ignore(); \
	while (N--)

using namespace std;

double pi = 3.14159265;

double getDensity(double R, double OC, double firstSegment)
{
	double centered1 = OC - R;
	double segment1 = OC * (centered1 / firstSegment);
	double base1 = 2 * R * (centered1 / firstSegment);
	double R2 = (base1 * centered1) / (segment1 * 2 + base1);
	double circle2 = R2 * R2 * pi;
	double area2 = centered1 * base1 / 2;

	// segment1 / OC = centered1 / firstSegment

	double centered2 = centered1 - 2 * R2;
	double segment2 = segment1 * (centered2 / centered1);
	double base2 = base1 * (centered2 / centered1);
	//	double R3 = (base2 * centered2 / 2) / (segment2 * 2 + base2);
	double area3 = centered2 * base2 / 2;

	double area2to3 = area2 - area3;

	double density = circle2 / area2to3;

	double density2 = density * area2;

	return density2;
}

int main()
{
	double a, b;
	cin >> a >> b;
	if (a > b)
		swap(a, b);
	double c = sqrt(a * a + b * b);
	double R = (a * b) / (a + b + c);

	double totalArea = (a * b) / 2;
	double firstCircle = R * R * pi;

	double OC = sqrt(R * R + (b - R) * (b - R));
	double firstSegment = b - R;

	double density = getDensity(R, OC, firstSegment);

	double total = (density + firstCircle) / totalArea;

	cout << setprecision(4) << fixed << total << endl;
}
