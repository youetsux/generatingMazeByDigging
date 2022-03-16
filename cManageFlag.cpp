#include <iostream>
#include "cManageFlag.h"


//複数フラグ対応
void cManageFlag::set(unsigned char _d)
{
	m_flag = m_flag | (unsigned char)_d;
}

//複数フラグ対応
void cManageFlag::reset(unsigned char _d)
{
	m_flag = m_flag & ~((unsigned char)_d);
}

//全リセット
void cManageFlag::reset() {
	m_flag = (unsigned char)0; //00000000にリセット
}

bool cManageFlag::get(unsigned char bit)
{
	unsigned char tmp = (m_flag >> bit) & 0x01;
	return(tmp);

}

void cManageFlag::print()
{
	using std::cout;
	using std::endl;

	cout << (int)m_flag << endl;
}