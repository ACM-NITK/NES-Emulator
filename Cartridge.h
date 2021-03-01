#pragma once
#include <cstdint>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
#include "Mapper_000.h"

class Cartridge{
public:
  Cartridge(const string& sFileName);
  ~Cartridge();

public:
	bool ImageValid();

	enum MIRROR
	{
		HORIZONTAL,
		VERTICAL,
		ONESCREEN_LO,
		ONESCREEN_HI,
	} mirror = HORIZONTAL;


private:
  bool bImageValid = false;
  vector <uint8_t> vPRGMemory;
  vector <uint8_t> vCHRMemory;

  uint8_t nMapperID = 0;
  uint8_t nPRGBanks = 0;
  uint8_t nCHRBanks = 0;

  shared_ptr<Mapper> pMapper;


public:
    bool cpuRead(uint16_t addr, uint8_t &data);
    bool cpuWrite(uint16_t addr, uint8_t data);

    bool ppuRead(uint16_t addr, uint8_t &data);
    bool ppuWrite(uint16_t addr, uint8_t data);
};
