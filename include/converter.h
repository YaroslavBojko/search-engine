#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "nlohmann/json.hpp"

/**
* Class for working with JSON files
*/

class ConverterJson
{
private:
    std::string configPath;
    std::string requestPath;
    std::string answersPath;

    std::string name;
    std::string version;
    int maxResponses;

    std::vector<std::string> resourcesPaths;
    std::vector<std::string> textDocuments;
    std::vector<std::string> fileNames;

    ConverterJson() = default;
    static ConverterJson* object;

public:
     /**
      * We create an instance object of the Converter JSON class.
      * @return object
      */
     static ConverterJson* getObject();


     /**
      * Method reading configuration data from
      * the config.json file
      */
      void readConfigFile (std::string path = "../config\\config.json");

    /**
     * Method for getting file contents
     * @return a list with the contents of the files listed
     * in config.json
     */
     std::vector<std::string> getTextDocuments();

};