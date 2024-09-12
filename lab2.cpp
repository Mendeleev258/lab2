#include <iostream>
#include <iomanip>

int main()
{
    setlocale(LC_ALL, "Russian");

    short choice;
    do 
    {
        std::cout << "1. Сумма заданного количества слагаемых\n";
        std::cout << "2. Сумма с заданной точностью\n";
        std::cout << "3. Завершение работы\n";

        bool isError = false;
        
        do
        {
            isError = false;
            std::cout << ">>> ";
            std::cin >> choice;
            if (!(choice >= 1 && choice <= 3)) 
            {
                std::cout << "Ошибка ввода!\n";
                std::cin.clear();
                std::cin.ignore(std::cin.rdbuf()->in_avail());
                isError = true;
            }
        } while (isError);
        
        if (choice != 3)
        {
            // input x
            
            double x;
            do
            {
                isError = true;
                std::cout << "Введите (|x| < 1): ";
                std::cin >> x;
                if (abs(x) < 1)
                    isError = false;
                else
                {
                    std::cout << "Ошибка ввода!\n";
                    std::cin.clear();
                    std::cin.ignore(std::cin.rdbuf()->in_avail());
                }
            } while (isError);

            if (choice == 1)
            {
                // task 1
                std::cout << "Введите количество слагаемых n = ";
                double s = 0, a = 1;
                int n;
                std::cin >> n;
                std::cout << '\n';

                for (double i = 0; i < n; ++i)
                {
                    s += a;
                    a *= (2 * i + 1) / (2 * i + 2) * x * (-1);
                }

                std::cout << std::setw(26) << std::left << "Количество слагаемых" << " = " << n << '\n';
                std::cout << std::setw(26) << std::left << "Точное значение" << " = " << std::fixed << std::setprecision(11) << 1.0 / sqrt(1 + x) << '\n';
                std::cout << std::setw(26) << std::left << "Приближенное значение" << " = " << std::fixed << std::setprecision(11) << s << '\n';
            }
            else
            {
                // task 2
                double s = 0, a = 1, eps, tau = 1.0 / sqrt(1 + x);
                int n = 0;
                std::cout << "Введите eps = ";
                std::cin >> eps;
                std::cout << '\n';

                for (double i = 0; abs(s - tau) > eps; ++i)
                {
                    n += 1;
                    s += a;
                    a *= (2 * i + 1) / (2 * i + 2) * x * (-1);
                }
                
                std::cout << std::setw(26) << std::left << "Количество слагаемых" << " = " << n << '\n';
                std::cout << std::setw(26) << std::left << "Точное значение" << " = " << std::fixed << std::setprecision(11) << 1.0 / sqrt(1 + x) << '\n';
                std::cout << std::setw(26) << std::left << "Приближенное значение" << " = " << std::fixed << std::setprecision(11) << s << '\n' << '\n';

                for (double i = 0; abs(s - tau) > eps * 0.1; ++i)
                {
                    n += 1;
                    s += a;
                    a *= (2 * i + 1) / (2 * i + 2) * x * (-1);
                }
                std::cout << "Для eps на порядок меньше\n";
                std::cout << std::setw(26) << std::left << "Количество слагаемых" << " = " << n << '\n';
                std::cout << std::setw(26) << std::left << "Точное значение" << " = " << std::fixed << std::setprecision(11) << 1.0 / sqrt(1 + x) << '\n';
                std::cout << std::setw(26) << std::left << "Приближенное значение" << " = " << std::fixed << std::setprecision(11) << s << '\n';
            }
            
            std::cout << "\nЗавершить работу? (Y/любая клавиша): ";
            
            char isExit;
            std::cin >> isExit;
            
            if (isExit == 'Y' || isExit == 'y')
                choice = 3;
        }

    } while (choice != 3);
}
