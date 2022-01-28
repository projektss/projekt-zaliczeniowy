#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <algorithm>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include <limits>
//-----------------------------------
using namespace std;
  class Logowanie
    {
        public:
        string haslo;
        string login;
        bool is_valid=false;
        string nowy_login;
        string nowe_haslo;
      
         
void rejestracja()
        {
        
			cout<<"Witamy w aplikacji z minigrami"<<endl<<"Tworcy projektu : Bartlomiej Kaminski & Szymon Skwara"<<endl<<"Zarejestruj sie aby kontynuowac"<<endl;
            cout<<endl<<"Ustaw login: \n";
            cin>>nowy_login;
            cout<<"\nUstaw haslo: \n";
            cin>>nowe_haslo;
            system("cls");
            cout<<"Uzytkownik " + nowy_login + " zostal utworzony pomyslnie\n\n";
        }
    
        void weryfikacja()
        {
            
        while(!is_valid)
        {
            cout<<"Podaj login: \n";
            cin>>login;
            cout<<"Podaj haslo: \n";
            cin>>haslo;
            if (haslo!=nowe_haslo || login!=nowy_login)
            {
            	cout<<"Nie udalo sie zalogowac\n\n";
  					
             }else {
            	is_valid = true;
            	system("cls");
            }
        }
    }
    
  
   
};
   class Zgadnij_liczbe
    {
        public:
        int a, b, life, maxrand;
        char c;
    
        void powitanie()
        {
     
            cout << "Gra 'Zgadywanie liczby' polega na odgadnieciu liczby wylosowanej przez komputer, masz na to maksymalnie 5 prób\n";
     
            cout << "Przy niepoprawnej odpowiedzi program podpowie Ci czy podana liczba jest za duza czy za mala wzgledem tej wylosowanej\n\n";
    }


        int trudnosc()
        {
            cout <<"Wybierz 1, 2, 3, zeby wybrac poziom trudnosci:\n\n"; 
     
            cout <<"1) Poziom Latwy (liczby z zakresu od 0 do 10)\n";
     
            cout <<"2) Poziom Sredni (liczby z zakresu od 0 do 20)\n";
     
            cout <<"3) Poziom Trudny (liczby z zakresu od 0 do 30)\n\n";
    
            cin >> c; 
            // odczytaj wybór uzytkownika
            cout << "\n";
    
        switch (c)
        {
            case '1' : maxrand = 10;  // losowa liczba bedzie z podanego zakresu
        break;
            case '2' : maxrand = 20;
        break;
            case '3' : maxrand = 30;
        break;
            default : return 0;
        }
    
        life = 5;         // liczba zyc
        
        b = rand() % maxrand;  // zmienna j otrzymuje wartosc od 0 do maxrand
     
        Wypisz(); //wywolanie wypisza
        return 0;
        }
    
        int Wypisz() //deklaracja wypisza
        {
        if (life <= 0)
        // gracz przegrywa jesli ma mniej niz jedno zycie
    
        {
            cout << "Przegrales\n\n";
            return 0;
        }

            cout << "Podaj liczbe: \n";
            cin >> a;          // odczytaj wpisana liczbe

        if ((a>maxrand) || (a<0)) // powtórz jesli liczba nie jest z podanego zakresu
        {
            cout << "Podana liczba nie jest w tym zakresie "<< "\n";
            Wypisz();
        }

        if (a == b)
        {
        cout << "Wygrales\n\n"; 
        
        }

        else if (a>b)
        {
            cout << "Za duza\n";
            life = life - 1;    // 
            cout << "Pozostale zycia: " << life << "\n\n";
            Wypisz();
        }

        else if (a<b)
        {
            cout << "Za mala\n";
            life = life - 1;
            cout << "Pozostale zycia:\n" << life << "\n\n";
            Wypisz();
        } 
        return 0;
    }
};

class kupon
{
	public:
	int wygrana,cala=0,x; double y,z;
	int los,k,n,k_,w_;
	int w[3];
	int wybrane;
	int losowe[6];
	int wylosowane1[10];
	int wylosowane2[6];
	int wpisowe;
	int pom;
	int pom1;
	char zn;
	
void gotoxy(int x, int y)
{
  COORD c;
  c.X = x - 1;
  c.Y = y - 1;
  SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void wypisz()
{int pom=0;
	gotoxy(80,5);
		for(int i=0;i<7;i++)
		{	
			for(int j=0;j<7;j++)
			{	
				cout<<setw(4)<<pom+j+1;
			}
		
			pom=pom+7;
			cout<<endl;
			gotoxy(80,5+i+1);
			
		}
	gotoxy(1,1);
	}
void wybierz()
{	
			cout<<endl<<"Twoje liczby: ";
			for(int i=0;i<6;i++)
			{
				cin>>losowe[i];
				while (!cin.good())
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"Podano litere, aby grac dalej uruchom program jeszcze raz";
    	getch();
	 exit(0); 

}
			}
			sort(losowe,losowe+6);
	}
bool czy_losowe()
{
			for(int i=0;i<6;i++)
		{
			if(losowe[i]>=50 || losowe[i]<=0 || losowe[i-1]==losowe[i]) return true;
		}
		 return false;
	}	
void sprawdz()
{
		do
		{
		czy_losowe();
		if(czy_losowe()==true) 
		{
		cout<<"Wybierz 6 niepowtarzajacych sie liczb od 1-49"<<endl<<"Wcisnij R aby powtorzyc";	
		zn=getch();
			if(zn==114) 
			{
			system("cls");
			wypisz();
			wybierz();
			sprawdz();
			}
			else 
			{
			cout<<endl<<"To nie jest R prosze uruchomic program jeszcze raz";
			exit(0);
			}
		}
		else
		{	system("cls");
			wypisz();
			cout<<endl<<"Wybrane liczby : ";
				for(int i=0;i<6;i++)
				cout<<losowe[i]<<" ";
		}
		}while(czy_losowe()==true);	
	}
void losowanie1()
{pom1=0;	 
		  do
		  {
		  for(int i=0;i<10;i++)
    		{
			wylosowane1[i]=rand()%49+1;
			}
    		sort(wylosowane1,wylosowane1+10);
    	}while(czy_wylosowane1()==true);
    	cout<<endl<<endl<<"Wylosowane liczby : ";
    	for(int i=0;i<10;i++)
    	{
    		cout<<wylosowane1[i]<<" ";
		}		
	}
bool czy_wylosowane1()
{
			for(int i=0;i<10-1;i++)
		{
			if(wylosowane1[i]==wylosowane1[i+1]) return true;
		}
		 return false;
}
void losowanie2()
{pom1=0;	 
		  do
		  {
		  for(int i=0;i<6;i++)
    		{
			wylosowane1[i]=rand()%49+1;
			}
    		sort(wylosowane1,wylosowane1+6);
    	}while(czy_wylosowane1()==true);
    	cout<<endl<<endl<<"Wylosowane liczby : ";
    	for(int i=0;i<6;i++)
    	{
    		cout<<wylosowane1[i]<<" ";
		}		
	}
bool czy_wylosowane2()
{
			for(int i=0;i<10-1;i++)
		{
			if(wylosowane1[i]==wylosowane1[i+1]) return true;
		}
		 return false;
}
void losowanie3()
{pom1=0;	 
		  do
		  {
		  for(int i=0;i<3;i++)
    		{
			wylosowane1[i]=rand()%49+1;
			}
    		sort(wylosowane1,wylosowane1+3);
    	}while(czy_wylosowane1()==true);
    	cout<<endl<<endl<<"Wylosowane liczby : ";
    	for(int i=0;i<3;i++)
    	{
    		cout<<wylosowane1[i]<<" ";
		}		
	}
bool czy_wylosowane3()
{
			for(int i=0;i<3-1;i++)
		{
			if(wylosowane1[i]==wylosowane1[i+1]) return true;
		}
		 return false;
}
void zaznacz_wylosowane()
{
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF0 );
	for(int i=0;i<10;i++)
	{
		los=wylosowane1[i];
		k_=los%7-1;
		w_=los/7;
		if(los%7==0)
		{
			w_--;
			k_=6;
		}
		
		if(wylosowane1[i]<10)
		{
			gotoxy(79+4*k_+3,5+w_);
			cout<<" ";	
		}
		else
		gotoxy(79+4*k_+3,5+w_);
		cout<<los;
		
	}
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
	
}
void zaznacz_wylosowane2()
{
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF0 );
	for(int i=0;i<6;i++)
	{
		los=wylosowane1[i];
		k_=los%7-1;
		w_=los/7;
		if(los%7==0)
		{
			w_--;
			k_=6;
		}
		
		if(wylosowane1[i]<10)
		{
			gotoxy(79+4*k_+3,5+w_);
			cout<<" ";	
		}
		else
		gotoxy(79+4*k_+3,5+w_);
		cout<<los;
		
	}
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
	
}
void zaznacz_wylosowane3()
{
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xF0 );
	for(int i=0;i<3;i++)
	{
		los=wylosowane1[i];
		k_=los%7-1;
		w_=los/7;
		if(los%7==0)
		{
			w_--;
			k_=6;
		}
		
		if(wylosowane1[i]<10)
		{
			gotoxy(79+4*k_+3,5+w_);
			cout<<" ";	
		}
		else
		gotoxy(79+4*k_+3,5+w_);
		cout<<los;
		
	}
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
	
}
void zaznacz_losowe()
{
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xCF );
	for(int i=0;i<6;i++)
	{
		los=losowe[i];
		k_=los%7-1;
		w_=los/7;
		if(los%7==0)
		{
			w_--;
			k_=6;
		}
		if(losowe[i]<10)
		{
			gotoxy(79+4*k_+3,5+w_);
			cout<<" ";
			
		}
		else
		gotoxy(79+4*k_+3,5+w_);
		cout<<los;
	
	}
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
	}
void zaznacz_losowe3()
{
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xCF );
	for(int i=0;i<3;i++)
	{
		los=w[i];
		k_=los%7-1;
		w_=los/7;
		if(los%7==0)
		{
			w_--;
			k_=6;
		}
		if(w[i]<10)
		{
			gotoxy(79+4*k_+3,5+w_);
			cout<<" ";		
		}
		else
		gotoxy(79+4*k_+3,5+w_);
		cout<<los;
	
	}
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
}	
void zaznacz_trafione()
{
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x2F );
	for(int i=0;i<10;i++)
	{	if(wylosowane1[i]==losowe[0] || wylosowane1[i]==losowe[1] || wylosowane1[i]==losowe[2] || wylosowane1[i]==losowe[3] || wylosowane1[i]==losowe[4] || wylosowane1[i]==losowe[5])
	{
		y=y+z;
		los=wylosowane1[i];
		k_=los%7-1;
		w_=los/7;
		if(los%7==0)
		{
			w_--;
			k_=6;
		}
		if(wylosowane1[i]<10)
		{
			gotoxy(79+4*k_+3,5+w_);
			cout<<" ";
			
		}
		else
		gotoxy(79+4*k_+3,5+w_);
		cout<<los;	
	}
	
	}
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
	y=y-3;
	wygrana= pow(x,y);
	if(wygrana==1) 
	{
	gotoxy(1,5);
	cout<<endl<<"Nic nie trafiles, sprobuj szczescia ponownie"<<endl<<"Laczna wygrana :"<<cala<<"zl";	
	}
	else
	{
	gotoxy(1,5);
	cala=cala+wygrana;
	cout<<endl<<"Wygrales: "<<wygrana<<" zloty GRATULACJE !"<<endl<<"Laczna wygrana :"<<cala<<"zl";
	}	
	}
void zaznacz_trafione2()
{
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x2F );
	for(int i=0;i<10;i++)
	{	if(wylosowane1[i]==losowe[0] || wylosowane1[i]==losowe[1] || wylosowane1[i]==losowe[2] || wylosowane1[i]==losowe[3] || wylosowane1[i]==losowe[4] || wylosowane1[i]==losowe[5])
	{
		y=y+z;
		los=wylosowane1[i];
		k_=los%7-1;
		w_=los/7;
		if(los%7==0)
		{
			w_--;
			k_=6;
		}
		if(wylosowane1[i]<10)
		{
			gotoxy(79+4*k_+3,5+w_);
			cout<<" ";
			
		}
		else
		gotoxy(79+4*k_+3,5+w_);
		cout<<los;	
	}
	
	}
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
	y=y-3;
	wygrana= pow(x,y);
	if(wygrana==1) 
	{
	gotoxy(1,5);
	cout<<endl<<"Nic nie trafiles, sprobuj szczescia ponownie"<<endl<<"Laczna wygrana :"<<cala<<"zl";	
	}
	else
	{
	gotoxy(1,5);
	cala=cala+wygrana;
	cout<<endl<<"Wygrales: "<<wygrana<<" zloty GRATULACJE !"<<endl<<"Laczna wygrana :"<<cala<<"zl";
	}	
	}	
void zaznacz_trafione3()
{
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x2F );
	for(int i=0;i<3;i++)
	{	if(wylosowane1[i]==w[0] || wylosowane1[i]==w[1] || wylosowane1[i]==w[2])
	{
		y=y+z;
		los=wylosowane1[i];
		k_=los%7-1;
		w_=los/7;
		if(los%7==0)
		{
			w_--;
			k_=6;
		}
		if(wylosowane1[i]<10)
		{
			gotoxy(79+4*k_+3,5+w_);
			cout<<" ";
			
		}
		else
		gotoxy(79+4*k_+3,5+w_);
		cout<<los;
		
	}
	
	}
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
	y=y-3;
	wygrana= pow(x,y);

	if(wygrana==1) 
	{	
	gotoxy(1,7);
	cout<<endl<<"Nic nie trafiles, sprobuj szczescia ponownie"<<endl<<"Laczna wygrana :"<<cala<<"zl";
	}
	else
	{
	gotoxy(1,7);
	cala=cala+wygrana;
	cout<<endl<<"Wygrales: "<<wygrana<<" zloty GRATULACJE !"<<endl<<"Laczna wygrana :"<<cala<<"zl";
	}
}
void wybor()
{
		do
		{
		for(int i=0;i<3;i++)
		{
			k=rand()%5+1;
			w[i]=losowe[k];
		}
			sort(w,w+3);
		}while(czy_w()==true);
		for(int i=0;i<3;i++)
		{
			cout<<w[i]<<" ";
		}
	}
bool czy_w()
{
			for(int i=0;i<2;i++)
		{
			if(w[i]==w[i+1]) return true;
		}
		 return false;	
	}
void menu()
{
		if(cala>10000000) 
	{
	system("cls");
	cout<<"Wyczerpales wszystkie nasze srodki, dziekujemy za udzial w grze";
	getch();
	exit(0);
	}
		cout<<"Wybierz opcje gry : "<<endl;
		cout<<"1. Male stawki, wiele wygranych(1,5zl)"<<endl;
		cout<<"2. Klasyczny totolotek(3zl)"<<endl;
		cout<<"3. Kto nie ryzykuje ten przegrywa dwa razy(10zl)"<<endl;
		gotoxy(21,1);
		cin>>wpisowe;
}
void wstep()
{
		
				cout<<"Program poprosi Cie o podanie 6 liczb(kazda po spacji) z zakresu 1-49 bez powtorzen"<<endl<<"Przykladowo : 10 13 5 48 3 25"<<endl;
				cout<<"Aby przejsc dalej wcisnij dowolny przycisk"<<endl;
				zn=getch();
				system("cls");
				gotoxy(60,5);
				wypisz();
				wybierz();
				sprawdz();
}

void koniec()
{
	cout<<endl<<"Zagraj jeszcze raz - R "<<endl<<"Wscinij dowolny klawisz aby wyjsc";
	zn=getch();
	if(zn==114)
		{
			system("cls");
			gra();
		}
		else		
		exit(0);			
}	
void gra()
{		system("cls");
		menu();
		switch(wpisowe)
		{
			case 1:
				n=10,x=2,y=3,z=3;
				system("cls");
				cout<<"Witamy w trybie male stawki wiele wygranych"<<endl<<"Nastapi zaraz losowanie "<<n<<" liczb"<<endl;
				wstep();
				losowanie1();
				zaznacz_losowe();
				zaznacz_wylosowane();
				zaznacz_trafione();	
				koniec();
			break;
			case 2:
				n=6,x=3,y=3,z=2.15;
				system("cls");
				cout<<"Witamy w trybie klasyczny totolotek"<<endl<<"Nastapi zaraz losowanie "<<n<<" liczb"<<endl;
				wstep();
				losowanie2();
				zaznacz_losowe();
				zaznacz_wylosowane2();
				zaznacz_trafione2();	
				koniec();
			break;
			case 3:
			n=3,x=10,y=3,z=3;
			system("cls");
			cout<<"Witamy w trybie kto nie ryzykuje ten przegrywa dwa razy"<<endl<<"Nastapi zaraz losowanie "<<n<<" liczb"<<endl;
			wstep();
			cout<<endl<<"Niestety z tych 6 liczb w losowaniu moga wziac udzial tylko 3"<<endl<<"i pozwol ze sam je wybiore beda to : ";
			wybor();
			losowanie3();
			zaznacz_losowe3();
			zaznacz_wylosowane3();
			zaznacz_trafione3();
			koniec();
			break;
			default: 
			system("cls");
			cout<<"Nie ma takiej gry, uruchom ponownie i podaj liczbe 1-3";
		}
		
	}
};
int main(int argc, char *argv[])
{	
	srand(time(0));
	Logowanie obiekt;
	obiekt.rejestracja();
    obiekt.weryfikacja();
	int g; char choose;
	cout<<"Dziekujemy za rejestracje, teraz czas na wybor gry : "<<endl;
	cout<<"1. Zgadywanie liczby"<<endl<<"2. Totolotek"<<endl;
	cout<<endl<<"Wybierz gre : ";
	cin>>g;
	switch(g)
	{		
	case 1:
    while(choose!='q') // mozlisowsc zagrania ponowanie lub wyjscia
    {
    system("cls");
    Zgadnij_liczbe z1;
    z1.powitanie();
    z1.trudnosc();
    cout<<"Wpisz q jesli chcesz wyjsc z gry\n";
    cout<<"Albo dowolny klawisz, aby zagrac ponownie\n";
    cin>> choose;
 	}
    break;
    case 2:
    {	
	kupon k1;
	k1.gra();
	getch();
	break;
	}
	default: 
	cout<<"Nie wybrano gry, uruchom ponownie i podaj liczbe 1-2";
	}
	
    return 0;
	
}
