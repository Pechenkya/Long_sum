#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    //std::ifstream cin("input.txt");
    //std::ofstream cout("output.txt");
    
    std::string num1{};
    std::string num2{};
    std::vector <int> number;
    
    std::getline(std::cin, num1);
    std::getline(std::cin, num2);
    
    if(num1.length() < num2.length())
        swap(num1, num2);
    
    int mod{};
    
    std::reverse(num1.begin(), num1.end());
    std::reverse(num2.begin(), num2.end());
    
    int counter{};
    int temp_int{};
    
    for(char t: num1)
    {
        if(counter < num2.length())
        {
            temp_int= ((int)t - 48) + ((int)num2[counter] - 48) + mod;
            if(temp_int >= 10)
            {
                temp_int -= 10;
                mod = 1;
            }
            else
            {
                mod = 0;
            }
            number.push_back(temp_int);
            counter++;
        }
        else
        {
            temp_int = ((int)t - 48) + mod;
            if(temp_int >= 10)
            {
                temp_int -= 10;
                mod = 1;
            }
            else
            {
                mod = 0;
            }
            number.push_back(temp_int);
        }
    }
    
    if(mod != 0) number.push_back(mod);
    
    std::reverse(number.begin(), number.end());
    
    for(auto t: number)
        std::cout << t;
    return 0;
}
