#include <bits/stdc++.h>
using namespace std;
int main(){
 string c; cin >> c;
 bool res_flag = false;
 if (c == "a"|| c == "e"|| c == "i"|| c == "o"|| c == "u") res_flag = true;
 
 if (res_flag) cout << "vowel" << endl;
 else cout << "consonant" << endl;
}