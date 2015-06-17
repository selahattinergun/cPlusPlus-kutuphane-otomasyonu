#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
                    struct kitap{                         
                           char *kitapadi;
                           char *kitapturu;
                           char *yayinevi;
                           int adet;
                           int yayintarihi;
                		   int fiyat;
                           };
int main(){
    while(1){ 
    typedef kitap kitap ;  
      int secim;
         printf("\n* * * * * * MENU * * * * * *\n");
         printf("1.Kitap Kaydi:\n");
         printf("2.Kitap Satis:\n");
         printf("3.Kitap Urun Ekle:\n");
         printf("4.Kitap Arama:\n");
         printf("5.Kitap Listesi:\n");
         printf("6.Kitap Kayit Kaldir:\n");
         printf("7.Depo Sayim(stok):\n");
         printf("0.Otomasyon Cikis:\n");
                 for(int i=1;i<15;i++){  
                         printf("* ",i);
                         }
                         printf("\n\nLutfen Seciminizi Giriniz=");
                         scanf("%d",&secim);                       
 
     if(secim==1){    
                              kitap girdi;  
                              girdi.kitapadi=(char *)malloc(sizeof(char)*300);
                              printf("Bosluksuz Kitab Adi Giriniz:");
                              scanf("%s",girdi.kitapadi);
                              girdi.yayinevi=(char *)malloc(sizeof(char)*300);
                              printf("Yayinevi Adi Giriniz:");
                              scanf("%s",girdi.yayinevi);
                              girdi.kitapturu=(char *)malloc(sizeof(char)*300);
                              printf("Kitap Turu Giriniz:");
                              scanf("%s",girdi.kitapturu);
                              printf("Adet sayisi:");
                              scanf("%d",&girdi.adet);
                              printf("Yayin Tarihi:");
                              scanf("%d",&girdi.yayintarihi);
                              printf("Kitap Fiyat:");
                              scanf("%d",&girdi.fiyat); 
                              FILE *fp=fopen("selahattinergun.txt","a");   
                              fprintf(fp,"%s %s %s %f %d %d %d %d %d\n",girdi.kitapadi,girdi.yayinevi,girdi.kitapturu,girdi.adet,girdi.yayintarihi,girdi.fiyat); 
                              printf("--Kayit Basari Ile Gerceklestirilmistir--\n");
                              fclose(fp); 
                              }
                               
                               
    if(secim==2){    
                              FILE *fp=fopen("selahattinergun.txt","r"); 
                               char satkitap[300];  
                                int istenen;  
                                printf("Isim girin:");
          scanf("%s",satkitap);
          printf("Istenen:");  
          scanf("%d",&istenen);
           int i=0; 
           kitap girdi[300];   
            while (!feof(fp)){ 
                              girdi[i].kitapadi=(char *)malloc(sizeof(char)*300);
                              girdi[i].yayinevi=(char *)malloc(sizeof(char)*300);
                              girdi[i].kitapturu=(char *)malloc(sizeof(char)*300);                                                                                                                    
           fscanf(fp,"%s %s %s %f %d %d %d %d %d\n",girdi[i].kitapadi,girdi[i].yayinevi,girdi[i].kitapturu,&girdi[i].adet,&girdi[i].yayintarihi,&girdi[i].fiyat);  
          i++;
          }
          for (int j=0;j<i;j++){                    
              if(strcmp(satkitap,girdi[j].kitapadi)==0){ 
                               girdi[j].adet=girdi[j].adet-istenen;                                    
                               printf("Satis Tamamlanmistir...");
                               printf("Odenecek Toplam Tutar=%dtl",girdi[j].fiyat*istenen);  
                               }
          fp=fopen("selahattinergun.txt","w"); 
          for (int j=0;j<=i-1;j++){
              fprintf(fp,"%s %s %s %f %d %d %d %d %d\n",girdi[j].kitapadi,girdi[j].yayinevi,girdi[j].kitapturu,girdi[j].adet,girdi[j].yayintarihi,girdi[j].fiyat); 
              }
              fprintf(fp,'\0');  
              fclose(fp);
              }
              }
       if(secim==3){    
                          kitap girdi[300];  
                       FILE *fp=fopen("selahattinergun.txt","r");
                       char gelkitap[300];  
                       int alim;     
                       printf("Siparis Edilen Kitabin Adini Giriniz:");
                       scanf("%s",gelkitap);
                       printf("Alim Adedi Giriniz:");
                       scanf("%d",&alim);
                       int i=0;
                       while(!feof(fp)){   
                              girdi[i].kitapadi=(char *)malloc(sizeof(char)*300);  
                              girdi[i].yayinevi=(char *)malloc(sizeof(char)*300);
                              girdi[i].kitapturu=(char *)malloc(sizeof(char)*300);  
                       fscanf(fp,"%s %s %s %f %d %d %d %f %d\n",girdi[i].kitapadi,girdi[i].yayinevi,girdi[i].kitapturu,&girdi[i].adet,&girdi[i].yayintarihi,&girdi[i].fiyat);  
                       i++;
                       }
                       for(int j=0;j<i;j++){                              
                                if(strcmp(gelkitap,girdi[j].kitapadi)==0){   
                               girdi[j].adet=girdi[j].adet+alim;
                               printf("Siparis Alimi Tamamlanmistir..");
                               printf("Odenecek Toplam Tutar:%dtl",girdi[j].fiyat*alim);
                               }
                       fp=fopen("selahattinergun.txt","w"); 
                       for(int j=0;j<=i-1;j++){
                           fprintf(fp,"%s %s %s %f %d %d %d %d %d\n",girdi[j].kitapadi,girdi[j].yayinevi,girdi[j].kitapturu,girdi[j].adet,girdi[j].yayintarihi,girdi[j].fiyat); 
                           }
                           }
                           fclose(fp); 
                           }
                            
                            
                                                                                                                                         
          if(secim==4){  
                               printf("Aradiginiz Kitap Adi Giriniz:");
                              char aranan[30];  
                              scanf("%s",aranan);
                              int bayrak=0;
                              FILE *fp=fopen("selahattinergun.txt","r");  
                              kitap girdi; 
                              girdi.yayinevi=(char *)malloc(sizeof(char)*300);
                              girdi.kitapadi=(char *)malloc(sizeof(char)*300);
                              girdi.kitapturu=(char *)malloc(sizeof(char)*300);
                              while(!feof(fp)){
                                               fscanf(fp,"%s %s %s %f %d %d %d %d %d\n",girdi.kitapadi,girdi.yayinevi,girdi.kitapturu,&girdi.adet,&girdi.yayintarihi,&girdi.fiyat);
                                                 if(strcmp(girdi.kitapadi,aranan)==0){  
                                                                                     bayrak=1;  
                                                 printf("Yayinevi Adi:%s\nKitabin Adi:%s\nKitabin Turu:%s\nAdedi:%d\nYayin Tarihi:%d\nTutari:%dtl\n",girdi.yayinevi,girdi.kitapadi,girdi.kitapturu,girdi.adet,girdi.yayintarihi,girdi.fiyat);                          
                              }
                              }
                              if(bayrak==0)
                              printf("Aradiginiz Kitap Bulunmamaktadir..!");
                              fclose(fp);  
                              }
          if(secim==5){   
                                           printf("KÝTAP DEPOSU:\n");
                                           FILE *fp=fopen("selahattinergun.txt","r");
                                           kitap girdi;
                              girdi.yayinevi=(char *)malloc(sizeof(char)*300);    
                              girdi.kitapadi=(char *)malloc(sizeof(char)*300);
                              girdi.kitapturu=(char *)malloc(sizeof(char)*300);  
                               while(!feof(fp)){  
                                               fscanf(fp,"%s %s %s %f %d %d %d %d %d\n",girdi.kitapadi,girdi.yayinevi,girdi.kitapturu,&girdi.adet,&girdi.yayintarihi,&girdi.fiyat);
                                               printf("\n/%s/ - Fiyat:%dtl\n",girdi.kitapadi,girdi.fiyat);
                                               }
                                               fclose(fp); 
                                               }
          if(secim==6){  
                               FILE *fp=fopen("selahattinergun.txt","r");
                                            char isim[100]; 
                                                   printf("Silmek Istediginiz Kitabin Adi:");                       
                                            scanf("%s",isim);
                                              int artis=0;  
                                                kitap girdi[200];  
                                            while(!feof(fp)){                                                       
                                            girdi[artis].kitapadi=(char *)malloc(sizeof(char)*300);  
                                            girdi[artis].yayinevi=(char *)malloc(sizeof(char)*300);
                                            girdi[artis].kitapturu=(char *)malloc(sizeof(char)*300);                                      
                                            fscanf(fp,"%s %s %s %f %d %d %d %d %d\n",girdi[artis].kitapadi,girdi[artis].yayinevi,girdi[artis].kitapturu,&girdi[artis].adet,&girdi[artis].yayintarihi,&girdi[artis].fiyat);
                                            artis++; 
                                            }
                                            fclose(fp); 
                                            FILE *fp2=fopen("selahattinergun.txt","w");
                                              for(int i=0;i<=artis-1;i++){
                                                      if(strcmp(isim,girdi[i].kitapadi)!=0)                                                                         
                              fprintf(fp2,"%s %s %s %f %d %d %d %d %d\n",girdi[i].kitapadi,girdi[i].yayinevi,girdi[i].kitapturu,girdi[i].adet,girdi[i].yayintarihi,girdi[i].fiyat);                                                                                                                                            
                              }
                              printf("Kayit Kaldirilmistir...");
                              fprintf(fp2,'\0');                               
                              fclose(fp2);  
                              }
                                                                                                                                   
          if(secim==7){  
                                                    kitap girdi;
                              FILE *fp=fopen("selahattinergun.txt","r"); 
                              while(!feof(fp)){  
                                             int i=0;     
                              girdi.kitapadi=(char *)malloc(sizeof(char)*300);    
                              girdi.yayinevi=(char *)malloc(sizeof(char)*300);
                              girdi.kitapturu=(char *)malloc(sizeof(char)*300);
                                fscanf(fp,"%s %s %s %f %d %d %d %d %d\n",girdi.kitapadi,girdi.yayinevi,girdi.kitapturu,&girdi.adet,&girdi.yayintarihi,&girdi.fiyat);
                                while(girdi.kitapadi[i++]!='\0');  
                                if(girdi.adet>=40)                                                                                                                                                                                                                                                                                               printf("\nStok Durumu Yeterli..\n");
                                else if(girdi.adet>=25)
                                printf("\nStok Girisi Yapilabilir..\n");
                                else if(girdi.adet>=15)
                                printf("\nStok Durumunu Takip Et..\n");
                                else if(girdi.adet>=6)
                                printf("\nStok Durumu Kritik..\n");
                                else if(girdi.adet>=1)
                                printf("\nStok Durumu Tukenmek Uzere..\n!!");
                                else if(girdi.adet==0)
                                printf("Stok Tukenmis Durumda..\n!!!");
                                                      printf("%s(=)%d\n",girdi.kitapadi,girdi.adet);   
                                                      }
                                                      fclose(fp); 
                                                      }
         
             if(secim==0)     
                              break;           
                                                      }
                                                      }
                                           

