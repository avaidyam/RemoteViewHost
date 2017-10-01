@import Cocoa;

@class NSRemoteView;
typedef unsigned char NSViewBridgeOwnerType;

// Common remote <--> service bridge interface to share objects via KVO.
@interface NSViewBridge : NSObject

+ (BOOL)automaticallyNotifiesObserversForKey:(id)arg1;
+ (BOOL)accessInstanceVariablesDirectly;
+ (BOOL)objectIsSuitable:(id)arg1;

@property NSObject *kvoBuddy;
@property (readonly) void *auditToken;
@property (readonly) int processIdentifier;

- (BOOL)_hasTrueValueForEntitlement:(id)arg1;
- (id)_copyValueForEntitlement:(id)arg1;

- (void)registerKey:(NSString *)key defaultObject:(id)obj owner:(NSViewBridgeOwnerType)ownerType;

- (void)setObject:(id)arg1 forKey:(id)arg2 withKVO:(BOOL)arg3;
- (void)setObject:(id)arg1 forKey:(id)arg2;
- (void)setValue:(id)arg1 forKey:(id)arg2;

- (id)valueForKey:(id)arg1;
- (id)allKeys;
- (NSInteger)keyCount;
- (BOOL)isKeyPath:(id)arg1;
- (NSViewBridgeOwnerType)ownerForKey:(id)arg1;
- (id)objectForKey:(id)arg1;
- (BOOL)hasObject:(id)arg1 forKey:(id)arg2;
- (BOOL)hasObjectForKey:(id)arg1;
- (BOOL)hasKey:(id)arg1;

- (BOOL)keyIsRelevantToBuddy:(id)arg1;

- (BOOL)changeOriginatesLocally;
- (BOOL)changeOriginatesLocally:(id)arg1;
- (void)nonLocalChangeInProgress:(id)arg1 block:(id)arg2;
- (BOOL)nonLocalChangeInProgress;

@end
