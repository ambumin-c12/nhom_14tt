#include "stdio.h"
#include "stdlib.h"   // de su dung ha, system(cls)
#include "conio.h"    // de su dung ham getch()

struct mon_hoc{
	char ma_mon[20];
	char ten_mon[40];
	int sinh_vien_hoc_mon_do;
	int sinh_vien_qua_mon;
	float ty_le_sinh_vien;
	
};

float tinh_ty_le_SV_qua_mon(mon_hoc *s){
	s->ty_le_sinh_vien = (float)s->sinh_vien_qua_mon / s->sinh_vien_hoc_mon_do * 100;
	
}

int nhap(mon_hoc *s){
	printf("\n-----------------------");
	printf("\nnhap vao ma mon: "); fflush(stdin); gets(s->ma_mon);
	printf("\nnhap vao ten mon: "); fflush(stdin); gets(s->ten_mon);
	printf("\nnhap so sinh vien hoc mon do: "); scanf("%d", &s->sinh_vien_hoc_mon_do);
	printf("\nnhap so sinh vien qua mon: "); scanf("%d", &s->sinh_vien_qua_mon);
	printf("\n-----------------------");
	tinh_ty_le_SV_qua_mon(s);	
		
}

int in(mon_hoc *s){
	printf("\n-----------------------");
	printf("\nma mon: %s", s->ma_mon);
	printf("\nten mon: %s", s->ten_mon);
	printf("\nso sinh vien hoc mon do: %d", s->sinh_vien_hoc_mon_do);
	printf("\nso sinh vien qua mon: %d", s->sinh_vien_qua_mon);
	printf("\nty le sinh vien qua mon: %.2f phan tram", s->ty_le_sinh_vien);
	printf("\n-----------------------");
		
}

int nhap_danh_sach(mon_hoc *s, int &n){
	for(int i=0; i<n; i++){
		printf("\nnhap vao thong tin mon hoc thu %d: ", i+1);
		nhap(s+i);
	}
	
}

int in_danh_sach(mon_hoc *s, int n){
	for(int i=0; i<n; i++){
		printf("\nthong tin mon hoc thu %d: ", i+1);
		in(s+i);
	}
	
}

int sap_xep_tang_dan(mon_hoc *s, int n){
	printf("\nDANH SACH SINH VIEN THEO MON HOC TANG DAN");
	mon_hoc temp;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if((s+i)->sinh_vien_hoc_mon_do>(s+j)->sinh_vien_hoc_mon_do){				
				temp = *(s+i);
				*(s+i) = *(s+j);
				*(s+j) = temp;
			}
			
		}
		
	}
	
}

float sap_xep_giam_dan(mon_hoc *s, int n){
	printf("\nSAP XEP TI LE SINH VIEN QUA MON GIAM DAN");
	mon_hoc temp;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if((s+i)->ty_le_sinh_vien<(s+j)->ty_le_sinh_vien){
				temp = *(s+i);
				*(s+i) = *(s+j);
				*(s+j) = temp;
			}
			
		}
		
	}
	
}

int ghi_file_bin(mon_hoc *s, int n){
	FILE *f;
	f = fopen("bai 4 chuyen de 15a.bin", "wb");
	if(f==NULL){
		printf("\nloi tao file!");
		return 0;
	}
	
	fwrite(&n, sizeof(int), 1, f);
	for(int i=0; i<n; i++){
		fwrite((s+i), sizeof(mon_hoc), 1, f);
	}
	fclose(f);
}

int doc_file_bin(mon_hoc *s, int &n){
	FILE *f;
	f = fopen("bai 4 chuyen de 15a.bin", "rb");
	if(f==NULL){
		printf("\nloi mo file!");
		return 0;
	}
	
	fread(&n, sizeof(int), 1, f);
	for(int i=0; i<n; i++){
		fread((s+i), sizeof(mon_hoc), 1, f);
	}
	fclose(f);
}

int main(){
	
	// khai bao	
	int n;
	int nhap;
	
	do{
		printf("nhap vao day so luong mon hoc: ");
		scanf("%d", &n);
	}while(n<=0);
	
	// cap phat bo nho dong
	mon_hoc *s = (mon_hoc*)malloc(n*sizeof(mon_hoc));
	
	// tao menu
	do{
		system("cls");
		printf("\n********************************************");
		printf("\n***         1.nhap danh sach             ***");
		printf("\n***         2.in danh sach               ***");
		printf("\n***         3.sap xep theo so sinh vien  ***");
		printf("\n***           hoc mon do tang dan        ***");
		printf("\n***         4.ghi file bin               ***");
		printf("\n***         5.doc file bin               ***");
		printf("\n********************************************");
		printf("\n***         nhap lua chon cua ban        ***");
		printf("\n********************************************");
		scanf("%d", &nhap);
		
		switch(nhap){
			case 1:
				printf("\nban da chon nhap danh sach mon hoc");
				nhap_danh_sach(s, n);
				printf("\nnhap danh sach thanh cong!");
				printf("\nan phim bat ki de tiep tuc...");
				getch();
				break;
				
			case 2:
				printf("\nban da chon in danh sach mon hoc");
				in_danh_sach(s, n);
				printf("\nin danh sach thanh cong!");
				printf("\nan phim bat ki de tiep tuc...");
				getch();
				break;
				
			case 3:
				printf("\nban da chon sap xep danh sach mon hoc theo so sinh vien tang dan");
				sap_xep_tang_dan(s, n);
				in_danh_sach(s, n);
				printf("\nin danh sach thanh cong!");
				printf("\nan phim bat ki de tiep tuc...");
				getch();
				break;
				
			case 4:
				printf("\nban da chon ghi file bin");
				sap_xep_tang_dan(s, n);
				ghi_file_bin(s, n);
				printf("\nghi file thanh cong!");
				printf("\nan phim bat ki de tiep tuc...");
				getch();
				break;
				
			case 5:
				printf("\nban da chon doc file bin");
				doc_file_bin(s, n);
				printf("\ndoc file thanh cong!");
				sap_xep_giam_dan(s, n);
				in_danh_sach(s, n);
				printf("\nin danh sach theo ty le giam dan thanh cong!");
				printf("\nan phim bat ki de tiep tuc...");
				getch();
				break;
		}	
		
	}while(nhap!=0);
	free(s);
} 
