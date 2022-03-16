#pragma once
#include "cMap.h"
#include <map>
#include <random>
#include <array>
#include <bitset>

using std::map;
using std::bitset;

enum Direction{
	Up=0,Left=1,Down=2,Right=3,Error
};

const map<Direction, pair<int, int>> pdir = { {Direction::Up,   { 0,-1}},
											  {Direction::Left, {-1, 0}},
											  {Direction::Down, { 0, 1}},
											  {Direction::Right,{ 1, 0}}
											};

class cMyMaze
{
private:
	//乱数のための乱雑な変数たち
	std::random_device rnd;// 非決定的な乱数生成器を生成
	std::mt19937 mt;//  メルセンヌ・ツイスタ
private:
	//掘れる方向を表すフラグ[RDLU]の順にビットで並んでいる
	bitset<4> m_fDigDir;
	cMap m_map;
	void preparingData();
	void finalizeData();
	pair<int, int> getInitPoint();
	vector<pair<int, int>> m_InitPointList;
	bitset<4> checkDigDir(pair<int, int> _point);
	Direction getDigDir(pair<int, int> _point);
	
public:
	cMyMaze(int _w, int _h)
		:m_map(_w, _h), mt(rnd()),m_fDigDir("0000"){}
	void digingWall();
	void showMyMaze();

	void printDigFlagBit() {
		m_fDigDir.set(Direction::Up).set(Direction::Left);
		if(m_fDigDir.any())
			std::cout << m_fDigDir << std::endl;
		m_fDigDir.reset(Direction::Up).reset(Direction::Left);
		if (m_fDigDir.any())
			std::cout << m_fDigDir << std::endl;
	}
};

