#include <iostream>
#include "SNPE/SNPE.hpp"
#include "SNPE/SNPEFactory.hpp"
#include "DlSystem/DlVersion.hpp"
#include "DlSystem/DlEnums.hpp"
#include "DlSystem/String.hpp"



using namespace std;

int main()
{
    cout << "hello" << endl;
    static zdl::DlSystem::Runtime_t runtime = zdl::DlSystem::Runtime_t::CPU;
    static zdl::DlSystem::Version_t Version = zdl::SNPE::SNPEFactory::getLibraryVersion();
    cout << "SNPE Version: " << Version.asString().c_str() << endl; //Print Version number

    cout << "hello222" << endl;
    return 0;
}
