#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

template <class T>
class Bag {
public:
	Bag(int bagCapacity = 3);
	~Bag();

	int size() const;
	bool IsEmpty() const;
	T& Element() const;

	void Push(const T&);
	void Pop();

private:
	T* array;
	int capacity;
	int top;
};

//ChangeSize
template <class T>
void ChangeSize1D(T*& a, const int oldSize, const int newSize) {
	if (newSize < 0)throw "New length must be >=0";

	T* temp = new T[newSize];
	int number = min(oldSize, newSize);
	copy(a, a + number, temp);
	delete[]a;
	a = temp;
}

//Capacity
template <class T>
Bag<T>::Bag(int bagCapacity) : capacity(bagCapacity) {
	if (capacity < 1)throw "Capacity must be >0";
	array = new T[capacity];
	top = -1;
}


//delete
template<class T>
Bag<T>::~Bag()
{
	delete[] array;
	cout<<"Bag 삭제"<<endl;
}

//IsEmpty
template <class T>
inline bool Bag<T>::IsEmpty() const{
	return top == -1;
}

//Size
template <class T>
inline int Bag<T>::size() const{
	return top+1;
}

//Element
template <class T>
T& Bag<T>::Element() const {
	if (IsEmpty())throw "Bag is empty";
	int random = rand() % (top + 1);
	return array[random];
}

//Push
template <class T>
void Bag<T>::Push(const T& x) {
	if (capacity == top + 1) {
		ChangeSize1D(array, capacity, 2 * capacity);
		capacity *= 2;
	}
	array[++top] = x;
}

//Pop
template <class T>
void Bag<T>::Pop() {
	if (IsEmpty())throw "Bag is empty, cannot delete";
	int del = rand() % (top + 1);
	copy(array + del + 1, array + top + 1, array + del);
	array[top--].~T();
}

class Character {
protected:
	char* name;
	int level;
	int power;
	int speed;
	int intel;
	int att;
	int def;
	int health;
	int mental;
public:
	Character(int level, int power, int speed, int intel, int att, int def, int health, int mental) :level(level), power(power), speed(speed), intel(intel), att(att), def(def), health(health), mental(mental)
	{
	}
	Character(){}
	virtual void move(){}
	virtual void showInfo(){}
	virtual void attack(){}
	~Character() {
		cout << name << " 캐릭터 삭제완료" << endl;
		delete[]name;
	}
};

class Warrior : public Character {
private:
	char* weapon;
public:
	Warrior(int level, int power, int speed, int intel, int att, int def, int health, int mental)
		:Character(level, power, speed, intel, att, def, health, mental)
	{
		char tem[100];
		cout << "전사를 생성합니다." << endl;
		cout << "캐릭터 이름 입력 : ";
		cin >> tem;
		name = new char[strlen(tem) + 1];
		strcpy(name, tem);

		cout << "무기 이름 입력 : ";
		cin >> tem;
		weapon = new char[strlen(tem) + 1];
		strcpy(weapon, tem);
	}
		void move(){
			cout<<"==>전사 이동출력"<<endl;
			cout<<"이동했습니다."<<endl; 
		}
		
		void showInfo(){
			cout<<"==>전사 정보출력"<<endl;
			cout<<"캐릭터 이름: "<<name<<", 무기 이름 : "<<weapon<<", 레벨 : "<<level<<", 힘 : " <<power<<", 민첩 : "<<speed<<", 지능 : "<<intel<<", 공격력 : "<<att<<", 방어력 : "<<def<<", 체력 : "<<health<<", 정신력 : "<<mental<<endl;
		}
		void attack(){
			cout<<"==>전사 공격 출력"<<endl;
			cout<<"("<<weapon<<")칼로 찔렀습니다."<<endl;

		}

	~Warrior() {
		cout << weapon << " 무기 삭제 완료" << endl;
		delete[]weapon;
	}

};

class Archer : public Character {
	private:
		char *weapon;
	public:
		Archer(int level,int power,int speed,int intel,int att,int def,int health,int mental)
			:Character(level,power,speed,intel,att,def,health,mental)
		{
			char tem[100];
			cout<<"궁수를 생성합니다."<<endl;
			cout<<"캐릭터 이름 입력: ";
			cin>>tem;
			name=new char[strlen(tem)+1];
			strcpy(name,tem);

			cout<<"무기 입력: ";
			cin>>tem;
			weapon=new char[strlen(tem)+1];
			strcpy(weapon,tem);
		}
		void move(){
			cout<<"==>궁수 이동출력"<<endl;
			cout<<"이동했습니다."<<endl; 
		}
		void showInfo(){
			cout<<"==>궁수 정보출력"<<endl;
			cout<<"캐릭터 이름: "<<name<<", 무기 이름 : "<<weapon<<", 레벨 : "<<level<<", 힘 : " <<power<<", 민첩 : "<<speed<<", 지능 : "<<intel<<", 공격력 : "<<att<<", 방어력 : "<<def<<", 체력 : "<<health<<", 정신력 : "<<mental<<endl;
		}
		void attack(){
			cout<<"==>궁수 공격 출력="<<endl;
			cout<<"("<<weapon<<")화살을 쐈습니다."<<endl;

		}
		
		~Archer(){
			cout<<weapon<<" 무기 삭제완료"<<endl;
			delete []weapon;
		}
		
};


class Sorcerer : public Character {
	private:
		char *weapon;
	public:
		Sorcerer(int level,int power,int speed,int intel,int att,int def,int health,int mental)
			:Character(level,power,speed,intel,att,def,health,mental)
		{
			char tem[100];
			cout<<"마법사를 생성합니다."<<endl;
			cout<<"캐릭터 이름 입력: ";
			cin>>tem;
			name=new char[strlen(tem)+1];
			strcpy(name,tem);

			cout<<"무기 입력: ";
			cin>>tem;
			weapon=new char[strlen(tem)+1];
			strcpy(weapon,tem);
		}
		void move(){
			cout<<"==>마법사 이동출력"<<endl;
			cout<<"이동했습니다."<<endl; 
		}
		
		void showInfo(){
			cout<<"==>마법사 정보출력"<<endl;
			cout<<"캐릭터 이름: "<<name<<", 무기 이름 : "<<weapon<<", 레벨 : "<<level<<", 힘 : " <<power<<", 민첩 : "<<speed<<", 지능 : "<<intel<<", 공격력 : "<<att<<", 방어력 : "<<def<<", 체력 : "<<health<<", 정신력 : "<<mental<<endl;
		}
		void attack(){
			cout<<"==>마법사 공격 출력"<<endl;
			cout<<"("<<weapon<<")마법을 걸었습니다."<<endl;

		}
		
		~Sorcerer(){
			cout<<weapon<<" 무기 삭제완료"<<endl;
			delete []weapon;
		}
		
};


int main() {
	srand(time(NULL));
	
	Warrior* warrior = new Warrior(1, 100, 50, 20, 5, 3, 80, 20);
	warrior->showInfo();
	warrior->move();
	warrior->attack();
	cout << endl;
	
	Archer* archer = new Archer(1, 50, 100, 20, 5, 3, 50, 50);
	archer->showInfo();
	archer->move();
	archer->attack();
	cout << endl;

	Sorcerer* sorcerer = new Sorcerer(1, 20, 50, 100, 5, 3, 20, 80);
	sorcerer->showInfo();
	sorcerer->move();
	sorcerer->attack();
	cout << endl;	
	cout<<endl;

	Bag<Character*> bag;
	cout<<endl<<"빈 Bag에대해 Size(),IsEmpty() 결과 출력"<<endl;
	cout << "Size of the bag:  " << bag.size() << endl;
	cout << "Is the bag empty? " << bag.IsEmpty() << endl;
	cout<<endl;

	cout<<"Push()3번 수행합니다."<<endl<<endl;
	bag.Push(warrior);
	bag.Push(archer);
	bag.Push(sorcerer);
	cout << "Size of the bag:  " << bag.size() << endl;
	cout << "Is the bag empty? " << bag.IsEmpty() << endl;
	cout<<"Element() 리턴된 객체에 대해 showInfo(),move(),attack() 결과 출력"<<endl;
	Character* element = bag.Element();
	element->showInfo();
	element->move();
	element->attack();
	cout<<endl;

	cout<<"Push()6번 수행합니다."<<endl<<endl;
	bag.Push(warrior);
	bag.Push(warrior);
	bag.Push(archer);
	bag.Push(archer);
	bag.Push(sorcerer);
	bag.Push(sorcerer);

	cout << "Size of the bag: " << bag.size() << endl;
	cout << "Is the bag empty? " << bag.IsEmpty() << endl;
	cout<<"Element() 리턴된 객체에 대해 showInfo(),move(),attack() 결과 출력"<<endl;

	Character* element2 = bag.Element();
	element2->showInfo();
	element2->move();
	element2->attack();
	
	cout<<endl<<"Pop()2번 수행합니다."<<endl<<endl;
	bag.Pop();
	bag.Pop();

	cout << "Size of the bag: " << bag.size() << endl;
	cout << "Is the bag empty? " << bag.IsEmpty() << endl;
	cout<<"Element() 리턴된 객체에 대해 showInfo(),move(),attack() 결과 출력"<<endl;

	Character* element3 = bag.Element();
	element3->showInfo();
	element3->move();
	element3->attack();
	cout<<endl;

	delete warrior;
	delete archer;
	delete sorcerer;

	return 0;
}
