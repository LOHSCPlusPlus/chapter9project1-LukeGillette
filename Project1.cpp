#include<iostream>
#include<fstream>
using namespace std;

struct CarType{
// this is the actual struct for the car info //
  CarType();
  enum{MAX_CHAR_LENGTH = 500};
  char Name[MAX_CHAR_LENGTH];
  double MPG;
  int Cylinders;
  double Displacement;
  double Horsepower;
  double Weight;
  double Acceleration;
  int Model;
  char Origin[MAX_CHAR_LENGTH];
  bool ValidEntry;
};
CarType::CarType(){
  for(int index = 0; index < MAX_CHAR_LENGTH;index++ ){
  Name[index] = 0;
  Origin[index] = 0;
  }
  MPG = 0;
  Cylinders = 0;
  Displacement = 0;
  Horsepower = 0;
  Weight = 0;
  Acceleration = 0;
  Model = 0;
  ValidEntry = false;
    }
  
const int MaxCars = 500;
CarType readCar(ifstream &inFile){
  CarType car;
  inFile.get(car.Name, CarType::MAX_CHAR_LENGTH,';');
  inFile.ignore(100,';');
  inFile >> car.MPG;
  inFile.ignore(100,';');
  inFile >> car.Cylinders;
  inFile.ignore(100,';');
  inFile >> car.Displacement;
  inFile.ignore(100,';');
  inFile >> car.Horsepower;
  inFile.ignore(100,';');
  inFile >> car.Weight;
  inFile.ignore(100,';');
  inFile >> car.Acceleration;
  inFile.ignore(100,';');
  inFile >> car.Model;
  inFile.ignore(100,';');
  inFile >> car.Origin;
  inFile.ignore(100,'\n');
  car.ValidEntry = !inFile.eof();
  return car;
}

int readCars(CarType cars[]){
  ifstream CarFile("cars.txt");
  int numCars = 0;
  while(CarFile.peek() != EOF){
    cars[numCars] = readCar(CarFile);
    numCars++;
  }
  return numCars;
}
void PrintCar(CarType car){
  cout << car.Name << ";" << car.MPG << ";" << car.Cylinders << ";" << car.Displacement << ";" << car.Horsepower << ";" << car.Weight << ";" << car.Acceleration << ";" << car.Model << ";" << car.Origin << ";" << endl;
}
void PrintCars(CarType cars[]){
for(int index = 0; index < MaxCars; index++){
  if (cars[index].ValidEntry == true){
  cout << "index " <<  index << " ";
  PrintCar (cars [index]);
    }
}
  }

int readInt(const char prompt[]){
    int temp = 0;
    cout << prompt;
    cin >> temp;
    while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << prompt;
        cin >> temp;
    }
    return temp;
}

double readdouble(const char prompt[]){
    double temp = 0;
    cout << prompt;
    cin >> temp;
    while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << prompt;
        cin >> temp;
    }
    return temp;
}
void addCar(CarType cars[]){
  for(int index = 0; index < MaxCars; index++){
    if (cars[index].ValidEntry == false){
  cout << "Car Name" << endl;
cin.getline(cars[index].Name,CarType::MAX_CHAR_LENGTH);
  cars[index].MPG = readdouble("enter the cars MPG");
  cars[index].Cylinders = readInt("enter the cars Cylinder value");
  cars[index].Displacement = readdouble("enter the Displacement value");
  cars[index].Horsepower = readdouble("enter the cars Horsepower");
  cars[index].Weight = readdouble("enter the cars weight");
  cars[index].Acceleration = readdouble("enter the cars Acceleration");
  cars[index].Model = readInt("enter the cars Model");
      cout << "enter the cars origin" << endl;
  cin >> cars[index].Origin;
    return;
}
    }
  cout << "car data base is full" << endl;
  }

void PrintCarsbyorgin(CarType cars[]){
  string input;
  cout << "sort by region: ";
  cin >> input;
for(int index = 0; index < MaxCars; index++){
  if (cars[index].Origin == input){
  cout << "index " <<  index << " ";
  PrintCar(cars[index]);
    }
}
  }

void removeCars(CarType cars[]){
  int index = 0;
  while(index < 0 || index > 500){
  index = readInt("enter the car number");
    }
  cars[index].ValidEntry = false;
}


void menu(){
  CarType Car[MaxCars];
  readCars(Car);
   string option;
  cout << "Car File:" << endl << "List" << endl << "Remove" << endl << "Add" << endl << "Car orgin" << endl << "Quit" << endl;
  cin >> option;
  if (option == "List"){
    PrintCars(Car);
    cout << "type 'quit' to return to main menu" << endl;
    cin >> option;
  if (option == "quit"){
      return;
      }
    }
  if (option == "Remove"){
    removeCars(Car);
    cout << "type 'quit' to return to main menu" << endl;
    cin >> option;
  if (option == "quit"){
    return;
    }
  }
  if (option == "Add"){
    addCar(Car);
    cout << "type 'quit' to return to main menu" << endl;
    cin >> option;
  if (option == "quit"){
    return;
    }
  }
  if (option == "Car orgin"){
    PrintCarsbyorgin(Car);
    cout << "type 'quit' to return to main menu" << endl;
    cin >> option;
  if (option == "quit"){
    return;
    }
  }
  if (option == "quit"){
      return
  }
  else{
    cout << "not a valid option" << endl;
    return
  }
}
  

int main() {
  menu();
}