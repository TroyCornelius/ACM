#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;
FILE *f = fopen("source.cpp", "w");
string content;
int key[35], keyLength, contentLength;
void init()
{
     content="71060c02241a11224f52144754595f6a1d515d08003b521733060c49614f0e4d4f4e4713595e44641b4f6a415f7f4970724f42412e0007674707094710591079555f6c41076f4e5a3c54420863445c671464471310101064554f310e1c6f5a133c1b420b68525577544e0d130c105e7f55057c4a476f0970724f4241684f55674f4e4713565f42645d0639154e245247725f5941234f4967015547581b1b19640e6577414e6f525a724f4241684f55674f4e5c3910101064554f77414e6f525a2f654241684f55674f4e1a3910101064086577414e6f5d55060707412b0011224f0c02555f4255641c1c77141d2a1e1f211c4e412701193e4f08084110595e27070a36120721155a26070741240a1b201b06475c5610442c1c1c7702012b1754584f4241681f00331c4645635c555137104f24140c221b0e7202074d681b1d22014e1e5c4510472d190377060b3b523b114f584c614d5c7c654e47131040453006477535062a5211371642083b4f27280d0f2f5c45775f2a125c67515e0b0715050e0c2e3a15576e5464471310101f6b210732410f3a06123d1d1141270955330707141340425f26190a3a41546f1e13311c16003a4f14290b4e035c425155291a01380a646f525a721d07153d1d1b675f556d4e3a3a";
    // keyLength = rand()%31 + 1;
     //for (int i=0; i<keyLength; i++) key[i] = rand()%100;
     }
void Decrypt()
{
     contentLength = content.length();
     for(int i = 0; i < contentLength; i += keyLength) 
     {
        for(int j = 0; j < keyLength && i + j < contentLength; j++) 
        {
                fprintf(f, "%.2x", content[i + j] ^ key[j]);
        }
     }
     }
void dfs(int len)
{
     if (len >= keyLength)
     {
        Decrypt();
        return;       
     }
     else
     {
        for (int i=0; i<=30; i++){ key[len] = i;
        dfs(len+1);   }
     }
     
     }
int main()
{
    srand(12345);
    init();
    for (int i=1; i<=31; i++)
    {
        keyLength = i;
        dfs(0);
  //  Decrypt();
    fprintf(f, "\n\n\n");
    }
    return 0;
    }
