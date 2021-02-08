#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <chrono> 
#include "cryptopp/modes.h"
#include "cryptopp/aes.h"
#include "cryptopp/filters.h"
using namespace std::chrono; 
int main(int argc, char* argv[]) {
    
    
    byte key[ CryptoPP::AES::DEFAULT_KEYLENGTH ], iv[ CryptoPP::AES::BLOCKSIZE ];
    memset( key, 0x00, CryptoPP::AES::DEFAULT_KEYLENGTH );
    memset( iv, 0x00, CryptoPP::AES::BLOCKSIZE );

      int i;
      double avg;
      int encrypt[100];
      int decrypt[100];
      int etime[100];
      int dtime[100];
      double overallavgtime=0;
      for(i=0;i<5;i++){

      std::ifstream file("data.txt");
      std::string plaintext;
      int j=0;
      double avgtime=0;

      while (std::getline(file, plaintext)) {
      //std::cout << str << "\n";
      
      
       //j++;
       

    //std::string plaintext = "hii";
    std::string ciphertext;
    std::string decryptedtext;

    //
    // Dump Plain Text
    //
    //std::cout << "Plain Text (" << plaintext.size() << " bytes)" << std::endl;
    //std::cout << plaintext;
    //std::cout << std::endl << std::endl;

    //
    
    //
    auto start = high_resolution_clock::now();
    // Create Cipher Text
    CryptoPP::AES::Encryption aesEncryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption( aesEncryption, iv );

    CryptoPP::StreamTransformationFilter stfEncryptor(cbcEncryption, new         CryptoPP::StringSink( ciphertext ) );
    stfEncryptor.Put( reinterpret_cast<const unsigned char*>( plaintext.c_str() ),   plaintext.length() );
    stfEncryptor.MessageEnd();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    
    encrypt[j]=duration.count();
    


    // Dump Cipher Text
    //
    //std::cout << "Cipher Text (" << ciphertext.size() << " bytes)" << std::endl;

    //for( int i = 0; i < ciphertext.size(); i++ ) {

     //   std::cout << "0x" << std::hex << (0xFF & static_cast<byte>(ciphertext[i])) << " ";
   // }

    //std::cout << std::endl << std::endl;

    //
   
    //
    auto start1 = high_resolution_clock::now();
    // Decrypt
    CryptoPP::AES::Decryption aesDecryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Decryption cbcDecryption( aesDecryption, iv );

    CryptoPP::StreamTransformationFilter stfDecryptor(cbcDecryption, new CryptoPP::StringSink( decryptedtext ) );
    stfDecryptor.Put( reinterpret_cast<const unsigned char*>( ciphertext.c_str() ), ciphertext.size() );
    stfDecryptor.MessageEnd();
   
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    
    decrypt[j]=duration1.count();
     

    //
    // Dump Decrypted Text
    //
    //std::cout << "Decrypted Text: " << std::endl;
    //std::cout << decryptedtext;
    //std::cout << std::endl << std::endl;


     
  
    //std::cout << "Time taken by"<< j <<"iterration: "
        // << duration.count() << " microseconds" << std::endl;
      
         j++;

   }
    for(j=0;j<50;j++)
    {
       avgtime= avgtime+encrypt[j];
     }
      std::cout << "Avg Encrypion time by 50 iterration in microsecond:";
      avg = avgtime/50.0f;
      std::cout<<avg<< std::endl;
      etime[i] = avg;
   
    

   for(j=0;j<50;j++)
    {
       avgtime= avgtime+decrypt[j];
     }
      std::cout << "Avg decrypion time by 50 iterration in microsecond:";
      avg = avgtime/50.0f;
      std::cout<<avg<< std::endl;
      dtime[i] = avg;
       
   }
  
    for(i=0;i<5;i++)
    {
       //std::cout<<time[i]<<std::endl;
       overallavgtime= overallavgtime+etime[i];
     }
      std::cout << "the average of all the avg. execution times(Encryption)in microsecond:";
      avg = (overallavgtime/5.0f);
      std::cout<<avg<< std::endl;

    for(i=0;i<5;i++)
    {
       //std::cout<<time[i]<<std::endl;
       overallavgtime= overallavgtime+dtime[i];
     }
      std::cout << "the average of all the avg. execution times (decryption) in microsecond:";
      avg = (overallavgtime/5.0f);
      std::cout<<avg<< std::endl;



}
