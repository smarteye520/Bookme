//
//  UIImageExtension.swift
//  Bookme
//
//  Created by Stdio.hue on 10/17/17.
//  Copyright © 2017 Apple. All rights reserved.
//

import UIKit

extension UIImage {
    
    static var screenShoot: UIImage? {
        let windowBounds = UIApplication.shared.keyWindow!.bounds
        UIGraphicsBeginImageContextWithOptions(windowBounds.size, true, 0)
        UIApplication.shared.keyWindow!.drawHierarchy(in: windowBounds, afterScreenUpdates: false)
        let image = UIGraphicsGetImageFromCurrentImageContext()
        UIGraphicsEndImageContext()
        return image
    }
    
    func cropImage(atRect rect: CGRect) -> UIImage {
        let imageRef = self.cgImage!.cropping(to: rect)
        return UIImage(cgImage: imageRef!)        
    }
    
}
