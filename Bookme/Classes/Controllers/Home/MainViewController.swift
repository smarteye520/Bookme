//
//  MainViewController.swift
//  Bookme
//
//  Created by Oleksiy on 9/29/17.
//  Copyright © 2017 Leopard. All rights reserved.
//

import UIKit
import Alamofire

class MainViewController: UIViewController {
    
    @IBOutlet weak var collectionView: UICollectionView!
    fileprivate let sectionInsets = UIEdgeInsets(top: 15.0, left: 15.0, bottom: 15.0, right: 15.0)
    fileprivate let itemsPerRow: CGFloat = 3
    var booksArray: NSMutableArray = []
    
    //MARK: - View Lifecycle
    override func viewDidLoad() {
        super.viewDidLoad()
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        configureUI()
        loadBooks()
    }
    
    //MARK: - Helper
    private func configureUI() {
        self.navigationController?.isNavigationBarHidden = false
        self.navigationController?.navigationBar.barTintColor = UIColor(red: 54.0 / 255, green: 54.0 / 255, blue: 91.0 / 255, alpha: 1.0)
        self.setNavigationBarItem()
        self.navigationController?.navigationBar.tintColor = .white
        self.navigationItem.setHidesBackButton(true, animated:true);
        
        let titleAttributes = [
            NSFontAttributeName: UIFont.systemFont(ofSize: 25)
        ]
        self.navigationController?.navigationBar.titleTextAttributes = titleAttributes
        
        self.navigationController?.navigationBar.titleTextAttributes = [NSForegroundColorAttributeName : UIColor.white]
        self.navigationController?.navigationBar.topItem?.title = app_name
    }
    
    //MARK: Books Handle
    
    private func loadBooks() {
        booksArray.removeAllObjects()
        // add local books to booksArray
        
        
        
        // add books to booksArray from server
        
        let hud = MBProgressHUD.showAdded(to: self.view, animated: true)
        hud?.show(true)
        Alamofire.request(BASE_URL + "/User/" + Config.getAuthorizedUser()!  + "/MyBooks", method: .get, parameters: nil).responseJSON { response in
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
                //                var data = ("Data: \(utf8Text)")
                let bookDicsArray = json["books"] as? NSArray
                for i in 0...(bookDicsArray?.count)! - 1 {
                    let bookDic = bookDicsArray?[i] as! NSDictionary
                    let book = BookModel()
                    book.name = bookDic["bookName"] as? NSString
                    book.danacode = bookDic["danacode"] as? NSString
                    book.isLocal = false
                    self.booksArray.add(book)
                }
                
                
            }
            self.collectionView.reloadData()
        }
    }
    
    
    fileprivate func downLoadBook(_book: BookModel, userTalken: NSString!)  {
        NativeBridge.sharedInstance().downloadBook(withUserId: userTalken! as String, bookId: String(_book.danacode))
    }
}

//MARK: - CollectionView Datasource.
extension MainViewController : UICollectionViewDataSource {
    func numberOfSections(in collectionView: UICollectionView) -> Int {
        return 1
    }
    
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return booksArray.count
    }
    
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "bookCVC", for: indexPath) as! BookCVC
        
        // Configure the cell
        let book = booksArray[indexPath.row] as! BookModel
        cell.configureWithBoolModel(book)
        return cell
    }
    
    func collectionView(_ collectionView: UICollectionView, viewForSupplementaryElementOfKind kind: String, at indexPath: IndexPath) -> UICollectionReusableView {
        // Dequeue Reusable Supplementary View
        if let supplementaryView = collectionView.dequeueReusableSupplementaryView(ofKind: UICollectionElementKindSectionHeader, withReuseIdentifier: "bookCVC", for: indexPath) as? BookCVC {
            // Configure Supplementary View
            supplementaryView.backgroundColor = UIColor.white
            
            return supplementaryView
        }
        
        fatalError("Unable to Dequeue Reusable Supplementary View")
    }
}

//MARK: - CollectionView Delegate.
extension MainViewController : UICollectionViewDelegate {
    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        let selectedBook = booksArray[indexPath.row] as! BookModel
        if selectedBook.isLocal {
            // show from local
        } else {
            // download from server
            let book = booksArray[indexPath.row] as! BookModel
            downLoadBook(_book: book, userTalken: Config.getAuthorizedUser()! as NSString)
        }
    }
}

//MARK: - CollectionView Layout Delegate.
extension MainViewController : UICollectionViewDelegateFlowLayout {
    func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, sizeForItemAt indexPath: IndexPath) -> CGSize {
        let paddingSpace = sectionInsets.left * (itemsPerRow + 1)
        let availableWidth = view.frame.width - paddingSpace
        let widthPerItem = availableWidth / itemsPerRow
        
        return CGSize(width: widthPerItem, height: widthPerItem * 1.4)
    }
    
    func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, insetForSectionAt section: Int) -> UIEdgeInsets {
        return sectionInsets
    }
    
    func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, minimumLineSpacingForSectionAt section: Int) -> CGFloat {
        return sectionInsets.left
    }
}

//MARK: - SlideMenuControllerDelegate.
extension MainViewController : SlideMenuControllerDelegate {
    
    func leftWillOpen() {
        print("SlideMenuControllerDelegate: leftWillOpen")
    }
    
    func leftDidOpen() {
        print("SlideMenuControllerDelegate: leftDidOpen")
    }
    
    func leftWillClose() {
        print("SlideMenuControllerDelegate: leftWillClose")
    }
    
    func leftDidClose() {
        print("SlideMenuControllerDelegate: leftDidClose")
    }
    
    func rightWillOpen() {
        print("SlideMenuControllerDelegate: rightWillOpen")
    }
    
    func rightDidOpen() {
        print("SlideMenuControllerDelegate: rightDidOpen")
    }
    
    func rightWillClose() {
        print("SlideMenuControllerDelegate: rightWillClose")
    }
    
    func rightDidClose() {
        print("SlideMenuControllerDelegate: rightDidClose")
    }
}
