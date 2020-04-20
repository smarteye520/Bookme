//
//  SettingVC.swift
//  Bookme
//
//  Created by Oleksiy on 10/6/17.
//  Copyright © 2017 Leopard. All rights reserved.
//

import UIKit

class SettingVC: UIViewController {

    //MARK: - View Lifecycle
    override func viewDidLoad() {
        super.viewDidLoad()
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(true)
        configureUI()
    }
    
    //MARK: - Helper
    
    private func configureUI() {
        self.setNavigationBarItem()
        self.navigationController?.navigationBar.barTintColor = UIColor(red: 54.0 / 255, green: 54.0 / 255, blue: 91.0 / 255, alpha: 1.0)
        self.setNavigationBarItem()
        self.navigationController?.navigationBar.tintColor = .white
        
        let titleAttributes = [
            NSFontAttributeName: UIFont.systemFont(ofSize: 25)
        ]
        self.navigationController?.navigationBar.titleTextAttributes = titleAttributes
        
        self.navigationController?.navigationBar.titleTextAttributes = [NSForegroundColorAttributeName : UIColor.white]
        self.navigationController?.navigationBar.topItem?.title = action_settings
    }

}
