#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

void insertion_sort(vector<int>& nums) {
	// For each number: add it in the previous sorted subarray
	for (int i = 1; i < (int)nums.size(); i++) {
		int key = nums[i];
		int j = i - 1;
		// Shift and add in the right location
		while (j >= 0 && nums[j] > key) {
			nums[j + 1] = nums[j];	// shift right
			j--;
		}
		nums[j + 1] = key;	// The first right element
	}
}

void insertion_sort_v2(vector<int>& nums) {
	for (int i = 1; i < nums.size(); i++)
		for (int j = i - 1; j >= 0 && nums[j] < nums[j + 1]; j--)
			swap(nums[j], nums[j + 1]);
}

void selection_sort(vector<int>& v)
{
	
	for (int i = 0; i < v.size() - 1; i++)
	{
		int mn_pos = i;
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[j] < v[mn_pos])
				mn_pos = j;
		}
		swap(v[i], v[mn_pos]);
	}
}


vector<int> count_sort(vector<int>& v)
{
	int mx_val = v[0];
	for (int i = 1; i < v.size(); i++)
		if (v[i] > mx_val)
			mx_val = v[i];

	vector<int>count(mx_val + 1);

	for (int i = 0; i < v.size(); i++)
		count[v[i]]++;

	int idx = 0;
		for (int j = 0; j <= mx_val; j++)
		{
			while (count[j]--)
			{
				v[idx] = j;
				idx++;
			}
		}
	
	return v;

}

vector<int> count_sort_for_negatives(vector<int>& nums)//leetcode problem..https://leetcode.com/problems/sort-an-array/
{
	vector<int>countPos(500001);
	vector<int>countNeg(500001);

	for (int i = 0; i < nums.size(); i++)
	{
		
		if (nums[i] >= 0)
			countPos[nums[i]]++;
		else
			countNeg[nums[i] * -1]++;
	}
	
	int idx = 0;
	for (int j = 50000; j >=0; j--)
	{
		
		while (countNeg[j]--)
		{
			nums[idx] = -1*j;
			idx++;
		}
	}

	for (int j = 0; j <= 50000; j++)
	{


		while (countPos[j]--)
		{
			nums[idx] = j;
			idx++;
		}
	}

	

	return nums;
}

vector<long long> count_sort_for_a_range(vector<long long>& nums)
{
	long long mx_val = nums[0],mn_val=nums[0];
	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] > mx_val)
			mx_val = nums[i];

		if (nums[i] < mn_val)
			mn_val = nums[i];
	}

	long long shift = mx_val - mn_val;
	

	vector<long long>countPos(mx_val + 1);
	vector<long long>countNeg(mx_val + 1);
	
	
	for (int i = 0; i < nums.size(); i++)
	{

		if (nums[i]-mn_val >= 0)
			countPos[nums[i]-mn_val]++;
		else
			countNeg[nums[i]-mn_val * -1]++;
	}

	int idx = 0;
	for (long long j = shift; j >= 0; j--)
	{
		
		while (countNeg[j]--)
		{
			
			nums[idx] = ( - 1 * j) + mn_val;
			idx++;
			
		}
		
	}

	for (int j = 0; j <= shift; j++)
	{


		while (countPos[j]--)
		{
			
			nums[idx] = j+mn_val;
			idx++;
		}
	}



	return nums;
}

vector<string>count_sort_for_string_v1(vector<string>& array)
{
	vector<vector<string>>count(26);

	for (int i = 0; i < array.size(); i++)
	{
		count[array[i][0] - 'a'].push_back(array[i]);
	}

	
	int idx = 0;
	for (int i = 0; i <26; i++)
	{
		for (int j = 0; j < count[i].size(); j++,idx++)
		{
			array[idx] = count[i][j];
		}
	}

	return array;

}

vector<vector<int>> minimumAbsDifference(vector<int>& arr) {

	vector<vector<int>>res;
	sort(arr.begin(), arr.end());
	int min_diff = INT_MAX;
	for (int i = 1; i < arr.size(); i++)
	{
		if (arr[i] - arr[i - 1] < min_diff)
		{
			min_diff = arr[i] - arr[i - 1];
			res.clear();
			res.push_back({arr[i - 1], arr[i]});
		}
		else if (arr[i] - arr[i - 1] == min_diff) {
			res.push_back({ arr[i - 1], arr[i] });
		}
	}

	return res;
}

int largestPerimeter(vector<int>& nums) {

	sort(nums.begin(), nums.end());
	for (int i = nums.size() - 1; i >= 2; i--)
	{
		if (nums[i] < nums[i - 1] + nums[i - 2])
			return nums[i] + nums[i - 1] + nums[i - 2];

	}
	return 0;
}

int arrayPairSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int res = 0;
	for (int i = 0; i < nums.size(); i += 2)
		res += nums[i];

	return res;
}

void wiggleSort1(vector<int>& nums) {
	sort(nums.begin(), nums.end());

	for (int i = 1; i + 1 < (int)nums.size(); i += 2)
		swap(nums[i], nums[i + 1]);
}


// O(nlogn) time and O(n) space
void wiggleSort2(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	vector<int> ans;	// O(n) extra memory

	int left = 0, right = nums.size() - 1;
	while (left <= right) {
		ans.push_back(nums[left]);
		if (left != right)	// don't add same position twice
			ans.push_back(nums[right]);
		left += 1;
		right -= 1;
	}
	nums = ans;
}


int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
	vector<int>times(dist.size());
	int counter = 0;

	for (int i = 0; i < dist.size(); i++)
	{
		if (dist[i] % speed[i] == 0)
			times[i] = dist[i] / speed[i];

		else
			times[i] = (dist[i] / speed[i]) + 1;

	}

	sort(times.begin(), times.end());

	for (int i = 0; i < times.size(); i++)
	{
		if (times[i] <= i)
			return counter;

		else
			counter++;
	}
}

int largestSumAfterKNegations(vector<int>& nums, int k) {
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size() && nums[i] < 0 && k; i++, k--)
	{
		nums[i] *= -1;
	}

	sort(nums.begin(), nums.end());

	if (k && k % 2 != 0)
		nums[0] *= -1;

	int res = 0;
	for (int i = 0; i < nums.size(); i++)
		res += nums[i];

	return res;
}

int findUnsortedSubarray(vector<int>& nums) {
	vector<int>v = nums;

	sort(nums.begin(), nums.end());
	bool touched = 0;
	int minpos = 0, maxpos = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] != v[i])
		{
			if (!touched)
			{
				touched = 1;
				minpos = i;
			}
			else
			{
				maxpos = i;
			}
		}
	}

	if (touched)
		return (maxpos - minpos) + 1;
	else
		return 0;

}

int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
	vector<pair<int, int>>jobs;

	for (int i = 0; i < difficulty.size(); i++)
		jobs.push_back(make_pair(difficulty[i], profit[i]));

	sort(worker.begin(), worker.end());
	sort(jobs.begin(), jobs.end());

	int job = 0, totalmxprofit = 0, mxprofitsofar = 0;
	for (int i = 0; i < worker.size(); i++)
	{
		for (; job < jobs.size() && worker[i] >= jobs[job].first; job++)
		{
			mxprofitsofar = max(mxprofitsofar, jobs[job].second);
		}
		totalmxprofit += mxprofitsofar;
	}

	return totalmxprofit;

}

int reductionOperations(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int res=0, total = 0, prev = 0, minimum = nums[0];
	for (int i = nums.size() - 1; i > 0 && nums[i] > minimum; i--)
	{
		
		int curfreq = 1;
		while (nums[i] == nums[i - 1])
		{
			curfreq++;
			i--;
		}
		total =curfreq + prev;
		prev = total;
		res += total;
		
	}
	
	return res;
}

vector<int> read_vector() {
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	return v;
}




int main() {

	vector<int > v = read_vector();
	reductionOperations(v);

	for (int i = 0; i < (int)v.size(); ++i) {
		cout <<endl<< v[i] << " ";
	}

	



	return 0;
}