#include <iostream>
#include <vector>

using namespace std;

class Car {
public:
    Car(string brand, string model, int year)
        : brand(brand), model(model), year(year) {}

    virtual void display_info() const {
        cout << year << " " << brand << " " << model << endl;
    }

protected:
    string brand;
    string model;
    int year;
};

class Manual : public Car {
public:
    Manual(string brand, string model, int year, string transmission_type)
        : Car(brand, model, year), transmission_type(transmission_type) {}

    void display_info() const override {
        Car::display_info();
        cout << "Transmission Type: Manual" << endl;
    }

private:
    string transmission_type;
};

class Automatic : public Car {
public:
    Automatic(string brand, string model, int year, string transmission_type)
        : Car(brand, model, year), transmission_type(transmission_type) {}

    void display_info() const override {
        Car::display_info();
        cout << "Transmission Type: Automatic" << endl;
    }

private:
    string transmission_type;
};

class CarStore {
public:
    void add_car(const Car& car) {
        cars.push_back(car);
    }

    void display_all_cars_info() const {
        for (const auto& car : cars) {
            car.display_info();
        }
    }

private:
    vector<Car> cars;
};

int main() {
    Automatic bmw_automatic("BMW", "X7", 2022, "Automatic");
    Manual audi_manual("Audi", "A4", 2024, "Manual");

    CarStore car_store;
    car_store.add_car(bmw_automatic);
    car_store.add_car(audi_manual);

    car_store.display_all_cars_info();
}
