#pragma once
#include <iostream>
using namespace std;

class Orugie
{

    //public:
      //  string name;
        //float uron;
        //float ves;
    private:
        string name;
        float uron;
        float ves;
    public:
        friend class Characteristic;
    //2.  Добавьте GET-методы для всех полей.
        string getName();
        float getUron();
        float getVes();

    //3.  Сделайте SET-метод для наносимого урона.
        void setUron(float ur);
        // 3. Создайте динамический объект оружия и выведите его переменные в консоль.
        //int* dlina = new int(5);

        // 2.  Создайте конструктор, принимающий 3 параметра и использующий их для инициализации переменных класса.
        Orugie(string name, float uron, float ves); // : name(name), uron(uron), ves(ves) {}

        // 3.  Создайте конструктор без параметров, который будет вызывать конструктор из предыдущего пункта, передавая туда какие-то значения по умолчанию.
        Orugie(); //: Orugie("Mech", 5, 3) {}
        //1.  Создайте деструктор для класса оружия, в котором выведите в консоль все данные оружия и сообщение о том, что он удаляется.
        //~Orugie() {
            // cout << "Объекты:" << name << ", " << uron << ", " << ves << ", " << *dlina << " " << "Уничтожаться" << endl;
            //delete dlina;
        //}
        //4. Запустив программу и убедитесь, что в обоих случаях вызывается деструктор (разумеется, про delete для динамических объектов не нужно забывать).

        // 5.  Добавьте метод в класс оружия, принимающий в качестве параметра максимально допустимый вес для оружия, и который возвращает true или false. Если максимально допустимый вес меньше, чем вес оружия, то возвращается true, а иначе false. Своего рода, это проверка сможет ли поднять некто данное оружие или нет.
        bool maxVes(float max_ves);//{
            //return max_ves < ves;
        //}

        //6.  Добавьте метод, принимающий объект оружия, и возвращающий суммарный вес текущего объекта и переданного.
        float peredacha(Orugie o); //{
        //    return (this->ves + o.ves);
        //    return peredacha(o.ves);
        

        float peredacha(float ves_per); //{
        //    return this->ves + ves_per;
        //}


        //Orugie(const string& name, float uron, float ves)
        //    : name(name), uron(uron), ves(ves)
        //{
        //}
};

