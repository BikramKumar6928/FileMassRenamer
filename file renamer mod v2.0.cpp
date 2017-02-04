#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<cmath>
using namespace std;

int stringToInt(string s)
{
	int x=0;
	for(int i=0;i<s.length();i++)
	{
		char a=s.at(i);
		x=x*10+(a-'0');
	}
	return x;
}





string intToString(int x)
{
	int y=x;
	int l=0;
	while(y!=0)
	{
		l++;
		y=y/10;
	}
	char s[l];
	for(int i=l-1;i>=0;i--)
	{
		s[i]=(x%10)+'0';
		x=x/10;
	}
	string a=s;
	return s;
}



int main(){
	
	cout<<"Enter the existing name of file";
	string exist="",New,format="";
	string x1="";
	int fstart;
	getline(cin,exist);
	if(exist==""){
		exist="videoplayback";
	}
	cout<<"Enter the format of file";
	getline(cin,format);
	if(format==""){
		format="mp4";
	}
	cout<<"Enter the new name of file";
	getline(cin,New);
	cout<<"Enter no of files";
	int l,start;
	cin>>l;
	cin.ignore();
	cout<<"Enter start of no";
	getline(cin,x1);
	if(x1==""){
		start=1;
	}	
	else{
		start=stringToInt(x1);
	}
	cout<<"Enter start no. of existing file";
	getline(cin,x1);
	if(x1==""){
		fstart=1;
	}
	else{
		fstart=stringToInt(x1);
	}
	
	
	
	string New1=New;
	string exist1=exist;
	
	if(fstart==1){
		//for the first exception
		exist=exist+"."+format;
		New=New+"."+format;
		start++;
		New="\"" + New +"\"";
		exist="\""+exist+"\""; 		
		string s="rename "+exist+" "+New;
	//	cout<<s<<endl;
		system(s.c_str());
		exist=exist1;
		New=New1;
		//End of exception
	}
	for(int i=fstart;i<=l+fstart;i++){
		exist=exist+"_"+intToString(i)+"."+format;
		New=New+"_"+intToString(start)+"."+format;
		start++;
		
		//surrounding by quotes
		New="\"" + New +"\"";
		exist="\""+exist+"\""; 
		
		string s="rename "+exist+" "+New;
		exist=exist1;
		New=New1;
		if(i==1) 
		{
			start--;
			continue;	
		}
	//	cout<<s<<endl;
		system(s.c_str());
		
	}

system("pause");


}
