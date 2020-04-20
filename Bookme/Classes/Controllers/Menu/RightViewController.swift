//
//  RightViewController.swift
//  Bookme
//
//  Created by Oleksiy on 10/1/17.
//  Copyright © 2017 Leopard. All rights reserved.
//

import UIKit

enum RightMenu: Int {
    case main = 0
    case setting
    case shopping
    case logOut
}

protocol RightMenuProtocol : class {
    func changeViewController(_ menu: RightMenu)
}

class RightViewController: UIViewController {
    
    var mainViewController: UIViewController!

    @IBOutlet weak var userEmailLabel: UILabel!
    @IBOutlet weak var tableView: UITableView!
    
    fileprivate var menus = [your_books, action_settings, buy_book,  action_logout]
    fileprivate var menuIcons = [#imageLiteral(resourceName: "books"), #imageLiteral(resourceName: "setting"), #imageLiteral(resourceName: "shopping_cart"), #imageLiteral(resourceName: "arrow")]
    
    lazy fileprivate var settingViewController: UIViewController = {
        let storyboard = UIStoryboard(name: "Main", bundle: nil)
        let settingVC = storyboard.instantiateViewController(withIdentifier: "SettingVC") as! SettingVC
        return UINavigationController(rootViewController: settingVC)
    }()
    
    //MARK: - View Lifecycle

    override func viewDidLoad() {
        super.viewDidLoad()
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        userEmailLabel.text = Config.getUserEmail()
    }
    
    //MARK: Menu action
    
    fileprivate func changeViewController(_ menu: RightMenu) {
        switch menu {
        case .main:
            self.slideMenuController()?.changeMainViewController(self.mainViewController, close: true)
        case .setting:
            self.slideMenuController()?.changeMainViewController(self.settingViewController, close: true)
        case .shopping:
            if let url = URL.init(string: website_link) {
                if #available(iOS 10.0, *) {
                    UIApplication.shared.open(url, options: [:], completionHandler: nil)
                } else {
                    // Fallback on earlier versions
                }
            }
            
        case .logOut: // LoginViewController
            Config.setAuthorizedUser(_applicationGuid: "")
            Config.setUserEmail(_emailAddress: "")
            let storyboard = UIStoryboard(name: "Main", bundle: nil)
            let loginVC = storyboard.instantiateViewController(withIdentifier: "LoginViewController") as! LoginViewController
            AppDelegate.getAppDelegate().window?.rootViewController = loginVC
        }
        
    }
    
}

//MARK: - Table View Datasource
extension RightViewController: UITableViewDataSource {
   
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return menus.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        
        let cell = tableView.dequeueReusableCell(withIdentifier: "rightMenuCell", for: indexPath) as! RightViewCell
        
        cell.menutitleLabel.text = menus[indexPath.row]
        cell.menuIconImageView.image = menuIcons[indexPath.row]
        
        return cell
    }
}

//MARK: - Table View Delegate
extension RightViewController: UITableViewDelegate {
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        if let menu = RightMenu(rawValue: indexPath.row) {
            self.changeViewController(menu)
        }
    }
}
