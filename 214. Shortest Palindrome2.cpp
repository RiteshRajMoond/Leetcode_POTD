// This is an Application of KMP

class Solution {
public:
    string shortestPalindrome(string& s) {

        string rev = string(s.rbegin(), s.rend());
        string combined = s + "*" + rev;
        int n = combined.size();
        vector<int> lps(n, 0);;

        formLPS(combined, lps, n);

        int longestPalindromeLength = lps.back();

        string nonPalindromicString = s.substr(longestPalindromeLength);

        return rev.substr(0, nonPalindromicString.size()) + s;
        
    }
private:
    void formLPS(string& pat, vector<int>& lps, int n) { // KMP
        lps[0] = 0;
        int i = 1, len = 0;

        while(i < n) {
            if(pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if(len != 0) 
                    len = lps[len-1];
                else {
                    i++;
                }
            }
        }
    }

};
