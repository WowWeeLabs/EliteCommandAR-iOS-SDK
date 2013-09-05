//
//  ViewController.h
//  RoboMeBasicSample
//
//  Copyright (c) 2013 WowWee Group Limited. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <ECAR/GunConnection.h>

@interface ViewController : UIViewController <GunConnectionDelegate>

@property (weak, nonatomic) IBOutlet UITextView *outputTextView;

@end
