class Solution {
		public:
			int numberOfSubstrings(string s) {
				
				int n = s.length();
				
				vector<int>count = {0, 0, 0};
				int i = 0, j = 0, res = 0, ans = 0;
				
				for (i = 0; i < n; i++) {
					count[s[i]-'a']++;     /* have some hashmap or counter */
					
					/* Loop inside for to reduce the window size based on constraint */
					while (j < n && count[0] && count[1] && count[2]) {
						ans++;
						count[s[j]-'a']--;
						j++;
					}
					
					/* Count number of substrings */
					res += ans;
				}
				
				return res;
			}
		};
