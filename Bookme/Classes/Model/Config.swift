//
//  Config.swift
//  Bookme
//
//  Created by Oleksiy on 9/29/17.
//  Copyright © 2017 Leopard. All rights reserved.
//

import UIKit

class Config: NSObject {
    
    static func setAuthorizedUser(_applicationGuid: String) {
        UserDefaults.standard.set(_applicationGuid, forKey: APPLICATIONGUID)
    }
    
    static func getAuthorizedUser() -> String? {
        return UserDefaults.standard.string(forKey: APPLICATIONGUID)
    }
    
    static func setUserEmail(_emailAddress: String) {
        UserDefaults.standard.set(_emailAddress, forKey: EMAIL_ADDRESS)
    }
    
    static func getUserEmail() -> String? {
        return UserDefaults.standard.string(forKey: EMAIL_ADDRESS)
    }

}
