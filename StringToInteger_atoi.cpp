class Solution {
public:
    int myAtoi(string str) {
        int answer=0;
        int i=0;
        string s(str);
        int l = s.length();
        bool sign = true;
        while(i<l && s[i] == ' ')
            i++;
        cout<<"\nall the leading whitespaces trimmed";
        if((s[i]<'0' || s[i]>'9') && s[i] != '-' && s[i] !='+')
            return 0;
        cout<<"\nstarting the processing";
        if(s[i] == '-') {
            sign = false;
            i++;
            cout<<"\nNumber is negative";
        } else if (s[i] == '+') {
            i++;
        }
        
        while(i<l) {
            cout<<"\nhere is the element s["<<i<<"] \t"<<s[i];
            if(s[i]==' ') {
                break;
            }
            if(s[i] >= '0' && s[i] <='9') {
                int x = s[i]-'0';
                //cout<<"\n x="<<x;
                if(sign && static_cast<long int>(answer)*10 + x >= INT_MAX) {
                    return INT_MAX;
                } else if (!sign && static_cast<long int>(answer)*10 + x > INT_MAX) {
                    return INT_MIN;
                }
                answer = answer*10 + x;
                i++;
            } else {
                return (sign ? answer : -answer);
            }
            cout<<"\nanswer= "<<answer;
        }
        return (sign ? answer : -answer);
        
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
        string str = stringToString(line);
        
        int ret = Solution().myAtoi(str);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
