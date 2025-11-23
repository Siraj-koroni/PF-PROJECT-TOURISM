#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<windows.h>

#include"dist_function.h"

void setColor(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


void gotoxy(int x, int y){
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}


void type(const char *text){
    while(*text){
        printf("%c", *text++);
        Sleep(25);
    }
}


void loading(){
    char bar[30] = "[----------------------------]";
    for(int i=1; i<28; i++){
        bar[i] = '#';
        printf("\r%s", bar);
        Sleep(80);
    }
    printf("\n");
}


void header(const char *title){
    setColor(11);
    // printf("╔══════════════════════════════════════════╗\n");
    // printf("║   ");
    setColor(14);
    printf("%-35s", title);
    setColor(11);
    // printf("║\n");
    // printf("╚══════════════════════════════════════════╝\n");
    setColor(15);
}


void mainMenuUI(){
    system("cls");
    system("color 0A");

    header("GILGIT BALTISTAN TOURISM SYSTEM");

    setColor(10);
    gotoxy(5,5);
    // printf("1. About Gilgit Baltistan");

    gotoxy(5,7);
    // printf("2. Tourist Places");

    gotoxy(5,9);
    // printf("3. Hotels");

    gotoxy(5,11);
    // printf("4. Booking");

    gotoxy(5,13);
    // printf("5. Exit");

    setColor(14);
    gotoxy(5,16);
    // printf("Enter your choice: ");

    setColor(15);
}


void welcomeScreen(){
    system("cls");
    system("color 1F");

    header("WELCOME TO GB TOURISM PORTAL");

    setColor(14);
    type("\nInitializing System...\n");
    loading();

    Sleep(500);
}


void mainMenu();
void aboutGB();
void tourismMenu();
void hotelMenu();
void bookingMenu();
void saveBookingToFile(char name[], char contact[], char hotel[], int days, int cost);

void showSkarduInfo();
void showShigarInfo();
void showGhancheInfo();
void showGilgitInfo();
void showHunzaInfo();
void showKharmangInfo();

void showHotelInfo(char distict[], int *totalCost);

int main()
{
    mainMenu();
    return 0;
}

void mainMenu()
{
    welcomeScreen();
    int choice;
    printf("\t -----------------------------------------------------------------\n");
    printf("\t|                                                                 |\n");
    printf("\t|                                                                 |\n");
    printf("\t|                                                                 |\n");
    printf("\t|       TOURISM DEPARTMENT OF GILGIT BALTISTAN                    |\n");
    printf("\t|                                                                 |\n");
    printf("\t|                                                                 |\n");
    printf("\t|    Are you planning to visit Gilgit Baltistan PAKISTAN?         |\n");
    printf("\t -----------------------------------------------------------------\n");
    //     int distChoice;
    //     char another_dist;
// system("color 0A");
// system("cls");

mainMenuUI();
printf("╔════════════════════════════════════╗\n");
printf("║       GB TOURISM SYSTEM            ║\n");
printf("╚════════════════════════════════════╝\n");

printf("\nLoading...\n");
// loading();

// setColor(14);
// gotoxy(10,10);
printf("1. About Gilgit Baltistan");

// setColor(11);
// gotoxy(10,12);
printf("2. Tourist Places");

// setColor(15);

    // system("color 5f");
    do
    {
        printf("\n\n\t=============== TOURISM & HOTEL BOOKING SYSTEM OF GILGIT BALTISTAN ===============\n");
        printf("\t1. About Gilgit Baltistan\n");
        printf("\t2. Tourist Places\n");
        printf("\t3. Hotel Information\n");
        printf("\t4. Booking\n");
        printf("\t5. Exit\n");
        printf("\nEnter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n')
                ;
            continue;
        }
        switch (choice)
        {
        case 1:
            aboutGB();
            break;
        case 2:
            tourismMenu();
            break;
        case 3:
            hotelMenu();
            break;
        case 4:
            bookingMenu();
            break;
        case 5:
            printf("\nThank you for using the Tourism System!\n");
            exit(0);
        default:
            printf("\nYou entered an Invalid choice!\n");
        }

    } while (1);
}

// system("color A6");
void aboutGB()
{    system("color A6");
    printf("\n\n-------------------- ABOUT GILGIT BALTISTAN --------------------\n");
    printf("Gilgit Baltistan is located in the northern areas of Pakistan.\n");
    printf("Gilgit-Baltistan is a high-mountain area where three of the world's \nhighest mountain ranges meet: the Himalayas, the Karakoram, and the Hindukush. .\n");
    printf(" It is home to diverse cultures, rich history, and unparalleled natural\n beauty, making it a paradise for adventurers, trekkers, and nature enthusiasts alike.\n");
    printf(" Polo is the most popular sport, and traditional dress includes a\n woollen cap, which is considered a significant part of the local identity.\n");
    printf("It is famous for:\n");
    printf("• World’s highest mountains (K2, Nanga Parbat, etc.)\n");
    printf("• Beautiful valleys & lakes\n");
    printf("• Unique culture and hospitality\n");
    printf("• Pleasant weather throughout the year\n");
}
void tourismMenu()
{
    system("color e7");
    int distChoice;
    printf("\n\nSelect a district to view tourist places:\n");
    printf("1. Skardu\n2. Shigar\n3. Ghanche\n4. Gilgit\n5. Hunza\n6. Kharmang\n");
    printf("Enter your choice: ");

    if (scanf("%d", &distChoice) != 1) { while(getchar()!='\n'); return; }

    switch(distChoice)
    {
        case 1: showSkarduInfo(); break;
        case 2: showShigarInfo(); break;
        case 3: showGhancheInfo(); break;
        case 4: showGilgitInfo(); break;
        case 5: showHunzaInfo(); break;
        case 6: showKharmangInfo(); break;
        default: printf("Invalid choice! enter correct distric choice.\n");
    }
}

void hotelMenu()
{
    system("color b3");
    printf("\n\n---------------------- HOTEL INFORMATION ----------------------\n");
    printf("Skardu Hotels:\n• Shangrila Resort – Rs. 8500\n• Skardu Continental – Rs. 6000\n");

    printf("\nHunza Hotels:\n• Serena Baltit Inn – Rs. 9000\n• Hunza View Hotel – Rs. 5500\n");

    printf("\nShigar Hotels:\n• Serena Shigar Fort – Rs. 10000\n• Shigar Palace Inn – Rs. 7000\n");

    printf("\nKhaplu Hotels:\n• Serena Khaplu Palace – Rs. 9500\n• Baltoro Inn – Rs. 6500\n");

    printf("\nGilgit Hotels:\n• Serena Gilgit – Rs. 8000\n• Gilgit Lodge – Rs. 5000\n");
}
void bookingMenu()
{
    char name[50], contact[20], hotelName[50];
    int days, hotelCost=0, choice;

    printf("\n---------------------- HOTEL BOOKING ----------------------\n");
 system("color F8");
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter contact number: ");
    scanf("%s", contact);

    printf("\nSelect hotel:\n");
    printf("1. Serena Skardu (8500)\n");
    printf("2. Serena Khaplu (9500)\n");
    printf("3. Hunza Baltit Inn (9000)\n");
    printf("4. Gilgit Serena (8000)\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1: hotelCost=8500; strcpy(hotelName,"Serena Skardu"); break;
        case 2: hotelCost=9500; strcpy(hotelName,"Serena Khaplu"); break;
        case 3: hotelCost=9000; strcpy(hotelName,"Baltit Inn Hunza"); break;
        case 4: hotelCost=8000; strcpy(hotelName,"Serena Gilgit"); break;
        default:
            printf("Invalid hotel!\n");
            return;
    }

    printf("How many days will you stay? ");
    scanf("%d", &days);

    int total = hotelCost * days;

    saveBookingToFile(name, contact, hotelName, days, total);

    printf("\nBooking Successful!\n");
    printf("Total Cost: Rs. %d\n", total);
}

/* ---------------------- SAVE BOOKING TO FILE ---------------------- */
void saveBookingToFile(char name[], char contact[], char hotel[], int days, int cost)
{
    FILE *fp = fopen("booking.txt", "a");

    if (fp == NULL) {
        printf("File error! Could not save booking.\n");
        return;
    }

    fprintf(fp, "Name: %s\nContact: %s\nHotel: %s\nDays: %d\nTotal Cost: %d\n-----------------\n",
            name, contact, hotel, days, cost);

    fclose(fp);
}

void showSkarduInfo()
{
    int choice, totalCost = 0;
    char again;
    system("color 3A");

    printf("\n<---------------!   SKARDU ATTRACTIONS   !--------------------->\n");
    printf("Here are some beautiful places you can visit in Skardu:\n");
    printf("1. Shangrila Resort \n");
    printf("2. Satpara Lake \n");
    printf("3. Deosai Plains \n");
    printf("4. Kharpocho Fort \n");
    printf("5. Kachura Lake \n");
    printf("6. Katpana Desert \n");

    do
    {
        printf("\nSelect a place number to get details: ");
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue; 
        }

        switch (choice)
        {
        case 1:
            printf("\n **Shangrila Resort:** Also known as Heaven on Earth. Beautiful resort with lake view and boating facilities.\n");
            printf("Estimated Entry/Activity Cost: Rs. 2000\n");
            totalCost += 2000;
            break;
        case 2:
            printf("\n **Satpara Lake:** Famous for its clear water and scenic surroundings.\n");
            printf("Estimated Entry/Activity Cost: Rs. 1500\n");
            totalCost += 1500;
            break;
        case 3:
            printf("\n **Deosai Plains:** Known as the ‘Roof of the World’, great for trekking and camping.\n");
            printf("Estimated Entry/Activity Cost: Rs. 2500\n");
            totalCost += 2500;
            break;
        case 4:
            printf("\n **Kharpocho Fort:** Historical fort which is built on a hill.\n");
            printf("Estimated Entry/Activity Cost: Rs. 1800\n");
            totalCost += 1800;
            break;
        case 5:
            printf("\n **Kachura Lake:** Serene lake surrounded by mountains, perfect for relaxation.\n");
            printf("Estimated Entry/Activity Cost: Rs. 1600\n");
            totalCost += 1600;
            break;
        case 6:
            printf("\n **Katpana Desert:** Unique cold desert with sand dunes and stunning views.\n");
            printf("Estimated Entry/Activity Cost: Rs. 1400\n");
            totalCost += 1400;
            break;
        default:
            printf("Invalid choice!\n");
        }

        while (getchar() != '\n');

        printf("\nDo you want to explore another place in Skardu? (y/n): ");
        if (scanf(" %c", &again) != 1) { 
            while (getchar() != '\n');
            again = 'n'; 
        }

    } while (again == 'y' || again == 'Y');

    showHotelInfo("Skardu",&totalCost);

    printf("\nTotal Estimated Cost for Your Skardu Trip (Attractions + Hotel): Rs.%d\n", totalCost);
    printf("Thank you for exploring Skardu!\n");
}


void showShigarInfo()
{
    int choice, totalCost = 0;
    char again;

    printf("\n<---------------!   SHIGAR ATTRACTIONS   !--------------------->\n");
    printf("Here are some beautiful places you can visit in Shigar:\n");
    printf("1. Shigar Fort \n");
    printf("2. Sarfaranga Cold Desert \n");
    printf("3. Blind Lake \n");
    printf("4. K2-Base Camp (Trekking)\n");

    do
    {
        printf("\nSelect a place number to get details: ");
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue; 
        }
        
        switch (choice)
        {
        case 1:
            printf("\n **Shigar Fort (Fong-Khar):** A historical fort and a museum, a cultural masterpiece.\n");
            printf("Estimated Entry/Activity Cost: Rs. 1500\n");
            totalCost += 1500;
            break;
        case 2:
            printf("\n **Sarfaranga Cold Desert:** A high-altitude cold desert perfect for jeep safaris and viewing K2.\n");
            printf("Estimated Entry/Activity Cost: Rs. 1200\n");
            totalCost += 1200;
            break;
        case 3:
            printf("\n **Blind Lake (Bara Lake):** A beautiful, serene lake surrounded by mountains.\n");
            printf("Estimated Entry/Activity Cost: Rs. 1800\n");
            totalCost += 1800;
            break;
        case 4:
            printf("\n **K2-Base Camp:** The starting point for the trek to K2, the world's second-highest mountain.\n");
            printf("Estimated Entry/Activity Cost: Rs. 2000 (Trekking portion/permit)\n");
            totalCost += 2000;
            break;
        default:
            printf("Invalid choice!\n");
        }

        while (getchar() != '\n');

        printf("\nDo you want to explore another place in Shigar? (y/n): ");
        if (scanf(" %c", &again) != 1) { 
            while (getchar() != '\n');
            again = 'n'; 
        }

    } while (again == 'y' || again == 'Y');

    showHotelInfo("Shigar",&totalCost);
    printf("\nTotal Estimated Cost for Your Shigar Trip (Attractions + Hotel): Rs.%d\n", totalCost);
    printf("Thank you for exploring Shigar!\n");
}


void showGhancheInfo()
{
    int choice, totalCost = 0;
    char again;

    printf("\n<---------------!   GHANCHE ATTRACTIONS   !--------------------->\n");
    printf("Here are some beautiful places you can visit in Ghanche (Khaplu):\n");
    printf("1. Khaplu Fort\n");
    printf("2. Chaqchan Masjid\n");
    printf("3. Thalley Valley\n");
    printf("4. Blind Lake Keris\n");

    do
    {
        printf("\nSelect a place number to get details: ");
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue; 
        }

        switch (choice)
        {
        case 1:
            printf("\n **Khaplu Fort (Yabgo Khar):** Ancient fort with stunning views of Khaplu Valley.\n");
            printf("Estimated Entry/Activity Cost: Rs. 1500\n");
            totalCost += 1500;
            break;
        case 2:
            printf("\n **Chaqchan Masjid:** One of the oldest mosques in Gilgit Baltistan, rich in culture and history.\n");
            printf("Estimated Entry/Activity Cost: Rs. 1200\n");
            totalCost += 1200;
            break;
        case 3:
            printf("\n **Thalley Valley:** A lush green valley and the starting point for Thalley La trek.\n");
            printf("Estimated Entry/Activity Cost: Rs. 1800\n");
            totalCost += 1800;
            break;
        case 4:
            printf("\n **Blind Lake Keris:** A beautiful, lesser-known blind lake.\n");
            printf("Estimated Entry/Activity Cost: Rs. 2000\n");
            totalCost += 2000;
            break;
        default:
            printf("Invalid choice!\n");
        }
        
        while (getchar() != '\n');
        
        printf("\nDo you want to explore another place in Ghanche? (y/n): ");
        if (scanf(" %c", &again) != 1) { 
            while (getchar() != '\n');
            again = 'n'; 
        }

    } while (again == 'y' || again == 'Y');

    showHotelInfo("Khaplu",&totalCost); 
    printf("\nTotal Estimated Cost for Your Ghanche Trip (Attractions + Hotel): Rs.%d\n", totalCost);
    printf("Thank you for exploring Ghanche!\n");
}


void showGilgitInfo() {
    int choice, totalCost = 0;
    char again;

    printf("\n<---------------!   GILGIT ATTRACTIONS   !--------------------->\n");
    printf("Here are some beautiful places you can visit in Gilgit:\n");
    printf("1. Naltar Valley\n");
    printf("2. Gilgit Bridge (Karakoram Highway View)\n");
    printf("3. Kargah Buddha\n");
    printf("4. Shandur Pass (Near)\n");

    do {
        printf("\nSelect a place number to get details: ");
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue; 
        }

        switch (choice) {
            case 1:
                printf("\n **Naltar Valley:**\n\t Famous for its lakes (Bashkiri, Blue, Firoza) and skiing during winter.\n");
                printf("Estimated Entry/Activity Cost: Rs. 1500\n");
                totalCost += 1500;
                break;
            case 2:
                printf("\n **Gilgit Bridge:**\n \tViewpoint near the historical Gilgit suspension bridge on the Indus River.\n");
                printf("Estimated Entry/Activity Cost: Rs. 500\n");
                totalCost += 500;
                break;
            case 3:
                printf("\n **Kargah Buddha:** \n\t A large standing Buddha carved into a cliff in the 7th century.\n");
                printf("Estimated Entry/Activity Cost: Rs. 800\n");
                totalCost += 800;
                break;
            case 4:
                printf("\n **Shandur Pass (Near):**\n \tHigh mountain pass, famous for the annual Shandur Polo Festival.\n");
                printf("Estimated Entry/Activity Cost: Rs. 2000\n");
                totalCost += 2000;
                break;
            default:
                printf("Invalid choice!\n");
        }

        while (getchar() != '\n');

        printf("\nDo you want to explore another place in Gilgit? (y/n): ");
        if (scanf(" %c", &again) != 1) { 
            while (getchar() != '\n');
            again = 'n'; 
        }

    } while (again == 'y' || again == 'Y');

    showHotelInfo("Gilgit",&totalCost);
    printf("\nTotal Estimated Cost for Your Gilgit Trip (Attractions + Hotel): Rs.%d\n", totalCost);
    printf("Thank you for exploring Gilgit!\n");
}


void showHunzaInfo() {
    int choice, totalCost = 0;
    char again;

    printf("\n<---------------!   HUNZA ATTRACTIONS   !--------------------->\n");
    printf("Here are some beautiful places you can visit in Hunza:\n");
    printf("1. Baltit Fort\n");
    printf("2. Altit Fort\n");
    printf("3. Attabad Lake\n");
    printf("4. Passu Cones\n");

    do {
        printf("\nSelect a place number to get details: ");
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue; 
        }

        switch (choice) {
            case 1:
                printf("\n **Baltit Fort:** Ancient fort with stunning views of Hunza Valley.\n");
                printf("Estimated Entry/Activity Cost: Rs. 1500\n");
                totalCost += 1500;
                break;
            case 2:
                printf("\n **Altit Fort:** Oldest fort in Hunza, rich in culture and history.\n");
                printf("Estimated Entry/Activity Cost: Rs. 1200\n");
                totalCost += 1200;
                break;
            case 3:
                printf("\n **Attabad Lake:** Crystal blue water lake formed after a landslide, famous for boating.\n");
                printf("Estimated Entry/Activity Cost: Rs. 1800\n");
                totalCost += 1800;
                break;
            case 4:
                printf("\n **Passu Cones:** Famous pointed mountain peaks (Cathedral Peaks), ideal for photography.\n");
                printf("Estimated Entry/Activity Cost: Rs. 2000\n");
                totalCost += 2000;
                break;
            default:
                printf("Invalid choice!\n");
        }

        while (getchar() != '\n');

        printf("\nDo you want to explore another place in Hunza? (y/n): ");
        if (scanf(" %c", &again) != 1) { 
            while (getchar() != '\n');
            again = 'n'; 
        }

    } while (again == 'y' || again == 'Y');

    showHotelInfo("Hunza",&totalCost);
    printf("\nTotal Estimated Cost for Your Hunza Trip (Attractions + Hotel): Rs.%d\n", totalCost);
    printf("Thank you for exploring Hunza!\n");
}

void showKharmangInfo() {
    int choice, totalCost = 0;
    char again;

    printf("\n<---------------!   KHARMANG ATTRACTIONS   !--------------------->\n");
    printf("Here are some beautiful places you can visit in Kharmang:\n");
    printf("1. Manthokha Waterfall\n");
    printf("2. Khamosh Waterfall (Shiriting Waterfall)\n");
    printf("3. Ghanche Nala\n");
    printf("4. Historical Sites\n");

    do {
        printf("\nSelect a place number to get details: ");
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue; 
        }

        switch (choice) {
            case 1:
                printf("\n **Manthokha Waterfall:** A tall and stunning waterfall surrounded by lush greenery and picnic areas.\n");
                printf("Estimated Entry/Activity Cost: Rs. 1500\n");
                totalCost += 1500;
                break;
            case 2:
                printf("\n **Khamosh Waterfall (Shiriting Waterfall):** A natural cascade noted for the water stream falling directly from an overhanging rock.\n");
                printf("Estimated Entry/Activity Cost: Rs. 1200\n");
                totalCost += 1200;
                break;
            case 3:
                printf("\n **Ghanche Nala:** Scenic area with clear streams and mountain views.\n");
                printf("Estimated Entry/Activity Cost: Rs. 1800\n");
                totalCost += 1800;
                break;
            case 4:
                printf("\n **Historical Sites:** Sites with local significance and history.\n");
                printf("Estimated Entry/Activity Cost: Rs. 2000\n");
                totalCost += 2000;
                break;
            default:
                printf("Invalid choice!\n");
        }

        while (getchar() != '\n');

        printf("\nDo you want to explore another place in Kharmang? (y/n): ");
        if (scanf(" %c", &again) != 1) { 
            while (getchar() != '\n');
            again = 'n'; 
        }

    } while (again == 'y' || again == 'Y');

    showHotelInfo("Kharmang",&totalCost);
    printf("\nTotal Estimated Cost for Your Kharmang Trip (Attractions + Hotel): Rs.%d\n", totalCost);
    printf("Thank you for exploring Kharmang!\n");
}



void showHotelInfo(char district[], int *totalCost)
{
    int hotelChoice, nights, hotelCostPerNight = 0;
    char bookHotel;

    printf("\n<---------------!  HOTELS in %s  !--------------------->\n", district);

    while (getchar() != '\n');

    printf("+++++ Do you want to book a hotel in %s? (y/n): ", district);
    if (scanf(" %c", &bookHotel) != 1) {
        while (getchar() != '\n');
        return; 
    }
    
    if (bookHotel != 'y' && bookHotel != 'Y') {
        printf("Skipping hotel booking for %s.\n", district);
        return;
    }
    
    printf("\nAvailable Hotels in %s:\n", district);
    
    if (strcmp(district, "Skardu") == 0)
    {
        printf("1. Shangrila Resort (Rs. 8500/night)\n");
        printf("2. Skardu Continental Hotel (Rs. 6000/night) \n");
        printf("3. Mountain Lodge (Rs. 5000/night)\n");
    }
    else if (strcmp(district, "Hunza") == 0)
    {
        printf("1. Serena Hunza Baltit Inn (Rs. 9000/night)\n");
        printf("2. Hunza View Hotel (Rs. 5500/night)\n");
        printf("3. Eagle’s Nest Hotel (Rs. 7000/night)\n");
    }
    else if (strcmp(district, "Shigar") == 0)
    {
        printf("1. Serena Shigar Fort (Rs. 10000/night)\n");
        printf("2. Shigar Palace Inn (Rs. 7000/night)\n");
        printf("3. Baltistan View Hotel (Rs. 5000/night)\n");
    }
    else if (strcmp(district, "Khaplu") == 0) 
    {
        printf("1. Serena Khaplu Palace (Rs. 9500/night)\n");
        printf("2. Baltoro Inn (Rs. 6500/night)\n");
        printf("3. Khaplu Residency (Rs. 4500/night)\n");
    }
    else if (strcmp(district, "Gilgit") == 0)
    {
        printf("1. Serena Gilgit (Rs. 8000/night)\n");
        printf("2. Gilgit Lodge (Rs. 5000/night)\n");
        printf("3. River View Hotel (Rs. 4000/night)\n");
    }
    else if (strcmp(district, "Kharmang") == 0)
    {
        printf("1. Manthokha Resort (Rs. 6000/night)\n");
        printf("2. Kharmang Inn (Rs. 4000/night)\n");
    }
    else {
        printf("No specific hotel information available for this district.\n");
        return;
    }


    printf("\nEnter your hotel choice number: ");
    while (scanf("%d", &hotelChoice) != 1) {
        printf("Invalid input! Please enter a number: ");
        while (getchar() != '\n');
    }


    if (strcmp(district, "Skardu") == 0) {
        if (hotelChoice == 1) hotelCostPerNight = 8500;
        else if (hotelChoice == 2) hotelCostPerNight = 6000;
        else if (hotelChoice == 3) hotelCostPerNight = 5000;
    } else if (strcmp(district, "Hunza") == 0) {
        if (hotelChoice == 1) hotelCostPerNight = 9000;
        else if (hotelChoice == 2) hotelCostPerNight = 5500;
        else if (hotelChoice == 3) hotelCostPerNight = 7000;
    } else if (strcmp(district, "Shigar") == 0) {
        if (hotelChoice == 1) hotelCostPerNight = 10000;
        else if (hotelChoice == 2) hotelCostPerNight = 7000;
        else if (hotelChoice == 3) hotelCostPerNight = 5000;
    } else if (strcmp(district, "Khaplu") == 0) {
        if (hotelChoice == 1) hotelCostPerNight = 9500;
        else if (hotelChoice == 2) hotelCostPerNight = 6500;
        else if (hotelChoice == 3) hotelCostPerNight = 4500;
    } else if (strcmp(district, "Gilgit") == 0) {
        if (hotelChoice == 1) hotelCostPerNight = 8000;
        else if (hotelChoice == 2) hotelCostPerNight = 5000;
        else if (hotelChoice == 3) hotelCostPerNight = 4000;
    } else if (strcmp(district, "Kharmang") == 0) {
        if (hotelChoice == 1) hotelCostPerNight = 6000;
        else if (hotelChoice == 2) hotelCostPerNight = 4000;
    } 

    if (hotelCostPerNight == 0) {
        printf("Invalid hotel choice or no cost found. Booking canceled.\n");
        return;
    }

    printf("You selected a hotel with a cost of Rs. %d per day.\n", hotelCostPerNight);

    printf("How many days will you be staying? ");
    while (scanf("%d", &nights) != 1 || nights <= 0) {
        printf("Invalid input! Please enter a positive number of day: ");
        while (getchar() != '\n');
    }

    int totalHotelCost = hotelCostPerNight * nights;
    *totalCost += totalHotelCost;

    printf("\nHotel Booking Successful!\n");
    printf("Total Hotel Cost for %d day: Rs.%d\n", nights, totalHotelCost);
}












