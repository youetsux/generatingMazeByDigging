#include "cMap.h"
#include <string>

using std::string;

cMap::cMap(int _w, int _h)
{
	if (_w < 5)_w = 5;
	if (_w % 2 == 0)_w = _w + 1;
		
	if (_h < 5)_h = 5;
	if (_h % 2 == 0)_h = _h + 1;

	m_size.first = _w;
	m_size.second = _h;
	m_map_dat.assign(m_size.first*m_size.second, block::wall);

}

block cMap::getMapDat(int _x, int _y) const
{
	return(m_map_dat[_y * getWidth() + _x]);
}
void cMap::setMapDat(int _x, int _y, block _fw)
{
	m_map_dat[_y * getWidth() + _x] = _fw;
}

void cMap::printMapDat(block _fw) const
{
	string mapchip[] = { "¡", " " };
	cout << mapchip[(int)_fw];
}

bool cMap::isFloor(int _x, int _y) const
{
	if (getMapDat(_x, _y) == block::floor)return true;
	else
		return false;
}
bool cMap::isWall(int _x, int _y) const
{
	if (getMapDat(_x, _y) == block::wall)return true;
	else
		return false;
}

void cMap::printMap() const
{
	for (auto j = 0; j < getHeight(); j++) {
		for (auto i = 0; i < getWidth(); i++) {
			printMapDat(getMapDat(i, j));
		}
		cout << "\n";
	}
}