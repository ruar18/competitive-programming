// Detecting Molecules - https://dmoj.ca/problem/ioi16p1
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> sorted(200001);
long long PFS[200001];
int find_subset(int l, int u, int w[], int n, int result[])
{
  sorted.resize(n);
  for(int i = 0; i < n; i++)
  {
    // Keep track of original indices
    sorted[i] = make_pair(w[i], i);
  }
  sort(sorted.begin(), sorted.begin() + n);

  // Make a PFS
  PFS[0] = sorted[0].first;
  for(int i = 1; i < n; i++)
    PFS[i] = PFS[i-1] + sorted[i].first;

  // Pointers: set them to the first element (smallest)
  int left = 0, right = 0;
  long long sum = sorted[0].first;
  // also make sure we're not out of range
  bool solutionFound = false;
  while(right < n && left < n)
  {
    // If the sum is good, break
    if(sum >= l && sum <= u)
    {
      solutionFound = true;
      break;
    }
    // If the sum is too low, keep upping it
    else if(sum <= l || sum < u)
      right++;
    // If the sum is too high, "erase" the leftmost elements
    else if(sum >= u)
      left++;
    sum = PFS[right] - PFS[left] + sorted[left].first;
  }
  // If the solution was found:
  if(solutionFound)
  {
    for(int i = left; i <= right; i++)
    {
      result[i-left] = sorted[i].second;
    }
    return (right - left + 1);
  }
  return 0;
}
