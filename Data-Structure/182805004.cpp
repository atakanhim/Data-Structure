#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string.h>
#include <stack>
#include <queue>

using namespace std;
#define isimuzunluk 25
#define soyisimuzunluk 25
#define nouzunluk 8
// fonksiyonlar 

//typedef Agac Veriyapisi;
struct Ogrenciler
{
	char ogrno[nouzunluk];
	char ogrisim[isimuzunluk];
	char ogrsoyad[soyisimuzunluk];
	Ogrenciler* sol;
	Ogrenciler* sag;
};
struct Agac
{
	Ogrenciler* kok;
	int dugumsayisi;
	void ekle(Ogrenciler* eklenecek);
	void agacKur(string dataTxt);
	
	Ogrenciler* ogrenciSil(Ogrenciler *ogr,int ogrno);
	void inorderTara(Ogrenciler*);
	void preorderTara(Ogrenciler*);
	void postorderTara(Ogrenciler*);
	 
	void ilkDerinlikAra();
	void ilkGenislikAra(); 
	
	
	void dosyayayazdir(Ogrenciler* nptr);
};
// struct dışı fonksiyonlar
Ogrenciler* min(Ogrenciler *ogr);
Ogrenciler* max(Ogrenciler *ogr);
int hangiDosya();
void dosyayaYaz(Agac* agac1, Agac* agac2 ,Agac* agac3);
void listeEkranaYazdir(Agac* agac1, Agac* agac2, Agac* agac3);


int main() {

	Agac *agac1,*agac2,*agac3;
	agac1 = new Agac();
	agac2 = new Agac();
	agac3= new Agac();

	cout << "1.Agac Kuruluyor [data1.txt icin]\n";
	agac1->agacKur("data1.txt");
	cout << "\n1.Agac Kuruldu ---> Agac kuruldu\n";

	cout << "\n2.Agac Kuruluyorrr [data2.txt icin]\n";
	agac2->agacKur("data2.txt");
	cout << "\n2.Agac Kuruldu ---> Agac kuruldu\n";

	cout << "\n3.Agac Kuruluyorrr [data3.txt icin]\n";
	agac3->agacKur("data3.txt");
	cout << "\n3.Agac Kuruldu ---> Agac kuruldu\n";

	bool bitir = true;
	char selection;
	do
	{
		cout << "\n\n\tAsagidaki islemlerden birini seciniz...\n\n";
		cout << "Arama yapmak icin : A\n";
		cout << "Listeyi ekrana yazdirmak icin : L\n";
		cout << "Ogrenci silmek icin : S\n";
		cout << "Dosyaya yazmak icin : Y\n";
		cout << "Cikis icin : C\n";
		cin >> selection;
		switch (selection)
		{
		case 'A':
		case 'a':
			int secim;
			cout << "Arama Turunu seciniz\n\n";
			cout << "Genislik Ara icin : 1"<<endl;
			cout << "Derinlik Ara icin : 2"<<endl;
			cin>>secim;
			if(secim == 1)
				agac1->ilkGenislikAra();
			else if(secim == 2)
				agac1->ilkDerinlikAra();
			else 
				cout<<endl<<"Hatali arama secimi"<<endl;
			
			break;
		case 'L':
		case 'l':
			listeEkranaYazdir(agac1,agac2,agac3);
			break;
		case 'S':
		case 's':
			int ogrno,agacno;
			cout << "Silmek istediginiz ogr no giriniz : ";	
			cin >> ogrno;
			cout << "\n Silmek istediginiz agaci giriniz(1-2-3) : ";	
			cin >> agacno;
			switch (agacno)
			{
			case 1:
				agac1->ogrenciSil(agac1->kok,ogrno);
				cout <<ogrno<< " -> Basari ile silindi \n\n";
				break;
			case 2:
				agac2->ogrenciSil(agac2->kok,ogrno);
				cout <<ogrno<< " -> Basari ile silindi \n\n";			
				break;
			case 3:
				agac3->ogrenciSil(agac3->kok,ogrno);
				cout <<ogrno<< " -> Basari ile silindi \n\n";	
				break;
			default:
				cout<<"Yanlis Veri Girdiniz";
				break;
			}
	
			break;
		case 'Y':
		case 'y':
		 	dosyayaYaz(agac1,agac2,agac3);
			cout << "Dosya Yazma Basarili\n\n";
			break;
		case 'C':
		case 'c':
			cout << "Cikis Basarili\n\n";
			bitir = false;
			break;

		default:
			cout << "Gecerli Deger Giriniz\n\n";
			break;
		}

	} while (bitir);

	return 0;
}
void listeEkranaYazdir(Agac* agac1, Agac* agac2 ,Agac* agac3) {
	
	bool bitir = true;
	int dosyaNum;
	char selection;
	cout << "\nPreorder listeleme yapmak icin : R\n";
	cout << "Inorder listeleme yapmak icin : I\n";
	cout << "Postorder listeleme yapmak icin : O\n\n";
	do {
		cout << "Seciminizi giriniz: ";
		cin >> selection;
		switch (selection)
		{
		case 'R':
		case 'r':
			cout << "Hangi dosya icin preorder listeleme Yapmak istiyorsunuz\n\n";
			dosyaNum = hangiDosya();
			if (dosyaNum == 1)
				agac1->preorderTara(agac1->kok);
			if (dosyaNum == 2)
				agac1->preorderTara(agac2->kok);
			if (dosyaNum == 3)
				agac1->preorderTara(agac3->kok);
			bitir = false;
			break;
		case 'I':
		case 'i':
			cout << "Hangi dosya icin inorder listeleme Yapmak istiyorsunuz\n\n";
			dosyaNum = hangiDosya();
			if (dosyaNum == 1)
				agac1->inorderTara(agac1->kok);
			if (dosyaNum == 2)
				agac1->inorderTara(agac2->kok);
			if (dosyaNum == 3)
				agac1->inorderTara(agac3->kok);
			bitir = false;
			break;
		case 'O':
		case 'o':
			cout << "Hangi dosya icin posterder listeleme Yapmak istiyorsunuz\n\n";
			dosyaNum = hangiDosya();
			if (dosyaNum == 1)
				agac1->postorderTara(agac1->kok);
			if (dosyaNum == 2)
				agac1->postorderTara(agac2->kok);
			if (dosyaNum == 3)
				agac1->postorderTara(agac3->kok);
			bitir = false;
			break;
		default:
			cout << "Gecerli Deger Giriniz\n\n";
			break;
		}
	} while (bitir);
}
int hangiDosya() {
	int selection; 
	bool bitir = true;
	cout << "\ndata1.txt icin: 1\n";
	cout << "data2.txt icin: 2\n";
	cout << "data3.txt icin: 3\n\n";
	do {
		cout << "Seciminizi giriniz:";
		cin >> selection;
		switch (selection)
		{
		case 1:
			cout << "Dosya 1\n\n";
			bitir = false;
			break;
		case 2:
			cout << "Dosya 2\n\n";
			bitir = false;
			break;
		case 3:
			cout << "Dosya 3\n\n";
			bitir = false;
			break;
		default:
			cout << "Gecerli Deger Giriniz\n\n";
			break;
		}
	} while (bitir);

	return selection;
}
void dosyayaYaz(Agac* agac1, Agac* agac2 ,Agac* agac3)
{
    bool bitir = true;
	int dosyaNum;
	do {
		cout << "\nAgac 1 icin: 1\n";
		cout << "Agac 2 icin: 2\n";
		cout << "Agac 3 icin: 3\n\n";
		cin >> dosyaNum;
		switch (dosyaNum)
		{
        case 1:
            agac1->dosyayayazdir(agac1->kok);
            bitir=false;
            break;
        case 2:
            agac2->dosyayayazdir(agac2->kok);
            bitir=false;
            break;
        case 3:
            agac3->dosyayayazdir(agac3->kok);
            bitir=false;
            break;
        default:
			cout << "Gecerli Deger Giriniz\n\n";
			break;
		}
    } while (bitir);
}
void Agac::dosyayayazdir(Ogrenciler* nptr)
{
    FILE *DosyaPtr;
    if( (DosyaPtr = fopen("DosyaCiktisi.txt","w")) == NULL )
    {
        printf("DosyaCiktisi.txt acilamadi!");
        exit(1);
    }
    while(true)
    {
        if (nptr)
        {
            fprintf(DosyaPtr,"%s %s %s\n",nptr->ogrno,nptr->ogrisim,nptr->ogrsoyad);
        }
        if(nptr->sol)
            nptr = nptr->sol;
        else if(nptr->sag)
            nptr = nptr->sag;
        else
            break;
    }
    fclose(DosyaPtr);
}
Ogrenciler* min(Ogrenciler *ogr){
	while(ogr->sol!=NULL)
		ogr= ogr->sol;
	return ogr;
}
Ogrenciler* max(Ogrenciler *ogr){
	while(ogr->sag!=NULL)
		ogr= ogr->sag;
	return ogr;
}
Ogrenciler* Agac::ogrenciSil(Ogrenciler *ogr,int ogrno) {
	if(ogr==NULL)
		return NULL;
	if(ogrno==atoi(ogr->ogrno)){
			if(ogr->sol == NULL && ogr->sag == NULL)
				return NULL;
			if(ogr->sag!= NULL){
				ogr = min(ogr->sag);
				int x = atoi(ogr->ogrno);
				ogr->sag = Agac::ogrenciSil(ogr->sag, x);
				
				return ogr;
			}

			ogr = max(ogr->sol);
			int y = atoi(ogr->ogrno);
			ogr->sol =Agac::ogrenciSil(ogr->sol, y);
			
			return ogr;
	}
	if(atoi(ogr->ogrno)<ogrno){
		ogr->sag = Agac::ogrenciSil(ogr->sag, ogrno);
	
		return ogr;
	}
	ogr->sol = Agac::ogrenciSil(ogr->sol, ogrno);
	return ogr;
}
// tarama fonksiyonları
void Agac::preorderTara(Ogrenciler* yeni)
{
	if (yeni)
	{
		cout << yeni->ogrno << "--" << yeni->ogrisim << "--" << yeni->ogrsoyad << endl;
		preorderTara(yeni->sol);
		preorderTara(yeni->sag);
	}
}
void Agac::inorderTara(Ogrenciler* yeni)
{
	if (yeni)
	{
		inorderTara(yeni->sol);
		cout << yeni->ogrno << "--" << yeni->ogrisim << "--" << yeni->ogrsoyad << endl;
		inorderTara(yeni->sag);
	}
}

void Agac::postorderTara(Ogrenciler* yeni)
{
	if (yeni)
	{
		postorderTara(yeni->sol);
		postorderTara(yeni->sag);
		cout << yeni->ogrno << "--" << yeni->ogrisim << "--" << yeni->ogrsoyad << endl;
	}
}

void Agac::ilkDerinlikAra()
{
	int sayac =0;
	char no[30];
	cout << "Ogrenci numarasi gir:";
	cin >> no;
	Ogrenciler* ara;
	stack < Ogrenciler* > yigin;
	yigin.push(kok);
	while (!yigin.empty())
	{
		sayac++;
		ara = yigin.top();
		yigin.pop();
		if (strcmp(no, ara->ogrno) == 0)
		{
			cout << sayac << " adimda bulundu ";
			cout << ara->ogrno << " " << ara->ogrisim << " " << ara->ogrsoyad << endl;
			return;
		}
		if (ara->sag)
			yigin.push(ara->sag);
		if (ara->sol)
			yigin.push(ara->sol);
	}

	
}

void Agac::ilkGenislikAra()
{
	int sayac = 0 ;
	char no[30];
	cout << "Ogrenci numarasi gir:";
	cin >> no;
	Ogrenciler* p;
	queue < Ogrenciler* > kuyruk;
	kuyruk.push(kok);
	while (!kuyruk.empty())
	{
		sayac++;
		p = kuyruk.front();
		kuyruk.pop();
		if (strcmp(no, p->ogrno) == 0)
		{
			cout << "Aradigin Kisi:" << endl;
			cout << sayac << " adimda bulundu ";
			cout << p->ogrno << " " << p->ogrisim << " " << p->ogrsoyad << endl;
			return;
		}
		if (p->sag)
			kuyruk.push(p->sag);
		if (p->sol)
			kuyruk.push(p->sol);
	}
}

void Agac::ekle(Ogrenciler* eklenecek)
{
	Ogrenciler* tara, * yeni;
	tara = kok;
	int karsilas;
	bool eklendi = false;
	yeni = new Ogrenciler;
	strcpy(yeni->ogrno, eklenecek->ogrno);
	strcpy(yeni->ogrisim, eklenecek->ogrisim);
	strcpy(yeni->ogrsoyad, eklenecek->ogrsoyad);
	yeni->sol = NULL;
	yeni->sag = NULL;
	cout << yeni->ogrno << "--" << yeni->ogrisim << "--" << yeni->ogrsoyad << endl;
	if (kok == NULL)
	{

		kok = yeni;
		dugumsayisi++;
		return;
	}
	while ((tara != NULL) && (!eklendi))
	{
		karsilas = atoi(yeni->ogrno);
		if (karsilas < 1003007)
		{
			if (tara->sol != NULL)
				tara = tara->sol;
			else
			{
				tara->sol = yeni;
				eklendi = true;
				cout << "Sol Kisi: " << dugumsayisi << endl;
			}
		}
		else if (karsilas >= 1003007)
		{
			if (tara->sag != NULL)
				tara = tara->sag;
			else
			{
				tara->sag = yeni;
				eklendi = true;
				cout << "Sag Kisi: " << dugumsayisi << endl;
			}
		}
		else
			cout << "Ayni veri yazilamaz\n";
	}
	if (eklendi)
		dugumsayisi++;
}


void Agac::agacKur(string veri)
{
	kok = NULL;
	dugumsayisi = 0;
	Ogrenciler* yeni;
	char ogrno[15], ad[30], soyad[30], satirAl[75];
	char* ptr;
	ifstream dosya;
	dosya.open(veri);
	dosya.getline(satirAl, 75);
	for (int i = 0; i < 75; i++) {				//satır sonundaki '\r' karakterini, '\0' karakteri ile değiştirme
		if (satirAl[i] == '\r')
			satirAl[i] = '\0';
	}
	while (dosya)
	{
		ptr = strtok(satirAl, "\t");		//	j sayacının değerine göre değişkenlere atama
		int j = 0;
		while (ptr != NULL)
		{
			if (j == 0)
				strcpy(ogrno, ptr);
			if (j == 1)
				strcpy(ad, ptr);
			if (j == 2)
				strcpy(soyad, ptr);
			if (j == 3) {			//bir ad ve bir soyad okunmasına rağmen satır sonu gelmedi ise öğrencinin iki adı var demektir,
				strcat(ad, " ");		//	bu iki ad arada bir boşluk bırakılarak öğrenci değişkenine atanır ve soyadı tekrar okunur
				strcat(ad, soyad);
				strcpy(soyad, ptr);
			}
			ptr = strtok(NULL, " ");
			j++;
		}
		yeni = new Ogrenciler;
		strcpy(yeni->ogrno, ogrno);
		strcpy(yeni->ogrisim, ad);
		strcpy(yeni->ogrsoyad, soyad);
		yeni->sol = yeni->sag = NULL;
	
		ekle(yeni);
		
		dosya.getline(satirAl, 75);
		for (int i = 0; i < 75; i++)
		{
			if (satirAl[i] == '\r')
				satirAl[i] = '\0';
		}
	}
	dosya.close();
}





