#include "cMyMaze.h"
#include <numeric>

void cMyMaze::preparingData()
{
	//マップ外壁の上部と下部を通路に
	for (int i = 0; i < m_map.getWidth(); i++)
	{
		m_map.setMapDat(i, 0, block::floor);
		m_map.setMapDat(i, m_map.getHeight() - 1, block::floor);
	}
	//マップ外壁の左部と右部を通路に
	for (int i = 1; i < m_map.getHeight() - 1; i++)
	{
		m_map.setMapDat(0, i, block::floor);
		m_map.setMapDat(m_map.getWidth() - 1, i, block::floor);
	}

}

void cMyMaze::finalizeData()
{
	//マップ外壁の上部と下部を壁に
	for (int i = 0; i < m_map.getWidth(); i++)
	{
		m_map.setMapDat(i, 0, block::wall);
		m_map.setMapDat(i, m_map.getHeight() - 1, block::wall);
	}
	//マップ外壁の左部と右部を壁に
	for (int i = 1; i < m_map.getHeight() - 1; i++)
	{
		m_map.setMapDat(0, i, block::wall);
		m_map.setMapDat(m_map.getWidth() - 1, i, block::wall);
	}
}

pair<int, int> cMyMaze::getInitPoint()
{
	std::uniform_int_distribution<> r_xrange(0, m_map.getWidth() - 2);
	std::uniform_int_distribution<> r_yrange(0, m_map.getHeight() - 2);
	pair<int, int> ret((int)(2 * (r_xrange(mt) / 2) + 1), (int)(2 * (r_yrange(mt) / 2) + 1));
	return(ret);
}

void cMyMaze::digingWall()
{
	pair<int, int> tmp = m_InitPointList.front();

	m_map.setMapDat(tmp, block::floor);
	if (checkDigDir(tmp).any() && m_map.isFloor(tmp))
	{
		Direction digdir = getDigDir(tmp);

		using std::cout;
		using std::endl;
		//cout << "(x, y) : (" << m_InitPointList.back().first << ", " << m_InitPointList.back().second << ")[" << digdir << "]" << endl;

		m_InitPointList.insert(m_InitPointList.begin(),
							  { tmp.first + 2 * (pdir.at(digdir).first),
								tmp.second + 2 * (pdir.at(digdir).second) });
		m_map.setMapDat({ tmp.first  + pdir.at(digdir).first,
						  tmp.second + pdir.at(digdir).second }, block::floor );
		digingWall();
	}
	else
	{
		if(!m_InitPointList.empty())
			m_InitPointList.erase(m_InitPointList.begin());
		return;
	}
}


bitset<4> cMyMaze::checkDigDir(pair<int, int> _point)
{
	bitset<4> canDig("0000");
	int& px = _point.first;
	int& py = _point.second;//うぜぇからコピー

	//LDRU 3210
	if (px == 1)
		canDig.set(3, false);
	else
	{
		canDig.set(3, m_map.isWall(px - 2, py));
	}

	if (py == 1)
		canDig.set(0, false);
	else
	{
		canDig.set(0, m_map.isWall(px, py - 2));
	}
	
	if (px == m_map.getWidth() - 2)
		canDig.set(1, false);
	else
	{
		canDig.set(1, m_map.isWall(px + 2, py));
	}
	
	if (py == m_map.getHeight() - 2)
		canDig.set(2, false);
	else
	{
		canDig.set(2, m_map.isWall(px, py + 2));
	}
	
	return canDig;
}


Direction cMyMaze::getDigDir(pair<int, int> _point)
{
	bitset<4> res = checkDigDir(_point);
	std::uniform_int_distribution<> r4(0, 3);
	while (true)
	{
		int m = r4(mt);
		if (res[m])
		{
			switch (m)
			{
			case 0:
				return Direction::Up;
				break;
			case 1:
				return Direction::Right;
				break;
			case 2:
				return Direction::Down;
				break;
			case 3:
				return Direction::Left;
				break;
			default:
				return Direction::Error;
			}
		}
	}
}

void cMyMaze::showMyMaze()
{
	preparingData();
	std::pair<int, int> p = getInitPoint();
	m_InitPointList.push_back(p);
	while(!m_InitPointList.empty())
	{
		digingWall();
	}
	finalizeData();
	m_map.printMap();
}