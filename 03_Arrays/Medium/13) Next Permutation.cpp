class Solution {
public:
    void nextPermutation(vector<int>& arr) {
	int n = arr.size();
	int last = -1;
	for(int i = n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            last = i;
            break;
        }
    }
    if(last == -1){
        reverse(arr.begin(),arr.end());
        return ;
    }
    else{

	for(int i = n-1;i>last;i--){
	    if(arr[i]>arr[last]){
	        swap(arr[i],arr[last]);
            break;
	    }
	}
	reverse(arr.begin()+last+1,arr.end());
    }
    }
};
