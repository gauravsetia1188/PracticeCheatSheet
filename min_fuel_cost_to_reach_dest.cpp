// A car, with a tank of volume K liters, and a constant fuel consumption of 1 liter per kilometer, starts driving in a straight line from the origin towards a destination D kilometer away.
// Along the road, there are N fuel stations, each at a distance di away from the origin. The cost of fuel at each fuel station is pi per liter.
// Write a function to compute the cheapest cost of fuel to reach the destination. Assume that the car starts with a full tank.

Analysis: Fuel Economy by Fatih Gelgi

In this problem, we need to determine "in which stations to stop" and "how many units of fuel to buy". In fact, it can be considered as "how many units of fuel to buy in each station" since FJ can stop at a station and buy 0 unit. To make the decision, we need a few observations.

If FJ can reach a cheaper station at y than the current station at x, he should better go there with just sufficient amount of fuel -- which is y - x. If he already has that amount of fuel, he doesn't need to buy any.
If there is no such station or it is too far, FJ fills the tank (if it's not already full) since the current station is the cheapest one till position the x + G.
Consider the sample input in the problem:

0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17	=> distance
+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
     40        7          15 12	                   	=> fuel price
3     1        0           6  5		           0	=> remaining fuel
      2       10           0  2                    0   	=> how much to buy
     80      150         174 174                 174	=> total cost
At the first station, FJ only buys 2 units of fuel -- the sufficient amount to go to the next cheaper station. Then he fills the tank at station 2 since there is no cheaper station afterwards. He didn't buy any fuel at station 3 since station 4 is cheaper and FJ has enough fuel to reach there.

Straightforward implementation based on the idea above requires sorting of stations with respect to the distance -- that is O(N log N). Then we need to find the next cheaper station of each station. That requires O(N) time for each station in the worst case. O(N^2) time complexity is too slow for the problem. Fortunately, we can optimize "finding the cheaper station" part using stacks. Starting from the last station, stations are pushed into the stack. At a station x, we pop the stack until the price of the station on the top is less then the price of x. The next cheaper station from x will be that one. Notice that the LIFO property of stack gives the opportunity to find the first station that is cheaper than x. We can visualize the method on the sample input as follows:

Station	Next cheaper station	Stack
-------	--------------------	-----
   4		-		  4
   3		4		  4 3
   2		-                 2
   1            2                 2 1
The running time for the stack is O(N) as illustrated. That makes the total time O(N log N) for the problem. Below is Travis's code:

#define NMAX 50000

struct station {
	int pos, cost;
	bool operator<(station const& o) const {
		return pos < o.pos;
	}
};
station stations[NMAX];

int s[NMAX];
int nextSmall[NMAX];

int main() {
#ifndef HOME
	freopen("fuel.in","r",stdin);
	freopen("fuel.out","w",stdout);
#endif

	int n, maxGas, curGas, dist;
	scanf("%d %d %d %d", &n, &maxGas, &curGas, &dist);
	for (int i = 0; i < n; i++) {
		scanf("%d", &stations[i].pos);
		scanf("%d", &stations[i].cost);
	}
	sort(stations, stations + n);

	// find next cheaper station for each station
	int stacklen = 0;
	for (int i = n-1; i >= 0; i--) {
		while (stacklen > 0 && stations[s[stacklen-1]].cost >= stations[i].cost) {
			stacklen--;
		}
		nextSmall[i] = (stacklen == 0 ? -1 : s[stacklen-1]);
		s[stacklen] = i;
		stacklen++;
	}

	curGas -= stations[0].pos;	// move to station 1
	long long cost = 0;
	for (int i = 0; i < n; i++) {
		// gas is less than 0 means it is impossible to reach the station
		if (curGas < 0) {
			printf("-1\n");
			return 0;
		}
		int gasNeeded = min(maxGas, (nextSmall[i] == -1 ? dist :
stations[nextSmall[i]].pos) - stations[i].pos);
		if (gasNeeded > curGas) {
			cost += (long long) (gasNeeded - curGas) * (long long) stations[i].cost;
			curGas = gasNeeded;
		}
		curGas -= (i == n-1 ? dist : stations[i+1].pos) - stations[i].pos;
	}

	if (curGas < 0) {
		printf("-1\n");
	} else {
		printf("%lld\n", cost);
	}
}
