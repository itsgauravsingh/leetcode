class Solution {
public:
    string convert(string s, int numRows) {
        if(s.size()<3 || numRows == 1)
            return s;
        int l = s.length();
        //cout<<"\nString length: "<<l<<", size: "<<s.size();
        string answer="";
        vector<bool> isP;
        int j=0;
        bool f=true;
        int jump=0;
        
        for(int i=0;i<l;i++) {
            isP.push_back(true);
        }
        for(int i=0;i<numRows;i++) {
            f= true;
            for(int next=i;next<l;) {
                if(isP[next]) {
                    answer.push_back(s[next]);
                    isP[next] = false;
                }
                if(f) {
                    jump = 2*(numRows-i-1);
                    f = false;
                    if(!jump){
                        continue;                    
                    }
                    
                } else {
                    jump = 2*i;
                    f = true;
                    if(!jump){
                        continue;                       
                    }
                }
                next += jump;
            }
        }
        return answer;
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        int numRows = stringToInteger(line);
        
        string ret = Solution().convert(s, numRows);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
