#include <stdio.h>
#include <string.h>
#define MAXSIZE 100
#define KEY 50

int Encryption(char* Plaintext, char* key) //�����㷨
{
	int i = 0, j = strlen(key), k = strlen(Plaintext), m = 0;
	char result[MAXSIZE] = { 0 };
	for (i = 0; i < k; i++)
	{
		if (Plaintext[i] != ' ' && Plaintext[i] >= 'a' && Plaintext[i] <= 'z')//������Сд��ĸ
		{
			if (key[m % j] >= 'a' && key[m % j] <= 'z')//��ԿΪСд��ĸ
			{
				result[i] = (Plaintext[i] + key[m % j] - 2 * 'a') % 26 + 'a';
			}
			else if (key[m % j] >= 'A' && key[m % j] <= 'Z')//��ԿΪ��д��ĸ
			{
				result[i] = (Plaintext[i] + key[m % j] - 'A' - 'a') % 26 + 'a';
			}
			m++;
		}
		else if (Plaintext[i] != ' ' && Plaintext[i] >= 'A' && Plaintext[i] <= 'Z')//�����Ǵ�д��ĸ
		{
			if (key[m % j] >= 'a' && key[m % j] <= 'z')//��ԿΪСд��ĸ
			{
				result[i] = (Plaintext[i] + key[m % j] - 'a' - 'A') % 26 + 'A';
			}
			else if (key[m % j] >= 'A' && key[m % j] <= 'Z')//��ԿΪ��д��ĸ
			{
				result[i] = (Plaintext[i] + key[m % j] - 'A' - 'A') % 26 + 'A';
			}
			m++;
		}
		else
			result[i] = ' ';
	}
	printf("���ܺ������Ϊ��%s\n", result);
	return 0;
}

int Decrypt(char* Ciphertext, char* key)//�����㷨
{
	int i = 0, j = strlen(key), k = strlen(Ciphertext), m = 0;
	char result[MAXSIZE] = { 0 };
	for (i = 0; i < k; i++)
	{
		if (Ciphertext[i] != ' ' && Ciphertext[i] >= 'a' && Ciphertext[i] <= 'z')//������Сд��ĸ
		{
			if (key[m % j] >= 'a' && key[m % j] <= 'z')//��ԿΪСд��ĸ
			{
				result[i] = (Ciphertext[i] + 26 - (key[m % j] - 'a') - 'a') % 26 + 'a';
			}
			else if (key[m % j] >= 'A' && key[m % j] <= 'Z')//��ԿΪ��д��ĸ
			{
				result[i] = (Ciphertext[i] + 26 - (key[m % j] - 'A') - 'a') % 26 + 'a';
			}
			m++;
		}
		else if (Ciphertext[i] != ' ' && Ciphertext[i] >= 'A' && Ciphertext[i] <= 'Z')//�����Ǵ�д��ĸ
		{
			if (key[m % j] >= 'a' && key[m % j] <= 'z')//��ԿΪСд��ĸ
			{
				result[i] = (Ciphertext[i] + 26 - (key[m % j] - 'a') - 'A') % 26 + 'A';
			}
			else if (key[m % j] >= 'A' && key[m % j] <= 'Z')//��ԿΪ��д��ĸ
			{
				result[i] = (Ciphertext[i] + 26 - (key[m % j] - 'A') - 'A') % 26 + 'A';
			}
			m++;
		}
		else
			result[i] = ' ';
	}
	printf("���ܺ������Ϊ��%s\n", result);
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
		printf("   1.����\n");
		printf("   2.����\n");
		printf("   0.�˳�\n");
		printf("===============\n");
		printf("������Ҫִ�еĲ�����");
		scanf_s("%d", &n);
		getchar();
		switch (n)
		{
		case 1:
			printf("���������ģ�");
			scanf_s("%[^\n]", Plaintext, MAXSIZE);
			getchar();
			printf("��������Կ��");
			scanf_s("%[^\n]", key, KEY);
			Encryption(Plaintext, key);
			break;
		case 2:
			printf("���������ģ�");
			scanf_s("%[^\n]", Ciphertext, MAXSIZE);
			getchar();
			printf("��������Կ��");
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