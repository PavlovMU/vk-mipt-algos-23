#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

template <typename T>
ostream& operator<<(ostream &fout, const vector <T> &v){
    for(auto curr : v)
        fout<<curr<<" ";
    return fout;
}

template <typename T>
ostream& operator<<(ostream &fout, const unordered_map <T, T> &v){
    for(auto curr : v)
        fout<<curr.first<<": "<<curr.second<<endl;
    return fout;
}

vector <int> two_sum(const vector <int> &target, int data){
    unordered_map<int, int> cash;
    for(int i=0; i<int(target.size()); i++){
        if(cash.find(target[i]) == cash.end())
            cash[data-target[i]] = i;
        else
            return vector<int>{cash[target[i]], i};
    }
    return vector<int>{};
}

int main(void){
    cout<<two_sum({1, 3, 5, 6, 4, 8}, 12)<<endl;
    cout<<two_sum({-13, 56, 36, 9, -4, 7}, 23);
    return 0;
}
