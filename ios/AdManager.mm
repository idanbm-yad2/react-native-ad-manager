#import "AdManager.h"
#import "react-native-ad-manager.h"
#import <jsi/jsi.h>
#import <React/RCTUtils.h>
#import <React/RCTBridge+Private.h>
#import <sys/utsname.h>

using namespace facebook::jsi;
using namespace std;

@implementation AdManager

@synthesize bridge = _bridge;
@synthesize methodQueue = _methodQueue;

RCT_EXPORT_MODULE()

+ (BOOL)requiresMainQueueSetup {
    return YES;
}

// Installing JSI Bindings as done by
// https://github.com/mrousavy/react-native-mmkv
RCT_EXPORT_BLOCKING_SYNCHRONOUS_METHOD(install)
{
    RCTBridge* bridge = [RCTBridge currentBridge];
    RCTCxxBridge* cxxBridge = (RCTCxxBridge*)bridge;
    if (cxxBridge == nil) {
        return @false;
    }

    auto jsiRuntime = (Runtime*) cxxBridge.runtime;
    if (jsiRuntime == nil) {
        return @false;
    }

    installExample(*(Runtime *)cxxBridge.runtime);
   
    return @true;
}


@end
