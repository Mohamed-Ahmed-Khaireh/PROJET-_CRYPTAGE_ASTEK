#include "entete.h"


int main()
{
    int Selec;
    char source[TEXT];
    char perroquet[TEXT];



    do
    {
     Selec = Interface();
        switch (Selec)
        {
        case 1:

                printf("\n\tLe texte a cypter ? : ");
                fflush(stdin);
                //("%s",source);
                gets(source);



                    Write(source, "source.txt");

        break;

        case 2:


                printf("\n\tLa cle de cryptage ? : ");
                fflush(stdin);
                //scanf("%s", perroquet);
                gets(perroquet);



                    Write(perroquet, "peroq.def");


        break;

        case 3: //CRYPTER
            Crypt();

        break;

        case 4: //DECRYPTER
            Decrypt();
        break;

        }
    }while (Selec!= 5);
  printf("\n\t\t\t\t\tBye Bye, que la force soit avec vous !\n");
    return 0;
}
