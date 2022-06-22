#include <bits/stdc++.h>

using namespace std;

struct person
{
    int age;
    string name;
};

template<typename T>
vector<pair<int, T>> enumerate(vector<T> v)
{
    int cnt = 0;
    vector<pair<int, T>> new_v;

    for(T element: v) {
        new_v.emplace_back(cnt++, element);
    }

    return new_v;
}

template<typename T, typename U>
vector<pair<T, U>> zip(vector<T> v1, vector<U> v2)
{
    vector<pair<T, U>> new_v;

    int sz = min(v1.size(), v2.size());

    for(int i = 0; i < sz; ++i) {
        new_v.emplace_back(v1[i], v2[i]);
    }
    
    return new_v;
}

int main()
{
    vector<person> v{{22, "Eduardo"}, {21, "Kay flock"}, {42, "Santo Amaro"}};
    vector<float> v2{2.5, 3.4, 6.8};

    for(auto &[i, person]: enumerate(v)) {
        printf("[%d, {%d, %s}]", i, person.age, person.name.c_str());
        cout << endl;
    }

    for(auto &[num, person]: zip(v2, v)) {
        printf("[%f, {%d, %s}]\n", num, person.age, person.name.c_str());
    }
}
