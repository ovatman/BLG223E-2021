#include <iostream>
#include <stdio.h>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <sstream>
using namespace std;

void map_example();
void unordered_set_map_example();
void wfreq_example();

int main(int argc, char *argv[]){

    //map_example();
    //unordered_set_map_example();
    wfreq_example();

    return EXIT_SUCCESS;
}

void map_example(){
	map<string, string> strMap;
	strMap["Monday"]    = "1";
	strMap["Tuesday"]   = "2";
	strMap["Wednesday"] = "3";
	strMap["Thursday"]  = "4";
	strMap["Friday"]    = "5";
	strMap["Saturday"]  = "6";

	strMap.insert(pair<string, string>("Sunday", "7"));
/*
    for (auto x : strMap) 
      cout << x.first << " " << x.second << endl; 

	while(!strMap.empty()){
		cout<<strMap.begin()->first<<" "
			<<strMap.begin()->second<<endl;
		strMap.erase(strMap.begin());
	}
*/
/*
    map<string,string>::iterator low = strMap.lower_bound("Saturday");
    map<string,string>::iterator high = strMap.upper_bound("Tuesday");

    for(auto it = low; it!=high; it++)
        cout << it->first << " " << it->second << endl;

 */
    map<string,string> interval(strMap.find("Saturday"),strMap.find("Tuesday"));
    for (auto x : interval) 
      cout << x.first << " " << x.second << endl; 

}

void unordered_set_map_example(){
    unordered_set<string> set1 ; 

    set1.insert("tolga") ; 
    set1.insert("ovatman") ; 
    set1.insert("blg223") ; 
    set1.insert("123412") ; 
    set1.insert("data-structures") ; 
      
    for (string s : set1)
        cout << s << " ";
    cout << endl;
    

	unordered_map<string, int> map1; 
  	map1["Monday"]    = 1;
	map1["Tuesday"]   = 2;
	map1["Wednesday"] = 3;
	map1["Thursday"]  = 4;
	map1["Friday"]    = 5;
	map1["Saturday"]  = 6;

	map1.insert(pair<string, int>("Sunday", 7));
  
    for (auto x : map1) 
      cout << x.first << " " << x.second << endl; 
      
}

void wfreq_example(){
    fstream infile;
    infile.open("../input.txt",ios::in);
	if(!infile.is_open()){
        cout << "File cannot be opened"<<endl;
        return;
    }			
	string line;
	map <string,int> freq; 
	while(getline(infile, line)){
        string temp="";
        stringstream ss(line);
        while(ss>>temp){
            string word="";
            for(char c:temp){
                if(tolower(c)<'a' || tolower(c)>'z' )
                    continue;
                else word+=tolower(c);
            }
            if(word.length()!=0)
                freq[word]++;
        }
	}
	infile.close();

    multimap<int,string> freq_rev;
    map<string,int>::iterator it;

    for(it=freq.begin();it!=freq.end();it++){
        freq_rev.insert(make_pair(it->second,it->first));
		cout<<(*it).first<<" "<<(*it).second<<endl;
	}

    cout<<"***************Most frequent words*****************"<<endl;
    multimap <int,string>::reverse_iterator myit;
    int count;
    for (myit=freq_rev.rbegin(),count=0;count<100;myit++,count++)
	    cout<<(*myit).second<<" "<<(*myit).first<<endl;

}