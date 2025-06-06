﻿#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    int age;
    std::string email;
    std::string adress;

public:
    // Геттеры
    std::string getName() const {
        return name;
    }

    std::string getAdress() const {
        return adress;
    }

    int getAge() const {
        return age;
    }

    std::string getEmail() const {
        return email;
    }

    // Сеттеры
    void setName(const std::string& newName) {
        if (!newName.empty()) {
            name = newName;
        }
        else {
            std::cerr << "Error: Name cannot be empty!" << std::endl;
        }
    }

    void setAge(int newAge) {
        if (newAge >= 0 && newAge <= 120) {
            age = newAge;
        }
        else {
            std::cerr << "Error: Age must be between 0 and 120!" << std::endl;
        }
    }

    void setEmail(const std::string& newEmail) {
        if (newEmail.find('@') != std::string::npos) {
            email = newEmail;
        }
        else {
            std::cerr << "Error: Invalid email format!" << std::endl;
        }
    }

    void setAdress(const std::string& newAdress) {
        if (!(newAdress.empty())) {
            adress = newAdress;
        }
        else {
            std::cerr << "Error: Adress can't be empty!" << std::endl;
        }
    }

    // Метод для вывода информации о человеке
    void displayInfo() const {
        std::cout << "Name: " << name << ", Age: " << age << ", Email: " << email << ", Adress" << adress << std::endl;
    }
};

int main() {
    Person person;

    // Устанавливаем значения с помощью сеттеров
    person.setName("John Doe");
    person.setAge(25);
    person.setEmail("john.doe@example.com");
    person.setAdress("Rostov-on-Don");

    // Выводим информацию с помощью геттеров
    std::cout << "Name: " << person.getName() << std::endl;
    std::cout << "Age: " << person.getAge() << std::endl;
    std::cout << "Email: " << person.getEmail() << std::endl;
    std::cout << "Adress: " << person.getAdress() << std::endl;

    // Пытаемся установить некорректные значения
    person.setName(""); // Ошибка: имя не может быть пустым
    person.setAge(150); // Ошибка: возраст должен быть от 0 до 120
    person.setEmail("invalid-email"); // Ошибка: некорректный email
    person.setAdress("");

    // Выводим информацию о человеке
    person.displayInfo();

    return 0;
}
