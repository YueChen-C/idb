/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <Foundation/Foundation.h>

#import <FBControlCore/FBFuture.h>
#import <FBControlCore/FBiOSTargetCommandForwarder.h>
#import <FBControlCore/FBiOSTargetFuture.h>

NS_ASSUME_NONNULL_BEGIN

@class FBApplicationBundle;

/**
 A protocol for a running debug server.
 */
@protocol FBDebugServer <FBiOSTargetContinuation>

/**
 The commands to execute within lldb to start a debug server.
 */
@property (nonatomic, copy, readonly) NSArray<NSString *> *lldbBootstrapCommands;

@end

/**
 Commands for starting a debug server.
 */
@protocol FBDebuggerCommands <NSObject, FBiOSTargetCommand>

/**
 Starts a gdb debug server for a given bundle id.
 The server is then bound on the TCP port provided.

 @param application the FBApplicationBundle instance for the application to debug. This *must* be present on the host's filesystem.
 @param port the TCP port to bind on the debug server on.
 @return a future that resolves with a debug server.
 */
- (FBFuture<id<FBDebugServer>> *)launchDebugServerForHostApplication:(FBApplicationBundle *)application port:(in_port_t)port;

@end

NS_ASSUME_NONNULL_END