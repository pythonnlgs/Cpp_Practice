#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    string x=argv[1];
    string h="g++ -s " + x;
    const char *l = h.data();
    system(l);
    system("upx -9 a.exe");
    return 0;
}