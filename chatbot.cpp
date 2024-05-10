#include <bits/stdc++.h>
using namespace std;

int main(){
    string temp = "Hello sfsfsd  sdfsfs";
    cout<<regex_search(temp,regex("\\b(?:Hello|hi)\\b"));
}