#include <vector>
#include <iostream>
using namespace std;

// note to take erase takes o(N) time
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
	
	int n = arr.size();
	int m = arr[0].size();

    int i = 0; 

	while (i<arr.size()-1) {

        int l1 = arr[i][0];
        int r1 = arr[i][1];
        int l2 = arr[i+1][0];
        int r2 = arr[i+1][1];

        if (l2 <= r1) {
			if(r1<r2)
            arr[i][1] = arr[i+1][1];
			else
			arr[i+1][1] = arr[i][1];
            arr.erase(arr.begin() + i + 1); // erase takes of o(n) so causing o(n^2) allover
            continue;
        }

        i++;
	}

    return arr;
}