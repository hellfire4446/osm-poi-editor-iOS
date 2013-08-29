//
//  OPEOpeningHoursEditViewController.m
//  OSM POI Editor
//
//  Created by David on 8/29/13.
//
//

#import "OPEOpeningHoursEditViewController.h"
#import "OPEOpeningHoursRuleEditViewController.h"

@interface OPEOpeningHoursEditViewController ()

@end

@implementation OPEOpeningHoursEditViewController

@synthesize rulesArray,openingHoursParser;

-(id)init {
    if (self = [super init]) {
        self.openingHoursParser = [[OPEOpeningHoursParser alloc] init];
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    if ([self.currentOsmValue length]) {
        [self.openingHoursParser parseString:self.currentOsmValue success:^(NSArray *blocks) {
            self.rulesArray = [blocks mutableCopy];
            //[rulesTableView reloadData];
        } failure:^(NSError *error) {
            NSLog(@"Error %@",error);
        }];
    }
    else {
        self.rulesArray = [NSMutableArray array];
    }
    
    rulesTableView = [[UITableView alloc] initWithFrame:self.view.bounds style:UITableViewStylePlain];
    rulesTableView.dataSource = self;
    rulesTableView.delegate = self;
    rulesTableView.autoresizingMask = UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth;
    
    [self.view addSubview:rulesTableView];
    
	// Do any additional setup after loading the view.
}

#pragma mark TableView

-(NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}
-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [self.rulesArray count]+1;
}

-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    NSString * cellIdentifierString = @"cellIdentifierString";
    UITableViewCell * cell = [tableView dequeueReusableCellWithIdentifier:cellIdentifierString];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:cellIdentifierString];
    }
    
    if ([indexPath isEqual:[self lastIndexPathForTableView:tableView]]) {
        cell.textLabel.text = @"Add Rule";
    }
    else {
        OPEOpeningHourRule * rule = self.rulesArray[indexPath.row];
        cell.textLabel.text = [self.openingHoursParser stringWithRule:rule];
    }
    return cell;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    OPEOpeningHourRule * rule = nil;
    if (![indexPath isEqual:[self lastIndexPathForTableView:tableView]]) {
        //Edit Rule
        rule = self.rulesArray[indexPath.row];
    }
    OPEOpeningHoursRuleEditViewController * ruleEditViewController = [[OPEOpeningHoursRuleEditViewController alloc] initWithRule:rule];
    [self.navigationController pushViewController:ruleEditViewController animated:YES];
    
}

-(NSIndexPath *)lastIndexPathForTableView:(UITableView *)tableView
{
    NSInteger lastSectionIndex = [tableView numberOfSections] - 1;
    NSIndexPath *lastIndexPath = [NSIndexPath indexPathForRow:([tableView numberOfRowsInSection:lastSectionIndex] - 1) inSection:lastSectionIndex];
    
    return lastIndexPath;
}

@end
