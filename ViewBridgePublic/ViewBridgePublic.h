@import Cocoa;

// Call this from the main() in the XPC service.
// Add these keys to your Info.plist in the XPC service:
//
// <key>NSPrincipalClass</key>
// <string>NSViewServiceApplication</string>
// <key>XPCService</key>
// <dict>
//     <key>ServiceType</key>
//     <string>Application</string>
//     <key>JoinExistingSession</key>
//     <true/>
//     <key>RunLoopType</key>
//     <string>_NSApplicationMain</string>
// </dict>
//
extern int NSViewServiceApplicationMain(void);

// Trust me, you *really* do not want to bother with these classes.
@class NSRemoteViewMarshal, NSViewServiceMarshal;

#import "NSViewBridge.h"
#import "NSRemoteViewController.h"
#import "NSServiceViewController.h"
