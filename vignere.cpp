// Vignere cipher algorithm implementation . This accept dynamic key perform encryption and decryption.
-----------------------------------------------------------------------------------------------------

#include <bits/stdc++.h>

using namespace std;

int main()
{
   char letters[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
   string key;
   string plain;
   cout<<"enter plain text"<<endl;
   cin>>plain;
   cout<<"enter key: "<<endl;
   cin>>key;
   
   int plength=plain.length();
   int klength=key.length();
   
   if(klength<plength)
   {
       int remain = plength-klength;
       remain=(remain/klength)+1;
       for(int i=0;i<remain;i++)
       {
           key+=key;
       }
   }
   string cipher="";
   for(int i=0;i<plength;i++)
   {
       int result=(plain[i]-'a'+key[i]-'a')%26;
       cipher+=letters[result];
    //   cout<<letters[result];
   }
   cout<<cipher<<endl;
  
  // decryption
string decrypt="";
 for(int i=0;i<cipher.length();i++)
   {

       int res=cipher[i]-key[i];
       if(res<0)
       {
        res=26+res;
       }
      decrypt+=letters[res];
    //   cout<<letters[result];
   }

cout<<decrypt<<endl;
  
 

    return 0;
}
