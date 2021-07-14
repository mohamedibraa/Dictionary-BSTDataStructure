#include<iostream>
#include "BSTree.cpp"
#include<string>
#include <fstream>
#include<algorithm>
#include<cctype>
using namespace std;

int main()
{
	int sel;
	BSTree<string> B;
	string a, d;
	ifstream out("file1.txt",ios::in);
	while (std::getline(out, a)&&std::getline(out, d))
	{	/*
		std::getline(out, a);
		std::getline(out, d);*/
		if (!B.contain(a))
		B.insert(a, d);
	}
	/*ifstream out("file1.txt", ios::in);
	std::string a;
	std::string b;
	while (!out.eof())
	{
		std::getline(out, a);
		std::getline(out, b);
		if (!B.contain(a))
			B.insert(a, b);
	}*/
 	
	
start:
	cout << "=============================================" << endl;
	cout << "==============SELECT FROM MENU===============" << endl;
	cout << "=============================================" << endl;
	cout << "1) Search Word" << endl;
	cout << "2) Insert Word" << endl;
	cout << "3) Edit Word" << endl;
	cout << "4) Display all meaning " << endl;
	cout << "5) delete word " << endl;
	cout << "6) Exit" << endl;

	cin >> sel;
	if (sel == 1)
	{
	 cout << "Enter Word : ";
		string word,r;
		cin >> word;
		//string a, d;
		//ifstream out ("file1.txt", ios::app);
		//while (!out.eof())
		//{
		//	out >> a >> d;
		//	if (a == word)
		//	{
		//		//cout <<"the meaning is "<< d<<"\n";
		//		B.insert(a, d);
		//	}
		//}
	/*	if ((int)word[0] >= 65 && (int)word[0] < 90)
		{
			word[0] =word[0] - 32;
		}
		else
		{
			word[0] = word[0];
		}
		*/
		if ((int)word[0] >= 48 && (int)word[0] < 57)
		{
			cout << "please enter string word \n";
		}
		else
		{
			for (int i = 0; i < word.size(); i++)
			{
				r += (char)tolower(word[i]);
			}
			if (!B.contain(r)) {
				cout << "Not Found , Enter Again !" << endl;
				goto start;
			}
			else {
				
				cout << "Meaning is : " << B.findNode(r) << endl << endl;
				goto start;
			}
		}
		}
	else if (sel == 2)
	{
		string word,r, meaning;
		cout << "Enter Word : ";
		cin >> word;

		if ((int)word[0] >= 48 && (int)word[0] < 57)
		{
			cout << "please enter string word \n";
		}
		else
		{
			for (int i = 0; i<word.size(); i++)
			{
				r+= (char)tolower(word[i]);
			}
			
			while (true) {
				if (!B.contain(word))
				{
					cout << "Enter the meaning of " << r << ":";
					cin >> meaning;
					B.insert(r, meaning);
					goto start;
				}
				else
				{
					cout << "the word aready founded \n if you want to edit meaning enter num 1 " <<
						"if you want to go to select menue enter another num ";
					int x = 0;
					string edit;
					cin >> x;
					if (x == 1)
					{
						cout << "Enter new meaning \n";
						cin >> edit;
						B.edit(word, edit);
						goto start;
					}
					else
						goto start;
				}
			}
		}
	}

	else if (sel == 3) {
		cout << "Enter the word that you want to edit it \n";
		string word,r;
		cin >> word;
		for (int i = 0; i < word.size(); i++)
		{
			r += (char)tolower(word[i]);
		}
		string edit,meaning;
		if (B.contain(r))
		{
			cout << "Enter the New meaning \n";
			cin >> edit;
			/*ofstream out;
			out.open("file1.txt", ios::app);
			out <<  r << "\n" << edit << "\n";
			out.close();*/

			/*string a, d;
			ifstream out("file1.txt", ios::app);
			while (!out.eof())
			{
				out >> a >> d;
				if (a == word)
				{
					d = edit;
				}
			}
			//string arr;*/
			/*char c;
			ifstream out("file1.txt");
			while (!out.eof())
			{
			   out.get(c);
			   arr += c;
				cout << c;

			}*/
			/*char c;
			string w, m;
			ifstream out("file1.txt");
			while (!out.eof())
			{
				
			}*/
			
			B.edit(r,edit);
			goto start;
		
		}

		else
		{
			cout<<word<<" not founded if you want to insert word with meaning enter 1 \n"<<
				"if you want to go to select menue enter another num \n";
			int x = 0;
			cin >> x;
			if (x == 1)
			{
				cout << "Enter the meaning \n";
					cin >> meaning;
				B.insert(word, meaning);
				goto start;
			}
			else
				goto start;
		}
	}
	else if (sel == 4) {
		/*char c;
		ifstream out ("file1.txt");
		while (!out.eof())
		{
			out.get(c);
			cout << c;       
			
		}*/
		
		B.traverse();

		goto start;
	}

	else if(sel==5){
	string word;
	cout << "enter word that you delete it"<<"\n";
		cin >> word;
		B.remove(word);
		goto start;
}
	else if (sel == 6) {
		
		B.traversee();
		return 0;
	}
	
	
	else {
		cout << "YOU MUST SELECT FROM THIS MENU " << endl;
		goto start;
	}
	

	system("pause");
	return 0;
}