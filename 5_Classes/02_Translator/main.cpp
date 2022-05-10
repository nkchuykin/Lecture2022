#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

class Translator{
    unordered_map<string, vector<string>> data;
public:
    void AddTranslation(const string& word, const string& translation)
    {
        data[word].push_back(translation);
        data[translation].push_back(word);
    }

    const vector<string>& operator[](const string& str) const{
        return data.at(str);
    }

    vector<string>& operator[](const string& str){
        return data[str];
    }

    void Print() const
    {
        for (const auto& [word, vec] : data){
            cout << word << ":";
            for (const auto& tr : vec)
            {
                cout << " " << tr;
            }
            cout << "\n";
        }
    }
};



int main() {
    // one один
    // code код
    // map карта отображение
    // even чётный даже
    Translator tr;
    tr.AddTranslation("one", "один");
    tr.AddTranslation("map", "карта");
    tr.AddTranslation("map", "отображение");
    //try{

    for (const auto& val : tr["map"])
    {
        cout << val << " ";
    }
    //}
   // catch (out_of_range& ex){
    //    cout << ex.what();
    //}
    cout << "\n--------------\n";
    //tr["один"].emplace_back("alone");
    tr.AddTranslation("один","alone");
    cout << "\n--------------\n";
    tr.Print();
    return 0;
}
