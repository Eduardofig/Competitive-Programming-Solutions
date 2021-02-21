#include <iostream>
#include <vector>

void solve(std::vector<int> array, int num)
{
    int max = array.size(), min = 0, index = (max + min)/2, _min, _max, __min, __max;
    while(array[index] != num) {
        if(array[index] < num) {
            min = index;
        } else {
            max = index;
        }        
        index = (max + min)/2;
    }
    _min = min, _max = index,__min = index, __max = max;
    index = (_max + _min)/2;
    while (_min != _max - 1) {
        if(array[index] == num) {
            _max = index;
        } else {
            _min = index;
        }
        index = (_max + _min)/2;
    }
    if(array[_max] == num) {
        std::cout << _max << std::endl;
    } else {
        std::cout << _min << std::endl;
    }
    index = (__max + __min)/2;
    while(__min != __max - 1) {
        if(array[index] == num) {
            __min = index;
        } else {
            __max = index;
        }
        index = (__max + __min)/2;
    }
    if(array[__max] == num) {
        std::cout << __max << std::endl;
    } else {
        std::cout << __min << std::endl;
    }
    return;
}

int main()
{
    std::vector<int> a = {1, 3, 3, 5, 7, 8, 9, 9, 9, 15};
    std::vector<int> b = {100, 150, 150, 153};
    solve(a, 9);
    solve(b, 150);
}

