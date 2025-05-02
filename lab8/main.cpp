
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector> 
#include <queue>
using namespace std;

int sep(char c)
{
    if (c == ' ' || c == ',' || c == '.' || c == '?' || c == '!') return 1;
    else return 0;
}

string tolower(string& cuv)
{
    string rez = cuv;
    for (auto it = rez.begin(); it != rez.end(); it++)
        if (*it >= 'A' && *it <= 'Z')
            *it = *it + 'a' - 'A';
    return rez;
}

class comp
{
public:
    bool operator ()(const pair<string, int>& cuv1, const pair<string, int>& cuv2)
    {
        if (cuv1.second == cuv2.second)
            return cuv1.first > cuv2.first; //cuv1 are prioritate
        return cuv1.second < cuv2.second; //cuv2 are prioritate
    }
};

int main()
{
	ifstream file("input.txt");
    if (!file) 
    {
        cout << "eroare deschidere" << endl;
        return 0;
    }

    string line;
    getline(file, line);
    file.close();

    vector<string> cuvinte;
    string cuvant;

    for (int i = 0; i < line.size(); i++)
        if (!sep(line[i])) cuvant = cuvant+line[i];
        else {
            if (!cuvant.empty())
            {
                cuvinte.push_back(tolower(cuvant));
                cuvant.clear();
            }
    
       }

    //pt ultimul cuvant fara separator dupa el(daca este)
    if (!cuvant.empty())
    {
        cuvinte.push_back(tolower(cuvant));
        cuvant.clear();
    }

    map <string, int> nrcuv;

    //nr aparitii pt fiecare cuvant
    for (auto it=cuvinte.begin(); it!=cuvinte.end(); it++)
        nrcuv[*it]++;

    //first=lexicografic //second=nr apartitii

    priority_queue<pair<string, int>,vector<pair<string, int>>,comp> pq;
    for (auto it = nrcuv.begin(); it != nrcuv.end(); it++) 
        pq.push(make_pair(it->first, it->second));
  
    while (!pq.empty())
    {
        cout << pq.top().first << " => " << pq.top().second << endl;
        pq.pop();
    }


    /*
    for (auto it=nrcuv.begin(); it!=nrcuv.end(); it++)
    {
        cout << it->first << ": " << it->second <<endl;
    }*/
     
   
    return 0;
}