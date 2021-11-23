#include<stdio.h>
#include<string.h>

// *******strecture des information de client********

struct Client{
	char Nom[12];
	char Prenom[12];
	char CIN[12];
	float Montant;
};
struct	Client C[1000];
int nombreDuCompte = 0;

//  fonction permit d'ajouter une client
void Ajouter_client(){
        
    
         	printf("saisir le nom de client \n");
         	scanf("%s", C[nombreDuCompte].Nom);
         	printf("donner le prenom de client\n");
         	scanf("%s", C[nombreDuCompte].Prenom);
         	printf("donner CIN de client \n");
         	scanf("%s", C[nombreDuCompte].CIN);
         	printf("donner le montant\n");
         	scanf("%f",&C[nombreDuCompte].Montant );
         	
         	nombreDuCompte++;
}
 //  fonction permit de Depotre le montant  
void Depot(int i){	
	 float MD;
	 printf("saisir le montant que vous volez Depotre\t");
	 scanf("%f",&MD);
	 C[i].Montant += MD;
	 printf("votre montant apre l'operation est %f ",C[i].Montant);
     
}
//  fonction permit de retrer le montant	 
	 
void Retrait(int u){
	 float MR;
	 printf("saisir le montant que vous volez retrait\t");
	 scanf("%f",&MR);
	 if (MR > C[u].Montant){
	 	printf("votre solde ne suffit pas ");
	 } 
	 else{
	 printf("votre montant apres l'operation est %f",C[u].Montant -= MR);
      }
}
   // fonction permit de  recherche une compts de client
void recherche(){
   	char tmp[12];
   	int i,choi,c, position;
   	printf("entrer CIN de client que vous recherche \n");
   	scanf("%s",tmp);
   	for(i=0;i<nombreDuCompte;i++){
   		if (strcmp(tmp,C[i].CIN)==0){
         	printf("le client a rechercher a un montant %f",C[i].Montant);	
			 position = i; 
       } 
	}
	
     printf("les operation :\n");
     printf("1 : retrait\n");
     printf("2 : depot\n");
     printf("choisir une choix que vous volez ");
     scanf("%d",&choi);
     
     switch(choi){
     	case 1:
     		Retrait(position);
     		break;
 		case  2:
 			Depot(position);
 			break;
 		default :
 			printf("ce choix n'existe pas");
	 }

}	 
	 
// fonction premit de recherche un client par son CIN
void Recherche_par_CIN(){
	   	char tmp[12];
   	int i,choi,c;
   	printf("entrer CIN de client que vous recherche \n");
   	scanf("%s",tmp);
   	for(i=0;i<nombreDuCompte;i++){
   		if (strcmp(tmp,C[i].CIN)==0){
         	printf("le client a rechercher est Nom: %s  Prenom : %s CIN : %s  Montant : %f",C[i].Nom,C[i].Prenom,C[i].CIN,C[i].Montant);
        }
    }
	
}
//  Par Ordre Ascendant
void afficheAscendant(){
	int i;
  struct Client t;
	for (i=0;i<nombreDuCompte;i++){
		if(C[i].Montant>C[i+1].Montant);
		t=C[i];
		C[i]=C[i+1];
		C[i+1]=t;
	}
	for (i = 0; i <= nombreDuCompte ; i++) {
		printf("les comptes des client est %s %s %s %f \n \n ",C[i].Nom,C[i].Prenom,C[i].CIN,C[i].Montant);
	}
}
//Par Ordre Descendant
void afficheDescendant(){
	int i;
  struct Client t;
	for (i=0;i<nombreDuCompte;i++){
		if(C[i].Montant<C[i+1].Montant);
		t=C[i];
		C[i]=C[i+1];
		C[i+1]=t;
	}
	for (i = 0; i <= nombreDuCompte ; i++) {
		printf("les comptes des client est %s %s %s %f \n \n ",C[i].Nom,C[i].Prenom,C[i].CIN,C[i].Montant);
	}
}


 // fonction premit de affiche les cliens
void Affiche(){
	int ch;
	printf("1 : Par Ordre Ascendant\n 2:Par Ordre Descendant\n 3 : Compts superieur_Ascendant\n 4 : Compts superieur_Descendant");
	scanf("%d",&ch);
	switch(ch){
		case 1:
			afficheAscendant();
			break;
		case 2:
		    afficheDescendant();
			break;
		case 3:
			affichSUP();
			break;
		case 4:
			AffichD();
		    break;	
	}
	
	
}    
void rojo3(){
	int c;
	printf("1:retur au menu\n 2: sorti dans le programme\n");
	scanf("%d",&c);
	system("cls");
	switch(c){
		case 1:
			Menu();
			break;
		default :
			printf("vous avez quitter le programme");
	}
}

// Par Ordre Ascendant (les comptes bancaires ayant un montant supérieur à un chiffre introduit)
void affichSUP(){
		int i;
		float A;
		printf("saisir un Montant ");
		scanf("%f",&A);
  struct Client t;
	for (i=0;i<nombreDuCompte;i++){
		if(C[i].Montant>C[i+1].Montant);
		t=C[i];
		C[i]=C[i+1];
		C[i+1]=t;
	}
	for (i = 0; i <= nombreDuCompte ; i++) {
		if (C[i].Montant>A)
		printf("les comptes des client est %s %s %s %f \n \n ",C[i].Nom,C[i].Prenom,C[i].CIN,C[i].Montant);
	}
}
//Par Ordre Descendant (les comptes bancaires ayant un montant supérieur à un chiffre introduit)
void AffichD(){
		int i;
		float A;
		printf("saisir un Montant");
		scanf("%f",&A);
  struct Client t;
	for (i=0;i<nombreDuCompte;i++){
		if(C[i].Montant<C[i+1].Montant);
		t=C[i];
		C[i]=C[i+1];
		C[i+1]=t;
	}
	for (i = 0; i <= nombreDuCompte ; i++) {
		if (C[i].Montant>A)
		printf("les comptes des client est %s %s %s %f \n \n ",C[i].Nom,C[i].Prenom,C[i].CIN,C[i].Montant);
	}
	
}
//Fidélisation
void Fidelisation(){
	
}
void Menu(){
		int choix,i ,N,q;
   	
   		system("cls");
   		   printf("\t\t\t\tMENU\n");
   		   printf("\t\t\t1 : ajouter un seul Client\n\n");
   		   printf("\t\t\t2 : ajouter plusieur Client\n\n");
   		   printf("\t\t\t3 : operation \n\n");
   		   printf("\t\t\t4 : affichage\n\n");
   		   printf("\t\t\t5 : recherche un client par CIN \n\n");
   		   printf("\t\t\t0 : Quitter\n");
   		   printf("entree votre choix\t");
   		   scanf("%d",&choix);
   	    switch(choix){
   		 	case 1:
   		 		Ajouter_client();
   		 		rojo3();
   		 		break;
   		 		
   		 	case 2:
   		 		printf("donner nombre de compts\t");
   		 		scanf("%d",&N);
   		 		for(i=0;i<N;i++){
					 Ajouter_client();}
					 	rojo3();
   		 		break;
   		 	case 3:
            recherche();
            	rojo3();
            break;
            case 4:
            	Affiche();
            		rojo3();
            	break;
            case 5:
                Recherche_par_CIN();
            	rojo3();
            	break;
            default :            	
			printf("vous avez Quitter");
				 		
	   }
   		
}
int main(){
    	
   Menu(); 
	   
return 0;
}
                
