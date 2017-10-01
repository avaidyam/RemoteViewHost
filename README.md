#  RemoteViewHost

A very simple proof-of-concept showing how to use `ViewBridge.framework` to split up GUI code into different services and vend them from a central app. Basically, XPC but for `NSView` et al. This is also supported through the `NSExtension` API which I might add to this to show how to create and host extensions with UI in an app at a later date.

![Sample](https://raw.githubusercontent.com/avaidyam/RemoteViewHost/master/Sample.png)
