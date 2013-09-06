Elite CommandAR iOS SDK
================================

The EliteCommandAR iOS SDK lets you receive button presses from your [Elite CommandAR pistol](http://appgear.com/en/games/elite-commandar) on devices running iOS 5.0 and above. 

Documentation of the SDK is available here: http://www.wowweelabs.com/ecar/iOS/docs/index.html

Support is available at the RoboCommunity forums: http://www.robocommunity.com/

For Android or Unity SDKs visit: http://www.wowweelabs.com/

For information on WowWee products visit: http://www.wowwee.com/

Getting Started
---------------------------------------

Download the [EliteCommandAR iOS SDK](https://github.com/WowWeeLabs/EliteCommandAR-iOS-SDK).

The quickest way to get started is to open the sample app under the SampleProject directory. The sample app starts listening to events from the gun and prints these to the text view.

Creating your own app using the ECAR iOS SDK
-----------------------------------------------

Here are the basic steps in creating your own app:

1. In XCode, create a new project. The simplest application is a Single-View application.

2. Open the project navigator in Xcode.

3. Drag the EliteCommandAR-iOS-SDK directory from the Mac OS Finder to the Frameworks directory for your project in XCode. This directory contains the framework.

4. The ECAR framework requires a few other frameworks and libraries to be added to your project. The easiest way to add them is
to copy them from the ECARSample app under the SampleProject directory. 

	Open the ECAR sample app in XCode. Drag all of the additional frameworks from the frameworks folder (in the project navigator)
	of the ECAR sample project into the frameworks folder of your project.
	
	The additional frameworks and libraries include the following: AudioToolbox.framework, AVFoundation.framework, AudioToolbox.framework, MediaPlayer.framework, Security.framework.

Next steps:

1. In the ViewController.h file, add the following line (after `import <UIKit/UIKit.h>`):

		#import <ECAR/GunConnection.h>

2. Edit the `@interface` declaration in the ViewController.h file to the following:

		@interface ViewController : UIViewController <GunConnectionDelegate>

3. Add a property for the GunConnection object.

		@property (nonatomic, strong) GunConnection *gunConnection;

4. Rename ViewController.m to ViewController.mm (required because the ECAR SDK uses some c++ libraries)

5. In the ViewController.mm viewDidLoad method, add the following code to initialize and start the connection to the gun.

		self.gunConnection = [[GunConnection alloc] initWithDelegate: self];
		[self.gunConnection startListening];
		

6. Implement the required method for GunConnectionDelegate eventReceived.

		- (void)eventReceived:(GunEvent)event {
			// handle gun event
		}

License
-----------------------------------------------

EliteCommandAR iOS SDK is available under the Apache License, Version 2.0 license. See the LICENSE.txt file for more info.