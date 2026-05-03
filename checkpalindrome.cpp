#include<iostream>
#include<string>
#include<cctype>
using namespace std;
bool isPalindrome(string S){
    int left = 0;
    int right = S.size()-1;
    while(left<right){
        while(tolower(S[left]) != tolower(S[right])){
            return false;
        }
        left++;
        right--;
        
    }
    return true;
}
int main(){
    string S;
    cout<<"Enter a string: ";
    cin>> S;
    if(isPalindrome(S)){
        cout<<"The string is a palindrome."<<endl;
    }
    else{
        cout<<"The string is not a palindrome."<<endl;
    }
    return 0;
}