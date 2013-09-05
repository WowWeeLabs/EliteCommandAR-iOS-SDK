Elite CommandAR Pistol iOS SDK
===============

The ECAR iOS SDK lets you receive button presses from your [ECAR pistol](http://appgear.com/en/games/elite-commandar).

Documentation of the SDK is available here: http://www.wowweelabs.com/ecar/iOS/docs/index.html

Support is available at the RoboCommunity forums: http://www.robocommunity.com/.

For Android or Unity SDKs visit: http://www.wowweelabs.com/.

For information on WowWee products visit: http://www.wowwee.com/.

Getting Started
---------------------------------------

Download the [ECAR Android SDK](https://github.com/WowWeeLabs/ECAR-Android-SDK).

The quickest way to get started is to open the sample app under the SampleProject directory. The ECAR sample app starts listening to events from the gun and prints these to the text view.

Creating your own app using the ECAR iOS SDK
-----------------------------------------------

Here are the basic steps in creating your own app:

1. In XCode, create a new project. The simplest application is a Single-View application.

2. Open the project navigator in Xcode.

3. Drag the ECAR-iOS-SDK directory from the Mac OS Finder to the Frameworks directory for for your project in XCode. This directory contains the framework.

4. The ECAR framework requires a few other frameworks and libraries to be added to your project. The easiest way to add them is
to copy them from the ECARSample app under the SampleProject directory. 

	Open the ECARSample app in XCode. Drag all of the additional frameworks from the frameworks folder (in the project navigator)
	of the ECARSample project into the frameworks folder of your project.
	
	The additional frameworks and libraries include the following: AudioToolbox.framework, AVFoundation.framework, AudioToolbox.framework, MediaPlayer.framework, Security.framework.

Next steps:

1. In the ViewController.h file, add the following line (after `import <UIKit/UIKit.h>`):

		#import <ECAR/GunConnection.h>

2. Edit the `@interface` declaration in the ViewController.h file to the following:

		@interface ViewController : UIViewController <GunConnectionDelegate>

3. Add a property for the GunConnection object.

		@property (nonatomic, strong) GunConnection *gunConnection;

4. Rename ViewController.m to ViewController.mm (required because the GunConnection uses some c++ libraries)

5. In the ViewController.mm viewDidLoad method, add the following code to initialize and start the connection to the gun.

		self.gunConnection = [[GunConnection alloc] initWithDelegate: self];
		[self.gunConnection startListening];
		

6. Implement the required method for GunConnectionDelegate eventReceived.

		- (void)eventReceived:(GunEvent)event {
			// handle gun event
		}

License
-----------------------------------------------

ECAR iOS SDK is available under the Apache License, Version 2.0 license. See the LICENSE.txt file for more info.