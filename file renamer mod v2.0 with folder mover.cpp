#include<bits/stdc++.h>
#define ll long long int
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


string intToString (int a)
{
    ostringstream temp;
    temp<<a;
    return temp.str();
}


/*string intToString(int x)
{
	int y=x;
	int l=0;
	while(y>0)
	{
		l++;
		y=y/10;
	}
	char s[l];
	for(int i=l-1;i>=0;i--)
	{
		s[i]=char(0);
	}
	for(int i=l-1;i>=0;i--)
	{
		s[i]=char((x%10)+'0');
		x=x/10;
	}
	string a=s;
	return s;

}
*/
ll special_input(){
	string x1;
	getline(cin,x1);
	if(x1==""){
		return 1;
	}	
	else{
		return stringToInt(x1);
	}
	
}


int main(){
	string exist="",New,format="",Fname;
	string x1="";
	int fstart,l,start;
	char MTF;
	
	cout<<"Enter the existing name of file"<<endl;
	getline(cin,exist);
	if(exist==""){
		exist="videoplayback";
	}

	cout<<"Enter the format of file"<<endl;
	getline(cin,format);
	if(format==""){
		format="mp4";
	}

	cout<<"Enter the new name of file"<<endl;
	getline(cin,x1);
	if(x1==""){
		New=exist;
	}
	else{
		New=x1;
	}
	
	Fname="\""+New;// Surrounding with quotes.... foldername

	cout<<"Enter no of files"<<endl;
	cin>>l;
	cin.ignore();
	
	cout<<"Enter start no. of existing files "<<endl;
	fstart=special_input();
	
	cout<<"Enter start of no. of new files"<<endl;
	start = special_input();
	
	cout<<"Wanna move the files to a folder?(y/n) "<<endl;
	getline(cin,x1);
	if(x1==""){
		MTF='y';
	}
	else{
		MTF=x1.at(0);
	}
	
	if(MTF=='n'){
		string New1=New;     //backup of the data
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
    }
    else{
    	string New1=New;
		string exist1=exist;
		
		if(fstart==1){
			string makeFolder="md "+Fname;
			system(makeFolder.c_str());
			//for the first exception
			exist=exist+"."+format;
			New=New+"."+format;
			start++;
			New= New +"\"";
			exist="\""+exist+"\""; 		
			string s="move "+exist+" "+Fname+"/"+New;
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
			New= New +"\"";
			exist="\""+exist+"\""; 
			
			string s="move "+exist+" "+Fname+"/"+New;
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
    }

system("pause");

}
