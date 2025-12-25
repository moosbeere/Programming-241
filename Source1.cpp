#include <iostream>
#include "Orugie.h"
#include "Characteristic.h"
#include "MyMath.h"
using namespace std;

int MyMath::counter = 0;

// 1.  Создайте класс оружия со следующими полями: название оружия, наносимый урон и его вес.
class Orugie1 {
    //1.  Сделайте все поля в классе оружия закрытыми.
public:
    string name;
    float uron;
    float ves;
    // 3. Создайте динамический объект оружия и выведите его переменные в консоль.
    //int* dlina = new int(5);

    // 2.  Создайте конструктор, принимающий 3 параметра и использующий их для инициализации переменных класса.
    //Orugie(string name, float uron, float ves) : name(name), uron(uron), ves(ves) {}

    // 3.  Создайте конструктор без параметров, который будет вызывать конструктор из предыдущего пункта, передавая туда какие-то значения по умолчанию.
    //Orugie() : Orugie("Mech", 5, 3) {}


    //void setClass(Orugie *o) {
        //cout << "lol" << endl;
    //}

    //1.  Создайте деструктор для класса оружия, в котором выведите в консоль все данные оружия и сообщение о том, что он удаляется.
    //~Orugie() {
        // cout << "Объекты:" << name << ", " << uron << ", " << ves << ", " << *dlina << " " << "Уничтожаться" << endl;
        //delete dlina;
    //}
    //4. Запустив программу и убедитесь, что в обоих случаях вызывается деструктор (разумеется, про delete для динамических объектов не нужно забывать).

    // 5.  Добавьте метод в класс оружия, принимающий в качестве параметра максимально допустимый вес для оружия, и который возвращает true или false. Если максимально допустимый вес меньше, чем вес оружия, то возвращается true, а иначе false. Своего рода, это проверка сможет ли поднять некто данное оружие или нет.
    //bool maxVes(float max_ves) {
        //return max_ves < ves;
    //}

    //6.  Добавьте метод, принимающий объект оружия, и возвращающий суммарный вес текущего объекта и переданного.
    //float peredacha(Orugie o) {
    //    return (this->ves + o.ves);
    //    //return peredacha(o.ves);
    //}

    //float peredacha(float ves_per) {
    //    cout << "lol" << endl;
    //    return this->ves + ves_per;
    //}
};

int main() {
    //setlocale(LC_ALL, "Russian");
    //4.  Создайте 2 объекта, используя конструктор с параметрами и без.
    //5.  Выведите значения всех переменных обоих экземпляров в консоль.
    //Orugie o;
    //cout << o.name << " " << o.uron << " " << o.ves << endl;
    //Orugie klinok = Orugie("Klinok", 3, 2);
    //cout << klinok.name << " " << klinok.uron << " " << klinok.ves << endl;

    //Orugie mech;
    //mech.setClass(&klinok);
    // 5. 
    //cout << mech.maxVes(6) << endl;

    //cout << klinok.peredacha(mech);
    //return 0;

    Orugie o("Klinok", 2, 3);
    cout << o.getName() << o.getUron() << o.getVes() << endl;
    Characteristic k(10);

    //8.  Проверьте созданный функционал, создав оружие, экземпляр класса Characteristic и вызвав его метод GetDamage.
    cout << k.GetDamage(o);
    cout << MyMath::Add(2, 3) << " " << MyMath::Sub(2, 3) << " " << MyMath::Mult(2, 3) << " " << MyMath::Div(2, 3) << " " << MyMath::counter << endl;

}