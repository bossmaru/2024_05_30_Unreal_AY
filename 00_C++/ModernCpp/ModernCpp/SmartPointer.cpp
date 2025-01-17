#include <iostream>
#include < memory>

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


// shared_ptr

// weak_ptr

// unique_ptr


class Player
{
public:
	Player() { cout << "기본생성자 호출" << endl; }
	Player(int hp) : _hp(hp) { cout << "타입 변환 생성자 호출" << endl; }
    ~Player() { cout << "소멸자 호출" << endl; }


    void Attack()
    {
        if (target.expired() == false)
            target.lock()->_hp -= 10;
            cout << "공격 !!!" << endl;
    }

    void SetTarget(shared_ptr<Player> target)
    {
        this->target = target;
    }

private:
    weak_ptr<Player> target;
	int _hp = 0;
};


#pragma region MySharedPtr
struct RefCountBlock
{
	int refCount = 1;
};

template<typename T>
class SharedPtr
{
public:
    SharedPtr(T* ptr) : _block(nullptr), _ptr(ptr)
    {
        _block = new RefCountBlock();
        cout << "RefCount : " << _block->refCount << endl;
    }

    SharedPtr(const SharedPtr<T>& other)
        : _ptr(other._ptr)
        , _block(other._block)
    {
        if (_ptr != nullptr)
        {
            _block->refCount++;
            cout << "RefCount : " << _block->refCount << endl;
        }
    }

    ~SharedPtr()
    {
        if (_ptr != nullptr)
        {
            _block->refCount--;
            cout << "RefCount : " << _block->refCount << endl;

            if (_block->refCount <= 0)
            {
                delete _block;
                delete _ptr;
                _ptr = nullptr;
            }
        }
    }

    SharedPtr<T>& operator=(const SharedPtr<T>& other)
    {
        _ptr = other._ptr;
        _block = other._block;

        if (_ptr != nullptr)
        {
            _block->refCount++;
            cout << "RefCount : " << _block->refCount << endl;
        }

        return (this);
    }

    T operator->()
    {
        if (_ptr != nullptr)
            return _ptr;
        return nullptr;
    }


private:
	RefCountBlock* _block;
	T* _ptr;
};

void PrintPlayer(SharedPtr<Player> player)
{
	// cout << player->_hp << endl;
}

#pragma endregion

int main()
{
	shared_ptr<Player> p1 = make_shared<Player>(5);
	shared_ptr<Player> p2 = make_shared<Player>(10);

    // shared ptr의 순환 참조 문제
    // --> weak_ptr로 해결
    p1->SetTarget(p2);
    p2->SetTarget(p1);

    p1->Attack();
    p2->Attack();

    // unique_ptr
    unique_ptr<Player>p3 = make_unique<Player>();



	// SharedPtr<Player> p = SharedPtr<Player>(new Player(30));
	// PrintPlayer(p);

	return 0;
}