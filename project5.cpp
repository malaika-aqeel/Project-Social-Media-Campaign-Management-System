/*
 * =============================================
 *  Social Media Campaign Management System
 *  Instructor: Umar Khalil
 * =============================================
 */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// ---------------------------------------------
//  Global Client Data
// ---------------------------------------------
string clientName;
string businessName;
string businessType;   // "Small", "Medium", "Corporate"
int    campaignDays;

// 1D Arrays: platform names and base charges
string platformNames[3]   = {"Instagram", "Facebook", "LinkedIn"};
double platformCharges[3] = {15000, 12000, 20000};

// Selected platform and campaign data
int    selectedPlatform  = 0;   // 1, 2, or 3
int    staticPosts       = 0;
int    reelPosts         = 0;
int    carouselPosts     = 0;
double adBudget          = 0;

// ---------------------------------------------
//  FUNCTION PROTOTYPES
// ---------------------------------------------
void   registerClient();
void   displayPlatforms();
void   selectPlatform();
double calculatePostDesignCost();
double calculateAdHandlingFee();
double calculateExtraDurationCharges();
double calculateGST(double totalServiceCost);
double calculateDiscount(double totalServiceCost);
void   displayFinalBill();
void   displayClientDetails();
bool   displayMenu();

// ---------------------------------------------
//  1. REGISTER CLIENT
// ---------------------------------------------
void registerClient() {
    cout << "    SOCIAL MEDIA CAMPAIGN REGISTRATION  "<<endl;

    cout << "Enter Client Name  : ";
    cin  >> clientName;

    cout << "Enter Business Name  : ";
    cin  >> businessName;

    int typeChoice;
    cout << "Business Type(press 1 for small business 2 for medium 3 for corporate )";
   
    cin  >> typeChoice;

    if (typeChoice == 1)
        businessType = "Small";
    else if (typeChoice == 2)
        businessType = "Medium";
    else if (typeChoice == 3)
        businessType = "Corporate";
    else
        cout << "Invalid choice"<<endl;

    cout << "Enter Campaign Duration (days): ";
    cin  >> campaignDays;

    if (campaignDays <= 0)
        cout << "Invalid duration"<<endl;

    cout << "===Registration Successful==="<<endl;
}

// ---------------------------------------------
//  2. DISPLAY PLATFORMS
// ---------------------------------------------
void displayPlatforms() {
    cout << "=========SOCIAL MEDIA PLATFORMS========"<<endl;
    cout << "1 Instagram     Base Charges: Rs. 15000"<<endl;
    cout << "2 Facebook      Base Charges: Rs. 12000"<<endl;
    cout << "3 LinkedIn      Base Charges: Rs. 20000"<<endl;
}

// ---------------------------------------------
//  3. SELECT PLATFORM + POST & AD DETAILS
// ---------------------------------------------
void selectPlatform() {
    displayPlatforms();

    cout << "Select Platform (1, 2 or 3) ";
    cin  >> selectedPlatform;

    if (selectedPlatform == 1)
        cout << "  Selected: Instagram"<<endl;
    else if (selectedPlatform == 2)
        cout << "  Selected: Facebook"<<endl;
    else if (selectedPlatform == 3)
        cout << "  Selected: LinkedIn"<<endl;
    else {
        cout << "Invalid choice"<<endl;
        return;
    }

    cout << "== Post Details =="<<endl;
    cout << "Number of Static Posts    (Rs 1000 each) ";
    cin  >> staticPosts;

    cout << "Number of Reel/Video Posts (Rs 2500 each) ";
    cin  >> reelPosts;

    cout << "Number of Carousel Posts  (Rs 1800 each) ";
    cin  >> carouselPosts;

    cout << "Enter Ad Budget (Rs) ";
    cin  >> adBudget;

    cout << "  Platform and campaign details saved"<<endl;
}

// ---------------------------------------------
//  4. CALCULATE POST DESIGN COST
//     Static   = staticPosts   * 1000
//     Reel     = reelPosts     * 2500
//     Carousel = carouselPosts * 1800
// ---------------------------------------------
double calculatePostDesignCost() {
    double staticCost   = staticPosts   * 1000;
    double reelCost     = reelPosts     * 2500;
    double carouselCost = carouselPosts * 1800;
    double totalDesign  = staticCost + reelCost + carouselCost;
    return totalDesign;
}

// ---------------------------------------------
//  5. CALCULATE AD HANDLING FEE
//     below 50000  = adBudget * 5  / 100
//     50000-100000 = adBudget * 8  / 100
//     above 100000 = adBudget * 10 / 100
// ---------------------------------------------
double calculateAdHandlingFee() {
    double handlingFee;
    if (adBudget < 50000)
        handlingFee = adBudget * 5 / 100;
    else if (adBudget <= 100000)
        handlingFee = adBudget * 8 / 100;
    else
        handlingFee = adBudget * 10 / 100;
    return handlingFee;
}

// ---------------------------------------------
//  6. CALCULATE EXTRA DURATION CHARGES
//     above 30 days = (days - 30) * 500
// ---------------------------------------------
double calculateExtraDurationCharges() {
    double extraCharges;
    if (campaignDays > 30)
        extraCharges = (campaignDays - 30) * 500;
    else
        extraCharges = 0;
    return extraCharges;
}

// ---------------------------------------------
//  7. CALCULATE GST
//     GST = totalServiceCost * 16 / 100
// ---------------------------------------------
double calculateGST(double totalServiceCost) {
    double gst = totalServiceCost * 16 / 100;
    return gst;
}

// ---------------------------------------------
//  8. CALCULATE DISCOUNT
//     Small     = totalServiceCost * 5  / 100
//     Medium    = totalServiceCost * 8  / 100
//     Corporate = totalServiceCost * 10 / 100
// ---------------------------------------------
double calculateDiscount(double totalServiceCost) {
    double discount;
    if (businessType == "Small")
        discount = totalServiceCost * 5 / 100;
    else if (businessType == "Medium")
        discount = totalServiceCost * 8 / 100;
    else if (businessType == "Corporate")
        discount = totalServiceCost * 10 / 100;
    else
        discount = 0;
    return discount;
}

// ---------------------------------------------
//  9. DISPLAY FINAL CAMPAIGN BILL
// ---------------------------------------------
void displayFinalBill() {
    if (selectedPlatform == 0) {
        cout << "No platform selected! Select platform first"<<endl;
        return;
    }

    int    platformIndex    = selectedPlatform - 1;
    double platformCharge   = platformCharges[platformIndex];
    double postDesignCost   = calculatePostDesignCost();
    double adHandlingFee    = calculateAdHandlingFee();
    double extraCharges     = calculateExtraDurationCharges();

    double totalServiceCost = platformCharge + postDesignCost
                              + adBudget + adHandlingFee + extraCharges;

    double gst      = calculateGST(totalServiceCost);
    double discount = calculateDiscount(totalServiceCost);

    double finalCost = totalServiceCost + gst - discount;

    cout << fixed << setprecision(2);
    cout << "========== SOCIAL MEDIA CAMPAIGN BILL =========="<<endl;
    cout << "\nClient Name      : " << clientName;
    cout << "\nBusiness Name    : " << businessName;
    cout << "\nBusiness Type    : " << businessType << " Business";
    cout << "\nSelected Platform: " << platformNames[platformIndex];
    cout << "\nCampaign Duration: " << campaignDays << " Days\n";
    cout << "Platform Charges : Rs. " << platformCharge  <<endl;
    cout << "Post Design Cost : Rs. " << postDesignCost  <<endl;
    cout << "Ad Budget        : Rs " << adBudget        <<endl;
    cout << "Ad Handling Fee  : Rs " << adHandlingFee   <<endl;
    cout << "Extra Duration   : Rs " << extraCharges    <<endl;
    cout << "GST (16%)        : Rs " << gst             <<endl;
    cout << "Discount         : Rs " << discount        <<endl;
    cout << "Final Campaign Cost: Rs " << finalCost     <<endl;
}

// ---------------------------------------------
//  10. DISPLAY CLIENT DETAILS
// ---------------------------------------------
void displayClientDetails() {
    cout << "======== CLIENT DETAILS ========"<<endl;
    cout << "Client Name     : " << clientName    <<endl;
    cout << "Business Name   : " << businessName  <<endl;
    cout << "Business Type   : " << businessType  <<endl;
    cout << "Campaign Days   : " << campaignDays  <<endl;
    if (selectedPlatform != 0)
        cout << "Platform        : " << platformNames[selectedPlatform - 1] <<endl;
}

// ---------------------------------------------
//  DISPLAY MENU — sab kuch yahan handle hota hai
// ---------------------------------------------
bool displayMenu() {
    cout << "====SOCIAL MEDIA CAMPAIGN MENU==== "<<endl;
    cout << "1 View Platforms"<<endl;
    cout << "2 Select Campaign Platform"<<endl;
    cout << "3 Calculate Campaign Cost"<<endl;
    cout << "4 View Client Details"<<endl;
    cout << "5 Exit"<<endl;
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;

    if (choice == 1)
        displayPlatforms();
    else if (choice == 2)
        selectPlatform();
    else if (choice == 3)
        displayFinalBill();
    else if (choice == 4)
        displayClientDetails();
    else if (choice == 5) {
        cout << "Thank you Goodbye "<<endl;
        return false;
    }
    else
        cout << "Invalid choice! Enter 1-5"<<endl;

    return true;
}

// ---------------------------------------------
//  MAIN FUNCTION
// ---------------------------------------------
int main() {
    registerClient();
    while (displayMenu());
    return 0;
}
