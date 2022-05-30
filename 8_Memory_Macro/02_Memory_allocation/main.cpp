#include <iostream>
#include <memory>

struct Student{
    std::string name;
    double grade;
    inline static int counter = 0;
    Student(std::string name, double grade) : name(std::move(name)), grade(grade){
        std::cout << counter++ << " Student() with" << name << " " << grade << "\n";
    }

    ~Student() {
        std::cout << "~Student()" << "\n";
    }

};

int main() {
    {
        Student st1{"Ivan", 5};
    }
    {
        Student* st_ptr = new Student{"Ivan", 5};
        delete st_ptr;
    }
    {
        std::unique_ptr<Student> uptr = std::make_unique<Student>("Ivan", 5);

    }
    {
        char* data = new char[1024];
        Student* st_on_data = new (data) Student("Ivan", 5);
        std::cout << sizeof(Student) << " " << st_on_data << " "
            << reinterpret_cast<int*>(data) << "\n";
        st_on_data->~Student();
        //delete st_on_data;
        delete[] data;
    }
    {
        char data[1024];
        Student* st_on_data = new (data) Student("Ivan", 5);
        st_on_data->~Student();
        //delete st_on_data;
    }
    {
        void* data = operator new(1024);
        Student* st_on_data = new (data) Student("Ivan", 5);
        //std::cout << sizeof(Student) << " " << st_on_data << " " << reinterpret_cast<int*>(data) << "\n";
        st_on_data->~Student();
        //delete st_on_data;
        operator delete(data);
    }
    { //Феникс
        Student st("Petya",3);
        st.~Student();
        new (&st) Student("VasyaVasyaVasya",5);
        //16 байт  - это строка из 16 символов если длина <  16
        // или же первые 8 байт это указатель в дин. память
    }

    std::cout << sizeof(std::string) << "\n";
    return 0;
}
