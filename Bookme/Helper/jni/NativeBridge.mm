//
//  NativeBridge.m
//  Bookme
//
//  Created by Nguyen Chi Dung on 10/21/17.
//  Copyright © 2017 Leopard. All rights reserved.
//

#import "NativeBridge.h"
#import "rsa-jni.h"

@interface NativeBridge()

@property (nonatomic, assign) long nativeSession;

@end

@implementation NativeBridge

+ (instancetype)sharedInstance {
    static id sharedInstance = nil;
    
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[self alloc] init];
    });
    
    return sharedInstance;
}

- (long)nativeSession {
    if (_nativeSession == 0) {
        
        char *path = (char *)[[self applicationDocumentsDirectory] UTF8String];
       
        self.nativeSession = il_co_bookme_bookmedigital_NativeBridge_Init(path);
    }
    
    return _nativeSession;
}

- (void)downloadBookWithUserId:(NSString *)userId bookId:(NSString *)bookId {
    
    char *path = (char *)[[self applicationDocumentsDirectory] UTF8String];
    
    char *d = (char *)[bookId UTF8String];
    
    char *u = (char *)[userId UTF8String];
    
    NSLog(@"Folder: %@", [self applicationDocumentsDirectory] );
    
    int download = il_co_bookme_bookmedigital_NativeBridge_DownloadBook(d, u, self.nativeSession, path);
    
    NSLog(@"%zd", download);
}

- (NSString *)applicationDocumentsDirectory
{
    return [[[[NSFileManager defaultManager] URLsForDirectory:NSDocumentDirectory
                                                    inDomains:NSUserDomainMask] lastObject] absoluteString];
}

@end
