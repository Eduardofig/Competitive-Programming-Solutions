#include <iostream>

int pascal(int row, int column)
{
    if(column == 1 || column == row || row == 1) {
        return 1;
    }
    return pascal(row - 1, column) + pascal(row - 1, column - 1);
}

void pascal_triangle(int rows) 
{
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < i + 1; ++j) {
            std::cout << pascal(i, j) << " ";
        }
        std::cout << std::endl;
    }
    return;
}

int main(int argc, char *argv[])
{
    int a;
    std::cin >> a;
    pascal_triangle(a);
    return 0;
}
