#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	for(int N; cin >> N; ) {
	    pair<int, int> square[N];
	    for(int i = 0; i < N; i++) {
	        int x, y;
	        cin >> x >> y;
	        square[i] = {x, y};
	    }
    	int result = 0;
    	sort(square, square + N);
    	for(int i = 0; i < N; i++) {
    	    for(int j = i + 1; j < N; j++) {
    	        auto x = square[i].first - square[j].first, y = square[i].second - square[j].second;
    	        pair<int, int> p = {square[i].first + y, square[i].second - x}, q = {square[j].first + y, square[j].second - x};
    	        if(binary_search(square, square + N, p) && binary_search(square, square + N, q)) {
    	            result++;
    	        }
    	    }
    	}
    	cout << result / 2 << endl;
	}
	return 0;
}
