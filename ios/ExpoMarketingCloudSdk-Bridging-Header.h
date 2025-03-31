//
// Use this file to import your target's public headers that you would like to expose to Swift.
//
#import <EXNotifications/EXNotificationCenterDelegate.h>
#import <MarketingCloudSDK/MarketingCloudSDK.h>
#import "RCTAppDelegate.h"

// Implement the SFMCSdkURLHandlingDelegate delegate
@interface AppDelegate : RCTAppDelegate <UNUserNotificationCenterDelegate, SFMCSdkURLHandlingDelegate>
@end // Added semicolon here to close the @interface block

@implementation AppDelegate

// This method is called after successfully initializing the SFMCSdk
- (void)pushSetup {
    dispatch_async(dispatch_get_main_queue(), ^{
        // Here we set the URL Handling delegate to present URLs from CloudPages, OpenDirect, and In-App Messages
        [[SFMCSdk mp] setURLHandlingDelegate:self];
        // Set UNUserNotificationCenter delegate, register for remote notifications, etc...
    });
}

// ...
// Implement the required delegate method to handle URLs
- (void)sfmc_handleURL:(NSURL * _Nonnull)url type:(NSString * _Nonnull)type {
    if ([[UIApplication sharedApplication] canOpenURL:url]) {
        [[UIApplication sharedApplication] openURL:url options:@{} completionHandler:^(BOOL success) {
            if (success) {
                NSLog(@"url %@ opened successfully", url);
            } else {
                NSLog(@"url %@ could not be opened", url);
            }
        }];
    }
}

@end
