#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


struct Person
{
    string last_name;
    string first_name;
};
vector<string> read_file(const string& path) {
    ifstream file;
    file.open(path);
    vector<string>result;
    string line;
    while (getline(file, line)) {
        result.push_back(line);
    }
    file.close();
    return result;
}
void split(const string& source, char delim, string& last_name, string& first_name) {
    auto pos = source.find(delim);
    last_name = source.substr(0, pos);
    first_name = source.substr(pos + 1);
}
vector<Person> record_struct(const string& path, Person& pers) {
    auto lines = read_file(path);
    vector<Person> result;

    for (string names : lines) {

        split(names, '|', pers.last_name, pers.first_name);
        result.push_back(pers);
    }

    return result;
}
void record_file(const string& path, vector<Person>& pers) 
{
    ofstream file;
    file.open(path);
    if (file.is_open())
    {
        for (Person item : pers)
        {
            file << item.last_name << endl;
        }
    }
    else
    {
        cerr << "File could not be written" << endl;
        return;
    }
    file.close();
}
int main()
{
    string path0 = "C:\\Users\\Student\\Desktop\\test.txt";
    Person Vani;
    string path1 = "C:\\Users\\Student\\Desktop\\Return.txt";
    vector<Person> full_names = record_struct(path0, Vani);


    cout << Vani.first_name << " " << Vani.last_name << endl;
    record_file(path1, full_names);
    return 0;
}