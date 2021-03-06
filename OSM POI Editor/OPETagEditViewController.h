//
//  OPETagEditViewController.h
//  OSM POI Editor
//
//  Created by David on 3/25/13.
//
//

#import <UIKit/UIKit.h>
#import "OPEMRUtility.h"
#import "OPEManagedReferenceOptional.h"
#import "OPEConstants.h"
#import "OPEManagedOsmElement.h"
#import "OPEDone+CancelViewController.h"

typedef void (^newTagBlock)(NSString * key,NSString * value);

@interface OPETagEditViewController : OPEDone_CancelViewController

@property (nonatomic, strong) NSString * osmKey;
@property (nonatomic, strong) NSString * currentOsmValue;
@property (nonatomic, strong) OPEManagedReferenceOptional * managedOptional;
@property (nonatomic, strong) OPEManagedOsmElement * element;

@property (nonatomic, readonly) BOOL showDoneButton;

@property (nonatomic, copy) newTagBlock completionBlock;

-(id)initWithOsmKey:(NSString *)osmKey value:(NSString *)value withCompletionBlock:(newTagBlock)newCompletionBlock;

+(OPETagEditViewController *)viewControllerWithOsmKey:(NSString *)osmKey currentOsmValue:(NSString *)osmValue andType:(OPEOptionalType)type withCompletionBlock:(newTagBlock)newCompletionBlock;

+(NSString *)sectionFootnoteForOsmKey:(NSString *)osmKey;

@end
