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
  int getDamage() const { return damage; }
  WeaponType getType() const { return type; }

  void display() const {
    std::cout << "Оружие: " << name << ", Урон: " << damage << std::endl;
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
};

int main() {
  Weapon sword("Меч", 25, ONEHANDED);

  WeaponType swordType = sword.getType();
  if (swordType == ONEHANDED) {
    std::cout << sword.getName() << ": Одноручное оружие" << std::endl;
  } else if (swordType == TWOHANDED) {
    std::cout << sword.getName() << ": Двуручное оружие" << std::endl;
  } else if (swordType == BOW) {
    std::cout << sword.getName() << ": Лук" << std::endl;
  } else if (swordType == CROSSBOW) {
    std::cout << sword.getName() << ": Арбалет" << std::endl;
  }

  std::cout << std::endl;

  Player player2 = {2, "magistika", "password"};
  player2.display();

  MagicWeapon fireSword("Огненный меч", 30, ONEHANDED, 15);

  WeaponType fireSwordType = fireSword.getType();
  if (fireSwordType == ONEHANDED) {
    std::cout << "Тип: Одноручное оружие" << std::endl;
  }

  std::cout << "Имя: " << fireSword.getName() << std::endl;
  std::cout << "Основной урон: " << fireSword.getDamage() << std::endl;
  std::cout << "Магический урон: " << fireSword.getMagicDamage() << std::endl;

  MagicWeapon unknownMagicWeapon;
  std::cout << unknownMagicWeapon.getName() << std::endl;

  return 0;
}
