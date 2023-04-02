#include <stdio.h>
#include <string.h>
#define MAXSIZE 100
#define KEY 50

int Encryption(char* Plaintext, char* key) //加密算法
{
	int i = 0, j = strlen(key), k = strlen(Plaintext), m = 0;
	char result[MAXSIZE] = { 0 };
	for (i = 0; i < k; i++)
	{
		if (Plaintext[i] != ' ' && Plaintext[i] >= 'a' && Plaintext[i] <= 'z')//明文是小写字母
		{
			if (key[m % j] >= 'a' && key[m % j] <= 'z')//密钥为小写字母
			{
				result[i] = (Plaintext[i] + key[m % j] - 2 * 'a') % 26 + 'a';
			}
			else if (key[m % j] >= 'A' && key[m % j] <= 'Z')//密钥为大写字母
			{
				result[i] = (Plaintext[i] + key[m % j] - 'A' - 'a') % 26 + 'a';
			}
			m++;
		}
		else if (Plaintext[i] != ' ' && Plaintext[i] >= 'A' && Plaintext[i] <= 'Z')//明文是大写字母
		{
			if (key[m % j] >= 'a' && key[m % j] <= 'z')//密钥为小写字母
			{
				result[i] = (Plaintext[i] + key[m % j] - 'a' - 'A') % 26 + 'A';
			}
			else if (key[m % j] >= 'A' && key[m % j] <= 'Z')//密钥为大写字母
			{
				result[i] = (Plaintext[i] + key[m % j] - 'A' - 'A') % 26 + 'A';
			}
			m++;
		}
		else
			result[i] = ' ';
	}
	printf("加密后的密文为：%s\n", result);
	return 0;
}

int Decrypt(char* Ciphertext, char* key)//解密算法
{
	int i = 0, j = strlen(key), k = strlen(Ciphertext), m = 0;
	char result[MAXSIZE] = { 0 };
	for (i = 0; i < k; i++)
	{
		if (Ciphertext[i] != ' ' && Ciphertext[i] >= 'a' && Ciphertext[i] <= 'z')//明文是小写字母
		{
			if (key[m % j] >= 'a' && key[m % j] <= 'z')//密钥为小写字母
			{
				result[i] = (Ciphertext[i] + 26 - (key[m % j] - 'a') - 'a') % 26 + 'a';
			}
			else if (key[m % j] >= 'A' && key[m % j] <= 'Z')//密钥为大写字母
			{
				result[i] = (Ciphertext[i] + 26 - (key[m % j] - 'A') - 'a') % 26 + 'a';
			}
			m++;
		}
		else if (Ciphertext[i] != ' ' && Ciphertext[i] >= 'A' && Ciphertext[i] <= 'Z')//明文是大写字母
		{
			if (key[m % j] >= 'a' && key[m % j] <= 'z')//密钥为小写字母
			{
				result[i] = (Ciphertext[i] + 26 - (key[m % j] - 'a') - 'A') % 26 + 'A';
			}
			else if (key[m % j] >= 'A' && key[m % j] <= 'Z')//密钥为大写字母
			{
				result[i] = (Ciphertext[i] + 26 - (key[m % j] - 'A') - 'A') % 26 + 'A';
			}
			m++;
		}
		else
			result[i] = ' ';
	}
	printf("解密后的明文为：%s\n", result);
	return 0;
}
int main()
{
	int n;
	char Plaintext[MAXSIZE] = { 0 };
	char Ciphertext[MAXSIZE] = { 0 };
	char key[KEY] = { 0 };
	while (1)
	{
		printf("===============\n");
		printf("   1.加密\n");
		printf("   2.解密\n");
		printf("   0.退出\n");
		printf("===============\n");
		printf("请输入要执行的操作：");
		scanf_s("%d", &n);
		getchar();
		switch (n)
		{
		case 1:
			printf("请输入明文：");
			scanf_s("%[^\n]", Plaintext, MAXSIZE);
			getchar();
			printf("请输入密钥：");
			scanf_s("%[^\n]", key, KEY);
			Encryption(Plaintext, key);
			break;
		case 2:
			printf("请输入密文：");
			scanf_s("%[^\n]", Ciphertext, MAXSIZE);
			getchar();
			printf("请输入密钥：");
			scanf_s("%[^\n]", key, KEY);
			Decrypt(Ciphertext, key);
			break;
		case 0:
			exit(0);
			break;
		}
	}
	return 0;
}