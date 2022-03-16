#pragma once
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;
using std::pair;

enum class block {
	floor = 1,
	wall = 0,
};

class cMap
{
private:
	pair<int, int> m_size;
	//first, second -> width, height
	vector<block> m_map_dat;
	void printMapDat(block _fw) const;
public:
	cMap()
		: m_size({ 0,0 }) {}
	cMap(int _w, int _h);
	~cMap() {};
	int getWidth() const { return(m_size.first); }
	int getHeight() const { return(m_size.second); }
	block getMapDat(int _x, int _y) const;
	bool isFloor(int _x, int _y) const;
	bool isWall(int _x, int _y) const;
	void setMapDat(int _x, int _y, block _fw);
	void printMap() const;
};


//std::random_device rnd;// �񌈒�I�ȗ���������𐶐�
//std::mt19937 mt(rnd());//  �����Z���k�E�c�C�X�^��32�r�b�g�ŁA�����͏����V�[�h�l
//std::uniform_int_distribution<> rand100(0, 99);        // [0, 99] �͈͂̈�l����
//0,99�������o�C�j�V�����C�U�ŏ�����

