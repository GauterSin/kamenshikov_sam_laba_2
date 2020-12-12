#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;


// В public отправляюься все наши функции
// в Private отправляются все локальные переменные

class Truba{
	public:
        vector<string> id = {"ID_1", "ID_2", "ID_3"};		
		vector<string> repairs = {"В_ремонте", "Исправна", "Исправна"};

		// добавляем трубу
		void show(){
			cout<<"================"<<endl;
			for (int i = 0; i<=(id.size() - 1);i++){
				cout<<id[i]<<": ";
				cout<<repairs[i]<<endl;
			}
		}
		void add(){
			
			cout<<"================"<<endl;
			string scales;
			cout<<"Ремонтируется или нет?"<<endl;
			cout<<"1.В ремонте"<<endl;
			cout<<"2.Исправна"<<endl;
			cin>>scales;
			cout<<""<<endl;

			if (scales == "1"){
				repairs.push_back("В_ремонте");
				
				string name;
		        	name = "ID_" + to_string(id.size() + 1);
				id.push_back(name);
			}
			if (scales == "2"){
				repairs.push_back("Исправна");
				
				string name;
		        	name = "ID_" + to_string(id.size() + 1);
				id.push_back(name);
			}
			if((scales != "1") and (scales != "2")){
				cout<<"Ошибочка вышла((((((((("<<endl;
			}

		};
		// удаляем трубу
		void del(){
			cout<<"================"<<endl;
			for (int i = 0; i<=(id.size()-1); i++){
				cout<<id[i]<< " ";
			}
			cout<<""<<endl;
			string name;	
			cout<<"Введите ID трубы(необходимо ввести только цифру) = ";
			cin>>name;
			cout<<""<<endl;
			auto iter_1 = id.cbegin();
			auto iter_2 = repairs.cbegin();
			for (int i=0; i<=(id.size()-1);i++){
				if (name == id[i]){
					id.erase(iter_1 + i - 1);
					repairs.erase(iter_2 + i - 1);
					break;
				}
			}

		};
		// редактирую количество труб
		void edit(){
			int wall = true;
			string scales;
			string name;
			cout<<"================"<<endl;
			while (wall == true){
				cout<<"Введите ID_(необходимо ввести только цифру"<<endl;
				cout<<"Если хотите закончить введите exit"<<endl;
				cin>>scales;
				cout<<""<<endl;
				name = "ID_" + scales;
				if (scales == "exit"){
					wall = false;
				}else{
					cout<<"Введите изменение: "<<endl;
					cout<<"1.В_ремонте"<<endl;
					cout<<"2.Исправна"<<endl;
					cout<<"Ввод: ";
					cin>>scales;
					cout<<""<<endl;
					if (scales == "1"){
						scales = "В_ремонте";
						for (int i = 0;i<=(id.size()-1);i++){
							if (name == id[i]){
									repairs[i] = scales;
									cout<<id[i]<<": "<<repairs[i]<<endl;
									break;
							}
						
						}			
					}
					if (scales == "2"){
						scales = "Исправна";
						for (int i = 0;i<=(id.size()-1);i++){
							if (name == id[i]){
								repairs[i] = scales;
								cout<<id[i]<<": "<<repairs[i]<<endl;
								break;
							}
						}
					}	
				}
			}	
		};
		// поиск труб по названию/признаку
		void search(){
			cout<<"================"<<endl;
			string scales;
			cout<<"1.Поиск труб по признаку 'В_ремонте'"<<endl;
			cout<<"2.Поиск по названию"<<endl;
			cin>>scales;
			cout<<""<<endl;
			if (scales == "1"){
				cout<<"1.Вывести все не работающие трубы"<<endl;
				cout<<"2.Вывести все работающие трубы"<<endl;
				cin>>scales;
				cout<<""<<endl;
				if(scales == "1"){
					scales = "В_ремонте";
					for (int i = 0; i<=(id.size()-1);i++){
						if (scales == repairs[i]){
							cout<<id[i]<< " ";
						}
					}
					cout<<""<<endl;
				}else{
					scales = "Исправна";
					for (int i = 1;i<=(id.size()-1);i++){
						if (scales == repairs[i]){
							cout<<id[i]<<" ";
						}
					}
					cout<<""<<endl;
				}
				
			}else{
				cout<<"Введите ID трубы(необходимо ввести только цифру)"<<endl;
				cin>>scales;
				cout<<""<<endl;
				scales = "ID_" + scales;

				for(int i = 0;i<=(id.size()-1);i++){
					if (scales == id[i]){
						cout<<id[i]<<": "<<repairs[i]<<endl;
						break;
					}
				}
			}
		};
};

class Ks{
	public:
		vector<string> id = {"ID_1", "ID_2", "ID_3"};		
		vector<double> shop = {10, 0, 20};


		// добавляем кс
		void show(){
			cout<<"================"<<endl;
			for (int i = 0; i<=(id.size() - 1);i++){
				cout<<id[i]<<": ";
				cout<<shop[i]<<endl;
			}
		}
		void add(){
			
			cout<<"================"<<endl;
			double scales;
			cout<<"Ввeдите кол-во не работающих цехов"<<endl;
			cin>>scales;
			if(cin.fail()){
				cin.clear();
				cin.ignore(100000, '\n');
				cout<<"Mistake\n"<<endl; 
			}else{	
				cout<<""<<endl;	
				// Оброботчик ошибок надо			
				shop.push_back(scales);
				string name;
	        		name = "ID_" + to_string(id.size() + 1);
				id.push_back(name);
				}
			};		
		// удаляем кс
		void del(){
			cout<<"================"<<endl;
			for(int i = 0; i<=(id.size()-1); i++){
				cout<<id[i]<< " ";
			}
			cout<<""<<endl;
			string name;	
			cout<<"Введите ID кс (необходимо ввести только цифру) = ";
			cin>>name;
			cout<<""<<endl;
			auto iter_1 = id.cbegin();
			auto iter_2 = shop.cbegin();
			for (int i=0; i<=(id.size()-1);i++){
				if (id[i] == name){
					id.erase(iter_1 + i - 1);
					shop.erase(iter_2 + i - 1);
					break;
				}
			}

		};

		// поиск по количеству цехов
		void search(){
			cout<<"================"<<endl;
			string scales;
			cout<<"1.Поиск по количеству цехов в работе"<<endl;
			cout<<"2.Поиск по названию"<<endl;
			cin>>scales;
			cout<<""<<endl;
			if (scales == "1"){

				double num;
				// оброботчик ошибок
				cout<<"Введите проценты "<<endl;
				cin>>num;
				if(cin.fail()){
					cin.clear();
					cin.ignore(100000, '\n');
					cout<<"Mistake\n"<<endl; 
				}else{
					cout<<""<<endl;
					for (int i = 0;i<=(id.size()-1);i++){
						if (num == shop[i]){
							cout<<id[i]<<endl;
						}
					}
				}
			}else{
				cout<<"Введите ID трубы(необходимо ввести только цифру)"<<endl;
				cin>>scales;
				cout<<""<<endl;
				scales = "ID_" + scales;

				for(int i = 0;i<=(id.size()-1);i++){
					if (scales == id[i]){
						cout<<id[i]<<": ";
						cout<<shop[i]<<endl;

						break;
					}
				}
			}
		};
};



int main()
{
	
	setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
	
	Truba truba;
	Ks ks;
	bool wall = true;
	string sms;
	while (wall == true){
		cout<<"================"<<endl;
		cout<<"1.Добавить трубу"<<endl;
		cout<<"2.Удалить трубу"<<endl;
		cout<<"3.Редактировать трубу"<<endl;	
		cout<<"4.Поиск труб"<<endl;
		cout<<"5.Показать трубы"<<endl;
		cout<<"================"<<endl;
		cout<<"6.Добавить кс"<<endl;
		cout<<"7.Удалить кс"<<endl;
		cout<<"8.Поиск кс"<<endl;
		cout<<"9.Показать кс"<<endl;
		cout<<"0.Выход"<<endl;
		cout<<""<<endl;
		cout<<"Введите цифру: ";
		cin>>sms;
		cout<<""<<endl;
		if (sms == "1"){
			truba.add();
		}

		if (sms == "2"){
			truba.del();
		}

		if (sms == "3"){
			truba.edit();
		}
	
		if (sms == "4"){
			truba.search();
		}
	
		if (sms == "5"){
			truba.show();
		}
	
		if (sms == "6"){
			ks.add();
		}
	
	
		if (sms == "7"){
			ks.del();
		}
	
		if (sms == "8"){
			ks.search();
		}
	
		if (sms == "9"){
			ks.show();
		}
	
		if (sms == "0"){
			wall = false;
		}
	}
                ofstream outf("laba_2_data.txt");
                outf << "Truba:"<< endl;
                for(int i = 0; i <= (truba.id.size() - 1); i++){
                  outf << "id = '" << truba.id[i] <<"' ";
                  outf << "rep = " << truba.repairs[i] <<endl;
                };
                outf << "Ks:" << endl;
                for(int i = 0; i <= (ks.id.size() - 1); i++){
                  outf << "id = '" << ks.id[i] <<"' ";
                  outf << "shop = " << ks.shop[i] << endl;
                };
                outf.close();

}
