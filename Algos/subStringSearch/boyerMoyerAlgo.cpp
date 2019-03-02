#include<iostream>
#include<string>
using namespace std;
class boyerMoyerAlgo
{
	private:
	string seq;	
	int *ptr;
	int anyOtherChar;
	
	void createTable()
	{
		ptr=new int[26];
		for(int i=0;i<26;i++)
		{
			ptr[i]=0;
		}
		int asciiChar=0;
		int total=0;
		for(int i=0;i<seq.length();i++)
		{
			if((int)seq[i]>=65)
			{
				asciiChar=((int)seq[i])-65;
			}
			else
			{
					asciiChar=((int)seq[i])-97;
			}
			if(ptr[asciiChar]==0)
			{
				ptr[asciiChar]=1;
				total++;
			}
			else
			{
				ptr[asciiChar]=ptr[asciiChar]+1;
			}
		}//create badMatchTable
		for(int i=0;i<seq.length();i++)
		{
			int max=getMax(i);
			int index=calAscii(seq[i]);
			ptr[index]=max;
		}
		anyOtherChar=seq.length();
	}
	
	int getMax(int index)
	{
		int a=1;
		int b=this->seq.length()-index-1;
		if(a>b)
			return a;
		return b;
	}
	public:
	void display()
	{
		for(int i=0;i<26;i++)
		{
			if(ptr[i]!=0)
			{
				cout<<"character:"<<(char)(i+65)<<','<<"value:"<<ptr[i]<<endl;
			}
		}
	}
	boyerMoyerAlgo(string seq)
	{
	this->seq=seq;
	createTable();
	}
	void findPattern(string str)
	{   bool doesExist=false;
		for(int i=0;i<str.length();i++)
		{
		 int index=calAscii(str[i]);
		 if(ptr[index]!=0)
		 {
		 	i+=ptr[index];
		 	doesExist=true;
		 	if(index==calAscii(this->seq[i]))
			 {
		 	for(int j=i;j>=0 &&doesExist==true;j--)
			 {   index=calAscii(str[j]);
			 	if(ptr[index]==0)
			 	doesExist=false;
			 }
			 }
		 }
		 else
		 {
		 	i+=anyOtherChar;
		 	doesExist=false;
		 }
		 
		}
		if(doesExist==true)
		{
			cout<<"Pattern Found\n";
		}
		else
		{
			cout<<"Pattern Not Found!\n";
		}
	}
	inline int calAscii(char a)
	{
		if((int)a>=65  &&(int)a<97)
			{
				return (int)a-65;
			}
			else
			{
					return (int)a-97;
			}
	}
};
int main()
{
	boyerMoyerAlgo obj("TEST");
	obj.findPattern("abbcdtsetstesfgjtest");

}
