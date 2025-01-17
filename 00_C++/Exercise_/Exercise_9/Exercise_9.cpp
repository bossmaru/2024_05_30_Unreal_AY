﻿#include <iostream>
using namespace std;
#include "Knight.h"
#include "Archer.h"
#include "Mage.h"
#include "Pet.h"

// [Bug Report #9]
// 궁수가 죽으면 펫도 같이 죽는 사양이 추가되었습니다.
// 그런데 왜 프로그램도 같이 죽는걸까요?
// 이유를 찾아서 고쳐주세요!

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	
	// 1. 외부에서 생성한 것은 외부에서 지워준다.
	// 2. use after free... 다 사용한(참조나 포인터로 들고갔음) 다음에 지워라.
	// ---
	// 동적할당... 쉬운 작업이 아님.
	// -> 리소스를 많이 잡아벅는다.
	// --> 운영체제 -> 커널영역 -> 나 Heap에 몇바이트 할당해줘.
	// --> Heap에 할당한 후에 운영체제가 저한테 다시 포인터를 넘겨줌.
	// --> 삭제도 이를 같이한다.  (게임 중간에 하지 않음)

	Pet* pet = new Pet();

	Archer* archer = new Archer(pet);
	archer->_hp = 100;
	archer->_maxHp = 100;
	archer->_attack = 20;

	Knight* knight = new Knight();	
	knight->_hp = 150;
	knight->_maxHp = 150;
	knight->_attack = 100;
	
	int damage = knight->GetAttackDamage();
	archer->AddHp(-damage);
	if (archer->IsDead())
		pet = nullptr;

	delete archer;
	delete knight;
	delete pet;
}
