#include"Functionalities.h"

using namespace std::placeholders;

int main()
{

    Container data;
    CreateObjects(data);
    auto fn = std::bind (SalaryGivenID, _2,_1);
    fn(101,data,101); // 101 should be hardcoded (fixed)
    std::cout<<fn(101,data)<<"\n";
    std::cout<<AverageSalary(data)<<"\n";

}
