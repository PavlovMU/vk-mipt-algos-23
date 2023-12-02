#include <iostream>
#include <vector>
using namespace std;

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

int feed_animals(vector <int>& animals, vector <int> &food){
    Shell_Sort(animals);
    Shell_Sort(food);
    size_t ans = 0;
    for(size_t i = 0; i < animals.size() && ans < animals.size(); i++)
        if(food[i] > animals[ans])
            ans++;
    return ans;
}

int main(void){
    vector <int> animals{1, 4, 3, 8}, food{8, 2, 3, 2};
    cout<<feed_animals(animals, food);
    return 0;
}
