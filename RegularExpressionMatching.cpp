class Solution {
public:
    bool recur(string& s,string& p, int& m, int& n, int i, int j) {
		if(i>=m && j>=n)
			return true;
		if(i<m && j<n) {
			if(j+1<n) {
				if(p[j+1] == '*') {
					return (recur(s,p,m,n,i,j+2) || ((s[i]==p[j] || p[j]=='.') ? recur(s,p,m,n,i+1,j) : false));
				} 
				return ((s[i]==p[j] || p[j]=='.') ? recur(s,p,m,n,i+1,j+1) : false);
			}
			if(s[i] == p[j] || p[j]=='.')
				return (i == m-1);
		}
		if(i>=m && j<n) {
			return isConsumable(p,j,n,s[m-1]);
		}
		return false;
	}
	bool isConsumable(string& p, int j,int n,char a) {
		bool alt=false;
		stack <char> s1;
		if(p[j] == '*') {
			alt = true;
			j++;
		}			
		while(j<n){
			if(p[j] != '*') {
				s1.push(p[j]);
			} else {
				if(s1.empty())
					return false;
				s1.pop();
			}
			j++;
		}
		if(alt && s1.size() == 1 && s1.top() == a) {
			return true;
		}
		if(s1.empty())
			return true;
		return false;
	}
    
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        char prev = ' ';
        int s_txt = 0;
        int p_txt = 0;
        int count = 0;
        bool f = false;
        int i=0,j=0,c=0;
        if (!m && !n)
            return true;
        if(!n || p[0] == '*') {
            cout<<"\nExiting due to pattern length";
            return false;
        }        
        return recur(s,p,m,n,0,0);
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        string p = stringToString(line);
        
        bool ret = Solution().isMatch(s, p);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
