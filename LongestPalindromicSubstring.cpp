#include <string>

class Solution {
public:
    /*
    bool isPalindrome(const string &s) {
        string temp = s;
        reverse(temp.begin(),temp.end());
        return temp.compare(s) ? false : true ;
    }
    */
    string longestPalindrome(string s) {
        int length = s.length();
        unordered_map<string,int> m;
        for(int l=length;l>=0;l--) {
            for(int i=0;i+l <= length; i++) {
                string temp(s,i,l);
                reverse(temp.begin(),temp.end());
                if (s.compare(i,l,temp) == 0){
                    reverse(temp.begin(),temp.end());
                    return temp;
                }
            }
        } 
        
        return "";
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        string ret = Solution().longestPalindrome(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
