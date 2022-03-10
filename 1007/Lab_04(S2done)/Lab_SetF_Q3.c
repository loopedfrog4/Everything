#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>  
 
#define CIPHER_KEY 8
#define SECOND_KEY -1
 
void main() 
{ 
    char fileName[20], ch; 
    FILE *fpTxtOriginal, *fpTxtEncrypt, *fpBinDecrypt; 
    FILE *fpBin, *fpBinData; 
    char strTemp[100] = "", strOriginal[100] = "";  
    char strEncrypted[100] = "", strDecrypted[100] = "";  
    char charPlain, charCipher; 
    char strBin[100] = ""; 
    float floatBin = 0.0; 
    unsigned char dataBin[300] = {0x00}; 
    int i, length, ret;
     
    printf("Opening encrypted text mode file %s\n", "Lab_EncryptedText.txt"); 
    fpTxtEncrypt = fopen("Lab_EncryptedText.txt", "r"); // text mode 
    if(fpTxtEncrypt == NULL) {
        printf(" File does not exist or error in opening %s\n", "Lab_EncryptedText.txt"); 
        fclose(fpTxtOriginal); 
        exit(4); 
    } 
 
    printf("\nEncrypted content: ");  
    if( fgets (strEncrypted, 100, fpTxtEncrypt) != NULL ) { 
      puts(strEncrypted); // write content to stdout 
    } 
     
    printf("Closing encrypted text mode file %s\n", "Lab_EncryptedText.txt");   
    fclose(fpTxtEncrypt); 
 
    //Decrypt 
    length = strlen(strEncrypted); 
    for (i = 0; i < length; i++) { 
        ch = strEncrypted[i];  
     
        // Perform Caesar Cipher substitution decryption 
        if (ch != ' ') {
            ch = (ch - CIPHER_KEY);
            ch = (ch - SECOND_KEY);
            strncat(strDecrypted, &ch, 1);  
        }else{
            strncat(strDecrypted, &ch, 1);  
        }
         
    } 
    printf("\nDecrypted content: %s\n", strDecrypted);  
    printf("\n");
 
    printf("Opening file %s in text mode to write encrypted content\n", "Lab_SetF1_Q3.txt"); 
    FILE *out = fopen("Lab_SetF1_Q3.txt","w");
    fprintf(out, "FIRST KEY: %d\n SECOND KEY: %d\n %s", CIPHER_KEY, SECOND_KEY, strDecrypted);
	fclose(out);
}

