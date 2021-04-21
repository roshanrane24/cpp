#include <iostream>


int main()
{
    std::string name = "Eren";
    int age = 19;
    float height = 1.83;

    printf("%s is %d years old.\n", name.c_str(), age);
    printf("%s is %fm tall..\n", name.c_str(), height);

    return 0;
}
