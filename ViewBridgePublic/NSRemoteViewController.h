@import Cocoa;
#import "NSViewBridge.h"

@class NSRemoteViewController;
typedef void (^NSRemoteViewControllerConnectionHandler)(NSRemoteViewController *);

// Use this Bridge in the host App side.
@interface NSViewRemoteBridge : NSViewBridge

@property (readonly) NSRemoteView *remoteView;

@property (readonly) void *auditToken;
@property (readonly) int processIdentifier;

- (instancetype)initWithRemoteView:(NSRemoteView *)remoteView;

- (void)registerKey:(NSString *)key defaultObject:(id)obj owner:(NSViewBridgeOwnerType)ownerType;

@end

// Just let the poor thing do its job without poking its guts, okay?
@interface NSRemoteView : NSView
@end

// Use this in the host App side.
@interface NSRemoteViewController : NSViewController

+ (void)requestViewController:(NSString *)className
  fromServiceListenerEndpoint:(NSXPCListenerEndpoint *)listenerEndpoint
            connectionHandler:(NSRemoteViewControllerConnectionHandler)connectionHandler;

+ (void)requestViewController:(NSString *)className
fromServiceWithBundleIdentifier:(NSString *)bundleIdentifier
            connectionHandler:(NSRemoteViewControllerConnectionHandler)connectionHandler;

+ (void)requestViewController:(NSString *)className
withServiceSubclassIdentifier:(NSString *)subclassIdentifier
                forRemoteView:(NSRemoteView *)remoteView
            connectionHandler:(NSRemoteViewControllerConnectionHandler)connectionHandler;

+ (void)requestViewController:(NSString *)className
withServiceSubclassIdentifier:(NSString *)subclassIdentifier
            connectionHandler:(NSRemoteViewControllerConnectionHandler)connectionHandler
                    withBlock:(id)unknown;

@property (readonly) void *serviceAuditToken;
@property (readonly) int serviceProcessIdentifier;

@property (readonly) NSString *serviceViewControllerClassName;
@property (readonly) NSString *serviceBundleIdentifier;
@property (readonly) NSString *remoteViewIdentifier;
@property (readonly) NSXPCListenerEndpoint *serviceListenerEndpoint;

- (void)synchronizeAnimationsInActions:(id)unknown;
- (void)viewServiceDidTerminateWithError:(NSError *)error;
- (void)disconnect;

- (id)exportedObject;
- (NSXPCInterface *)exportedInterface;

- (NSXPCInterface *)serviceViewControllerInterface;
- (id)serviceViewControllerProxyWithErrorHandler:(void (^)(NSError *error))errorHandler;
- (id)serviceViewControllerProxy;

- (void)setServiceViewControllerClassName:(NSString *)className;
- (void)setServiceBundleIdentifier:(NSString *)bundleIdentifier;
- (void)setServiceListenerEndpoint:(NSXPCListenerEndpoint *)listenerEndpoint;

@end


