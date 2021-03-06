//
//  VICacheConfiguration.h
//  VIMediaCacheDemo
//
//  Created by Vito on 4/21/16.
//  Copyright © 2016 Vito. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface VICacheConfiguration : NSObject <NSMutableCopying, NSCopying>

+ (instancetype)configurationWithFilePath:(NSString *)filePath;

@property (nonatomic, copy, readonly) NSString *filePath;

@property (nonatomic, strong, readonly) NSURLResponse *response;
- (NSArray<NSValue *> *)cacheFragments;

/**
 *  cached progress
 */
@property (nonatomic, readonly) float progress;
@property (nonatomic, readonly) long long downloadedBytes;
@property (nonatomic, readonly) float downloadSpeed; // kb/s

@end

@interface VIMutableCacheConfiguration : VICacheConfiguration

- (void)updateResponse:(NSURLResponse *)response;
- (void)save;
- (void)addCacheFragment:(NSRange)fragment;

/**
 *  Record the download speed
 */
- (void)addDownloadedBytes:(long long)bytes spent:(NSTimeInterval)time;

@end
