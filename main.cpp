#include "converter.h"

int main()
{
    ConverterJson::getObject()->readConfigFile();
    ConverterJson::getObject()->sealPathFiles();
    ConverterJson::getObject()->sealFiles1();
}
