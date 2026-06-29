/*

Given an integer array, check if it represents min-heap or not.

Input : [2, 3, 4, 5, 10, 15]
Output: true
Explanation: The input represents a min-heap.

		   2
		 /   \
		/	  \
	   3	   4
	  / \	  /
	 /   \   /
	5	 10 15

Input : [2, 10, 4, 5, 3, 15]
Output: false
Explanation: The input is not a min-heap, as it violate the heap property.

		   2
		 /   \
		/	  \
	   10	   4
	  / \	  /
	 /   \   /
	5	  3 15

*/

class Solution
{
public:
	bool checkMinHeap(vector<int> const &nums)
	{
		int n = nums.size();
		for(int i = 0;i<n;i++){
			int leftchild = (i)*2 + 1;
			int rightchild = (i)*2 + 2;
			if(leftchild<n){
				if(nums[leftchild]<nums[i]) return false;
			}
			if(rightchild<n){
				if(nums[rightchild]<nums[i]) return false;
			}
		}
		return true;
	}
};
