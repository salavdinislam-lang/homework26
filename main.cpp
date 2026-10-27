#include <iostream>
#include <cmath>

using namespace std;

long long fact(int n) {
    long long res = 1;
    for (int i = 1; i <= n; i++) {
        res = res * i;
    }
    return res;
}

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

long long calc(int a, int b) {
    long long p = 1;
    bool found = false;
    for (int i = a; i <= b; i++) {
        if (isPrime(i)) {
            p = p * i;
            found = true;
        }
    }
    if (!found) return 0;
    return p;
}

long long calc(int n) {
    long long p = 1;
    for (int i = 1; i <= n; i++) {
        p = p * i;
    }
    return p;
}

void swapValues(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int sumDivisors(int n) {
    int s = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            s += i;
        }
    }
    return s;
}

int countEvens(int a, int b) {
    int cnt = 0;
    for (int i = a; i <= b; i++) {
        if (i % 2 == 0) {
            cnt++;
        }
    }
    return cnt;
}

int countIntegersStep(double a, double b, double c) {
    int cnt = 0;
    for (double x = a; x <= b + 0.000001; x += c) {
        if (fabs(x - round(x)) < 0.00001) {
            cnt++;
        }
    }
    return cnt;
}

void perfectNumbers(int a, int b) {
    bool any = false;
    for (int i = a; i <= b; i++) {
        if (i <= 1) continue;
        int s = 0;
        for (int d = 1; d < i; d++) {
            if (i % d == 0) s += d;
        }
        if (s == i) {
            cout << i << " ";
            any = true;
        }
    }
    if (!any) cout << "Нет совершенных чисел";
    cout << "\n";
}

void pythagoras(int a, int b) {
    bool any = false;
    for (int x = a; x <= b; x++) {
        for (int y = x; y <= b; y++) {
            for (int z = y; z <= b; z++) {
                if (x * x + y * y == z * z) {
                    cout << "(" << x << ", " << y << ", " << z << ")\n";
                    any = true;
                }
            }
        }
    }
    if (!any) {
        cout << "В диапазоне нет таких чисел\n";
    }
}

void sumPrimesExceedS() {
    int s;
    cout << "Введите S: ";
    cin >> s;

    cout << "\n1 - цикл while\n2 - цикл do-while\n3 - цикл for\nВыберите цикл: ";
    int loopChoice;
    cin >> loopChoice;

    if (loopChoice == 1) {
        int sum = 0;
        int count = 0;
        int num = 1;
        while (sum <= s) {
            if (num == 1 || isPrime(num)) {
                sum += num;
                count++;
            }
            num++;
        }
        cout << "Количество: " << count << ", Сумма: " << sum << "\n";
    } else if (loopChoice == 2) {
        int sum = 0;
        int count = 0;
        int num = 1;
        do {
            if (num == 1 || isPrime(num)) {
                sum += num;
                count++;
            }
            num++;
        } while (sum <= s);
        cout << "Количество: " << count << ", Сумма: " << sum << "\n";
    } else {
        int sum = 0;
        int count = 0;
        for (int num = 1; sum <= s; num++) {
            if (num == 1 || isPrime(num)) {
                sum += num;
                count++;
            }
        }
        cout << "Количество: " << count << ", Сумма: " << sum << "\n";
    }
}

void triangularNumbersTask() {
    int n;
    cout << "Введите натуральное число N: ";
    cin >> n;

    int tri[200];
    int tCount = 0;
    tri[tCount++] = 0;

    for (int k = 1;; k++) {
        int val = k * (k + 1) / 2;
        if (val > n) break;
        tri[tCount++] = val;
    }

    bool ok = false;
    for (int i = 0; i < tCount; i++) {
        for (int j = 0; j < tCount; j++) {
            for (int k = 0; k < tCount; k++) {
                if (tri[i] + tri[j] + tri[k] == n) {
                    cout << n << " = " << tri[i] << " + " << tri[j] << " + " << tri[k] << "\n";
                    ok = true;
                    break;
                }
            }
            if (ok) break;
        }
        if (ok) break;
    }

    if (!ok) {
        cout << "Нельзя представить\n";
    }
}

void menu() {
    int choice = -1;
    while (choice != 0) {
        cout << "\n================= МЕНЮ =================" << "\n";
        cout << "1. Вычисление факториала для заданного числа" << "\n";
        cout << "2. Вычисление произведения простых чисел в диапазоне [a, b]" << "\n";
        cout << "3. Функция для обмена значений x и y" << "\n";
        cout << "4. Определить сумму делителей для числа N" << "\n";
        cout << "5. Перегруженная функция (произведение чисел от 1 до N)" << "\n";
        cout << "6. Вычислить количество четных чисел в диапазоне [a, b]" << "\n";
        cout << "7. Сколько целых чисел попадает в диапазон [a, b] с шагом c" << "\n";
        cout << "8. Совершенные числа в диапазоне [a, b]" << "\n";
        cout << "9. Пифагоровы тройки в диапазоне [a, b]" << "\n";
        cout << "10. Сумма простых чисел до превышения S (while / do-while / for)" << "\n";
        cout << "11. Разложение числа на сумму до трех треугольных чисел" << "\n";
        cout << "0. Выход" << "\n";
        cout << "Выберите номер задачи: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int n;
                cout << "Введите число n: ";
                cin >> n;
                cout << "Факториал = " << fact(n) << "\n";
                break;
            }
            case 2: {
                int a, b;
                cout << "Введите границы [a, b]: ";
                cin >> a >> b;
                cout << "Произведение простых чисел = " << calc(a, b) << "\n";
                break;
            }
            case 3: {
                int x, y;
                cout << "Введите x и y: ";
                cin >> x >> y;
                swapValues(x, y);
                cout << "После обмена: x = " << x << ", y = " << y << "\n";
                break;
            }
            case 4: {
                int n;
                cout << "Введите число N: ";
                cin >> n;
                cout << "Сумма делителей = " << sumDivisors(n) << "\n";
                break;
            }
            case 5: {
                int n;
                cout << "Введите число N: ";
                cin >> n;
                cout << "Произведение до N = " << calc(n) << "\n";
                break;
            }
            case 6: {
                int a, b;
                cout << "Введите границы [a, b]: ";
                cin >> a >> b;
                cout << "Количество четных чисел = " << countEvens(a, b) << "\n";
                break;
            }
            case 7: {
                double a, b, c;
                cout << "Введите a, b и шаг c: ";
                cin >> a >> b >> c;
                cout << "Количество целых чисел = " << countIntegersStep(a, b, c) << "\n";
                break;
            }
            case 8: {
                int a, b;
                cout << "Введите границы [a, b]: ";
                cin >> a >> b;
                cout << "Совершенные числа: ";
                perfectNumbers(a, b);
                break;
            }
            case 9: {
                int a, b;
                cout << "Введите границы [a, b]: ";
                cin >> a >> b;
                pythagoras(a, b);
                break;
            }
            case 10: {
                sumPrimesExceedS();
                break;
            }
            case 11: {
                triangularNumbersTask();
                break;
            }
            case 0:
                cout << "Выход из программы...\n";
                break;
            default:
                cout << "Неверный пункт меню!\n";
                break;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    menu();
    return 0;
}
