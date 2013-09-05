//
//  RoboMe.h
//  RoboMe
//
//  Created by Josh Savage on 1/7/13.
//  Copyright (c) 2013 WowWee Group Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
@protocol GunConnectionDelegate;

/** The GunConnection class provides a way to send and receive commands to WowWee's Elite CommandAR Pistol.
 */
@interface GunConnection : NSObject 


typedef enum {
    // Trigger pressed
    GunEvent_TriggerPressed = 1,
    // Trigger released
    GunEvent_TriggerReleased = 2,
    // Gun went to sleep
    GunEvent_Disconnect = 4,
    // Button 1 pressed (weapon select button)
    GunEvent_Button1Pressed = 5,
    // Button 1 released (weapon select button)
    GunEvent_Button1Released = 6,
    // Button 2 pressed (grenade button)
    GunEvent_Button2Pressed = 7,
    // Button 2 released (grenade button)
    GunEvent_Button2Released = 8,
    // Button 3 pressed (shield button)
    GunEvent_Button3Pressed = 9,
    // Button 3 released (shield button)
    GunEvent_Button3Released = 10,
    // Button 4 pressed (reload button)
    GunEvent_Button4Pressed = 11,
    // Button 4 released (reload button)
    GunEvent_Button4Released = 12,
    // Keep alive for gun connection
    GunEvent_KeepAlive = 25,
    // Sent when gun is connected
    GunEvent_Connect = 28,
    // Undefined event
    GunEvent_Undefined = 29
} GunEvent;

/** GunConnectionDelegate to be called when commands are received from the robot. */
@property (nonatomic, strong) id<GunConnectionDelegate> delegate;

/** Initialize GunConnection object with GunConnectionDelegate delegate.
 
 @param delegate GunConnectionDelegate to be called when events are received from the gun.
 */
- (id)initWithDelegate: (id)delegate;

/** Start listening to events from the gun. */
-(void)startListening;

/** Stop listening to events from the gun. */
-(void)stopListening;

/** Is currently listening on the headphone jack.
 
 @return Is currently listening.
 */
-(BOOL)isListening;

/** Initializes the audio session.
 
    Note generally doesn't need to be called as it is run automatically
    the first time startListening method is called. */
- (void)initAudioSession;

/** Returns device volume.
 
 @return Volume is between 0.0-1.0 (1.0 max. volume).
 */
-(float)getVolume;

/** Returns ECAR SDK library version.
 
 @return ECAR SDK library version.
 */
-(NSString *)getLibVersion;

/** Returns whether or not gun is connected.
 
 @return Gun is currently connection.
 */
- (BOOL)isGunConnected;

/** Returns whether or not a headset is plugged in.
 
 @return Headset is plugged in
 */
- (BOOL)isHeadsetPluggedIn;

/** Returns whether or not audio route is to wired headset;
 
 @return Route is to headset
 */
- (BOOL)isRouteToWiredHeadset;

/** Returns whether or not audio route is to an Airplay device;
 
 @return Route is to Airplay
 */
- (BOOL)isOutputRouteToAirplay;

/** Returns whether or not audio route is to HDMI;
 
 @return Route is to HDMI
 */
- (BOOL)isOutputRouteToHDMI;

/** Returns whether or not audio route is to USB Audio Device;
 
 @return Route is to USB Audio Device
 */
- (BOOL)isRouteToUSBAudioDevice;

/** Returns whether or not audio route is to Bluetooth Device;
 
 @return Route is to Bluetooth Device
 */
- (BOOL)isRouteToBluetoothDevice;

/** Returns readable string for GunEvent
 
 @param event Event
 
 @return Readable string for GunEvent */
+ (NSString *)eventToString: (GunEvent)event;

/** Gun events received from the ECAR pistol
 
 typedef enum {
 // Trigger pressed
 GunEvent_TriggerPressed = 1,
 
 // Trigger released
 GunEvent_TriggerReleased = 2,
 
 // Gun went to sleep
 GunEvent_Disconnect = 4,
 
 // Button 1 pressed (weapon select button)
 GunEvent_Button1Pressed = 5,
 
 // Button 1 released (weapon select button)
 GunEvent_Button1Released = 6,
 
 // Button 2 pressed (grenade button)
 GunEvent_Button2Pressed = 7,
 
 // Button 2 released (grenade button)
 GunEvent_Button2Released = 8,
 
 // Button 3 pressed (shield button)
 GunEvent_Button3Pressed = 9,
 
 // Button 3 released (shield button)
 GunEvent_Button3Released = 10,
 
 // Button 4 pressed (reload button)
 GunEvent_Button4Pressed = 11,
 
 // Button 4 released (reload button)
 GunEvent_Button4Released = 12,
 
 // Keep alive for gun connection
 GunEvent_KeepAlive = 25,
 
 // Sent when gun is connected
 GunEvent_Connect = 28,
 
 // Undefined event
 GunEvent_Undefined = 29
 } GunEvent; */


@end

/** The GunConnectionDelegate protocal allows you to receive commands from the gun and get information about the headset connection.  */
@protocol GunConnectionDelegate <NSObject>

/** Called when a command received from RoboMe.
 
 @param command GunEvent received from the gun. */
- (void)eventReceived:(GunEvent)event;

@optional
/** Called when the gun is connected */
- (void)gunConnected;

/** Called when the gun is disconnected
 
    Note if the gun is turned off while still connected this method is not called.
 */
- (void)gunDisconnected;

/** Called when headset is plugged in */
- (void)headsetPluggedIn;

/** Called when headset is unplugged */
- (void)headsetUnplugged;

/** Called when volume changes.
 
    Note this is useful for prompting the user to set the correct volume level for receiving commands.
 
    @param volume Value is between 0.0-1.0 (1.0 max. volume). */
- (void)volumeChanged: (float)volume;


@end