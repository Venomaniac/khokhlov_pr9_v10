using namespace std;
#include <iostream>

const int SIZE = 10;

double ishData[SIZE] = { 15.0, 42.5, 78.0, 100.0, 0.0, 63.5, 89.0, 27.0, 55.5, 91.0 };

double currData[SIZE];

void incrCharge(double* data, int size)
{
    for (int i = 0; i < size; i++)
    {
        data[i] += 10.0;
    }
}
void decrCharge(double* data, int size)
{
    for (int i = 0; i < size; i++)
    {
        data[i] -= 10.0;
    }
}
void setFullCharge(double* data, int size)
{
    for (int i = 0; i < size; i++)
    {
        data[i] = 100.0;
    }
}
void ogrCharge(double* data, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (data[i] < 0.0)
        {
            data[i] = 0.0;
        }
        else if (data[i] > 100.0)
        {
            data[i] = 100.0;
        }
    }
}
void (*processors[])(double*, int) = {
    incrCharge,
    decrCharge,
    setFullCharge,
    ogrCharge
};
void applyProcessing(double* data, int size, void(*processor)(double*, int))
{
    if (processor != nullptr)
    {
        processor(data, size);
    }
}
void copyIshData()
{
    for (int i = 0; i < SIZE; i++)
    {
        currData[i] = ishData[i];
    }
}

void printData(const char* nazv)
{
    cout << nazv << ":" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << currData[i] << " ";
    }
    cout << "\n" << endl;
}
void printMenu()
{
    cout << "Меню:" << endl;
    cout << "1. Ввести данные (сбросить к исходным)" << endl;
    cout << "2. Показать данные" << endl;
    cout << "3. Выбрать и выполнить обработку" << endl;
    cout << "4. Восстановить исходные данные" << endl;
    cout << "5. Выход" << endl;
    cout << "Выберите пункт: ";
}
void printProcessorMenu()
{
    cout << "\nДоступные обработки:" << endl;
    cout << "1. Увеличить заряд на 10" << endl;
    cout << "2. Уменьшить заряд на 10" << endl;
    cout << "3. Установить заряд всех устройств равным 100" << endl;
    cout << "4. Ограничить значения диапазоном от 0 до 100" << endl;
    cout << "Выберите обработку: ";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    copyIshData();
    int choice = 0;
    while (choice != 5)
    {
        printMenu();
        cin >> choice;
        switch (choice) {
        case 1:
        {
            copyIshData();
            cout << "Данные сброшены к исходным\n" << endl;
            break;
        }
        case 2:
        {
            printData("Текущие данные");
            break;
        }
        case 3:
        {
            printProcessorMenu();
            int op;
            cin >> op;
            if (op >= 1 && op <= 4)
            {
                void (*processor)(double*, int) = processors[op - 1];
                printData("До обработки");
                applyProcessing(currData, SIZE, processor);
                printData("После обработки");
            }
            else
            {
                cout << "Неверный номер обработки\n" << endl;
            }
            break;
        }
        case 4:
        {
            copyIshData();
            cout << "Исходные данные восстановлены\n" << endl;
            break;
        }
        case 5:
        {
            cout << "Выход из программы";
            break;
        }
        default: {
            cout << "Неверный пункт меню\n" << endl;
            break;
        }
        }
    }
}