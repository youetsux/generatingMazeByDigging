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
	//pair<int, int>でアクセスできるようにオーバーロード
	block getMapDat(pair<int, int> _point) const;
	bool isFloor(pair<int, int> _point) const;
	bool isWall(pair<int, int> _point) const;
	void setMapDat(pair<int, int> _point, block _fw);
	void printMap() const;
};

