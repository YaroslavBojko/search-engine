#include <iostream>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>

struct Record
{
    std::string name;
    std::string family;
    int age;
};

int main() {
    Record record;
    std::cin >> record.name >> record.family >> record.age;

    std::ofstream file("record.json");
    nlohmann::json dict;
    dict["name"] = record.name;
    dict["family"] = record.family;
    dict["age"] = record.age;
    file << dict;
}
