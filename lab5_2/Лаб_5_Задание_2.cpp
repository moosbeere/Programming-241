#include <iostream>

using namespace std;
enum class weaponType {
	ONEHANDED,
	TWOHANDED,
	BOW,
	CROSSBOW,
	NON
};
enum class weaponIdc {
	a,
	b
};

class weapon {
private:
	weaponType type;
	weaponIdc idc;
	string name;
	float damage, weight;
public:
	weapon(string tnam = "NON", float tdam = 0, float twei = 0, weaponType ttyp = weaponType::NON, weaponIdc tidc = weaponIdc::a) {
		this->name = tnam;
		this->damage = tdam;
		this->weight = twei;
		switch (ttyp) {
		case weaponType::ONEHANDED:
			this->type = weaponType::ONEHANDED; break;
		case weaponType::TWOHANDED:
			this->type = weaponType::TWOHANDED; break;
		case weaponType::BOW:
			this->type = weaponType::BOW; break;
		case weaponType::CROSSBOW:
			this->type = weaponType::CROSSBOW; break;
		default:
			this->type = weaponType::NON; break;
		}
		switch (tidc) {
		case weaponIdc::a:
			this->idc = weaponIdc::a; break;
		case weaponIdc::b:
			this->idc = weaponIdc::b; break;
		}
		cout << "\nTHE WEAPON HAS DESCENDED;\n";
	}

	~weapon();
	string getName();
	float getWeight();
	virtual float getDamage();
	weaponType getType();
	weaponIdc getIdc();


	virtual void attack() = 0;
};

class magicWeapon : public weapon {
private:
	float addDamage;
public:
	magicWeapon(string tnam, float tdam, float twei, weaponType ttyp, weaponIdc tidc, float tadd)
		: weapon(tnam, tdam, twei, ttyp, tidc), addDamage(tadd) {
	};
	magicWeapon() : magicWeapon("EXCALIBUR", 25.7, 237, weaponType::BOW, weaponIdc::b, 25) {};
	float getAddDamage();
	float getDamage();
	void attack() override;
};

weapon::~weapon() {
	cout << "\nTHE WEAPON HAS BEEN OBLITERATED;\n";
}

class shotWeapon : public weapon {
private:
	bool exists;
public:
	shotWeapon(string tnam = "NON", float tdam = 0, float twei = 0, weaponType ttyp = weaponType::NON, weaponIdc tidc = weaponIdc::a, bool texi = 0) :
		weapon(tnam, tdam, twei, ttyp, tidc), exists(texi) {
	};
	bool getExists();
	void attack() override;
};

string weapon::getName() {
	return name;
}
float weapon::getDamage() {
	return damage;
}
float weapon::getWeight() {
	return weight;
}
weaponType weapon::getType() {
	return type;
}
weaponIdc weapon::getIdc() {
	return idc;
}
float magicWeapon::getAddDamage() {
	return magicWeapon::addDamage;
}
float magicWeapon::getDamage() {
	return weapon::getDamage() + addDamage;
}
bool shotWeapon::getExists() {
	return exists;
}
float compare(float dam1, float dam2) {
	return dam1 > dam2 ? dam1 : dam2;
}
void magicWeapon::attack() {
	cout << "\nАтакуем магическим оружием\n";
}
void shotWeapon::attack() {
	if (getExists() == false) {
		cout << "Атакуем одноразовым оружием" << endl;
		this->exists = true;
	}
	else {
		cout << "Оружие уже было использовано" << endl;
	}
};


template <class T>

class weaponHand
{
private:
	T left;
	T right;
public:
	weaponHand(T tleft, T tright) : left(tleft), right(tright) {};
	T getLeftType()
	{
		return left;
	}
	T getRightType()
	{
		return right;
	}
	void setleftType(T type)
	{
		left = type;
	}
	void setrightType(T type)
	{
		right = type;
	}
};




int main() {
	setlocale(LC_ALL, "Russian");

	magicWeapon b;
	shotWeapon a;
	shotWeapon c = { "NON", 12, 200, weaponType::ONEHANDED, weaponIdc::a, 1 };
	b.attack();
	a.attack();
	a.attack();

	weaponHand<int> h(11, 12);
	weaponHand<weaponType> t(weaponType::CROSSBOW, weaponType::ONEHANDED);
	cout << h.getLeftType() << " " << h.getRightType() << endl;

	weaponType d = t.getLeftType();
	if (d == weaponType::CROSSBOW) {
		cout << "Тип в левой руке - CROSSBOW" << endl;
	}
}