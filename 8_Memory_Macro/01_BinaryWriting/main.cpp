#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    uint64_t num = 0xDEADBEEF00000000;
    ofstream t_out("out.txt");
    t_out << num;

    ofstream out("out.bin", ios::binary);
    out.write(reinterpret_cast<char*>(&num),sizeof(num));
    out.close();


    uint64_t num2;
    ifstream in("out.bin", ios::binary);
    in.read(reinterpret_cast<char*>(&num2), sizeof(uint64_t));


    std::cout << num << std::endl;
    std::cout << num2 << std::endl;

    //-----------
    vector<int> v = {1,2,3,4,5};
    ofstream outv("vec.bin", ios::binary);
    size_t size = v.size();
    outv.write(reinterpret_cast<char*>(&size),sizeof(size_t));
    for (int i = 0; i < size; ++i) {
        outv.write(reinterpret_cast<char*>(&v[i]),sizeof(int));
    }
    outv.close();


    ifstream inv("vec.bin", ios::binary);
    size_t size1;
    inv.read(reinterpret_cast<char*>(&size1),sizeof(size_t));
    vector<int> res(size1);
    for (int i = 0; i < size1; ++i) {
        inv.read(reinterpret_cast<char*>(&res[i]),sizeof(int));
    }

    for (auto num : res){
        cout << num << " ";
    }

    // ------
    int* x = nullptr;
    void* tmp = x;
    char * ch_ptr = static_cast<char*>(tmp);

    return 0;
}
