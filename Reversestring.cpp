void reversestring(vector<char>&s){
    int left = 0;
    int right = s.size()-1;
    while(left<right){
        swap(s[left],s[right]);
        left++;
        right--;
    }
}
// leedcode 344. Reverse String
// https://leetcode.com/problems/reverse-string/description/