#include "converter.h"

ConverterJson* ConverterJson::object = nullptr;
ConverterJson* ConverterJson::getObject()
{
    if (object == nullptr)
        object = new ConverterJson;

    return object;
}

void ConverterJson::readConfigFile(std::string path)
{
    std::ifstream file(path);

    if (file.is_open())
    {
        nlohmann::json configFile;
        file >> configFile;
        name = configFile["config"]["name"];
        version = configFile["config"]["version"];
        maxResponses = configFile["config"]["maxResponses"];

        resourcesPaths.clear();
        for(auto pathFileTxt : configFile["files"])
        {
            resourcesPaths.push_back(pathFileTxt);
        }

        std::cout << "********** " << name << " **********" << std::endl;
        std::cout << "Version: " << version << std::endl;
        std::cout << "Max responses per request: " << maxResponses << std::endl;
        std::cout << "Search is carried out in " << resourcesPaths.size() << " files" << std::endl;

        file.close();
    }
    else
    {
        std::cerr << "Config file is missing" << std::endl;
    }
}
