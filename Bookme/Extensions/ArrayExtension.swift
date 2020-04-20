//
//  ArrayExtension.swift
//  Bookme
//
//  Created by Stdio.hue on 10/17/17.
//  Copyright © 2017 Apple. All rights reserved.
//

import Foundation

extension Array {
    
    var random: Iterator.Element? {
        guard !isEmpty else {
            return nil
        }
        
        let index = Int(arc4random_uniform(UInt32(count)))
        return self[index]
    }
    
    
}

extension Array where Element: Equatable {
    mutating func remove(_ object: Element) {
        if let index = index(of: object) {
            remove(at: index)
        }
    }
}
