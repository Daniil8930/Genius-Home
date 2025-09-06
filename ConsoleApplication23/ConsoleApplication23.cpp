#include <iostream> // означает выводить и вводить  
#include <string> // это для быстрой работы
#include <vector> // означает динамический массив
#include <ctime>  // означает добавление времени
#include <iomanip>// максимально точное вычисление устройства
#include <windows.h>// цвет текста
using namespace std;// это нужно чтобы не обращаться каждый раз к std в коде
// Прототипы функций
void setColor(int color); // это функция с помощью которой можно изменить цвет текста
void showMenu(); // ФУНКЦИЯ ПОКАЗЫВАЕТ МЕНЮ
void controlLight(bool& light, vector<string>& log); // Controling Light - Контролирование света
void controlAC(bool& acOn, int& temperature, vector<string>& log); // Controling ALC - Контролирование кондиционера
void controlDoor(bool& doorOpen, vector<string>& log);// Controling Door - Контролирование дверью
void controlCamera(bool& cameraOn, vector<string>& log); // Controling Camera - Контролирование камерой
void controlMusic(bool& musicOn, int& volume, vector<string>& log); // Controling Music - Контролирование музыкой
void showStatus(bool light, bool acOn, int temp, bool doorOpen, bool cameraOn, bool musicOn, int volume); // Showed status - Показывает статус
void logAction(const string& action, vector<string>& log); // log Action - Вывод действий кода
void showLog(const vector<string>& log);
string getCurrentTime();

// Цветовые константы
#define COLOR_DEFAULT 7       // Белый
#define COLOR_TITLE 11        // Голубой
#define COLOR_MENU 10         // Зеленый
#define COLOR_SUCCESS 2       // Зеленый (успех)
#define COLOR_WARNING 6       // Желтый (предупреждение)
#define COLOR_ERROR 4         // Красный (ошибка)
#define COLOR_STATUS_ON 10    // Зеленый (включено)
#define COLOR_STATUS_OFF 8    // Серый (выключено)
#define COLOR_HIGHLIGHT 14    // Желтый (выделение)

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); // Setting color - настройка цвета
}

int main() {
    setlocale(LC_ALL, "Russian"); // Used Russian Language - Использует Русский язык
    // Инициализация состояний устройств
    bool light = false;
    bool acOn = false;
    int temperature = 22;
    bool doorOpen = false;
    bool cameraOn = false;
    bool musicOn = false;
    int volume = 50;

    vector<string> log; // Stringered massive - массив с помощью string
    int choice;

    // Начальное логирование
    logAction("Система запущена", log);
    do {
        showMenu(); // Using Function "ShowMenu" - Использование функции "ShowMenu"
        cin >> choice;

        switch (choice) { // Using cases - Использование коробок
        case 1:
            controlLight(light, log);
            break;
        case 2:
            controlAC(acOn, temperature, log);
            break;
        case 3:
            controlDoor(doorOpen, log);
            break;
        case 4:
            controlCamera(cameraOn, log);
            break;
        case 5:
            controlMusic(musicOn, volume, log);
            break;
        case 6:
            showStatus(light, acOn, temperature, doorOpen, cameraOn, musicOn, volume);
            break;
        case 7:
            showLog(log);
            break;
        case 8:
            setColor(COLOR_TITLE);
            cout << "Выход из системы..." << endl;
            setColor(COLOR_DEFAULT);
            logAction("Выход из системы", log);
            break;
        default:
            setColor(COLOR_ERROR);
            cout << "Неверный выбор! Попробуйте снова." << endl;
            setColor(COLOR_DEFAULT);
        }

        cout << endl;
    } while (choice != 8);

    return 0;
}

void showMenu() {// Using couts - Использование "cout"
    setColor(COLOR_TITLE);
    cout << "===================================" << endl;
    cout << "        УМНЫЙ ДОМ v1.0" << endl;
    cout << "===================================" << endl;
    setColor(COLOR_DEFAULT);

    setColor(COLOR_MENU);
    cout << "1. ";
    setColor(COLOR_HIGHLIGHT);
    cout << "Управление светом" << endl;

    setColor(COLOR_MENU);
    cout << "2. ";
    setColor(COLOR_HIGHLIGHT);
    cout << "Управление кондиционером" << endl;

    setColor(COLOR_MENU);
    cout << "3. ";
    setColor(COLOR_HIGHLIGHT);
    cout << "Управление дверью" << endl;

    setColor(COLOR_MENU);
    cout << "4. ";
    setColor(COLOR_HIGHLIGHT);
    cout << "Управление камерой наблюдения" << endl;

    setColor(COLOR_MENU);
    cout << "5. ";
    setColor(COLOR_HIGHLIGHT);
    cout << "Управление музыкой" << endl;

    setColor(COLOR_MENU);
    cout << "6. ";
    setColor(COLOR_HIGHLIGHT);
    cout << "Показать статус всех устройств" << endl;

    setColor(COLOR_MENU);
    cout << "7. ";
    setColor(COLOR_HIGHLIGHT);
    cout << "Показать журнал действий" << endl;

    setColor(COLOR_MENU);
    cout << "8. ";
    setColor(COLOR_HIGHLIGHT);
    cout << "Выход" << endl;

    setColor(COLOR_TITLE);
    cout << "===================================" << endl;
    setColor(COLOR_HIGHLIGHT);
    cout << "Выберите действие: ";
    setColor(COLOR_DEFAULT);
}

void controlLight(bool& light, vector<string>& log) {
    int choice;
    setColor(COLOR_TITLE);
    cout << "\n--- Управление светом ---" << endl;
    setColor(COLOR_DEFAULT);

    cout << "Текущее состояние: ";
    if (light) {
        setColor(COLOR_STATUS_ON);
        cout << "ВКЛ";
    }
    else {
        setColor(COLOR_STATUS_OFF);
        cout << "ВЫКЛ";
    }
    setColor(COLOR_DEFAULT);
    cout << endl;

    setColor(COLOR_MENU);
    cout << "1. Включить свет" << endl;
    cout << "2. Выключить свет" << endl;
    cout << "3. Назад" << endl;
    setColor(COLOR_HIGHLIGHT);
    cout << "Выберите действие: ";
    setColor(COLOR_DEFAULT);

    cin >> choice;

    if (choice == 1) {
        light = true;
        setColor(COLOR_SUCCESS);
        cout << "Свет включен!" << endl;
        setColor(COLOR_DEFAULT);
        logAction("Свет включен", log);
    }
    else if (choice == 2) {
        light = false;
        setColor(COLOR_WARNING);
        cout << "Свет выключен!" << endl;
        setColor(COLOR_DEFAULT);
        logAction("Свет выключен", log);
    }
}

void controlAC(bool& acOn, int& temperature, vector<string>& log) {
    int choice;
    setColor(COLOR_TITLE);
    cout << "\n--- Управление кондиционером ---" << endl;
    setColor(COLOR_DEFAULT);

    cout << "Текущее состояние: ";
    if (acOn) {
        setColor(COLOR_STATUS_ON);
        cout << "ВКЛ";
    }
    else {
        setColor(COLOR_STATUS_OFF);
        cout << "ВЫКЛ";
    }
    setColor(COLOR_DEFAULT);
    cout << endl;

    cout << "Текущая температура: ";
    setColor(COLOR_HIGHLIGHT);
    cout << temperature << "C" << endl;
    setColor(COLOR_DEFAULT);

    setColor(COLOR_MENU);
    cout << "1. Включить кондиционер" << endl;
    cout << "2. Выключить кондиционер" << endl;
    cout << "3. Изменить температуру" << endl;
    cout << "4. Назад" << endl;
    setColor(COLOR_HIGHLIGHT);
    cout << "Выберите действие: ";
    setColor(COLOR_DEFAULT);

    cin >> choice;

    if (choice == 1) {
        acOn = true;
        setColor(COLOR_SUCCESS);
        cout << "Кондиционер включен!" << endl;
        setColor(COLOR_DEFAULT);
        logAction("Кондиционер включен", log);
    }
    else if (choice == 2) {
        acOn = false;
        setColor(COLOR_WARNING);
        cout << "Кондиционер выключен!" << endl;
        setColor(COLOR_DEFAULT);
        logAction("Кондиционер выключен", log);
    }
    else if (choice == 3) {
        setColor(COLOR_HIGHLIGHT);
        cout << "Введите новую температуру (16-30C): ";
        setColor(COLOR_DEFAULT);
        cin >> temperature;
        if (temperature >= 16 && temperature <= 30) {
            setColor(COLOR_SUCCESS);
            cout << "Температура установлена на " << temperature << "C" << endl;
            setColor(COLOR_DEFAULT);
            logAction("Температура установлена на " + to_string(temperature) + "C", log);
        }
        else {
            setColor(COLOR_ERROR);
            cout << "Неверная температура!" << endl;
            setColor(COLOR_DEFAULT);
        }
    }
}

void controlDoor(bool& doorOpen, vector<string>& log) {
    int choice;
    setColor(COLOR_TITLE);
    cout << "\n--- Управление дверью ---" << endl;
    setColor(COLOR_DEFAULT);

    cout << "Текущее состояние: ";
    if (doorOpen) {
        setColor(COLOR_WARNING);
        cout << "ОТКРЫТА";
    }
    else {
        setColor(COLOR_SUCCESS);
        cout << "ЗАКРЫТА";
    }
    setColor(COLOR_DEFAULT);
    cout << endl;

    setColor(COLOR_MENU);
    cout << "1. Открыть дверь" << endl;
    cout << "2. Закрыть дверь" << endl;
    cout << "3. Назад" << endl;
    setColor(COLOR_HIGHLIGHT);
    cout << "Выберите действие: ";
    setColor(COLOR_DEFAULT);

    cin >> choice;

    if (choice == 1) {
        doorOpen = true;
        setColor(COLOR_WARNING);
        cout << "Дверь открыта!" << endl;
        setColor(COLOR_DEFAULT);
        logAction("Дверь открыта", log);
    }
    else if (choice == 2) {
        doorOpen = false;
        setColor(COLOR_SUCCESS);
        cout << "Дверь закрыта!" << endl;
        setColor(COLOR_DEFAULT);
        logAction("Дверь закрыта", log);
    }
}

void controlCamera(bool& cameraOn, vector<string>& log) {
    int choice;
    setColor(COLOR_TITLE);
    cout << "\n--- Управление камерой наблюдения ---" << endl;
    setColor(COLOR_DEFAULT);

    cout << "Текущее состояние: ";
    if (cameraOn) {
        setColor(COLOR_STATUS_ON);
        cout << "ВКЛ";
    }
    else {
        setColor(COLOR_STATUS_OFF);
        cout << "ВЫКЛ";
    }
    setColor(COLOR_DEFAULT);
    cout << endl;

    setColor(COLOR_MENU);
    cout << "1. Включить камеру" << endl;
    cout << "2. Выключить камеру" << endl;
    cout << "3. Назад" << endl;
    setColor(COLOR_HIGHLIGHT);
    cout << "Выберите действие: ";
    setColor(COLOR_DEFAULT);

    cin >> choice;

    if (choice == 1) {
        cameraOn = true;
        setColor(COLOR_SUCCESS);
        cout << "Камера наблюдения включена!" << endl;
        setColor(COLOR_DEFAULT);
        logAction("Камера наблюдения включена", log);
    }
    else if (choice == 2) {
        cameraOn = false;
        setColor(COLOR_WARNING);
        cout << "Камера наблюдения выключена!" << endl;
        setColor(COLOR_DEFAULT);
        logAction("Камера наблюдения выключена", log);
    }
}

void controlMusic(bool& musicOn, int& volume, vector<string>& log) {
    int choice;
    setColor(COLOR_TITLE);
    cout << "\n--- Управление музыкой ---" << endl;
    setColor(COLOR_DEFAULT);

    cout << "Текущее состояние: ";
    if (musicOn) {
        setColor(COLOR_STATUS_ON);
        cout << "ВКЛ";
    }
    else {
        setColor(COLOR_STATUS_OFF);
        cout << "ВЫКЛ";
    }
    setColor(COLOR_DEFAULT);
    cout << endl;

    cout << "Текущая громкость: ";
    setColor(COLOR_HIGHLIGHT);
    cout << volume << "%" << endl;
    setColor(COLOR_DEFAULT);

    setColor(COLOR_MENU);
    cout << "1. Включить музыку" << endl;
    cout << "2. Выключить музыку" << endl;
    cout << "3. Изменить громкость" << endl;
    cout << "4. Назад" << endl;
    setColor(COLOR_HIGHLIGHT);
    cout << "Выберите действие: ";
    setColor(COLOR_DEFAULT);

    cin >> choice;

    if (choice == 1) {
        musicOn = true;
        setColor(COLOR_SUCCESS);
        cout << "Музыка включена!" << endl;
        setColor(COLOR_DEFAULT);
        logAction("Музыка включена", log);
    }
    else if (choice == 2) {
        musicOn = false;
        setColor(COLOR_WARNING);
        cout << "Музыка выключена!" << endl;
        setColor(COLOR_DEFAULT);
        logAction("Музыка выключена", log);
    }
    else if (choice == 3) {
        setColor(COLOR_HIGHLIGHT);
        cout << "Введите новую громкость (0-100%): ";
        setColor(COLOR_DEFAULT);
        cin >> volume;
        if (volume >= 0 && volume <= 100) {
            setColor(COLOR_SUCCESS);
            cout << "Громкость установлена на " << volume << "%" << endl;
            setColor(COLOR_DEFAULT);
            logAction("Громкость установлена на " + to_string(volume) + "%", log);
        }
        else {
            setColor(COLOR_ERROR);
            cout << "Неверная громкость!" << endl;
            setColor(COLOR_DEFAULT);
        }
    }
}

void showStatus(bool light, bool acOn, int temp, bool doorOpen, bool cameraOn, bool musicOn, int volume) {
    setColor(COLOR_TITLE);
    cout << "\n--- Статус всех устройств ---" << endl;
    setColor(COLOR_DEFAULT);

    cout << "Свет: ";
    setColor(light ? COLOR_STATUS_ON : COLOR_STATUS_OFF);
    cout << (light ? "ВКЛ" : "ВЫКЛ") << endl;
    setColor(COLOR_DEFAULT);

    cout << "Кондиционер: ";
    setColor(acOn ? COLOR_STATUS_ON : COLOR_STATUS_OFF);
    cout << (acOn ? "ВКЛ" : "ВЫКЛ");
    setColor(COLOR_DEFAULT);
    cout << " (";
    setColor(COLOR_HIGHLIGHT);
    cout << temp << "C";
    setColor(COLOR_DEFAULT);
    cout << ")" << endl;

    cout << "Дверь: ";
    setColor(doorOpen ? COLOR_WARNING : COLOR_SUCCESS);
    cout << (doorOpen ? "ОТКРЫТА" : "ЗАКРЫТА") << endl;
    setColor(COLOR_DEFAULT);

    cout << "Камера: ";
    setColor(cameraOn ? COLOR_STATUS_ON : COLOR_STATUS_OFF);
    cout << (cameraOn ? "ВКЛ" : "ВЫКЛ") << endl;
    setColor(COLOR_DEFAULT);

    cout << "Музыка: ";
    setColor(musicOn ? COLOR_STATUS_ON : COLOR_STATUS_OFF);
    cout << (musicOn ? "ВКЛ" : "ВЫКЛ");
    setColor(COLOR_DEFAULT);
    cout << " (";
    setColor(COLOR_HIGHLIGHT);
    cout << volume << "%";
    setColor(COLOR_DEFAULT);
    cout << ")" << endl;
}

void logAction(const string& action, vector<string>& log) {
    string logEntry = getCurrentTime() + " - " + action;
    log.push_back(logEntry);
}

void showLog(const vector<string>& log) {
    setColor(COLOR_TITLE);
    cout << "\n--- Журнал действий ---" << endl;
    setColor(COLOR_DEFAULT);

    if (log.empty()) {
        setColor(COLOR_WARNING);
        cout << "Журнал пуст" << endl;
        setColor(COLOR_DEFAULT);
    }
    else {
        for (const auto& entry : log) {
            setColor(COLOR_MENU);
            cout << entry << endl;
        }
    }
}

string getCurrentTime() {
    time_t now = time(0);
    struct tm local_time;
    localtime_s(&local_time, &now);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &local_time);
    return string(buffer);
}