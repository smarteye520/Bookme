//
//  DateExtension.swift
//  Bookme
//
//  Created by Stdio.hue on 10/17/17.
//  Copyright © 2017 Apple. All rights reserved.
//

import UIKit

extension Date {
    
    fileprivate static let dateFormatter: DateFormatter = {
        $0.setLocalizedDateFormatFromTemplate("MM/dd/yyyy")
        return $0
    }(DateFormatter())
    
    var dateString: String {
        return Date.dateFormatter.string(from: self)
    }
    
    func adding(days: Int) -> Date {
        return Calendar.current.date(byAdding: .day, value: days, to: self)!
    }
    
    func daysBetween() -> Int {
        let units: Set<Calendar.Component> = [.day]
        let components = Calendar.current.dateComponents(units, from: Date(), to: self)
        return components.day!
    }
    
}
