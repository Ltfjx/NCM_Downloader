
//
//     0w0
//


#include <stdio.h>
#include <iostream>
#include <cstring>
#include <afx.h>
#include <thread>

#pragma comment(lib, "urlmon.lib")
using namespace std;

inline bool ifexists(const std::string& name) {
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}

void download(const char* SongURLchar,const char* filenamechar)
{
	URLDownloadToFileA(NULL, SongURLchar, filenamechar, 0, NULL);//下载文件
}

int main()
{
	//初始化
	string temp;//临时用于将char转换为string的变量
	const char* tempchar;
	char path[MAX_PATH];
	GetCurrentDirectory(MAX_PATH,path);
	//string configdir = configdir + temp;
	//configdir = configdir + "\\NCMD_Config.ini";
	//tempchar = configdir.data();
	//if (ifexists(temp+"\\NCMD_Config.ini")==false)
	//{
	//	::WritePrivateProfileString("NCMD", "Debug", false, tempchar);
	//}
	//GetPrivateProfileString("NCMD", "Debug", false, isdebugenabled.GetBuffer(MAX_PATH), MAX_PATH,tempchar );


	temp = path;
	cout <<"CurrentPath: " + temp<<endl;
	cout << "Enter Song ID..."<<endl;
	char songid[20];


	//输入歌曲id
	gets_s(songid);
	cout << endl;
	temp = songid;
	cout << "SongID: "+temp<< endl;



	string SongURL;
	SongURL = SongURL + "https://music.163.com/song/media/outer/url?id=";
	SongURL = SongURL + songid;
	SongURL = SongURL + ".mp3";

	const char* SongURLchar;
	SongURLchar = SongURL.data();//String to char


	cout << "SongURL: "+SongURL << endl;


	string filename;
	filename = filename + path;
	filename = filename + "\\";
	filename = filename + songid;
	filename = filename + ".mp3";


	const char* filenamechar;
	filenamechar = filename.data();


	cout << "FileName: " +filename << endl;


	thread th(download,SongURLchar,filenamechar);//启动下载线程
	cout << endl<<"Downloading..." << endl;
	th.join();
	cout << "Comeplete." << endl << endl;
	
	CFile DownloadFile;//判断下载的文件的大小
	if (DownloadFile.Open(filenamechar, CFile::modeRead))
	{
		int DownloadFileSize = DownloadFile.GetLength();
		cout << "FileSize: " ;
		cout << DownloadFileSize << endl;
		cout << endl;
		DownloadFile.Close();

		if (DownloadFileSize == 93477)//若下载失败会返回该大小的文件
		{
			cout << "Failed. The SongID seems to be wrong? " << endl;
			remove(filenamechar);//若下载失败，则删除文件
			cout << "Press any key to exit...";
			getchar();
		}
		else
		{
			cout << "Succeed." << endl;
			cout << "Press any key to exit...";
			getchar();
		}

	}
	


}

