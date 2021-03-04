
//
//     0w0
//

#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include <cstring>
#pragma comment(lib, "urlmon.lib")
using namespace std;

int main()
{
	char path[MAX_PATH];
	GetCurrentDirectory(MAX_PATH,path);
    printf("%s%s\n","CurrentPath: ",path);
	cout << "Enter Song ID..."<<endl;
	char songid[20];
	gets_s(songid);
	printf("SongID: %s\n",songid);
	string SongURL;
	SongURL = SongURL + "https://music.163.com/song/media/outer/url?id=";
	SongURL = SongURL + songid;
	SongURL = SongURL + ".mp3";

	const char* SongURLchar;
	SongURLchar = SongURL.data();


	cout << "SongURL: "+SongURL << endl;


	string filename;
	filename = filename + path;
	filename = filename + "\\";
	filename = filename + songid;
	filename = filename + ".mp3";


	const char* filenamechar;
	filenamechar = filename.data();


	cout << "FileName: " +filename << endl;


	URLDownloadToFileA(NULL, SongURLchar, filenamechar, 0, NULL);
	printf("Succeed.\n");//有时间的话加个失败/成功判断


}

