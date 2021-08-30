// Given below pattern of license plates (Pattern only, not the actual list of license plates), Find the nth license plate
// All license plates no are of size 5 chars
// Eg, if n is 3, ans is - 00002

// 00000
// 00001
// 00002
// ........
// ........
// 99999
// 0000A
// 0001A
// 0002A
// ........
// .........
// 9999A
// 0000B
// 0001B
// 0002B
// .........
// .........
// 9999B
// 0000C
// ........
// ........
// 9999Z
// 000AA
// 001AA
// .........
// .........
// 999AA
// 000AB
// ..........
// ..........
// 999ZZ
// 00AAA
// ........
// ........
// ZZZZZ




string findTargetStr(int n) {

   unordered_map<int, char> IntToletters; // key to 26 letters

   helper(IntToletters); 

   string ans = "00000";

   n = n - 1;

   int index = 4;

   int time;

   if (n <= 99999) {
       while(n) {
            int lastnum = n % 10;
            ans[index] = lastnum + '0';
            index--;
            n = n / 10;
       }
   } 
  else if (n > 99999 && n <= (26 * 10000 + 99999)) {
            int key = (n - 100000) / 10000;  // use to find out it should be 'A' or 'B' or 'C' ......
            int remain = (n - 100000) % 10000;
            char last = IntToletters[key];
            ans[index] = last;
            index--;
            while (remain) {
                   int lastnum = remain % 10;
                   ans[index] = lastnum + '0';
                   index--;
                   remain = remain / 10;
            }
   } 
   else if (n > (26 * 10000 + 99999) && n <= (99999 +  26 * 10000 + 26^2 * 1000)) {
            int key = (n - (26 * 10000 + 100000)) / 1000;
            int remain = (n - (26 * 10000 + 100000)) % 1000;
            time = 2;
            while (time) {
                   int k = key % 26;
                   ans[index] = IntToletters[k];
                   index--;
                   key = key / 26;
                   time--;
            }
            while (remain) {
                   int lastnum = remain % 10;
                   ans[index] = lastnum + '0';
                   index--;
                   remain = remain / 10;
            }
    }
    else if (n > (99999 +  26 * 10000 + 26^2 * 1000) && n <= (99999 +  26 * 10000 + 26^2 * 1000 + 26^3 * 100)) {
            int key = (n - (26^2 * 1000 + 26 * 10000 + 100000)) / 100;
            int remain = (n - (26^2 * 1000 + 26 * 10000 + 100000)) % 100;
            time = 3;
            while (time) {
                   int k = key % 26;
                   ans[index] = IntToletters[k];
                   index--;
                   key = key / 26;
                   time--;
            }
            while (remain) {
                   int lastnum = remain % 10;
                   ans[index] = lastnum + '0';
                   index--;
                   remain = remain / 10;
            }
    }
    // similar idea for 5th and 6th region ...
    return ans;
}

void helper(unordered_map<int, char>& map) {

    map[0] = 'A';

    map[1] = 'B';

    map[2] = 'C';
    ...
    ...
    map[25] = 'Z'; 
}
