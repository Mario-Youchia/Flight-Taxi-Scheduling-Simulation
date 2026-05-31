
#include <iostream>
#include "scheduler.h"
#include <fstream>
#include <string>

int main()
{
    scheduler* s=new scheduler;
    ifstream file;
    s->readData(file, "list.txt");
    s->Run();
  
    ofstream Output;
    Output.open("Output.txt");
    if (Output.is_open())
    {
        s->Finish(Output);
    }
    else cout << "Cannot Create Output File";
    delete s;
    return 0;
}
