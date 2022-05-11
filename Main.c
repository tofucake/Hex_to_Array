#include <stdio.h>
typedef unsigned char byte;

int main(void)
{
	char path[50] = {0};		//ファイルパス入力用配列
	printf("Please,enter a file name\n");
	scanf("%s", path); 
	FILE* fp = fopen(path, "rb");	//バイナリモードでオープン
	
	if(fp == NULL)			//NULLなら強制終了
	{
		printf("ERROR:Can't find data");
		return -1;
	}
	
	byte c = fgetc(fp);		//１バイト
	printf("byte Array[] = {");
	
	for(;;)
	{
		printf("0x%02x", c);
		c = fgetc(fp);		//呼ばれる度に次のバイトを読み込んでいく
		if (feof(fp)) break;	//変数cがファイルの末端を読み込んだならループ終了
		printf(",");	
	}
	
	printf("}");
	fclose(fp);
	return 0;
}
