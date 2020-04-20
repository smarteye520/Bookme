//
//  RightViewCell.swift
//  Bookme
//
//  Created by Oleksiy on 10/6/17.
//  Copyright © 2017 Leopard. All rights reserved.
//

import UIKit

class RightViewCell: UITableViewCell {

    @IBOutlet weak var menutitleLabel: UILabel!
    @IBOutlet weak var menuIconImageView: UIImageView!
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}
