#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int binary_search(vector<int>& nums, int val) {
	int start = 0, end = (int)nums.size() - 1;	// (int)

	while (start <= end) {
		int mid = start + (end - start) / 2;

		if (nums[mid] == val)
			return mid;
		if (nums[mid] < val)
			start = mid + 1;
		else if (nums[mid] > val)
			end = mid - 1;
	}
	return -1;
}
//------------------------------------------------------------------------
int BSfindFirst(vector<int>& nums, int val) {
	int start = 0, end = (int)nums.size() - 1, position = -1;

	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (nums[mid] < val)
			start = mid + 1;
		else if (nums[mid] > val)
			end = mid - 1;
		else
			end = mid - 1, position = mid;	// Find smaller in left
	}
	return position;
}

int BSfindLast(vector<int>& nums, int val) {
	int start = 0, end = (int)nums.size() - 1, position = -1;

	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (nums[mid] < val)
			start = mid + 1;
		else if (nums[mid] > val)
			end = mid - 1;
		else
			position = mid, start = mid + 1;	// Find higher in right
	}
	return position;
}

vector<int> searchRange_(vector<int>& nums, int target) {
	return { BSfindFirst(nums, target), BSfindLast(nums, target), };
}
//------------------------------------------------------------------------
vector<int> searchRange(vector<int>& nums, int target) {

	vector<int>res(2, -1);

	auto p = equal_range(nums.begin(), nums.end(), target);

	if (p.first == p.second)
		return res;

	res[0] = p.first - nums.begin();
	res[1] = p.second - nums.begin() - 1;

	return res;

}


int BSfindRightBoundary(vector<pair<int, int>>& nums, int val) {
	int start = 0, end = (int)nums.size() - 1, position = -1;

	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (nums[mid].first < val)
			start = mid + 1;

		else
			end = mid - 1, position = nums[mid].second;	
	}
	return position;
}

vector<int> findRightInterval(vector<vector<int>>& intervals) {
	int size = intervals.size();
	int c = 0;
	vector<pair<int,int>>lefts(size);
	vector<int>outputs(size);

	for (int i = 0; i < size; i++)
	{
		lefts[i].first = intervals[i][0];
		lefts[i].second = i;
	}
	sort(lefts.begin(), lefts.end());


	while (c!=size)
	{
		outputs[c] = BSfindRightBoundary(lefts, intervals[c][1]);
			c++;
	}

	return outputs;
}
//------------------------------------------------------------------------
// lower bound, but use the given start
int BSfindFirst(vector<int>& nums, int start, int val) {
	int end = (int)nums.size() - 1;
	int position = nums.size();

	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (nums[mid] < val)
			start = mid + 1;
		else
			end = mid - 1, position = mid;	// Find smaller in left
	}
	return position;
}

int triangleNumber(vector<int>& nums) {	// O(n^2 logn)
	int count = 0, n = nums.size();
	sort(nums.begin(), nums.end());
	// As values are sorted, given a, b, c: we only check a+b > c

	for (int i = 0; i < n - 2; i++) {
		int k = i + 2;	// start after j
		for (int j = i + 1; j < n - 1 && nums[i] != 0; j++) {
			int first_idx = BSfindFirst(nums, k, nums[i] + nums[j]);
			// All values starting from first_idx are invalid
			// The values between j and first_idx-1 are the possible ones
			count += first_idx - j - 1;
		}
	}
	return count;
}

//------------------------------------------------------------------------
bool possible(int coins, long long rows)
{
	long long sum = (rows * (rows + 1)) / 2;
	return coins >= sum;
}

int arrangeCoins(int n) {
	int left = 0, right = n, answer = 0;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (possible(n, mid))
			answer = mid, left = mid + 1;
		else
			right = mid - 1;
	}
	return answer;
}
//------------------------------------------------------------------------
bool possible(vector<int> nums, int threshold, int divisor)
{
	int sum = 0;
	for (int i = 0; i < nums.size(); i++)
		sum += (nums[i] + divisor - 1) / divisor;
	return sum <= threshold;
}


int smallestDivisor(vector<int>& nums, int threshold) {
	int left = 1, right = *max_element(nums.begin(),nums.end()), ans = 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (possible(nums, threshold, mid))
			ans = mid, right = mid - 1;
		else
			left = mid + 1;
	}
	return ans;
}
//------------------------------------------------------------------------
int possible(vector<int>& bloomDay, int k, int day, int m)
{
	int adj_flowers = 0, bouquets = 0;
	for (int i = 0; i < (int)bloomDay.size(); ++i) {
		if (bloomDay[i] <= day) {
			++adj_flowers;

			if (adj_flowers >= k)
				adj_flowers = 0, ++bouquets;	// Start counting for a new bouquet

			if (bouquets == m)	// more efficient to stop early
				return true;
		}
		else
			adj_flowers = 0;
	}
	return false;
}

int minDays(vector<int>& bloomDay, int m, int k) {
	int left = 1, right = *max_element(bloomDay.begin(), bloomDay.end()), ans = -1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (possible(bloomDay, k, mid, m))
			ans = mid, right = mid - 1;
		else
			left = mid + 1;
	}
	return ans;
}
//------------------------------------------------------------------------
bool possible(vector<int>& houses, vector<int> heaters, int ridus) {
	int j = 0;
	for (int i = 0; i < (int)heaters.size(); ++i) {

		int leftC = heaters[i] - ridus, rightC = heaters[i] + ridus;

		while (j < (int)houses.size() && leftC <= houses[j] && houses[j] <= rightC)
			++j;
	}
	return j == (int)houses.size();
}
int findRadius(vector<int>& houses, vector<int>& heaters) {
	sort(houses.begin(), houses.end());
	sort(heaters.begin(), heaters.end());

	int start = 0, end = 1e9, radius = -1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (possible(houses, heaters, mid))	// find smallest
			end = mid - 1, radius = mid;
		else
			start = mid + 1;
	}
	return radius;
}

//------------------------------------------------------------------------

int missing(int idx, vector<int>& nums)
{
	return nums[idx] - nums[0] - idx;
}

int kth(int idx, vector<int>& nums,int k)
{
	return nums[idx]+k - missing(idx, nums);
}


int missingElement(vector<int>& nums, int k) {

	int n = nums.size();

	if (k > missing(n - 1, nums))
		return kth(n - 1, nums, k);

	int left = 0, right = n - 1, lower_bound = -1;

	while (left<=right)
	{
		int mid = left + (right - left) / 2;
		if (k > missing(mid, nums))
			left = mid + 1;
		else
			lower_bound = mid, right = mid - 1;
	}
	return kth(lower_bound - 1, nums, k);
}
//------------------------------------------------------------------------
int count(int rows, int cols, int value)
{
	int count = 0;

	for (int r = 1; r <= rows; r++)
		count += min(value / r, cols);

	return count;
}


int findKthNumber(int m, int n, int k) {
	int start = 1, end = n * m, kth = -1;
	while (start <= end)
	{
		int mid = start + (end - start) / 2;
		if (count(m, n, mid) < k)
			start = mid + 1;
		else
			kth = mid, end = mid - 1;
	}
	return kth;
}

//------------------------------------------------------------------------
// Find value of X such that f(X) = 0
// It is guaranteed there is a solution for X in range [0, 3]

double f(double x) {
	return 4 * pow(x, 7) + 3 * pow(x, 5) - 1000;
}
double binary_search(double EPS = 1e-9) {
	double start = 0, end = 3;

	while (end - start > EPS) {
		double mid = start + (end - start) / 2;
		if (f(mid) < 0.0)
			start = mid;
		else
			end = mid;
	}
	return start;
}

double sqrt(double val)
{
	return val * val;
}

int mySqrt(int x) {
	double start = 0, end = pow(2, 31) - 1;
	while (end - start > 1e-9)
	{
		double mid = start + (end - start) / 2;
		if (sqrt(mid) < x)
			start = mid;

		else
			end = mid;

	}

	return end;
}
//------------------------------------------------------------------------
double circle_area(double r) {
	const double PI = acos(-1.0);
	return PI * r * r;
}

int total_can_eat(vector<double>& area, double x) {
	int can_eat = 0;
	for (int i = 0; i < (int)area.size(); i++)
		can_eat += (int)(area[i] / x);
	return can_eat;
}

double largest_area(vector<double>& pie_radius, int people) {
	double start = 0, end = 0;
	vector<double> area(pie_radius.size());

	for (int i = 0; i < (int)pie_radius.size(); i++) {
		area[i] = circle_area(pie_radius[i]);
		end = max(end, area[i]);
	}

	//while(fabs(start-end) < 1e-9)	{	// Wrong answers
	for (int i = 0; i < 100; i++) {
		double mid = (start + end) / 2;
		if (total_can_eat(area, mid) >= people)
			start = mid;
		else
			end = mid;
	}
	return start;
}
//------------------------------------------------------------------------

int main() {


	cout << round(2.82842);

	return 0;
}

