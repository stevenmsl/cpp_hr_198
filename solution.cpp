#include "solution.h"
#include "util.h"
#include <unordered_map>
#include <algorithm> //lower_bound
#include <string>
#include <queue>
#include <sstream>
#include <functional>
#include <math.h>

using namespace sol198;
using namespace std;

/*takeaways
  - DP
    - recursion and memorize what has been evaluated
  - time complexity : O(n)
*/
int Solution::rob(vector<int> &nums)
{
  int n = nums.size();
  if (n == 0)
    return 0;

  /* dp[i] max amount you can rob after considering house i
     - you might or might not rob the house i
       - if you don't rob it carries over dp[i-1]
       - if you rob it than it's dp[i-2] + nums[i]
       - you need to find which way will create a larger
         amount
  */
  auto dp = vector<int>(n);

  for (auto i = 0; i < n; i++)
    dp[i] = max(
        (i > 1 ? dp[i - 2] : 0) + nums[i],
        i > 0 ? dp[i - 1] : 0);

  return dp[n - 1];
}