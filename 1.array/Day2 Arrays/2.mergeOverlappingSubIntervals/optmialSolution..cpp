#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
	
	int n = arr.size();
	int m = arr[0].size();

    vector<vector<int>> ans;


    for (int i = 0; i < n; i++) {

        if(ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        }
        else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }

    return ans;
}


