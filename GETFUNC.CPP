#include<fstream.h>
#include<conio.h>
#include<stdio.h>

char fexpr[20];
int resn=0;
int state=0;
int create();
int getdata();
int main()
{
	clrscr();
	getdata();
	state=create();
	if(state==-1)
		cout<<"\nX-X:Fatal error! Cannot continue furthur!";
	else if(!state)
		cout<<"\nProgram succesfully compiled! Please run WORK.CPP to obtain the graph";
	getch();
	return 0;
}

int getdata()
{
	cout<<"Enter expression: \n[any math function or valid c++ expession is allowed; use x as variable]\nf(x)= ";
	gets(in);
	cout<<"Enter graph resolution:[integer value between 10 and 200][default:100]\n\t";
	cin>>resn;
	if(resn>200||resn<10)	resn=100;
	return 0;
}

int create()
{
	ofstream fout;
	fout.open("function.h",ios::out|ios::trunc);
	if(fout.good())
	{
		fout<<"#include<math.h>\n#define c "<<resln<<".0\ndouble f( double x = 0.0 ){\n\t\t";
		fout<<"return "<<<fexpr<" ";
		fout<<"; \n}";
		fout.close();
		return 0;
	}
	else 
		return -1;
	
}
