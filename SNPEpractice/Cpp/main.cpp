#include <iostream>
#include <fstream>
#include "SNPE/SNPE.hpp"
#include "SNPE/SNPEFactory.hpp"
#include "DlSystem/DlVersion.hpp"
#include "DlSystem/DlEnums.hpp"
#include "DlSystem/String.hpp"
#include "DlContainer/IDlContainer.hpp"
#include "SNPE/SNPEBuilder.hpp"
#include "udlExample.hpp"

#ifdef ANDROID
#include <GLES2/gl2.h>
#include "CreateGLBuffer.hpp"
#endif

using namespace std;

int main()
{
    string dlc = "/sdcard/test.dlc";
    string testPic = "/sdcard/test.jpg";

    cout << "hello" << endl;
    static zdl::DlSystem::Runtime_t runtime = zdl::DlSystem::Runtime_t::GPU;
    static zdl::DlSystem::Version_t Version = zdl::SNPE::SNPEFactory::getLibraryVersion();
    cout << "SNPE Version: " << Version.asString().c_str() << endl; //Print Version number

    if(zdl::SNPE::SNPEFactory::isRuntimeAvailable(runtime))
    {
        cout << "target support GPU" << endl;
    }
    else
    {
        runtime = zdl::DlSystem::Runtime_t::CPU;
        cout << "target not support GPU" << endl;
        cout << "fall back to CPU" << endl;
    }

    ifstream dlcFile(dlc);
    ifstream inputPic(testPic);
    if(!dlcFile || !inputPic) {
        cout << "no dlc file or input picture" << endl;
        return -1;
    }

    unique_ptr<zdl::DlContainer::IDlContainer> container =
        zdl::DlContainer::IDlContainer::open(zdl::DlSystem::String(dlc.c_str()));
    if (container == nullptr) {
        cout << "can not open container file!" << endl;
        return -1;
    }

    zdl::DlSystem::UDLFactoryFunc udlFunc = sample::MyUDLFactory;
    zdl::DlSystem::UDLBundle udlBundle;
    udlBundle.cookie = (void*)0xdeadbeaf, udlBundle.func = udlFunc;

    zdl::DlSystem::PlatformConfig platformConfig;


    unique_ptr<zdl::SNPE::SNPE> snpe;
    zdl::SNPE::SNPEBuilder snpeBuilder(container.get());

    snpe = snpeBuilder.setOutputLayers({})
        .setRuntimeProcessor(runtime)
        .setUdlBundle(udlBundle)
        .setPlatformConfig(platformConfig)
        .setUseUserSuppliedBuffers(false)
        .setInitCacheMode(false)
        .build();

    if (snpe == nullptr) {
        cout << "building snpe obj err" << endl;
        return -1;
    }

    cout << "hello222" << endl;
    return 0;
}
