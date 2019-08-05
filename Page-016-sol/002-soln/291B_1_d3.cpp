//00:13 04-11-2018 to 00:23 04-11-2018
//19:17 04-11-2018
//19:43 04-11-2018
//19:51 04-11-2018
//19:53 04-11-2018

#include<iostream>
#include<vector>

using namespace std;

#define N_ 100000

char c;
int p=0, in_quotes=0, prev_is_space=0, had_chars=0;

main(){
while(cin.get(c)){
	switch(c){
		case '\n':
			if(had_chars && !prev_is_space)
				cout << ">\n";
			return 0;
		case ' ':
			if(in_quotes){
				cout << c;
			}else{
				if(had_chars && !prev_is_space)
					cout << ">\n";
				prev_is_space = 1;
			}
			break;
		case '"':
			if(prev_is_space || !had_chars){
				cout << '<';
				prev_is_space = 0;
			}
			had_chars++;
			in_quotes = 1-in_quotes;
			break;
		default:
			if(prev_is_space || !had_chars){
				cout << '<';
				prev_is_space = 0;
			}
			had_chars++;
			cout << c;
			break;
	}
}
if(!prev_is_space)
	cout << ">\n";
}

//19:40 04-11-2018
//19:48 04-11-2018
//19:52 04-11-2018
//19:56 04-11-2018
//20:03 04-11-2018
