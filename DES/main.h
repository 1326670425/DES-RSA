#include <iostream>  
#include <fstream>  
#include <bitset>  
#include <string>
using namespace std;
class main
{
public:
	bitset<64> key;
	bitset<48> subKey[16];
	static int IP[64];
	static int IP_1[64];
	static int PC_1[56];
	static int PC_2[48];
	static int shiftBits[16];
	static int E[48];
	static int S_BOX[8][4][16];
	static int P[32];

public:
	bitset<32> f(bitset<32> R, bitset<48> k);
	bitset<28> leftShift(bitset<28> k, int shift);
	void generateKeys(bitset<64>& key);
	bitset<64> charToBitset(const char s[8]);
	void BitstoByteArray(char bytes[],bitset<64>& bits);
	bitset<64> encrypt(bitset<64>& plain);
	bitset<64> decrypt(bitset<64>& cipher);
	char* CStringtoChar(CString s);
	CString filling(CString s,int yu,int n,int type);
};