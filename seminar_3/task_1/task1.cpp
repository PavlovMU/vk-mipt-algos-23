#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
ostream& operator<<(ostream &fout, vector <T> &v){
    for(auto curr : v)
        fout<<curr<<" ";
    return fout;
}

void Shell_Sort(vector <int> &v){
    int gap = v.size() / 2;
    while(gap > 0){
        for(size_t current_position = gap; current_position < v.size(); current_position++){
            int m_gap = current_position;
            while(m_gap >= gap && v[m_gap] < v[m_gap - gap]){
                iter_swap(v.begin()+m_gap, v.begin() + m_gap - gap);
                m_gap-=gap;}
        }
        gap/=2;
    }
}

int main(void){
    vector <int> v{1, 5, 3, 7, 8, 2, 3, 9};
    cout<<v<<endl;
    Shell_Sort(v);
    cout<<v;
    return 0;
}
