#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, target;
    cin >> n >> target;
    vector<pair<int, int>> items;
	// append the element and its index
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		items.push_back({temp, i + 1});
	}

    sort(items.begin() , items.end());

//    int index1 = -1, index2 = -1;
//    for(int i = 0; i < n; i++){
//        for(int j = 0; j < n; j++){
//            if(i == j){continue;}
//            if(items[i] + items[j] == target){
//                index1 = j+1; index2 = i+1;
//                break;
//            }
//        }
//    }



    int left = 0;
	int right = n - 1;

	while (left < right){
        if(items[left].first + items[right].first > target){
            right --;
        }
        else if(items[left].first + items[right].first < target){
            left ++;
        }
        else if(items[left].first + items[right].first == target){
            cout << items[left].second << " " << items[right].second << "\n";
            return 0;
        }
	}

    cout << "IMPOSSIBLE\n";


    return 0;
}
