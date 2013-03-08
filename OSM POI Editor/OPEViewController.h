//
//  OPEViewController.h
//  OSM POI Editor
//
//  Created by David Chiles on 2/2/12.
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
#import "RMMapView.h"
#import "RMMapViewDelegate.h" 
#import <CoreLocation/CoreLocation.h>
#import "OPENode.h"
#import "OPEOSMData.h"
#import "OPEInfoViewController.h"
#import "OPENodeViewController.h"
#import "OPEMessage.h"

@interface OPEViewController : UIViewController <RMMapViewDelegate, CLLocationManagerDelegate, OPENodeViewDelegate,OPEInfoViewControllerDelegate,MBProgressHUDDelegate,NSFetchedResultsControllerDelegate> {
    RMMapView* mapView;
    UIImageView * plusImageView;
    
}

@property (nonatomic,strong) OPEOSMData * osmData;
@property (nonatomic,strong) CLLocationManager* locationManager;
@property (nonatomic,strong) OPETagInterpreter * interpreter;

@property (nonatomic,strong) UIBarButtonItem * infoButton;
@property (nonatomic,strong) UIBarButtonItem * location;
@property (nonatomic,strong) UIBarButtonItem * addOPEPoint;
@property (nonatomic,strong) RMAnnotation *openMarker;
@property (nonatomic,strong) RMMarker *theNewMarker;
@property (nonatomic,strong) UIView * label;
@property (nonatomic,strong) UILabel * calloutLabel;
@property (nonatomic,strong) RMMarker * addedNode;
@property (nonatomic,strong) RMMarker * nodeInfo;
@property (nonatomic,strong) RMMarker * currentLocationMarker;
@property (nonatomic) int currentTile;
@property (nonatomic, strong) OPEMessage * message;
@property (nonatomic, strong) NSMutableDictionary * imagesDic;
@property (nonatomic) RMSphericalTrapezium currentSquare;
@property (nonatomic) BOOL userPressedLocatoinButton;
@property (nonatomic) BOOL firstDownload;

@property (nonatomic,strong) NSFetchedResultsController * osmElementFetchedResultsController;

- (void) addMarkers:(NSNotification *) notification;
//- (void) pushMapAnnotationDetailedViewControllerDelegate:(id) sender;
//- (void) buttonEvent:(id)sender;

-(IBAction)infoButtonPressed:(id)sender;
-(IBAction)addPointButtonPressed:(id)sender;
-(IBAction)locationButtonPressed:(id)sender;

@end
