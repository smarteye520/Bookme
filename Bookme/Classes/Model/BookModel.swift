//
//  BookModel.swift
//  Bookme
//
//  Created by Oleksiy on 10/2/17.
//  Copyright © 2017 Leopard. All rights reserved.
//

import UIKit
//import Chapter

class BookModel: NSObject {
    
    var id: NSInteger!
    var name: NSString!
    var danacode: NSString!
    var coverName: NSString!
    var isLocal: Bool!
    var author: NSString!
    var manufacturer: NSString!
    var chapters = [Chapter]()
    var book_description: NSString!


}
