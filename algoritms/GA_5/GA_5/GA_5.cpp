//#include <iostream>
//using namespace std;
//#include <string>
//
////1
//class orujie {
//public:
//	float damage;
//	string name;
//	float weight;
//	bool prov;
//	//2.6
//	int allowed_weight = 50;
//	
//	//2
//	orujie(float d, string n, float w, int a_w) {
//		damage = d;
//		name = n;
//		weight = w;
//		allowed_weight = a_w;
//
//		if (w <= a_w) {
//			prov = true;
//		}
//		else {
//			prov = false;
//		}
//	}
//
//	//2.6 uslovie vesa ot dopustimogo
//
//
//
//	//3
//	orujie() : orujie(10, "wrist", 1, 50) {};
//
//	//  2 chast destructor
//	~orujie() {
//		cout << damage<< name<< weight ;
//		cout << " уничтожаeтся;      "<< endl;
//
//	}
//	
//	
//
//};
//
//
//
//
//int main() {
//	//4
//	//4
//	orujie crook = orujie(40, "crook", 2, 50);
//	orujie wrist = orujie();
//
//
//	
//	
//	
//	cout<<"Weight of the weapon = " << crook.weight << "\n";
//	cout <<"name of the weapon:" << crook.name << "\n";
//	cout <<"damage from 1 hit:" << crook.damage << "\n";
//	
//
//	cout << "2 orujie";
//	cout << "Weight of the weapon = " << wrist.weight << "\n";
//	cout << "name of the weapon:" << wrist.name << "\n";
//	cout << "damage from 1 hit:" << wrist.damage << "\n";
//	cout << endl;
//
//	//2.3 ukazatel na object
//	cout << "Destuctors:" << endl;
//
//	orujie* orujie2 = new orujie(27.5, "skelton", 45, 50);
//	delete orujie2;
//}