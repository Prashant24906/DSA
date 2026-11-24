class Solution {
public:

void merge(vector<int> &arr, long long low, long long mid, long long high) {
    vector<int> temp; // temporary array
    long long left = low;      // starting index of left half of arr
    long long right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if ((long long)arr[left] <= (long long)arr[right]) {
            temp.push_back((long long)arr[left]);
            left++;
        }
        else {
            temp.push_back((long long)arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back((long long)arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back((long long)arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (long long i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

long long countPairs(vector<int> &arr, long long low, long long mid, long long high) {
    long long right = mid + 1;
    long long cnt = 0;
    for (int i = low; i <= mid; i++) {
        while (right <= high && (long long)arr[i] > 2* (long long)arr[right]) right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}

long long mergeSort(vector<int> &arr, long long low, long long high) {
    int cnt = 0;
    if (low >= high) return cnt;
    long long mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);  // left half
    cnt += mergeSort(arr, mid + 1, high); // right half
    cnt += countPairs(arr, low, mid, high); //Modification
    merge(arr, low, mid, high);  // merging sorted halves
    return cnt;
}

int team(vector <int> & skill, int n)
{
    return mergeSort(skill, 0, n - 1);
}


    int reversePairs(vector<int>& nums) {
        return team(nums, nums.size());
    }
};
