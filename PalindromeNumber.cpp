class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        string s="";
        while(x>0) {
            s.push_back(x%10);
            x /=10;
        }
        string rev=s;
        reverse(s.begin(),s.end());
        if(s.compare(rev) == 0) {
            return true;
        }
        return false;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        bool ret = Solution().isPalindrome(x);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
