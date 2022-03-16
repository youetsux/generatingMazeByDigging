#pragma once
class cManageFlag
{
	unsigned char m_flag;
	//フラグ管理関数
public:
	cManageFlag()
		:m_flag(0) {}
	~cManageFlag() {}
	unsigned char get() { return m_flag; };
	bool get(unsigned char bit);
	void set(unsigned char _d);//複数フラグ対応
	void reset(unsigned char _d);//複数フラグ対応
	void reset();//全リセット
	void print();//デバッグ用
};

