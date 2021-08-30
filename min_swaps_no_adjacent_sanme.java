// Problem Statement:
// There is a tournament in which different teams are participating,Each Team member has been given a TShirt with Team Name on it,For eg: All the players of team "A" will be having TShirts printed with "A",

// Initially you have been given a sequence of team members,All the team members want to reorder themselves in order to form Good sequence,

// There are two types of Sequences:
// 1) Bad Sequence: If a team member is adjacent to same team members.
// eg:  BAA, AAB ,AAA (These all are Bad Sequences)
// 2) Good Sequence: If a team member is not adjacent to same teams members.
// eg: BAB , ABA (These are Good Sequences)
// You have to find the minimum numbers of swaps (between any team members) required to form the Good sequence.Return -1 ,If Good sequence can't be formed.




import java.io.*;
import java.lang.*;
import java.util.*;

class MinimumSwap{
	public static void main(String []arg) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		MinimumSwap ms = new MinimumSwap();
		System.out.println(ms.printMinimumSwaps("ABAACD"));
		System.out.println(ms.printMinimumSwaps("AABA"));
		System.out.println(ms.printMinimumSwaps("AABBCDEEFG"));
		System.out.println(ms.printMinimumSwaps("ABBACDAA"));
		System.out.println(ms.printMinimumSwaps("AABBBA"));
		System.out.println(ms.printMinimumSwaps("AACBAD"));
		System.out.println(ms.printMinimumSwaps("AABBB"));
	}

	public int printMinimumSwaps(String s){
		int n = s.length();
		Map<String, Integer> []dp = new HashMap[n];
		for(int i=0;i<n;i++){
			dp[i] = new HashMap();
		}
		int ans = rec(s, 0, dp);
		return ans > n ? -1 : ans;
	}

	private int rec(String s, int ind, Map<String, Integer> []dp){
		if(ind == s.length() || check(s, ind)){
			return 0;
		}
		if(dp[ind].containsKey(s.substring(ind))){
			return dp[ind].get(s.substring(ind));
		}
		int min = s.length()+1;
		if(ind == 0 || s.charAt(ind-1) != s.charAt(ind)){
			min = Math.min(min, rec(s, ind+1, dp));
		}
		for(int i=ind+1; i < s.length(); i++){
			if(ind == 0 || s.charAt(ind-1) != s.charAt(i)){
				s = swap(s, ind, i);
				min = Math.min(min, 1 + rec(s, ind+1, dp));
				s = swap(s, ind, i);
			}
		}
		dp[ind].put(s.substring(ind), min);
		return min;
	}

	private String swap(String s, int i, int j){
		char []c = s.toCharArray();
		char tmp = c[i];
		c[i] = c[j];
		c[j] = tmp;
		return new String(c);
	}

	private boolean check(String s, int ind){
		for(int i=Math.max(1, ind-1); i < s.length(); i++){
			if(s.charAt(i) == s.charAt(i-1)){
				return false;
			}
		}
		return true;
	}
}
