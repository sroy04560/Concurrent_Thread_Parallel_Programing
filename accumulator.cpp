#include<iostream>
#include<thread>
#include<vector>
#include<numeric>
using namespace std;

int main(){
    vector<int> v={1,2,3,4,5,6,7,8,9,10};
    auto dash_fold=[](string a,int b){
        return move(a)+ "-" + to_string(b);
    };
    string s=accumulate(next(v.begin()),v.end(),to_string(v[0]),dash_fold);
    cout<<s<<endl;
    return 0;
}