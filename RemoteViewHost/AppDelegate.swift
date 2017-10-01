import Cocoa

@NSApplicationMain
class AppDelegate: NSObject, NSApplicationDelegate {
    @IBOutlet weak var window: NSWindow!
    
    func applicationDidFinishLaunching(_ aNotification: Notification) {
        NSRemoteViewController.request("RemoteViewService.MyServiceViewController", fromServiceWithBundleIdentifier: "com.avaidyam.RemoteViewService") {
            self.window.contentViewController = $0
        }
    }
}

