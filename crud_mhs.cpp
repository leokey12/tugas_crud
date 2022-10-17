#include <iostream>
using namespace std;

int jumlah,choice;

struct data_tgllahir{
	char tgl[100];
	char bulan[100];
	char tahun[100];
};
 
struct data_mhs{
    string nama[100];
    char nim[100];
    data_tgllahir tgllahir;
    string matakuliah[100];
};

void menu(){
	cout<<"Menu : "<<endl;
	cout<<"1.Create"<<endl;
	cout<<"2.Update"<<endl;
	cout<<"3.Read"<<endl;
	cout<<"4.Delete"<<endl;
	cout<<"5.Exit"<<endl;
}

void batas(){
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
}

data_mhs input_data(data_mhs);
data_mhs update_data(data_mhs);
data_mhs delete_data(data_mhs);
void output_data(data_mhs);
int main(){
	char reply;
	int pilihan;
	reply ='t';
	data_mhs mhs ,tempmhs;
	do{
	system("cls");
 	menu();
	cout<<"Pilihan : ";
	cin>>pilihan;
		switch(pilihan){
		case 1 : 
			system("cls");
			cout << "Jumlah data : ";
			cin >> jumlah;
			{
				tempmhs = input_data(mhs);
				mhs = tempmhs;
			}
			break;
		case 2 :
			system("cls");
			if(jumlah == 0){
				cout<<"---DAFTAR KOSONG---"<<endl;
			}else{
				output_data(mhs);
				cout<<endl;
				batas();
				cout<<"Data yang ingin diUpdate : ";
				cin>>choice;
				batas();
				tempmhs = update_data(mhs);
				mhs = tempmhs;
			}
		
		case 3 :
			system("cls");
			if(jumlah == 0){
				cout<<"---DAFTAR KOSONG---"<<endl;
			}else{
				output_data(mhs);
			}
			break;
			
		case 4 : 
			system("cls");
			if(jumlah == 0){
				cout<<"---DAFTAR KOSONG---"<<endl;
			}else{
				output_data(mhs);
				cout<<endl;
				batas();
				cout<<"Data yang ingin diDelete : ";
				cin>>choice;
				batas();
				tempmhs = delete_data(mhs);
				mhs = tempmhs;
			}
			break;
		case 5:
				exit(1);
		default:
				cout<<"---PILIHAN SALAH---"<<endl;
		}
		cout<<"Pergi Ke Menu(Y/N) ? ";
		cin>>reply;
	} while(reply=='Y' or reply=='y');
	 cout<<"Anda keluar dari program. Terima kasih"<<endl;

}

data_mhs input_data (data_mhs mhs){
	for (int i=1; i < jumlah+1; i++){  
		cin.ignore();
		cout<<"Masukkan Nama Mahasiswa : ";
		cin>>mhs.nama[i];
		cout<<"Masukkan NIM pratikkan : ";
		cin>>mhs.nim[i];
		cin.ignore();
		cout<<"=== Masukkan Tanggal Lahir ===\n";
		cout<<"Masukkan Tanggal : ";
		cin>>mhs.tgllahir.tgl[i];
		cin.ignore();
		cout<<"Masukkan Bulan : ";
		cin>>mhs.tgllahir.bulan[i];
		cin.ignore();
		cout<<"Masukkan Tahun : ";
		cin>>mhs.tgllahir.tahun[i];
		cin.ignore();
		cout<<"Masukkan Matakuliah Mahasiswa : ";
		getline(cin,mhs.matakuliah[i]);
		cin.ignore();
		cout<<"data telah diinput\n\n";
	}
	return mhs;
}

data_mhs update_data (data_mhs mhs){
	cin.ignore();
	cout<<"Masukkan Nama Mahasiswa : ";
	getline(cin,mhs.nama[choice]);
	cout<<"Masukkan NIM pratikkan : ";
	cin>>mhs.nim[choice];
	cout<<"=== Masukkan Tanggal Lahir ===\n";
	cout<<"Masukkan Tanggal : ";
	cin>>mhs.tgllahir.tgl[choice];
	cout<<"Masukkan Bulan : ";
	cin>>mhs.tgllahir.bulan[choice];
	cout<<"Masukkan Tahun : ";
	cin>>mhs.tgllahir.tahun[choice];
	cin.ignore();
	cout<<"Masukkan Matakuliah Mahasiswa : ";
	getline(cin,mhs.matakuliah[choice]);
	cout<<"data telah diupdate\n\n";
	return mhs;
}

data_mhs delete_data (data_mhs mhs){
	mhs.nama[choice] = ' ';
	mhs.nim[choice] = ' ';
	mhs.tgllahir.tgl[choice] = ' ';
	mhs.tgllahir.bulan[choice] = ' ';
	mhs.tgllahir.tahun[choice] = ' ';
	mhs.matakuliah[choice] = ' ';
	cout<<"data telah didelete\n\n";
	jumlah-=1;
	return mhs;
}

void output_data (data_mhs mhs){    
			cout<<"	Data Mahasiswa "<<endl;
		for (int i=1; i < jumlah+1; i++){	
			cout<<"----------------------------------------"<<endl;
			cout<<"No                   : " << i <<endl;
			cout<<"Nama Mahasiswa       : " << mhs.nama[i]<<endl;
			cout<<"NIM Mahasiswa        : " << mhs.nim[i]<<endl;
			if(mhs.tgllahir.tgl[i] != ' ' && mhs.tgllahir.bulan[i] != ' ' && mhs.tgllahir.tahun[i] != ' '){
				cout<<"Tanggal Lahir        : " << mhs.tgllahir.tgl[i] << "-" <<mhs.tgllahir.bulan[i]<< "-" << mhs.tgllahir.tahun[i] << endl;
			}
			cout<<"Matakuliah Mahasiswa : " << mhs.matakuliah[i]<<endl;
		}
}
