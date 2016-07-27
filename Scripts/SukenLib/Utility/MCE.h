#pragma once

#include"../Manager.h"
#include"Data.h"
#include<string>
#include<map>

namespace suken {

class CMCEData{
public:
	~CMCEData();

	void Awake(const char* _file);

	int GetChip(char layer,int x,int y);

	int Array(char layer,int x,int y);

	std::string file;
	int *chip;
	int width;
	int height;
	CData *data;
};

class CMCE{
public:
	CMCE();

	void Awake(const char* _folder){
		folder = _folder;
	}

	void Read(const char* _file);

	void Delete(const char* _file);

	int Get(const char* _file,char layer,int x,int y);

	const char layerA;
	const char layerB;
	const char layerC;
private:
	std::string folder;
	std::map<std::string,CMCEData> file;

	bool CheckFile(const char* _file);
};

}

extern suken::CMCE mce;

