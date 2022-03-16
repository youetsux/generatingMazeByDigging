#include <iostream>
#include "cManageFlag.h"


//�����t���O�Ή�
void cManageFlag::set(unsigned char _d)
{
	m_flag = m_flag | (unsigned char)_d;
}

//�����t���O�Ή�
void cManageFlag::reset(unsigned char _d)
{
	m_flag = m_flag & ~((unsigned char)_d);
}

//�S���Z�b�g
void cManageFlag::reset() {
	m_flag = (unsigned char)0; //00000000�Ƀ��Z�b�g
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