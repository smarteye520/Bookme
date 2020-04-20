//
//  NativeBridge.h
//  Bookme
//
//  Created by Nguyen Chi Dung on 10/21/17.
//  Copyright © 2017 Leopard. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NativeBridge : NSObject

+ (instancetype)sharedInstance;

- (void)downloadBookWithUserId:(NSString *)userId bookId:(NSString *)bookId;

@end
