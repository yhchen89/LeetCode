/*---------------------------------------------
INPUT: a string s
OUTPUT: the longest palindromic substring in s
Algorithm: 從index=0為center開始向左右擴展尋找Palindrome
---------------------------------------------*/

#include<iostream>
#include<string>
#include<algorithm> //for reverse
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        /*TLE
        int sLength = s.length();
        string substring;
        string reverseSubstring;
        int subLength;
        int maxLength = 0;
        int ansI, ansJ;
        bool isPalindrome = true;
        
        if(sLength==0) return "";
        else if(sLength==1) return s;
        
        for(int i = 0; i < sLength; i++){
            if(sLength - i < maxLength)
                return s.substr(ansI, ansJ);
            for(int j = sLength - i; j >= 1; j--){
                if(j <= maxLength)
                    break;
                substring = s.substr(i, j);
                
                isPalindrome = true;
                for(int k = 0; k <= (j - 1) / 2; k++){
                    if(substring[k] != substring[j - 1 - k]){
                        isPalindrome = false;
                        break;
                    }
                }
                if(!isPalindrome)
                    continue;
                
                maxLength = j;
                ansI = i;
                ansJ = j;
            }
        }

        return s.substr(ansI, ansJ);*/
        int sLength = s.length();
        int maxLength = 0;
        int center=0;
        int left, right;
        int ansLeft, ansRight;
        bool isPalindrome = false;
        if(sLength == 0) return "";
        else if(sLength == 1) return s;

        for(center; center < sLength; center++){
            isPalindrome = false;
            left = center;
            right = center;
            while(left >= 0 && right < sLength){
                if(s[left] == s[right]){
                    isPalindrome = true;
                    left--;
                    right++;
                }
                else break;
            }
            if(!isPalindrome)continue;
            left++;
            right--;
            if(right - left + 1 > maxLength){
                maxLength = right - left + 1;
                ansLeft = left;
                ansRight = right;
            }
            isPalindrome = false;
            left = center;
            right = center + 1;
            while(left >= 0 && right < sLength){
                if(s[left] == s[right]){
                    isPalindrome = true;
                    left--;
                    right++;
                }
                else break;
            }
            if(!isPalindrome)continue;
            left++;
            right--;
            if(right - left + 1 > maxLength){
                maxLength = right - left + 1;
                ansLeft = left;
                ansRight = right;
            }
        }
        return s.substr(ansLeft, maxLength);
    }
};

int main(){
    Solution s;
    cout<<s.longestPalindrome("babad")<<endl;
    cout<<s.longestPalindrome("cbbd")<<endl;
    cout<<s.longestPalindrome("a")<<endl;
    cout<<s.longestPalindrome("ac")<<endl;
    cout<<s.longestPalindrome("aacabdkacaa")<<endl;
    cout<<s.longestPalindrome("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa")<<endl;
    cout<<s.longestPalindrome("kyyrjtdplseovzwjkykrjwhxquwxsfsorjiumvxjhjmgeueafubtonhlerrgsgohfosqssmizcuqryqomsipovhhodpfyudtusjhonlqabhxfahfcjqxyckycstcqwxvicwkjeuboerkmjshfgiglceycmycadpnvoeaurqatesivajoqdilynbcihnidbizwkuaoegmytopzdmvvoewvhebqzskseeubnretjgnmyjwwgcooytfojeuzcuyhsznbcaiqpwcyusyyywqmmvqzvvceylnuwcbxybhqpvjumzomnabrjgcfaabqmiotlfojnyuolostmtacbwmwlqdfkbfikusuqtupdwdrjwqmuudbcvtpieiwteqbeyfyqejglmxofdjksqmzeugwvuniaxdrunyunnqpbnfbgqemvamaxuhjbyzqmhalrprhnindrkbopwbwsjeqrmyqipnqvjqzpjalqyfvaavyhytetllzupxjwozdfpmjhjlrnitnjgapzrakcqahaqetwllaaiadalmxgvpawqpgecojxfvcgxsbrldktufdrogkogbltcezflyctklpqrjymqzyzmtlssnavzcquytcskcnjzzrytsvawkavzboncxlhqfiofuohehaygxidxsofhmhzygklliovnwqbwwiiyarxtoihvjkdrzqsnmhdtdlpckuayhtfyirnhkrhbrwkdymjrjklonyggqnxhfvtkqxoicakzsxmgczpwhpkzcntkcwhkdkxvfnjbvjjoumczjyvdgkfukfuldolqnauvoyhoheoqvpwoisniv")<<endl;
}
