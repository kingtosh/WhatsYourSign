//
//  Signing.h
//  WhatsYourSign
//
//  Created by Patrick Wardle on 7/7/16.
//  Copyright (c) 2016 Objective-See. All rights reserved.
//

#ifndef WYS_Signing_h
#define WYS_Signing_h

#import <AppKit/AppKit.h>
#import <Foundation/Foundation.h>

/* FUNCTIONS */

//get signing info for XIP
NSDictionary* checkXIP(NSString* archive);

//get the signing info of a file
NSDictionary* extractSigningInfo(NSString* path);

//determine if file is signed with Apple Dev ID/cert
BOOL isSignedDevID(NSString* binary);

//determine if a file is from the app store
// gotta be signed w/ Apple Dev ID & have valid app receipt
BOOL fromAppStore(NSString* path);

//get GUID (really just computer's MAC address)
// from Apple's 'Get the GUID in OS X' (see: 'Validating Receipts Locally')
NSData* getGUID(void);

//determine if a file is signed by Apple proper
BOOL isApple(NSString* path);

//check if a file has a cert that has been revoked
// just invokes 'spctl --assess <path to file>' and looks for 'CSSMERR_TP_CERT_REVOKED'
BOOL isRevoked(NSString* path);

//extract entitlements
// invokes 'codesign' to extract
NSDictionary* extractEntitlements(NSString* path);

#endif
