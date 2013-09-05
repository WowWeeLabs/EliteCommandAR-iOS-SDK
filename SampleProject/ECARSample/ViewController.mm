//
//  ViewController.m
//  RoboMeBasicSample
//
//  Copyright (c) 2013 WowWee Group Limited. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@property (nonatomic, strong) GunConnection *gunConnection;

@end

@implementation ViewController 

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // create Gun Connection object
    self.gunConnection = [[GunConnection alloc] initWithDelegate: self];
    
    // start listening for events from the gun
    [self.gunConnection startListening];
    
}

// Print out given text to text view
- (void)displayText: (NSString *)text {
    NSString *outputTxt = [NSString stringWithFormat: @"%@\n%@", self.outputTextView.text, text];
    
    // print command to output box
    [self.outputTextView setText: outputTxt];
    
    // scroll to bottom
    [self.outputTextView scrollRangeToVisible:NSMakeRange([self.outputTextView.text length], 0)];
}

// Start listening button callback
- (IBAction)startListeningButtonPressed:(id)sender {
    [self.gunConnection startListening];
}

// Stop listening button callback
- (IBAction)stopListeningButtonPressed:(id)sender {
    [self.gunConnection stopListening];
}


#pragma mark - RoboMeConnectionDelegate

// Event received from RoboMe
- (void)eventReceived:(GunEvent)event {
    
    // Display gun event in text view
    [self displayText: [NSString stringWithFormat: @"Received: %@" , [GunConnection eventToString: event]]];
}

- (void)gunConnected {
    [self displayText: @"Gun Connected!"];
}

- (void)gunDisconnected {
    [self displayText: @"Gun Disconnected"];
}


@end
