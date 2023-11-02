#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

class Banka
{
	protected:
	  long long int bakiye;
   public:
      Banka(){
      	bakiye =0;
      }
      
      Banka(long long int para){
      	bakiye = para;
      }
     bool paraCek(long long int para){
     	
     	
     	if(bakiye > 0 && bakiye >= para){
     	      bakiye -= para;
     	      return true;
     	}
     	else
              cout << "Hesabinizda bu kadar para yok" << endl;
           
           if(bakiye == 0)
              cout  << "Hesabinizda cekilecek para yok"<< endl;
           return false;
         
     }
     
     void paraYatir(long long int para)
     {
     	bakiye += para;
     	
     }
     
     long long int bakiyeSorgula(){
     	
     	return bakiye;
     	
     }
     
     void ayarla(long long int para)
     {
     	bakiye = para;
     }
    
      
};

Banka ustundag(0);


void menu(){
	ifstream data("/sdcard/bakiye.txt", ios_base::in);
	bool var;
	   if(!	data.is_open())
   {
   	cout << "bakiye.txt : dosya okuma hatasi" << endl;
   	var = false;
   }
   if(var == false){
   	ofstream tmp("/sdcard/bakiye.txt",ios_base::out|ios_base::app);
   	tmp<<0;
   
   	tmp.close();
   	var=true;
   	return;
   }
   ofstream log("/sdcard/log.txt",ios_base::out| ios_base::app);
   if(!log.is_open())
   {
   	cout <<"log verisi acilamadi" <<endl;
   }
   long long int bakiye;
   data >> bakiye;
   ustundag.ayarla(bakiye);
	
	
	int m;
	cout << "Ustundag Bankasi" << endl;
	cout << "islem sec: " << endl;
	cout << "   1)  Para Cek" << endl;
	cout << "   2)  Para Yatir" << endl;
	cout << "   3)  Bakiye"     << endl;

	
	cin >> m;
	
	switch(m){
		case 1:{
		    cout << "Bakiye : " << ustundag.bakiyeSorgula() << " TRY" << endl;
		    
		    cout << "Cekilecek miktar girin" <<endl;
		     long long int i;
		     cin >> i ;
		     bool result = ustundag.paraCek(i);
		    
		     if(result){
		      time_t c;
		     time(&c);
		   log << "Cekildi:" << i << " TRY "<< "Bakiye: " << ustundag.bakiyeSorgula() << " TRY Tarih: " << ctime(&c) <<endl;
		     log.flush();
		     cout << "islem basarili" << endl;
		     }
		     break;
		}
      case 2:
             cout << "Yatirilacak miktar girin" << endl;
             long long k;
             cin >> k;
             ustundag.paraYatir(k);
             time_t a;
		     time(&a);
		     log << "Yatirildi:" << k << " TRY "<< "Bakiye: " << ustundag.bakiyeSorgula() << " TRY Tarih: " << ctime(&a) <<endl;
              log.flush();
             cout << k << " TRY hesaba yatirildi"<< endl;
             cout << ustundag.bakiyeSorgula() << " TRY" << endl;
             break;
      case 3:
           cout << "Toplam Bakiye: " << ustundag.bakiyeSorgula()<< " TRY" << endl;
           break;
      
            
		default:
		     cout << "Gecersiz islem numasasi"<<endl;
		     break;
	}
	data.close();
	ofstream d("/sdcard/bakiye.txt",ios_base::out);
	d << ustundag.bakiyeSorgula() << endl;
	d.close();
	log.close();
}


int main(){
   
	while(1)
  menu();
 
	return 0;
}