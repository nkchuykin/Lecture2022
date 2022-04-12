#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> matrix(5,vector<int>(5));

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            matrix[i][j] = j + 5 * i;
        }
    }

    for (const vector<int>& row : matrix) {
        //row = {2,34,5};
        for(auto num : row)
        {
            cout << num << " ";
        }
        cout << "\n";
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
