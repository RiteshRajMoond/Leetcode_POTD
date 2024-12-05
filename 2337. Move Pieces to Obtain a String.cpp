// First Code:

class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        string s = "", t = "";

        for(int i = 0; i < n; i++) {
            if(start[i] != '_') s += start[i];
            if(target[i] != '_') t += target[i];
        }

        if(s != t) return false;

        int i = 0, j = 0;
        while(i < n && j < n) {
            while(i < n && start[i] == '_') i++;
            while(j < n && target[j] == '_') j++;

            if(i < n && start[i] == 'R' && i > j) return false;
            if(i < n && start[i] == 'L' && i < j) return false;

            i++, j++;
        }

        return true;
    }
};

// We can optimise this by not calculating string s and string t

class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();

        int i = 0, j = 0;
        while (i < n || j < n) {
            while (i < n && start[i] == '_') i++;
            while (j < n && target[j] == '_') j++;

            if (i == n && j == n) return true;

            if (i == n || j == n) return false;

            if (start[i] != target[j]) return false;
            if (start[i] == 'L' && i < j) return false; 
            if (start[i] == 'R' && i > j) return false; 

            i++;
            j++;
        }

        return true;
    }
};
