#include "pch.h"
#include "knight.h"

Knight::Knight()
// ���� �ʱ�ȭ ����
// ���⿡ Creature() ��������
{
	// ���� �ʱ�ȭ ����
	// cout << "Knight�� �⺻������" << endl;
	_stamina = 0;
}

Knight::Knight(int hp, int mp, int attack, int stamina)
: Creature(hp, mp, attack)
{
	// cout << "Knight�� Ÿ�Ժ�ȯ ������" << endl;
	_stamina = stamina;
}

Knight::~Knight()
{
	// cout << "Knight�� �Ҹ���" << endl;
}



void Knight::PrintCreature()
{
	cout << "Knight�� HP : " << _hp << endl;
}
