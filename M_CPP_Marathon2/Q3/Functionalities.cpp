#include "Functionalities.h"
using DriverPointer = std::shared_ptr<Driver>;
using ContainerOfLiscence = std::vector<LiscencePointer>;
using ContainerOfDriver = std::vector<DriverPointer>;
using VectorOfStrings = std::vector<std::string>;

std::function<void(ContainerOfDriver &, ContainerOfLiscence &)> CreateObjects = [](ContainerOfDriver &d_data, ContainerOfLiscence &l_data)
{
    l_data.emplace_back(
        std::make_shared<Liscence>(
            "11",
            10,
            LiscenceCategory::PERSONAL,
            "Nagpur",
            "Maharashtra"));

    l_data.emplace_back(
        std::make_shared<Liscence>(
            "22",
            11,
            LiscenceCategory::COMMERCIAL,
            "Pune",
            "Maharashtra"));
    
    l_data.emplace_back(
        std::make_shared<Liscence>(
            "33",
            12,
            LiscenceCategory::SPECIAL_PURPOSE,
            "Ahmedabad",
            "Gujrat"));

    d_data.emplace_back(
        std::make_shared<Driver>(
            "Rushabh",
            DriverCategory::DOMESTIC,
            1959,
            l_data[0]
        )
    );

    d_data.emplace_back(
        std::make_shared<Driver>(
            "Prathamesh",
            DriverCategory::DOMESTIC,
            1952,
            l_data[1]
        )
    );

    d_data.emplace_back(
        std::make_shared<Driver>(
            "Ujjwal",
            DriverCategory::COMMERCIAL,
            1970,
            l_data[2]
        )
    );
            
};


std::function<ContainerOfLiscence(ContainerOfDriver&)> FirstTwoInstancesByBirthYear = [](ContainerOfDriver& data){
    int count = 0;

    ContainerOfLiscence result;

    for(DriverPointer& ptr : data){
        if(ptr->getDriverBirthYear()<1960){
            result.emplace_back(ptr->getDriverLiscence().get());
            count++;
        }

        if(count==2){
            break;
        }
    }

    return result;
};

std::function<ContainerOfDriver(ContainerOfDriver&)> FirstTwoInstancesByLiscence = [](ContainerOfDriver& data){
    int count = 0;

    ContainerOfDriver result;

    for(DriverPointer& ptr : data){
        if(ptr->getDriverLiscence().get()->getLiscenceCategory()==LiscenceCategory::COMMERCIAL || ptr->getDriverLiscence().get()->getLiscenceCategory()==LiscenceCategory::PERSONAL){
            result.emplace_back(ptr);
            count++;
        }

        if(count==2){
            break;
        }
    }

    return result;
};


std::function<ContainerOfDriver(ContainerOfDriver&,std::string search)> FindDriverByRTO = [](ContainerOfDriver& data,std::string search)
{
    ContainerOfDriver result;

    for(DriverPointer& ptr : data){
        if(ptr->getDriverLiscence().get()->getLiscenceIssuingRTO()==search){
            result.emplace_back(ptr);
        }
    }
    return result;
};


std::function<ContainerOfLiscence(ContainerOfDriver&,VectorOfStrings)> SearchByVectorOfState =[](ContainerOfDriver& data,VectorOfStrings search)
{
    ContainerOfLiscence result;

    for(DriverPointer& ptr : data){
        for(std::string str : search){
            if(ptr->getDriverLiscence().get()->getLiscenceIssusingState()==str){
                result.emplace_back(ptr->getDriverLiscence().get());
            }
        }
    }

    return result;
};

void Operation(std::function<void(ContainerOfDriver&)> Fn,ContainerOfDriver& data){
    Fn(data);
}