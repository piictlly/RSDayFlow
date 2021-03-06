//
// RSDFDatePickerView.h
//
// Copyright (c) 2013 Evadne Wu, http://radi.ws/
// Copyright (c) 2013-2014 Ruslan Skorb, http://lnkd.in/gsBbvb
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#import <UIKit/UIKit.h>

@protocol RSDFDatePickerViewDelegate;
@protocol RSDFDatePickerViewDataSource;

/**
 The `RSDFDatePickerView` is a calendar view with infinity scrolling.
*/
@interface RSDFDatePickerView : UIView

/**
 Designated initializer. Initializes and returns a newly allocated view object with the specified frame rectangle and the specified calendar.
 
 @param frame The frame rectangle for the view, measured in points.
 @param calendar The calendar for the date picker view.
 */
- (instancetype)initWithFrame:(CGRect)frame calendar:(NSCalendar *)calendar;

///-----------------------------
/// @name Accessing the Delegate
///-----------------------------

/**
 The receiver's delegate.
 
 @discussion A `RSDFDatePickerView` delegate responds to message sent by tapping on date in the date picker view.
 */
@property (nonatomic, readwrite, weak) id<RSDFDatePickerViewDelegate> delegate;

///--------------------------------
/// @name Accessing the Data Source
///--------------------------------

/**
 The receiver's data source.
 
 @discussion A `RSDFDatePickerView` data source provides dates to mark in the date picker view.
 */

@property (nonatomic, readwrite, weak) id<RSDFDatePickerViewDataSource> dataSource;

///-----------------------------------
/// @name Scrolling to the Current Day
///-----------------------------------

/**
 Scrolls the date picker view to the current day.
 
 @param animated YES if you want to animate the change in position, NO if it should be immediate.
 */

- (void)scrollToToday:(BOOL)animated;

///-------------------------
/// @name Reloading the Data
///-------------------------

/**
 Reloads all of the data for the date picker view.
 
 @discussion Discard the dataSource and delegate data and requery as necessary.
 */
- (void)reloadData;

///------------------------------------
/// @name Accessing Classes of Subviews
///------------------------------------

/**
 The class of the view with labels for each day of the week. Default value is `RSDFDatePickerDaysOfWeekView`.
 
 @discussion Can be overridden in subclasses for customization.
 */
- (Class)daysOfWeekViewClass;

/**
 The class of the collection view which used to display days and months in the date picker view. Default value is `RSDFDatePickerCollectionView`.
 
 @discussion Can be overridden in subclasses for customization.
 */
- (Class)collectionViewClass;

/**
 The class of the layout of the collection view which used the date picker. Default value is `RSDFDatePickerCollectionViewLayout`.
 
 @discussion Can be overridden in subclasses for customization.
 */
- (Class)collectionViewLayoutClass;

/**
 The class of the reusable view which used to display a month and year in the date picker view. Default value is `RSDFDatePickerMonthHeader`.
 
 @discussion Can be overridden in subclasses for customization.
 */
- (Class)monthHeaderClass;

/**
 The class of the cell which used to display a day in the date picker view. Default value is `RSDFDatePickerDayCell`.
 
 @discussion Can be overridden in subclasses for customization.
 */
- (Class)dayCellClass;

@end

/**
 The `RSDFDatePickerViewDelegate` protocol defines the message sent to a date picker view delegate when date is tapped.
 */
@protocol RSDFDatePickerViewDelegate <NSObject>

///-----------------------------------
/// @name Responding to Date Selection
///-----------------------------------

@optional

/**
 Tells the delegate that the user did select a date.
 
 @param view The view whose date was selected.
 @param date The selected date.
 */
- (void)datePickerView:(RSDFDatePickerView *)view didSelectDate:(NSDate *)date;

@end

/**
 The `RSDFDatePickerViewDataSource` protocol is adopted by an object that provides dates to mark in the date picker view.
 */
@protocol RSDFDatePickerViewDataSource <NSObject>

///------------------------------
/// @name Providing Dates to Mark
///------------------------------

@optional

/**
 Provides dates to mark for the data source.
 
 @param view The view to whom dates are provided.
 
 @return The dictionary that contains dates (as keys) and completeness of tasks on these days (as objects).
 */
- (NSDictionary *)datePickerViewMarkedDates:(RSDFDatePickerView *)view;

@end
