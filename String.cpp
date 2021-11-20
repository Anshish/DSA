#include<iostream>
using namespace std;

void convert_lower(string str)
{
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]>='A' && str[i]<='Z')
            str[i]+=32;
    }
    cout<<"string in lower case is: "<<str<<endl;
}
void convert_upper(string str)
{
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]>='a' && str[i]<='z')
            str[i]-=32;
    }
    cout<<"string in upper case is: "<<str<<endl;
}
void count(string str)
{
    int word=1;
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]==' ' && str[i-1]!=' ')
            word++;
    }
    cout<<"no. of words are: "<<word<<endl;
}
void valid(string str)
{
    for(int i=0;str[i]!='\0';i++)
    {
        if(!(str[i]>=65 && str[i]<=90) && !(str[i]>=97 && str[i]<=122) && !(str[i]>=48 && str[i]<=57))
        {
            cout<<"invalid"<<endl;
            exit(-1);
        }
    }
    cout<<"valid"<<endl;
}
void reverse(string str)
{
    int n=str.length();
    for(int i=0,j=n-1;i<n/2;i++,j--)
    {
        char temp=str[i];
        str[i]=str[j];
        str[j]=temp;
    }
    cout<<"reversed string is: "<<str<<endl;
}
void compare(string str1,string str2)
{
    if(str1 != str2)
    {
        cout<<"strings are not equal"<<endl;
    }
    else
    {
        cout<<"strings are equal"<<endl;
    }
}
void check_palindrome(string str)
{
    int i,j;
    int n=str.length();
    i=0;
    j=n-1;
    for(i,j;i<n/2;i++,j--)
    {
        if(str[i] != str[j])
        {
            cout<<"string is not a palindrome"<<endl;
            exit(-1);
        }
    }
    cout<<"string is palindrome"<<endl;
}
void check_duplicate(string str)
{
    int H[26]={0};
    for(int i=0;str[i]!='\0';i++)
    {
        H[str[i]-97]++;
    }
    for(int i=0;i<26;i++)
    {
        if(H[i]>1)
        {
            cout<<char(i+97)<<": "<<H[i]<<endl;
        }
    }
}
void check_anagram(string str1,string str2)
{
    int H[26]={0};
    int i;
    for(i=0;str1[i]!='\0';i++)
    {
        H[str1[i]-97]++;
    }
    for(i=0;str2[i]!='\0';i++)
    {
        H[str1[i]-97]--;
        if(H[str1[i]-97]<0)
        {
            cout<<"not anagram";
            exit(-1);
        }
    }
    if(str2[i]=='\0')
        cout<<"it's anagram";
}
int main()
{
   string str="hello world";
}