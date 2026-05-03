#include<iostream>
#include<string>
using namespace std;

bool valid(char ch){
if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z')||(ch>='0' && ch<='9')){
    return true;
}
return false;
}
char toLowerCase(char ch){
    if(ch>='A' && ch<='Z'){
        return ch - 'A' + 'a';
}
return ch;

}
bool ispalindrome(string s){
int i = 0;
int j = s.length()-1;
while(i<j){
if(!valid(s[i])){
i++;
}
else if(!valid(s[j])){
j--;
}
else{
if(toLowerCase(s[i]) != toLowerCase(s[j])){
return false;
}
i++;
j--;
}return true;
}
}
int main(){
string s;
cout<< "Enter the String:"<<endl;
cin>> s;
if(ispalindrome(s)){
cout<< " Palindrome"<<endl;
}
else{
cout<<"Not palindrome";
}
}