#include <iostream>
#include <cstring>
#include <cryptopp/channels.h> 
#include <cryptopp/filters.h> 
#include <cryptopp/sha.h> 
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <fstream>
#include <chrono> 
using namespace std::chrono; 

int main(int argc, char *argv[])
{
   using namespace CryptoPP;

   int execution[100];
      int etime[100];
      double overallavgtime=0;
      int i;
      double avg;
      for(i=0;i<5;i++){
      double avgtime=0;
      std::ifstream file("data.txt");
      std::string msg ;
      int j=0;
      
      while (std::getline(file, msg )) {   //get each line from data.txt which has 50 lines 
      //std::cout << str << "\n";

   auto start = high_resolution_clock::now();
  // Set hash variables
   SHA512 hash;
   std::string digest;

   // Run hash functions

    HexEncoder encoder(new FileSink(std::cout));

   // 
   hash.Update((const byte*)msg.data(), msg.size());
   digest.resize(hash.DigestSize());
   hash.Final((byte*)&digest[0]);
   std::cout << "Message: " << msg << std::endl;
   std::cout << "SHA-512: ";
   StringSource(digest, true, new Redirector(encoder));
   std::cout << std::endl;
   auto stop = high_resolution_clock::now();
   auto duration = duration_cast<microseconds>(stop - start);
    execution[j]=duration.count();
    j++;
}

 for(j=0;j<50;j++)                  //this loop is besically calculate the avg time of 50 iteration
    {
       avgtime= avgtime+execution[j];
     }
      std::cout << "Avg execution time by 50 iterration in microsecond:";
      avg = avgtime/50.0f;
      std::cout<<avg<< std::endl;
      etime[i] = avg;


}


    for(i=0;i<5;i++)                  //this loop is besically calculate the avg time of 5 (50 iteration)
    {
       //std::cout<<time[i]<<std::endl;
       overallavgtime= overallavgtime+etime[i];
     }
      std::cout << "the average of all the avg. execution time in microsecond:";
      avg = (overallavgtime/5.0f);
      std::cout<<avg<< std::endl;


}
