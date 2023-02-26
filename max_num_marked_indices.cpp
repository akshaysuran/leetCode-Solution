#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxNumOfMarkedIndices(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        unordered_map<int, bool> isMatched;
        int i = n - 1;
        int j = n / 2 - 1;
        while (i >= 0 && j >= 0)
        {
            if (isMatched[i])
            {
                i--;
                continue;
            }
            if (isMatched[j])
            {
                j--;
                continue;
            }
            if (nums[i] >= 2 * nums[j])
            {
                res += 2;
                isMatched[i] = true;
                isMatched[j] = true;
                i--;
                j--;
                continue;
            }
            j--;
        }
        return res;
    }
};

int main()
{
    int n = 0;
    int cp = 0;
    cin >> n;
    vector<int> num(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> cp;
        num[i] = cp;
    }
    Solution solution = Solution();
    cout << solution.maxNumOfMarkedIndices(num) << endl;
    return 0;
}