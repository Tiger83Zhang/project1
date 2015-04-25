//
//  CustomTableView.h
//  PayforCreditCardController
//
//  Created by Shen on 12-2-8.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface CMTableView : UITableView {
    UIEdgeInsets    _priorInset;
    BOOL            _keyboardVisible;
    CGRect          _keyboardRect;
}

- (void)findAndResignFirstResponder;
- (void)adjustOffsetToIdealIfNeeded;

@end