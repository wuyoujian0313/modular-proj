//
//  AppDelegate.m
//  mesop
//
//  Created by Wu YouJian on 2019/7/5.
//  Copyright © 2019 AI. All rights reserved.
//

#import "AppDelegate.h"
#import <AIBase/AIBase.h>

@interface AppDelegate ()
@property (nonatomic, strong) AINavigationController        *mainNav;
@property (nonatomic, strong) AIWKWebViewController         *mainVC;

@end

@implementation AppDelegate

+ (AppDelegate*)shareMyApplication {
    return (AppDelegate*)[UIApplication sharedApplication].delegate;
}

- (void)useWKWebViewController {
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    AIWKWebViewController *tempVC = [[AIWKWebViewController alloc] init];
    self.mainVC = tempVC;
    
    AINavigationController *tempNav = [[AINavigationController alloc] initWithRootViewController:_mainVC];
    self.mainNav = tempNav;
    _mainNav.navigationBarHidden = YES;
    
    self.window.rootViewController = _mainNav;
    [_window makeKeyAndVisible];
}

- (void)layoutMainPage {
    [self useWKWebViewController];
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    [self layoutMainPage];
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}


- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

- (void)handleURL:(NSURL *)url {
    NSData *jsonData = [url.host dataUsingEncoding:NSUTF8StringEncoding];
    NSError *error = nil;
    NSDictionary *dic = [NSJSONSerialization JSONObjectWithData:jsonData
                                                        options:NSJSONReadingMutableContainers error:&error];
    
    [[NSNotificationCenter defaultCenter] postNotificationName:@"toPlugin10085Notification" object:dic userInfo:nil];
}
- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey, id> *)options {
    [self handleURL:url];
    return YES;
}

- (BOOL)application:(UIApplication *)application handleOpenURL:(NSURL *)url  {
    [self handleURL:url];
    return YES;
}

- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation {
    [self handleURL:url];
    return YES;
}

@end
