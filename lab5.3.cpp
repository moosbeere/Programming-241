#include <iostream>
#include <string>

enum WeaponType { ONEHANDED, TWOHANDED, BOW, CROSSBOW };

class Weapon {
private:
  std::string name;
  int damage;
  WeaponType type;

public:
  Weapon(std::string name, int damage, WeaponType type)
      : name(name), damage(damage), type(type) {}

  Weapon() : name("Стандартный меч"), damage(8), type(ONEHANDED) {}

  std::string getName() const { return name; }
  virtual int getDamage() const { return damage; }
  WeaponType getType() const { return type; }

  void display() const {
    std::cout << "Оружие: " << name << ", Урон: " << getDamage() << std::endl;
  }

  virtual bool operator>(const Weapon &other) const {
    return this->getDamage() > other.getDamage();
  }

  virtual bool operator<(const Weapon &other) const {
    return this->getDamage() < other.getDamage();
  }

  virtual void Attack() = 0;
};

struct Player {
  int id;
  std::string login;
  std::string password;

  void display() const {
    std::cout << "ID: " << id << " Login: " << login
              << " Password: " << password << std::endl;
  }
};

class MagicWeapon : public Weapon {
private:
  int magicDamage;

public:
  MagicWeapon() : Weapon(), magicDamage(0) {}

  MagicWeapon(std::string name, int damage, WeaponType type, int magicDamage)
      : Weapon(name, damage, type), magicDamage(magicDamage) {}

  int getMagicDamage() const { return magicDamage; }

  int getDamage() const override { return Weapon::getDamage() + magicDamage; }

  bool operator>(const Weapon &other) const override {
    return this->getDamage() > other.getDamage();
  }

  bool operator<(const Weapon &other) const override {
    return this->getDamage() < other.getDamage();
  }

  void Attack() override {
    std::cout << "Атакуем магическим оружием: " << getName();
  }
};

class OnetimeWeapon : public Weapon {
private:
  bool used;

public:
  OnetimeWeapon(std::string name, int damage, WeaponType type)
      : Weapon(name, damage, type), used(false) {}

  OnetimeWeapon() : Weapon("Одноразовый нож", 10, ONEHANDED), used(false) {}

  void Attack() override {
    if (used) {
      std::cout << "Оружие уже было использовано: " << getName() << std::endl;
    } else {
      std::cout << "Атакуем одноразовым оружием: " << getName();
      used = true;
    }
  }
};

template <typename TLeft, typename TRight> class DualWeapon {
private:
  TLeft leftHand;
  TRight rightHand;

public:
  DualWeapon(const TLeft &left, const TRight &right)
      : leftHand(left), rightHand(right) {}

  DualWeapon() : leftHand(TLeft()), rightHand(TRight()) {}

  TLeft getLeftHand() const { return leftHand; }
  TRight getRightHand() const { return rightHand; }

  void setLeftHand(const TLeft &weapon) { leftHand = weapon; }
  void setRightHand(const TRight &weapon) { rightHand = weapon; }
};

int main() {
  // Ошибка
  // Weapon weapon("Меч", 25, ONEHANDED);

  MagicWeapon fireSword("Огненный меч", 30, ONEHANDED, 15);
  MagicWeapon iceAxe("Ледяной топор", 25, TWOHANDED, 20);
  MagicWeapon unknownMagicWeapon;

  Player player2 = {2, "magistika", "password"};
  player2.display();

  fireSword.Attack();
  iceAxe.Attack();
  unknownMagicWeapon.Attack();

  OnetimeWeapon throwingKnife("Метательный нож", 15, ONEHANDED);

  std::cout << "Первая атака: ";
  throwingKnife.Attack();

  std::cout << "Вторая атака: ";
  throwingKnife.Attack();

  MagicWeapon magicSword("Волшебный меч", 20, ONEHANDED, 10);
  OnetimeWeapon disposableAxe("Одноразовый топор", 25, TWOHANDED);

  DualWeapon<MagicWeapon, OnetimeWeapon> warriorWeapons(magicSword,
                                                        disposableAxe);

  warriorWeapons.getLeftHand().Attack();
  warriorWeapons.getRightHand().Attack();
  warriorWeapons.getRightHand().Attack();

  int leftWeaponId = 1001;  // ID для меча
  int rightWeaponId = 1002; // ID для щита

  DualWeapon<int, int> weaponIds(leftWeaponId, rightWeaponId);
  std::cout << "Левая рука: ID " << weaponIds.getLeftHand() << std::endl;
  std::cout << "Правая рука: ID " << weaponIds.getRightHand() << std::endl;

  weaponIds.setLeftHand(1003);
  weaponIds.setRightHand(1004);
  std::cout << "Левая рука: ID " << weaponIds.getLeftHand() << std::endl;
  std::cout << "Правая рука: ID " << weaponIds.getRightHand() << std::endl;

  return 0;
}
