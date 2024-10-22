#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;

class DATA_CARRIER {
protected:
    double sizeInGB;

public:
    DATA_CARRIER(double size) : sizeInGB(size) {}

    virtual double area() const 
    {
        return sizeInGB; 
    }

    virtual void display(ostream& out) const
    {
        out << "Носій даних: \n";
        out << "Розмір: " << sizeInGB << " ГБ\n";
    }
};

// Похідний клас HARD_DRIVE (жорсткий диск)
class HARD_DRIVE : public DATA_CARRIER {
private:
    int cylinders; // Кількість циліндрів
    int tracks;    // Кількість доріжок
    int sectors;   // Кількість секторів
    string brand;  // Марка жорсткого диска

public:
    HARD_DRIVE(double size, int cyl, int trk, int sct, string br)
        : DATA_CARRIER(size), cylinders(cyl), tracks(trk), sectors(sct), brand(br) {}

    void display(ostream& out) const override
    {
        DATA_CARRIER::display(out);
        out << "Кількість циліндрів: " << cylinders << "\n"
            << "Кількість доріжок: " << tracks << "\n"
            << "Кількість секторів: " << sectors << "\n"
            << "Марка: " << brand << "\n";
    }
};

// Похідний клас OPTICAL_DISK (оптичний диск)
class OPTICAL_DISK : public DATA_CARRIER {
private:
    int cylinders; // Кількість циліндрів
    int tracks;    // Кількість доріжок
    int sectors;   // Кількість секторів
    string brand;  // Марка оптичного диска

public:
    OPTICAL_DISK(double size, int cyl, int trk, int sct, string br)
        : DATA_CARRIER(size), cylinders(cyl), tracks(trk), sectors(sct), brand(br) {}

    void display(ostream& out) const override
    {
        DATA_CARRIER::display(out);
        out << "Кількість циліндрів: " << cylinders << "\n"
            << "Кількість доріжок: " << tracks << "\n"
            << "Кількість секторів: " << sectors << "\n"
            << "Марка: " << brand << "\n";
    }
};

void writeToFile(const HARD_DRIVE& hdd, const OPTICAL_DISK& optDisk, const string& filename)
{
    ofstream file(filename);

    if (file.is_open())
    {
        file << "Інформація про жорсткий диск:\n";
        hdd.display(file);
        file << "\nІнформація про оптичний диск:\n";
        optDisk.display(file);
        file.close();
        cout << "Дані успішно записані у файл: " << filename << endl;
    }
    else
    {
        cout << "Не вдалося відкрити файл!" << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Ukr");
    double hddSize, optDiskSize;
    int cylinders, tracks, sectors;
    string brand;

    cout << "Введіть розмір жорсткого диска (ГБ): ";
    cin >> hddSize;
    cout << "Введіть кількість циліндрів: ";
    cin >> cylinders;
    cout << "Введіть кількість доріжок: ";
    cin >> tracks;
    cout << "Введіть кількість секторів: ";
    cin >> sectors;
    cout << "Введіть марку жорсткого диска: ";
    cin >> brand;

    HARD_DRIVE hdd(hddSize, cylinders, tracks, sectors, brand);

    cout << "Введіть розмір оптичного диска (ГБ): ";
    cin >> optDiskSize;
    cout << "Введіть кількість циліндрів: ";
    cin >> cylinders;
    cout << "Введіть кількість доріжок: ";
    cin >> tracks;
    cout << "Введіть кількість секторів: ";
    cin >> sectors;
    cout << "Введіть марку оптичного диска: ";
    cin >> brand;

    OPTICAL_DISK optDisk(optDiskSize, cylinders, tracks, sectors, brand);

    hdd.display(cout);
    cout << endl;
    optDisk.display(cout);

    writeToFile(hdd, optDisk, "D:\\app\\data_carriers.txt");

    return 0;
}
