
#ifndef HASHTABLEH
#define HASHTABLEH

#include <string>
#include <vector>
#include "SECPK1/Int.h"
#ifdef WIN64
#include <Windows.h>
#endif

#define HASH_SIZE_BIT 25
#define HASH_SIZE (1<<HASH_SIZE_BIT)
#define HASH_MASK (HASH_SIZE-1)

#define B0MASK 0xFFFFFFF0ULL

// 36bit for offset, MAX 2^36 point in HashTable

typedef struct {
  uint32_t b0; // LSB key (28 bit) + HSB Offset (4 bit)
  uint32_t p;  // LSB Offset
} ENTRY;

class HashTable {

public:

  HashTable();
  void Add(Int *x, uint64_t  p);
  bool Get(Int *x, std::vector<uint64_t> &p);
  uint64_t GetNbItem();
  void Reset();
  double GetSizeMB();
  void PrintInfo();
  void Sort(uint32_t h);

private:

  ENTRY    *E[HASH_SIZE];  
  uint16_t  M[HASH_SIZE];  // Max
  uint16_t  C[HASH_SIZE];  // Count

};

#endif // HASHTABLEH
