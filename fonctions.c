#include "entete.h"



/*************************************************************************************************************/
 //Interface des choix
 int Interface()
{
    int Selec;

do
    {

printf("\n                             _________________________________________________________________");
printf("\n                            |                            MENU                                 |");
printf("\n                            |                                                                 |");
printf("\n                            |                                                                 |");
printf("\n                            | 1 => Saisissez ou modifiez le texte \x85 crypter (source.txt)      |");
printf("\n                            | 2 => Changez la cle de cryptage (peroq.def)                     |");
printf("\n                            | 3 => Crypter votre texte (dest.crt)                             |");
printf("\n                            | 4 => Decrypter votre texte (result.txt)                         |");
printf("\n                            |                                                                 |");
printf("\n                            |                     5 => EXIT  (BYE)                            |");
printf("\n                            |_________________________________________________________________|");
printf("\n\n\t");


    fflush(stdin); // windows
    scanf("%d", &Selec);

    if (Selec==0)
    {
        printf("Erreur de saisie ! Vous aviez saisi un nombre nul. Veuillez saisir un nombre (1 a 5)\n");

    }
    else if (Selec < 1)
    {
        printf("Erreur de saisie ! Vous aviez saisi un nombre negative. Veuillez saisir un nombre (1 a 5)\n");
    }
    else if (Selec > 5)
    {
        printf("Erreur de saisie ! Vous aviez saisi un nombre superieur a 5. Veuillez saisir un nombre (1 a 5)\n");
    }

    }while (Selec < 1 || Selec > 5);

    return Selec;
}
/**************************************************************************************************************************/


// Ecriture dans le fichier (source.txt et peroq.def)
/***************************************************************************************************************************/

int Write(char modif_fic[], char fichier[])
{
    //Ouverture du fichier source.txt pour la modification
    FILE *fp = NULL;
    fp = fopen(fichier, "w+");

    if (fp == NULL)
    {
        printf("\n\tErreur d'ouverture du fichier.\n");
        return EXIT_FAILURE;
    }

    fwrite(modif_fic, strlen(modif_fic), 1, fp);

    printf("\n\tEcriture dans le fichier \"%s\" terminee.\n\n", fichier);

    //Fermeture du fichier source.txt
     fclose(fp);
    if (!fclose(fp))
    {
        printf("\n\tErreur fermeture du fichier.\n");
        return EXIT_FAILURE;
    }

    return 0;
}

/**************************************************************************************************************************************************/



/*****************************************************************************************************************************************************/

int Crypt()
{
    FILE *fp = NULL;  // Fichier source
    FILE *fp1 = NULL; // Fichier contenant la clef de cryptage
    FILE *fp2 = NULL; // Fichier contenant les donnees cryptees (dst)

    fp = fopen("source.txt", "r");
    if (fp == NULL)
    {
        printf("\n\tErreur creation fichier source.txt.\n");

        return EXIT_FAILURE;
    }

    fp1 = fopen("peroq.def", "r");
    if (fp1 == NULL)
    {
        printf("\n\tErreur ouverture peroq.def");

        return EXIT_FAILURE;
    }

    fp2 = fopen("dest.crt", "w+");
    if (fp2 == NULL)
    {
        printf("\n\tErreur creation fichier dest.crt.\n");

        return EXIT_FAILURE;
    }

    char perroquet[TEXT];
    char x;
    for (int j = 0; j < TEXT; j++)
    {
        fread(&x, sizeof(x), 1, fp1);
        perroquet[j] = x;
    }
    char lettre;
    fread(&lettre, sizeof(lettre), 1, fp);
    int i = 0;
    char crypt;
    while (!feof(fp))
    {
        if (i == TEXT)
        {
            i = 0;
        }
        crypt = lettre - perroquet[i];
        fread(&lettre, sizeof(lettre), 1, fp);
        fwrite(&crypt, sizeof(crypt), 1, fp2);
        i++;
    }
    printf("\n\tCryptage termine.\n\n");

    if (fclose(fp) != 0)
    {
        printf("\n\tErreur fermeture source.txt");
    }

    if (fclose(fp1) != 0)
    {
        printf("\n\tErreur fermeture perroq.def");
    }

    if (fclose(fp2) !=0)
    {
        printf("\n\tErreur fermeture dest.crt");
    }
    remove("source.txt");

    return 0;
}
/**************************************************************************************************************/


int Decrypt()
{
    FILE *fp1 = NULL; // Fichier contenant la clef de cryptage
    FILE *fp2 = NULL; // Fichier contenant les donnees cryptees
    FILE *fp3 = NULL; // Fichier contenant les donnees decryptees

    fp1 = fopen("peroq.def", "r");
    if (fp1 == NULL)
    {
        printf("\n\tErreur ouverture peroq.def");
        return(EXIT_FAILURE);
    }

    fp2 = fopen("dest.crt", "r");
    if (fp2 == NULL)
    {
        printf("\n\tErreur ouverture dest.crt");
        return(EXIT_FAILURE);
    }

    fp3 = fopen("result.txt", "w+");
    if (fp3 == NULL)
    {
        printf("\n\tErreur ouverture result.txt");
        return(EXIT_FAILURE);
    }

    char perroquet[TEXT];
    char x;
    for (int j = 0; j < TEXT; j++)
    {
        fread(&x, sizeof(x), 1, fp1);
        perroquet[j] = x;
    }

    char crypt;
    fread(&crypt, sizeof(crypt), 1, fp2);
    int i = 0;
    char lettre;
    while (!feof(fp2))
    {
        if (i == TEXT)
        {
            i = 0;
        }
        lettre = perroquet[i] + crypt;
        fread(&crypt, sizeof(crypt), 1, fp2);
        fwrite(&lettre, sizeof(lettre), 1, fp3);
        i++;
    }



    if (fclose(fp1)!=0)
    {
        printf("\n\tErreur fermeture perroq.def");
        return(EXIT_FAILURE);
    }


    if (fclose(fp2)!=0)
    {
        printf("\n\tErreur fermeture dest.crt");
        return(EXIT_FAILURE);
    }


    if (fclose(fp3)!=0)
    {
        printf("\n\tErreur fermeture result.txt");
        return(EXIT_FAILURE);
    }
   ///// lecture fichier result.txt (decryptatge)
    char chaine[TEXT] = "";

     FILE *fp4 = NULL;
     fp4 = fopen("result.txt", "r");

    if (fp3 != NULL)
     {

       while( fgets(chaine, TEXT, fp4)!=NULL); // On lit le fichier tant qu'on ne redoit pas d'erreur (NULL)

        printf("\n\tDecryptage termine.\n");
        printf("\n\tDecryptage du contenu du fichier \"dest.crt\" : %s \n", chaine); // On affiche la chaine qu'on vient de lire


        fclose(fp4);
     }
 remove("result.txt");
return 0;
}
