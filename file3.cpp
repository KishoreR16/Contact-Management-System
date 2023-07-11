#include "file2.cpp"
#include<fstream>
int main()
{
	ifstream of("Duration.txt");
	string str;
	of>>str;
	cout<<str;
	while(getline(of,str))
	{
		cout<<str<<endl;
	}
	of.close();
	return 0;
}