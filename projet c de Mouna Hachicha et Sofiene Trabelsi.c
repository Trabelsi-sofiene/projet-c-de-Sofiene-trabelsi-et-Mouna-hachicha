#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define true 0
#define false 1

struct produit
	{
		char id[15];   // le code du produit
		char nom[30];
		float prix;
		int  quantite;
        int  nombrev;  // le nombre  total des produits vendu
		float somme;   // la somme des ventes
		int remise;  //remise sur le produit

	};

//**************************************************

	struct produit production[30];
	int nb = 0;	// nombre des produits
 	FILE *f;

//**************************************************

 	int Efichier()
{
    int i;
    f = fopen("texte.txt", "w");
    if (f == NULL)
        return -1;
    fprintf(f, "%d\n", nb);
    for (i = 0; i < nb; ++i)
    {

        fputs(production[i].id, f);
        fprintf(f, "\n");
        fputs(production[i].nom, f);
        fprintf(f, "\n");
        fprintf(f, "%f\n", production[i].prix);
        fprintf(f, "%d\n", production[i].quantite);
        fprintf(f, "%d\n", production[i].nombrev);
        fprintf(f, "%f\n", production[i].somme);
        fprintf(f, "%d\n", production[i].remise);
    }
    fclose(f);
    return 0;
}

//**************************************************

int Lfichier()
{
    int n = 0;
    int i;
    f = fopen("texte.txt", "r");
    if (f == NULL)
        return -1;
    fscanf(f, "%d\n", &n);
    for (i = 0; i < n; ++i)
    {
        fgets(production[i].id, 15, f);
        production[i].id[strlen(production[i].id) - 1] = 0;
        fgets(production[i].nom, 30, f);
        production[i].nom[strlen(production[i].nom)-1] = 0;
        fscanf(f, "%f", &production[i].prix);
        fscanf(f, "%d", &production[i].quantite);
        fscanf(f, "%d", &production[i].nombrev);
        fscanf(f, "%f\n", &production[i].somme);
        fscanf(f, "%d", &production[i].remise);
    }
    fclose(f);
    return n;
}

//**************************************************

void achat()
{
	int q,i;
    char id[15];
    int z=false;
    nb=Lfichier();
    printf("\nID du produit: ");
    fflush(stdin);
	gets(id);
    for (i=0; i<nb; i++){
        if (strcmp(id,production[i].id)==0)
        {
        	z=true;
	   	printf("\nnom du produit: %s",production[i].nom);
		printf("\nPrix: %f\n\n",production[i].prix);
	        do{
            printf("entrer la quantité desirée : ");
            fflush(stdin);
			scanf("%d",&q);
           }
           while (q<production[i].quantite)	;
            production[i].nombrev += q;
            production[i].quantite -= q;
            production[i].somme += q*(production[i].prix*(1-(production[i].remise/100.0)));
			}
	}
 if(z==false){

	printf("le produit est introuvable: %s.",id);
}
	Efichier();

}

//**************************************************

void supprimerp(){ //fonction qui efface un produit
	nb=Lfichier();
	char id[15];
	int i,j;
	int z=false;
printf("entrer l'ID du produit à supprimer  : ");
fflush(stdin);
gets(id);

for(i=0;i<nb;i++){
		z=true;
	if(strcmp(production[i].id,id)==0){
	for( j=i; j<(nb-1); j++)
			{
				production[j]=production[j+1];
			}
			nb--;
	}
}
if(z==false){
	printf("le produit est introuvable: %s .",id);
}
Efichier();
}

//**************************************************
int check(int i, int j)	// verifier si l id existe deja
{
	nb=Lfichier();
    printf("L'ID du produit: ");
    fflush(stdin);
	gets(production[nb].id);
    if (strcmp(production[i].id,production[j].id)==0){
        printf("L'ID existe deja ");
        return check(i++,j--);
		}
}

//**************************************************

void ajoutp(){	// fonction qui ajoute un produit

  	printf("entrer un nouveau produit\n");
	Lfichier();
  	    if (nb>0) {
  	    nb=Lfichier();
  		check(0,nb);
		}
	else{
		printf("\nL'Id du produit: ");
		fflush(stdin);
		gets(production[nb].id);
		}
		printf("le nom du produit: ");gets(production[nb].nom);
		printf("la quantité du produit: ");scanf("%d",&production[nb].quantite);
		printf("le prix du produit: ");scanf("%f",&production[nb].prix);
		printf("remise du produit: ");scanf("%d",&production[nb].remise);
		++nb;

	Efichier();
}

//**************************************************
int checkID(char id[]){
	int i;
nb=Lfichier();


 		Efichier();
 		for(i=0;i<nb;i++){

	if(strcmp(id,production[i].id)!=0){
			 fclose(f);
		}
   return 1;
  }

 fclose(f);
 return 0;
}

//**************************************************

void modifierp(){	// fonction qui modifie un produit
	char id[15];
    int test;
    int i;
	int x;

  printf("Entrer L'ID du produit à modifier: ");
	fflush(stdin);
	gets(id);
	test=checkID(id);
    if (test == 0)
 {
  printf("ID %s est introuvable", id);
 }
 else
 {
 		Lfichier();
  {
	for(i=0;i<nb;i++){

  if(strcmp(id,production[i].id)!=0)
	Efichier();
   else
   {
    printf("\n1. Modifier L' ID du produit");
    printf("\n2. Modifier le nom du produit ");
    printf("\n3. Modifier la quantité du produit");
    printf("\n4. Modifier le prix du produit");
    printf("\n5. Modifier la remise du produit");
    printf("\nEntrer votre choix du :");
    fflush(stdin);
    scanf("%d", &x);

    switch (x)
    {
    case 1:

     printf("Entrer le nouveau ID: ");
 		fflush(stdin);
        gets(production[i].id);
     break;
    case 2:
     printf("Entrer le nouveau nom: ");
    	fflush(stdin);
        gets(production[i].nom);
     break;
    case 3:
     printf("Entrer la nouvelle quantité : ");
    scanf("%d",&production[i].quantite);
    break;
    case 4:
     printf("Entrer le nouveau prix: ");
    scanf("%f",&production[i].prix);
     break;
     case 5:
     	 printf("Entrer la nouvelle remise : ");
   scanf("%d",&production[i].remise);
    default:
     printf("erreur");
     break;
    }
   Efichier();
   }

   }
  }
  fclose(f);
  f = fopen("texte.txt", "r");
 Lfichier();
 {
   Efichier();
  }
  fclose(f);
 }
}

//**************************************************

void expop(){ // fonction qui affiche tous les produits
	int i;

  nb = Lfichier();
  if (nb < 0)
    puts("erreur");
	printf(" \t\t\t\t *****  VITRINE *****\n");
   printf("\t---------------------------------------------------------------------------------------------------\n");
   printf("\tNUM |    NOM     |  ID PRODUIT  |  QUANTITE | NOMBRE VENDU |       PRIX        |  REMISE  |  SOMME \n");
   printf("\t---------------------------------------------------------------------------------------------------\n");

   for (i=0;i<nb;i++){
   printf("\t  %d      %s         %s         %d           %d        %f           %d          %f\n",i+1,production[i].nom,production[i].id,production[i].quantite,production[i].nombrev,production[i].prix,production[i].remise,production[i].somme);
	}

}

//**************************************************

void rechercherp(){// fonction qui recherche un produit dans le stock et l affiche
    int y;
    int i;
    char id[15];
    int T=0;
    nb = Lfichier();
    printf("Entrer L'ID du produit à rechercher : ");
	fflush(stdin);
	gets(id);
	T=checkID(id);
    if (T == 0)
 {
  printf("ID %s est introuvable\n", id);
 }
 else
 {printf("%d\n",&T);

     printf("le produit existe.voulez vous sa description?\n");
     printf("\n1-oui");
     printf("\n2-non");
     printf("\nEntrer votre choix: ");
     scanf("%d",&y);
 }
 switch(y){
 case 1:
   printf("\t---------------------------------------------------------------------------------------------------\n");
   printf("\tNUM |    NOM     |  ID PRODUIT  |  QUANTITE | NOMBRE VENDU |       PRIX        |  REMISE  |  SOMME \n");
   printf("\t---------------------------------------------------------------------------------------------------\n");
    for (i=0;i<nb;i++){
            if (strcmp(id,production[i].id)==0 ){
                printf("\t  %d      %s         %s         %d           %d        %f           %d          %f\n",i+1,production[i].nom,production[i].id,production[i].quantite,production[i].nombrev,production[i].prix,production[i].remise,production[i].somme);

    }

    }
 case 2:
    break;
 default:
    printf("essayer encore une fois ");
    break;
 }


}

//**************************************************

int main (){
	int x;
	nb = Lfichier();
	if(nb < 0)
		printf("erreur\n");

do{
	printf("\n");
	printf("\t\t\t  ===================================\n");
	printf("\t\t\t     Programme de gestion du stock\n");
	printf("\t\t\t  ===================================");

	printf("\n\nchoisissez:");
	printf("\n 1.) Ajouter un produit.");
	printf("\n 2.) Modifier un produit.");
	printf("\n 3.) Effacer un produit.");
	printf("\n 4.) Afficher tous les produits.");
	printf("\n 5.) Acheter un produit.");
	printf("\n 6.) rechercher un produit .");
	printf("\n 7.) Quitter le programme.");
	printf("\nChoix--> ");
	scanf("%d", &x);
	     switch(x){
        case 1 :
                ajoutp();
                break;
        case 2:
		    	modifierp();
				break;
        case 3:
        supprimerp();
               	 break;
        case 4:
               expop();
                break;
       	case 5:
       	achat();
		 break;
        case 6 :
            rechercherp();
            break;

		case 7:
		 	  exit(1);
			   break;
		 default :
                printf("essayer encore une fois ");
            break;
      }


}while(x!=6);
  printf("\nmerci pour votre confiance ");
}
