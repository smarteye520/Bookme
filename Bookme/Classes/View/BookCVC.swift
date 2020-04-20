//
//  BookCVC.swift
//  Bookme
//
//  Created by Oleksiy on 10/2/17.
//  Copyright © 2017 Leopard. All rights reserved.
//

import UIKit
import Kingfisher

class BookCVC: UICollectionViewCell {
    
    @IBOutlet weak var bookCoverImage: UIImageView!
    @IBOutlet weak var downloadImage: UIImageView!
    
    func configureWithBoolModel(_ bookModel: BookModel) {
        self.downloadImage.image = UIImage.init(named: "downloadicon")
        let bookCoveURLString = WEB_SITE_IMAGE_URL + (bookModel.danacode! as String) + ".jpg"
        self.bookCoverImage.kf.setImage(with: URL(string: bookCoveURLString))
    }
}
