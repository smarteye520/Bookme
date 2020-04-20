//
//  NSNumberExtension.swift
//  Bookme
//
//  Created by Stdio.hue on 10/17/17.
//  Copyright © 2017 Apple. All rights reserved.
//

extension NSNumber {
    
    func string() -> String {
        let formatter = NumberFormatter()
        formatter.numberStyle = .decimal
        //        formatter.groupingSeparator = "."
        //        formatter.decimalSeparator = ","
        return formatter.string(from: self)!
    }
    
}
