#pragma once
class Knight : public Player
{
public:
	Knight(string name, int hp, int mp, int attack);
	Knight(const Knight& other) : Player(other)
	{
		_stamina = other._stamina;
	}
	Knight& operator = (const Knight& other) // 복사대입연산자
	{
		return *this;
	}

	virtual ~Knight(); // 붙여줘야함

	// Player을(를) 통해 상속됨
	virtual void PrintInfo() override;
	virtual void PreAttack(Creature* other) override;
	virtual void Attack(Creature* other) override;
	virtual void GetExp(int amount) override;

private:
	int _stamina;
};

