#include<iostream>
using namespace std;

string generateKey(string s,string kw){
    string ans="";
    for(int i=0;i<s.size();i++){
        ans.push_back(kw[i%kw.size()]);
    }

    return ans;

}
 
 string vignereIncryption(string key,string str){
    string cipher_text;
    for(int i=0;i<str.size();i++){
        char x=(str[i]+key[i])%26+65;
        cipher_text.push_back(x);
    }
    return cipher_text;
 }

 string vignereDecryption(string key,string inc_str){
    string decrypted_text;

    for(int i=0;i<inc_str.size();i++){
        char x=(inc_str[i]-key[i]+26)%26+65;
        decrypted_text.push_back(x);
    }
    return decrypted_text;
 }
int main()
{
    string str="HELLOWORLD";
    string keyword="JAY";

// to make size of the key equal to the str
    string key=generateKey(str,keyword);
// incrytption function
    string ine_text=vignereIncryption(key,str);
    cout<<"KEY:-"<<key<<endl;
    cout<<"Cipher Text:-"<<ine_text<<endl;
// decryptioon function
    string orignalString=vignereDecryption(key,ine_text);
    cout<<"Orignal Text:-"<<orignalString<<endl;
    return 0;
}
