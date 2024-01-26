#include<stdio.h>
#include<stdlib.h>
#include<windows.h>


int main() {
    printf ("MAIN MENU\n.....................\n[0] QUIT\n[1] CALENDER\n[2] AGE\n[3] CONVERSION\n.....................\nSELECT AN OPTION:");

    int option;
    scanf ("%d", & option);
    
    system ("cls");
    
    if ( option != 0 && option != 1 && option != 2 && option != 3){
        system ("cls");
        printf ("INVALID INPUT!\nPLEASE TRY AGAIN!\n.....................\n");
        printf ("MAIN MENU\n.....................\n[0] QUIT\n[1] CALENDER\n[2] AGE\n[3] CONVERSION\n.....................\nSELECT AN OPTION:");
        scanf  ("%d", & option);
    }
    
    system ("cls");
    
    if ( option == 0){
        printf ("BYE!");
    }
    else if ( option == 1){
        calender (1);
    }
    else if ( option == 2){
        age (2);
    }
    else if ( option == 3){
        conversion (3);
    }
    
    


}

int calender(int a) {
    if( a==1 ){
        int year, month;

        printf ("    (CALENDER)   \nBACK TO MAIN MENU[0]\n.....................\nPLEASE ENTER YEAR:");
        scanf ("%d", & year );

        if ( year==0 ){
            system ("cls");
            main();
        }
        
        if ( year != 0){ 
            if ( year > 1498 || year < 1206 ){
                system ("cls");
                printf ("INVALID INPUT!\nPLEASE TRY AGAIN!\n.....................\n");
                calender (1);
            } 
            
        printf ("PLEASE ENTER MONTH:");
        scanf("%d", & month );
        
        if ( month >= 13 || month < 0){
           system ("cls");
           printf ("INVALID INPUT!\nPLEASE TRY AGAIN!\n.....................\n");
           calender (1);
        }
        else if ( month == 0){
            system ("cls");
            main();
        }
        else{

            int number[] = {31 ,31 ,31 , 31, 31, 31, 30, 30, 30, 30, 30, 29};
            
            char *NameOfMonth[] = {"   FARVARDIN  " , "   ORDIBEHSHT " , "    KHORDAD   " , "      TIR     " , "    MORDAD    " , "   SHAHRIVAR  " , 
                                   "     MEHR     " , "     ABAN     " , "     AZAR     " , "     DEY      " , "    BAHMAN    " , "    ESFAND    "};

            // یکم فروردین 1206 پنجشنبه میباشد
            
            int num_of_year = 365,plus = 0, space;
        
        for ( int i = 1206  ; i < year ; i++){
            plus += num_of_year ;
            // به ازای سال های کبیه یک روز اضافه تر
            if (i % 33 == 1 || i % 33 == 5 || i % 33 == 9 || i % 33 == 13 || 
            i % 33 == 17 || i % 33 == 22 || i % 33 == 26 || i % 33 == 30){
            plus++;
        }
        }
        
        //سی روزه بودن ماه اسفند سال های کبیسه

        int y = year;
        if (y % 33 == 1 || y % 33 == 5 || y % 33 == 9 || y % 33 == 13 || 
            y % 33 == 17 || y % 33 == 22 || y % 33 == 26 || y % 33 == 30){
            number[11] = 30;
        }

        //اضافه کردن تعداد روزهای ماه ها تا ماه وارد شده
        for (int j = 1; j < month; j++){
            plus += number[j-1];
        }

        printf("\n  %s\n",NameOfMonth[month - 1]);
        printf("SH YE DO SE CH PA JO\n");
        // چون یکم فروردین 1206 پنجشنبه بود و ابتدای تقویم 5 اسپیس دارد 
        // حاصل جمع تعداد روز را به علاوه 5 میکنیم و سپس از آن باقی مانده بر 7 میگیریم
        space = (plus+5) % 7;
        

        for (int k = 0; k < space ; k++){
            printf("  |");
        }

        for (int h = 1; h <= number[month - 1]; h++){
            if(h<10){ 
            printf("%d |", h);
            }
            else{
            printf("%d|", h);

            }
            //رفتن به خط بعدی  در تقویم
            if ((h + space) % 7 == 0){
                printf("\n");
            }
        }

        }
        }
        }
        }


int age(int b){

    //منو و دریافت ورودی تاریخ تولد و تاریخ امروز

    if ( b == 2){

        int year, month, day, todayyear, todaymonth, todayday, yourage, month_of_age, days_of_age, days, kabiseh, totalday, days1;
        int tarikhdays, num_of_year, totalplus = 0, plus;

        printf ("  (AGE CALCULATOR)   \nBACK TO MAIN MENU[0]\n.....................\nPLEASE ENTER YEAR OF BIRTH:");
        scanf ( "%d", & year );

        if ( year==0 ){
            system ("cls");
            main();
        }
        
        if ( year != 0 ){
            printf ("PLEASE ENTER MONTH OF YOUR BIRTH:");
            scanf ( "%d", & month );
            
        if ( month == 0){
            system ("cls");
            main();
        }
            
        else if ( month >= 13 || month < 0){
            system ("cls");
            printf ("INVALID INPUT!\nPLEASE TRY AGAIN!\n.....................\n");
            age (2);
        }

        else if ( month < 13 && month > 0){
            printf ("PLEASE ENTER DAY OF YOUR BIRTH:");
            scanf ( "%d", & day );

        if ( day == 0){
            system ("cls");
            main();
        }
                
        else if ( day > 31 || day < 0){
            system ("cls");
            printf ("INVALID INPUT!\nPLEASE TRY AGAIN!\n.....................\n");
            age (2);
        }

        else if ( day <= 31 && day > 0){
            printf(".....................\nPLEASE ENTER TODAY'S DATE: \nYEAR:");
            scanf("%d", & todayyear );

            printf("MONTH:");
            scanf("%d", & todaymonth );

            printf("DAY:");
            scanf("%d", & todayday );

            // محاسبه سن

            yourage = todayyear - year;

        if ( todaymonth < month || (todaymonth == month && todayday < day)){
            yourage = yourage - 1;
        }

            // محاسبه ماه های سن

        if ( todaymonth == month && day <= todaymonth ){
            month_of_age = 0 ;
        }
        else if (todaymonth == month && day > todayday ){
            month_of_age = 11 ;
        }
        else if ( todaymonth > month && day > todayday){
            month_of_age = todaymonth - month - 1 ;
        }
        else if ( todaymonth > month && day <= todayday){
            month_of_age = todaymonth - month ;
        }
        else if ( todaymonth < month && day > todayday ){
            month_of_age = (12 - month ) + ( todaymonth ) - 1 ;
        }
        else if ( todaymonth < month && day <= todayday ){
            month_of_age = (12 - month ) + month_of_age ;
        }

        // محاسبه روز های سن

        if ( todayday >= day ){
            days_of_age = todayday - day ;
        }
        else if ( todayday < day ){
            days_of_age = (30 - day ) + todayday ; 
        }

        // چاپ سن فرد با چاپ نشدن در صورت صفر بودن سال و ماه و روز زندگی فرد
        
        if ( yourage == 0 && month_of_age == 0 ){
            printf( "YOUR AGE IS: %d DAYS ", days_of_age);
        }
        else if ( yourage == 0 && days_of_age == 0){
            printf( "YOUR AGE IS: %d MONTHS ", month_of_age );
        }
        else if ( month_of_age == 0 && days_of_age == 0){
            printf( "YOUR AGE IS: %d YEARS  ", yourage);
        }
        else if ( yourage == 0 ){
            printf( "YOUR AGE IS: %d MONTHS %d DAYS ", month_of_age, days_of_age);
        }
        else if ( month_of_age == 0 ){
            printf( "YOUR AGE IS: %d YEARS %d DAYS ", yourage, days_of_age);
        }
        else if ( days_of_age == 0 ){
            printf( "YOUR AGE IS: %d YEARS %d MONTHS ", yourage, month_of_age);
        }
        else{
            printf("YOUR AGE IS: %d YEARS %d MONTHS %d DAYS", yourage, month_of_age, days_of_age);
        }

            

        //محاسبه تعداد روز های زندگی
        // در این بخش تعداد روزهای گذشته شده از امسال 
        // و تعداد روزهای سال تولد فرد از روز تولدش تا انتهای سال تولدش جداگانه حساب شده است

        if ( todaymonth > 6 ){
            days = (6*31) + ((todaymonth - 6 - 1) * 30) + todayday ;
        }

        if ( todaymonth <= 6){
            days = ((todaymonth - 1) * 31 ) + todayday ;
        }
        if (month > 6){
            days1 = ((11 - month)*30) + (29) + (30 - day) ;
        }
        if (month <= 6){
            days1 = ((6 - month) * 31) + (31 - day) + (5 * 30) + (29) ;
        }

            totalday = ( (yourage - 1 ) * 365 ) + ( days ) + days1 ;

        //اضافه کردن روز سی ام اسفند در صورت کبیسه بودن سال های بین تولد فرد تا امسال

        for ( int i = year ; i < todayyear ; i++){

        if (i % 33 == 1 || i % 33 == 5 || i % 33 == 9 || i % 33 == 13 || 
            i % 33 == 17 || i % 33 == 22 || i % 33 == 26 || i % 33 == 30){
            totalday = totalday + 1 ;
        }
        }

            printf ("\nTOTAL DAYS YOU LIVED ON EARTH: %d", totalday);
}
}
}
        // محاسبه چندشنبه بودن روز تولد فرد
        // این محاسبه با در نظر گرفتن پنجشنبه بودن 1 فروردین 1206 انجام شده

        int num_of_days[] = {31, 31, 31, 31, 31, 31, 30, 30, 30, 30, 30, 29};
        num_of_year = 365;

        
        for ( int i = 1206  ; i < year  ; i++){
        if (i % 33 == 1 || i % 33 == 5 || i % 33 == 9 || i % 33 == 13 || 
            i % 33 == 17 || i % 33 == 22 || i % 33 == 26 || i % 33 == 30){
            num_of_year = 366 ;
        }
        else{
            num_of_year = 365;
        }
            totalplus = totalplus + num_of_year ;
        }
        
        for ( int k = 0; k < month-1 ; k++){
                totalplus += num_of_days[k];
            }
            totalplus += (day - 1 );
            
            plus = totalplus % 7;

            if ( plus == 0){
                printf("\nTHE DAY YOU CAME TO THIS WORLD WAS PANJSHANBE");
            }
            if ( plus == 1){
                printf("\nTHE DAY YOU CAME TO THIS WORLD WAS JOME");
            }
            if ( plus == 2){
                printf("\nTHE DAY YOU CAME TO THIS WORLD WAS SHANBE");
            }
            if ( plus == 3){
                printf("\nTHE DAY YOU CAME TO THIS WORLD WAS YEKSHANBE");
            }
            if ( plus == 4){
                printf("\nTHE DAY YOU CAME TO THIS WORLD WAS DOSHANBE");
            }
            if ( plus == 5){
                printf("\nTHE DAY YOU CAME TO THIS WORLD WAS SESHANBE");
            }
            if ( plus == 6){
                printf("\nTHE DAY YOU CAME TO THIS WORLD WAS CHAHARSHANBE");
            } 
            


            }

        
}

int conversion(int c){
    if (c == 3){
        int option, solarday, solarmonth, solaryear;

        printf("(CONVERSION)\n");
        printf("[0] BACK TO MAIN MENU\n");
        printf("[1] SOLAR DATE TO CHRISTIAN AND LUNAR DATE\n");
        printf("PLEASE SELECT AN OPTION : ");
        
        
        scanf("%d", &option );

        if (option == 0){
            system("cls");
            main();
        }
        else if(option != 0 && option != 1 ){
            system ("cls");
            printf ("INVALID INPUT!\nPLEASE TRY AGAIN!\n.....................\n");
            conversion(3);
        }
        else if (option == 1){
            system ("cls");
            printf("ENTER THE SOLAR DATE\n");
            printf("....................................\n");

            printf("PLEASE ENTER THE YEAR:");
            scanf("%d", &solaryear );
            if (solaryear == 0){
                system("cls");
                main();
            }

            printf("\nPLEASE ENTER THE MONTH:");
            scanf("%d", &solarmonth );
            if (solarmonth == 0){
                system("cls");
                main();
            }

            printf("\nPLEASE ENTER THE DAY:");
            scanf("%d", &solarday );
            if (solarmonth == 0){
                system("cls");
                main();
            }

            Conversion(solaryear, solarmonth ,solarday);

        }
        

    }
    
}
int Conversion(int y,int m,int d){
    int Days=0, Days2, Days3;
    Days += (y-1) * 365 + (m+4) * 30 + d + 226899 + 2;

    char *monthnames[] = {"","APRIL","MAY","JUNE","JULY",
    "AUGUST","SEPTEMBER","OCTOBER","NOVEMBER",
    "DECEMBER","JANUARY","FEBRUARY","MARCH"};

    Days2 = Days;
    Days /= 365;
    Days2 %= 365;
    Days3 = Days2;
    Days3 %= 30;
    Days2 /= 30;
    
    printf("....................................\n");
    printf ("CHRISTIAN DATE:\n");
    printf ("%d ",Days);
    printf ("%s ",monthnames[Days2]);
    printf ("%d \n",Days3);

    int Days4 = 0, Days5, Days6;

    char *monthnames2[] = {"","RAMAZAN","SHAVVAL","ZIGADA",
    "ZIHAJA","MOHARRAM","SAFAR","RABIOAVAL","RABIOLSANI",
    "JAMADIOLAVAL","JAMADIOLSANI","RAJAB"};

    Days4 += floor( (y+1) * 365 + (m+3) * 29.5 + d + 7 + 10.875 * y );
    Days5 = Days4;
    Days4 /= 365;
    Days5 %= 365;
    Days6 = Days5;
    Days6 %= 30;
    Days5 /= 30;
    
    printf("....................................\n");
    printf("LUNARDATE:\n");
    printf("%d ",Days4);
    printf("%s ",monthnames2[Days5]);
    printf("%d \n",Days6);
}
