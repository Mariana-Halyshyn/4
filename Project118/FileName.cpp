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
        out << "���� �����: \n";
        out << "�����: " << sizeInGB << " ��\n";
    }
};

// �������� ���� HARD_DRIVE (�������� ����)
class HARD_DRIVE : public DATA_CARRIER {
private:
    int cylinders; // ʳ������ �������
    int tracks;    // ʳ������ ������
    int sectors;   // ʳ������ �������
    string brand;  // ����� ��������� �����

public:
    HARD_DRIVE(double size, int cyl, int trk, int sct, string br)
        : DATA_CARRIER(size), cylinders(cyl), tracks(trk), sectors(sct), brand(br) {}

    void display(ostream& out) const override
    {
        DATA_CARRIER::display(out);
        out << "ʳ������ �������: " << cylinders << "\n"
            << "ʳ������ ������: " << tracks << "\n"
            << "ʳ������ �������: " << sectors << "\n"
            << "�����: " << brand << "\n";
    }
};

// �������� ���� OPTICAL_DISK (�������� ����)
class OPTICAL_DISK : public DATA_CARRIER {
private:
    int cylinders; // ʳ������ �������
    int tracks;    // ʳ������ ������
    int sectors;   // ʳ������ �������
    string brand;  // ����� ��������� �����

public:
    OPTICAL_DISK(double size, int cyl, int trk, int sct, string br)
        : DATA_CARRIER(size), cylinders(cyl), tracks(trk), sectors(sct), brand(br) {}

    void display(ostream& out) const override
    {
        DATA_CARRIER::display(out);
        out << "ʳ������ �������: " << cylinders << "\n"
            << "ʳ������ ������: " << tracks << "\n"
            << "ʳ������ �������: " << sectors << "\n"
            << "�����: " << brand << "\n";
    }
};

void writeToFile(const HARD_DRIVE& hdd, const OPTICAL_DISK& optDisk, const string& filename)
{
    ofstream file(filename);

    if (file.is_open())
    {
        file << "���������� ��� �������� ����:\n";
        hdd.display(file);
        file << "\n���������� ��� �������� ����:\n";
        optDisk.display(file);
        file.close();
        cout << "��� ������ ������� � ����: " << filename << endl;
    }
    else
    {
        cout << "�� ������� ������� ����!" << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Ukr");
    double hddSize, optDiskSize;
    int cylinders, tracks, sectors;
    string brand;

    cout << "������ ����� ��������� ����� (��): ";
    cin >> hddSize;
    cout << "������ ������� �������: ";
    cin >> cylinders;
    cout << "������ ������� ������: ";
    cin >> tracks;
    cout << "������ ������� �������: ";
    cin >> sectors;
    cout << "������ ����� ��������� �����: ";
    cin >> brand;

    HARD_DRIVE hdd(hddSize, cylinders, tracks, sectors, brand);

    cout << "������ ����� ��������� ����� (��): ";
    cin >> optDiskSize;
    cout << "������ ������� �������: ";
    cin >> cylinders;
    cout << "������ ������� ������: ";
    cin >> tracks;
    cout << "������ ������� �������: ";
    cin >> sectors;
    cout << "������ ����� ��������� �����: ";
    cin >> brand;

    OPTICAL_DISK optDisk(optDiskSize, cylinders, tracks, sectors, brand);

    hdd.display(cout);
    cout << endl;
    optDisk.display(cout);

    writeToFile(hdd, optDisk, "D:\\app\\data_carriers.txt");

    return 0;
}
