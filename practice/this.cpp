#include <iostream>
#include <string>
using namespace std;

bool patternCheck (string s, string p, int indexs, int indexp, int total) {
    if (indexs >= total && indexp >= p.length()) {return true;}
    if (p[indexp] == s[indexs] || p[indexp] == '.' && indexs < total) {
        if (p[indexp] == '.' && p[indexp+1] == '*') {
            if (p[indexp+2] == s[indexs]) {
                if (patternCheck(s,p,indexs+1,indexp+3,total)) {
                    return true;
                }
            }
        }
        if (indexs == total-1) {
            if (indexp == p.length()-1) {return true;}
            if (p[indexp + 1] == '*' && indexp+1 == p.length()-1) {return true;}
        }
        if (p[indexp + 1] == '*') {
            return patternCheck(s, p, indexs+1, indexp, total);
        }
        else {
            return patternCheck(s, p, indexs+1, indexp+1, total);
        }
    }
    else {
        if (p[indexp+1] == '*') {
            return patternCheck(s, p, indexs, indexp+2, total);
        }
        return false;
    }
}

int main () {
    string s = "aabab";
    string p = "a.*ab";
    if (patternCheck(s, p, 0, 0, s.length())) {
        cout << "Does match\n";
    }
    else {
        cout << "Does not match\n";
    }
}