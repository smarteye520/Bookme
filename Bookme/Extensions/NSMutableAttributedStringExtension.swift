//
//  NSMutableAttributedStringExtension.swift
//  Bookme
//
//  Created by Stdio.hue on 10/17/17.
//  Copyright © 2017 Apple. All rights reserved.
//

import UIKit

extension NSMutableAttributedString {
    
    func append(_ string: String, colour: UIColor = .black, font: UIFont) {
        let attributes: [String: AnyObject] = [NSForegroundColorAttributeName: colour, NSFontAttributeName: font]
        let aString = NSAttributedString(string: string, attributes: attributes)
        self.append(aString)
    }
    
    func update(_ string: String, color: UIColor, font: UIFont ) {
        let plainString = self.string
        let textRange = (plainString as NSString).range(of: string)
        addAttribute(NSForegroundColorAttributeName, value: color, range: textRange)
        addAttribute(NSFontAttributeName, value: font, range: textRange)
    }
    
}
