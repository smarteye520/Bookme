//
//  Fonts.swift
//  Bookme
//
//  Created by Stdio.hue on 10/17/17.
//  Copyright © 2017 Apple. All rights reserved.
//

import UIKit

struct Fonts {
    
    static func standard(_ pointSize: CGFloat) -> UIFont {
        return UIFont.systemFont(ofSize: pointSize)
    }
    
    static func bold(_ pointSize: CGFloat) -> UIFont {
        return UIFont.boldSystemFont(ofSize: pointSize)
    }
    
    static func light(_ pointSize: CGFloat) -> UIFont {
        return UIFont.systemFont(ofSize: pointSize, weight: UIFontWeightLight)
    }
    
}
