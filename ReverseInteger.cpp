class Solution {
public:
    int reverse(int x) {
        if(x<=INT_MIN || x>INT_MAX || !x)
            return 0;
        if (x>-10 && x<10)
            return x;
        int max = 0x7FFFFFFF;
        int msb = 0x80000000;
        int toggle = 0xFFFFFFFF;
        int answer = 0;
        bool s = true;
        if(x<0) {
            // Reversing the two's compliment
            x -= 1;  
            x ^= toggle;
            s = false;
        }
        int i=1;
        while(x>0) {
            //cout<<"\n "<<i++<<"\t"<<static_cast<long int>(answer)*10;
            if (static_cast<long int>(answer)*10 + x%10 > max) {
                return 0;
            }
            answer *= 10;
            answer += x%10;
            x /= 10;
        }
        if (!s)
            return -answer;
        return answer;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        int ret = Solution().reverse(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
