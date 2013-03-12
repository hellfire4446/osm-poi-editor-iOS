#import "OPEManagedOsmTag.h"


@interface OPEManagedOsmTag ()

// Private interface goes here.

@end


@implementation OPEManagedOsmTag

+(OPEManagedOsmTag *)fetchOrCreateWithKey:(NSString *)key value:(NSString *)value
{
    NSPredicate *osmTagFilter = [NSPredicate predicateWithFormat:@"key == %@ AND value == %@",key,value];
    
    NSArray * results = [OPEManagedOsmTag MR_findAllWithPredicate:osmTagFilter];
    
    OPEManagedOsmTag * osmTag = nil;
    
    if(![results count])
    {
        osmTag = [OPEManagedOsmTag MR_createEntity];
        osmTag.key = key;
        osmTag.value = value;
    
    }
    else
    {
        osmTag = [results lastObject];
    }
    
    
    return osmTag;
}

@end
