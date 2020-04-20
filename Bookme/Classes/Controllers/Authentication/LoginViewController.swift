//
//  LoginViewController.swift
//  Bookme
//
//  Created by Oleksiy on 9/29/17.
//  Copyright © 2017 Leopard. All rights reserved.
//

import UIKit
import Alamofire

class LoginViewController: UIViewController {
    
    @IBOutlet weak var singinButton: UIButton!
    @IBOutlet weak var emailTF: SkyFloatingLabelTextField!
    @IBOutlet weak var passwdTF: SkyFloatingLabelTextField!
    
    //MARK: - View Lifecycle
    
    override func viewDidLoad() {
        super.viewDidLoad()
    }
    
    //MARK: - Action
    
    @IBAction func signinButtonClicked(_ sender: Any) {
        getLoginGuid()
    }
    
    private func gotoMain() {
        let storyboard = UIStoryboard(name: "Main", bundle: nil)
        let mainViewController = storyboard.instantiateViewController(withIdentifier: "MainViewController") as! MainViewController
        let leftViewController = storyboard.instantiateViewController(withIdentifier: "LeftViewController") as! LeftViewController
        let rightViewController = storyboard.instantiateViewController(withIdentifier: "RightViewController") as! RightViewController
        
        
        let nvc: UINavigationController = UINavigationController(rootViewController: mainViewController)
        rightViewController.mainViewController = nvc
        
        let slideMenuController = ExSlideMenuController(mainViewController:nvc, leftMenuViewController: leftViewController, rightMenuViewController: rightViewController)
        slideMenuController.automaticallyAdjustsScrollViewInsets = true
        slideMenuController.delegate = mainViewController
        
        AppDelegate.getAppDelegate().window?.rootViewController = slideMenuController
    }
    
    //MARK: - API
    
    private func getLoginGuid() {
        
        if emailTF.text == "" {
            emailTF.errorMessage = error_field_required
            return
        }
        emailTF.errorMessage = ""
        
        if passwdTF.text == ""  {
            passwdTF.errorMessage = error_field_required
            return
        }
        passwdTF.errorMessage = ""
        
        if emailTF.text?.isValidEmail() != true {
            emailTF.errorMessage = error_invalid_email
            return
        }
        emailTF.errorMessage = ""
        
        var passParam = ""
        for _ in 0...3 {
            passParam += "\(Int(arc4random_uniform(9)))"
        }
        passParam += passwdTF.text!
        
        for _ in 0...2 {
            passParam += "\(Int(arc4random_uniform(9)))"
        }
        let hud = MBProgressHUD.showAdded(to: self.view, animated: true)
        hud?.show(true)
        let parameters = ["username": emailTF.text ?? "", "password": passParam] as [String : Any]
        Alamofire.request(BASE_URL + "Login", method: .post, parameters: parameters).responseJSON { response in
            hud?.hide(true)
            
            
            if response.error as? [String: Any] != nil {
                self.view.makeToast("Invalid email address or password.", duration: 2.5, position: CSToastPositionCenter)
                return
            }

            if response.value as? [String: Any] == nil {
                self.view.makeToast("Invalid email address or password.", duration: 2.5, position: CSToastPositionCenter)
                return
            }
            if let json = response.value as? [String: Any] {
                let type = json["Type"] as! String
                if type == "Failed" {
                    self.view.makeToast(json["Message"] as! String, duration: 2.5, position: CSToastPositionCenter)
                    return
                }
                if type == "Success"{
                    Config.setAuthorizedUser(_applicationGuid: json["ApplicationGuid"] as! String)
                    Config.setUserEmail(_emailAddress: self.emailTF.text!)
                    self.gotoMain()
                }
                
            }
        }
    }

}
