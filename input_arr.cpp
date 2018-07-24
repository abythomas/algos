#include <bits/stdc++.h>

using namespace std;

int main(){
  cout<<"Enter number of test cases: ";
  int t,n,i,j;
  cin>>t;
  cout<<"Enter array:";
  char c=getchar();
  for(i=0;i<t;i++){
    string str;
    getline(cin,str);
    const char *cstr=str.c_str();
    char *token = strtok((char *)cstr, " ");
    vector <int> arr;
    int temp;
    j=0;
    while(token!=NULL){
      arr.push_back(atoi(token));
      cout<<arr[j]<<" ";
      token=strtok(NULL," ");
      j++;
    }
  }
}
