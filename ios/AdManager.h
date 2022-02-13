#import <React/RCTBridgeModule.h>

#ifdef __cplusplus

#import "react-native-ad-manager.h"

#endif

@interface AdManager : NSObject <RCTBridgeModule>

@property(nonatomic, assign) BOOL setBridgeOnMainQueue;

@end
