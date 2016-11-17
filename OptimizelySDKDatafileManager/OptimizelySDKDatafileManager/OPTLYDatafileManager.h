/****************************************************************************
 * Copyright 2016, Optimizely, Inc. and contributors                        *
 *                                                                          *
 * Licensed under the Apache License, Version 2.0 (the "License");          *
 * you may not use this file except in compliance with the License.         *
 * You may obtain a copy of the License at                                  *
 *                                                                          *
 *    http://www.apache.org/licenses/LICENSE-2.0                            *
 *                                                                          *
 * Unless required by applicable law or agreed to in writing, software      *
 * distributed under the License is distributed on an "AS IS" BASIS,        *
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. *
 * See the License for the specific language governing permissions and      *
 * limitations under the License.                                           *
 ***************************************************************************/

#import <Foundation/Foundation.h>
#import "OPTLYDatafileManagerBuilder.h"
#import <OptimizelySDKCore/OPTLYErrorHandler.h>
#import <OptimizelySDKCore/OPTLYLogger.h>
#import <OptimizelySDKShared/OPTLYHTTPRequestManager.h>


@protocol OPTLYErrorHandler, OPTLYLogger;

@protocol OPTLYDatafileManager <NSObject>

/** 
 * Download the datafile for the project ID
 * @param projectId The project ID of the datafile to request.
 * @param completion Completion handler.
 */
- (void)downloadDatafile:(nonnull NSString *)projectId
       completionHandler:(nullable OPTLYHTTPRequestManagerResponse)completion;

@end

@interface OPTLYDatafileManager : NSObject<OPTLYDatafileManager>

/// The time interval to regularly fetch the datafile.
@property (nonatomic, readonly) NSTimeInterval datafileFetchInterval;
/// The project ID of the datafile this datafile manager will monitor
@property (nonatomic, readonly, strong, nonnull) NSString *projectId;
/// The error handler to be used for the manager, client, and all subcomponents
@property (nonatomic, readwrite, strong, nullable) id<OPTLYErrorHandler> errorHandler;
/// A logger for the OPTLYDatafileManager to log messages.
@property (nonatomic, readonly, strong, nonnull) id<OPTLYLogger> logger;

/**
 * Init with builder block
 * @param block The builder block containing the datafile fetch interval.
 * @return an Optimizely Datafile Manager instance.
 */
+ (nullable instancetype)initWithBuilderBlock:(nonnull OPTLYDatafileManagerBuilderBlock)block;

@end
