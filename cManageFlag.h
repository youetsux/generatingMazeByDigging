#pragma once
class cManageFlag
{
	unsigned char m_flag;
	//�t���O�Ǘ��֐�
public:
	cManageFlag()
		:m_flag(0) {}
	~cManageFlag() {}
	unsigned char get() { return m_flag; };
	bool get(unsigned char bit);
	void set(unsigned char _d);//�����t���O�Ή�
	void reset(unsigned char _d);//�����t���O�Ή�
	void reset();//�S���Z�b�g
	void print();//�f�o�b�O�p
};

