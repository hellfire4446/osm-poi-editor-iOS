//
//  OPECategoryViewController.h
//  OSM POI Editor
//
//  Created by David Chiles on 2/13/12.
//  Copyright (c) 2011 David Chiles. All rights reserved.
//
//  This file is part of POI+.
//
//  POI+ is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  POI+ is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with POI+.  If not, see <http://www.gnu.org/licenses/>.

#import <UIKit/UIKit.h>
#import "OPETypeViewController.h"

@interface OPECategoryViewController : UIViewController <UITableViewDelegate, UITableViewDataSource, UISearchDisplayDelegate, UISearchBarDelegate>

@property (nonatomic,strong) IBOutlet UITableView * mainTableView;
@property (nonatomic,strong) UISearchDisplayController * searchDisplayController;
@property (nonatomic,strong) IBOutlet UISearchBar * searchBar;
//@property (nonatomic,strong) NSDictionary * categoriesAndTypes;
@property (nonatomic,strong) NSArray * categoriesArray;
@property (nonatomic,strong) NSDictionary * typesDictionary;

@property (nonatomic, strong) id <PassCategoryAndType> delegate;

@property (nonatomic, retain) NSMutableArray *searchResults;

@end
