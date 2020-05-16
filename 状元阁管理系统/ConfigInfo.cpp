#include "ConfigInfo.h"

ConfigInfo::ConfigInfo(string Name)
{

	string temp = ".dat";
	string FM = Name + temp;
	uniqueAddress = "Config\\";
	fileName = FM;
	completeFile = saveAddress + uniqueAddress + fileName;

}

ConfigInfo::ConfigInfo()
{
	uniqueAddress = "Config\\";
	fileName = "TestConfig.dat";
	completeFile = saveAddress + uniqueAddress + fileName;
}


ConfigInfo::~ConfigInfo()
{
	//�����������������
}

ConfigInfo ConfigInfo::operator = (const ConfigInfo& obj)
{
	BaseFile::operator=(obj);
	return *this;
}
