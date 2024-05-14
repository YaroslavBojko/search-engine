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

void ConverterJson::sealPathFiles()
{
    for(auto path : resourcesPaths)
    {
        std::cout << path << " ";
    }
}

std::vector<std::string> ConverterJson::sealFiles1()
{
    std::cout << resourcesPaths[1] << std::endl;
    /*std::ifstream stream(resourcesPaths[1]);
    if (stream.is_open())
    {
        std::string buffer1;
        while (stream.eof())
        {
            std::string buffer2;
            stream >> buffer2;
            buffer1 += buffer2;
            buffer1 += " ";
        }
        textDocuments.push_back(buffer1);
        stream.close();
    } else
    {
        std::cerr << "Error file not found!!!" << std::endl;
    }*/
}

std::vector<std::string> ConverterJson::getTextDocuments()
{
    textDocuments.clear();
    for(const auto& resourcesFile : resourcesPaths)
    {
        std::ifstream stream(resourcesFile);
        if (stream.is_open())
        {
            std::string buffer1;
            while (stream.eof())
            {
                std::string buffer2;
                stream >> buffer2;
                buffer1 += buffer2;
                buffer1 += " ";
            }
            textDocuments.push_back(buffer1);
            stream.close();
        } else
        {
            std::cerr << "Error file not found!!!" << std::endl;
        }
    }
}
