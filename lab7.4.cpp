#include <iostream>
#include <map>
#include <string>
#include <vector>

void printVector(const std::vector<float> &vec) {
  for (size_t i = 0; i < vec.size(); ++i) {
    std::cout << vec[i];
    if (i < vec.size() - 1) {
      std::cout << ", ";
    }
  }
  std::cout << std::endl;
}

// class Settings {
// private:
//   std::map<std::string, std::string> settingsMap;
//
// public:
//   void Add(const std::string &key, const std::string &value) {
//     settingsMap[key] = value;
//   }
//
//   std::string Get(const std::string &key) { return settingsMap[key]; }
//
//   void Print() const {
//     if (settingsMap.empty()) {
//       std::cout << "(пусто)" << std::endl;
//       return;
//     }
//     for (const auto &pair : settingsMap) {
//       std::cout << pair.first << " = " << pair.second << std::endl;
//     }
//   }
// };

class Settings {
private:
  static std::map<std::string, std::string> settingsMap; // статическое поле

public:
  static void Add(const std::string &key, const std::string &value) {
    settingsMap[key] = value;
  }

  static std::string Get(const std::string &key) { return settingsMap[key]; }

  static void Print() {
    if (settingsMap.empty()) {
      std::cout << "(пусто)" << std::endl;
    }
    for (const auto &pair : settingsMap) {
      std::cout << pair.first << " = " << pair.second << std::endl;
    }
  }

  static void Clear() { settingsMap.clear(); }
};

std::map<std::string, std::string> Settings::settingsMap; // Инициализация

int main() {
  std::vector<float> floatVector;

  floatVector.push_back(1.5f);
  floatVector.push_back(2.7f);
  floatVector.push_back(3.14f);
  floatVector.push_back(4.2f);
  floatVector.push_back(5.0f);

  printVector(floatVector);

  floatVector.insert(floatVector.begin() + 3, 9.8f);

  printVector(floatVector);

  floatVector.pop_back();

  printVector(floatVector);

  // Settings settings;
  //
  // settings.Add("lang", "Russian");
  //
  // settings.Print();
  //
  // std::cout << "'lang': " << settings.Get("lang") << std::endl;
  //
  // settings.Add("auto_save", "true");
  // settings.Print();

  Settings::Add("volume", "75");

  Settings::Print();

  std::cout << "'volume': " << Settings::Get("volume") << std::endl;

  Settings::Add("quality", "high");
  Settings::Print();

  Settings::Clear();
  Settings::Print();

  return 0;
}
