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
};

void compare(Weapon a, Weapon b) {
  std::cout << "Сравнение " << a.getName() << " и " << b.getName() << std::endl;
  std::cout << a.getName() << " > " << b.getName() << " = "
            << (a > b ? "true" : "false") << std::endl;
  std::cout << a.getName() << " < " << b.getName() << " = "
            << (a < b ? "true" : "false") << std::endl;
}

int main() {
  Weapon sword("Меч", 25, ONEHANDED);
  Weapon axe("Топор", 35, TWOHANDED);
  Weapon bow("Лук", 20, BOW);

  MagicWeapon fireSword("Огненный меч", 30, ONEHANDED, 15);
  MagicWeapon iceAxe("Ледяной топор", 25, TWOHANDED, 20);
  MagicWeapon unknownMagicWeapon;

  Player player2 = {2, "magistika", "password"};
  player2.display();

  std::cout << "Имя: " << fireSword.getName() << std::endl;
  std::cout << "Урон: " << fireSword.getDamage() << std::endl;
  std::cout << "Магический урон: " << fireSword.getMagicDamage() << std::endl;

  compare(sword, axe);
  compare(sword, fireSword);
  compare(fireSword, iceAxe);

  return 0;
}
