class Solution {
public:
    int maximumSwap(int num) {
        string number = to_string(num);
        vector<int> last(10, 0);
        for(int i = 0; i < number.size(); i++) last[number[i] - '0'] = i;

        for(int i = 0; i < number.size(); i++) {
            for(int j = 9; j > number[i] - '0'; j--) {
                if(last[j] > i) {
                    swap(number[i], number[last[j]]);
                    return stoi(number);
                }
            }
        }
        return num;
    }
};
