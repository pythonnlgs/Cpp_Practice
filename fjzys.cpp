#include <iostream>
#include <list>
#include <string>
#include <math.h>
#include <map>
using namespace std;

bool contain(list<int> lst, int g){
	for (auto& o:lst){
		if (o == g)
		{
			return true;
		}
	}
	return false;
}

int count(list<int> l, int ind){
	int c = 0;
	for (auto& kk:l){
		if (kk == ind)
		{
			c += 1;
		}
	}
	return c;
}

bool isz(int a){
	for (int i = 2; i < a; ++i)
	{
		if (a % i == 0)
		{
			return false;
		}
	}
	return true;
}

string zysfj(int inp){
	list<int>::const_iterator cIter;
	list<int> ll;

	//std::map<int, int>::const_iterator cIter;
	map<int, int> content;
	map<int, int>::iterator iter;

	string nonrt = "Could not fj this inp.";
	int _inp = inp;

	if (isz(inp))
	{
		return nonrt;
	}else{
		while (inp){
			if (isz(inp) && (inp != 1)){
				//cout << inp << endl;
				ll.push_back(inp);
				inp = 0;
			}else{
				for (int i=2; i<inp; i++){
					if ((inp % i == 0) && isz(i)){
						//cout << i << endl;
						ll.push_back(i);
						inp = int(inp/i);
						break;
					}
				}
			}
		}

		ll.sort();
		//cout << "ll:(list<int>)" << endl;
		list<int>::iterator cIter;
		list<int> zys_no_rpt;
		for (auto& k: ll){
			//cout << k << endl;
			if (! contain(zys_no_rpt, k)){
				zys_no_rpt.push_back(k);
			}
		}
		for (auto& p:zys_no_rpt){
			content[p] = count(ll, p);
		}
		string body_ = to_string(_inp) + string(" = ");
		string body;
		//cout << "ff" << endl;
		for (iter = content.begin(); iter != content.end(); iter++){
			//cout << iter -> first << " " << iter -> second << endl;
			body += string("*") + to_string(iter -> first) + string("^") + to_string(iter -> second);
		}

		return body_ + body.substr(1);
	}
}

int main(){
	int inputs;
	cin >> inputs;
	cout << zysfj(inputs) << endl;
	return 0;
}
