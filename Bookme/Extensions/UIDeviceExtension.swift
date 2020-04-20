//
//  UIDeviceExtension.swift
//  Bookme
//
//  Created by Stdio.hue on 10/17/17.
//  Copyright © 2017 Apple. All rights reserved.
//

import UIKit

extension UIDevice {
    
    enum DeviceType {
        case iPhone35, iPhone40, iPhone47, iPhone55, other
    }
    
    static var deviceType: DeviceType {        
        switch UIScreen.main.bounds.size.height {
        case 480:
            return .iPhone35
        case 568:
            return .iPhone40
        case 667:
            return .iPhone47
        case 736:
            return .iPhone55
        default:
            return .other
        }
    }
    
}
