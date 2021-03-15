/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "panoply.h"
#include <string.h>

void
panoplyprog_1(char *host)
{
	int idTmp;
	CLIENT *clnt;
	boolean  *result_1;
	compte  creercompte_1_arg;
	boolean  *result_2;
	compte  seconnecter_1_arg;
	compte  *result_3, clientCompte;
	int  *affichercompte_1_arg;
	int  *result_4;
	char *nombrecompte_1_arg;
	boolean  *result_5;
	abonnement  creerabonnement_1_arg;
	int  *result_6;
	char *nombreabonnement_1_arg;
	abonnement  *result_7;
	int  afficherabonnement_1_arg;
	boolean  *result_8;
	abonnement  majunabonnement_1_arg;
	boolean  *result_9;
	compte  affectationabonnement_1_arg;
	boolean  *result_10;
	collection  creercollection_1_arg;
	int  *result_11;
	char *nombrecollection_1_arg;
	collection  *result_12;
	int  affichercollection_1_arg;
	boolean  *result_13;
	vetement  associervetementcollection_1_arg;
	boolean  *result_14;
	vetement  creervetement_1_arg;
	vetement  *result_15;
	int  affichervetement_1_arg;
	int  *result_16;
	char *nombrevetement_1_arg;
	boolean  *result_17;
	location  louervetement_1_arg;
	int  *result_18;
	char *nombrelocation_1_arg;
	location  *result_19;
	int  afficherlocation_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, PANOPLYPROG, PANOPLYVERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	
		printf("~~~~~~~~~ PARTIE GESTIONNAIRE ~~~~~~~~~~~ \n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
		printf("\n");
		printf("\n");
		printf("************ CREATION DE COMPTE *************\n");
		printf("\n");
		strcpy(creercompte_1_arg.nom,"Toto");
		strcpy(creercompte_1_arg.prenom,"Tuxie");
		creercompte_1_arg.identifiant=0;
		strcpy(creercompte_1_arg.mdp,"AZgestionnaire");
		strcpy(creercompte_1_arg.adresse,"Avenue Gorgeu");
		creercompte_1_arg.monType=gestionnaire; 
		result_1 = creercompte_1(&creercompte_1_arg, clnt);
		if (result_1 == (boolean *) NULL) {
		clnt_perror (clnt, "Creation échouée !");
		}
		if (*result_1==echoue)
		{
			printf("Creation du compte echoue!\n");
		}
		else
		{
			printf("Creation du compte %d d'ID %d reussi !!\n",creercompte_1_arg.monType,creercompte_1_arg.identifiant);
			printf("\n");
		}	
		
		printf("************ CONNEXION *************\n");
		printf("\n");
		result_2 = seconnecter_1(&creercompte_1_arg, clnt);
		if (result_2 == (boolean *) NULL) {
		clnt_perror (clnt, "CONNEXION échouée !");
		}
		printf("BIENVENUE au GESTIONNAIRE %s !!\n",creercompte_1_arg.prenom);

		printf("\n");

		printf("************ CREATION DE COLLECTION *************\n");

		char collections[5][20]={"Vestes","Robes","Manteaux","Sacs","Combis & Smokings"};

		for(int i = 0;i<5;i++)
		{	
			strcpy(creercollection_1_arg.nomCollection,collections[i]);
			creercollection_1_arg.idCollection=i;
			result_10 = creercollection_1(&creercollection_1_arg, clnt);
			if (result_10 == (boolean *) NULL) {
			clnt_perror (clnt, "Creation collection échouée !");
			}
			printf("Collection %s créée !!! \n",creercollection_1_arg.nomCollection);
			printf("\n");
		}
		printf("\n");
		printf("************ CREATION DE VÊTEMENT *************\n");

		char nomVetement[10][64]={"Veste Crop","Veste Velours","Robes droites","Robes Volantes","Manteau chiné","Manteau Corona","Clutch","Pochette","Combinaison à volant","Smoking soie"};
		int prixVetement[10]={89,96,95,84,115,180,82,92,114,116};
		int nbCredit[10]={3,2,1,2,1,1,2,1,3,3};
		int idVetement[10]={0,1,2,3,4,5,6,7,8,9};
		int nbExemplaire[10]={7,10,2,5,3,4,8,1,2,3};
		for(int i=0;i<10;i++)
		{	
			strcpy(creervetement_1_arg.nomVetement,nomVetement[i]);
			creervetement_1_arg.prixVetement=prixVetement[i];
			creervetement_1_arg.nbCredit=nbCredit[i];
			creervetement_1_arg.idVetement=idVetement[i];
			creervetement_1_arg.nbExemplaire=nbExemplaire[i];
			creervetement_1_arg.maCollection.idCollection=tableauCollection[i].idCollection;
			result_14 = creervetement_1(&creervetement_1_arg, clnt);
			if (result_14 == (boolean *) NULL) {
			clnt_perror (clnt, "Creation vetement échouée !!");
			}
			printf("Vêtement %s créé !!! \n",creervetement_1_arg.nomVetement);
		}
		printf("\n");
		printf("************ CREATION ABONNEMENT *************\n");

		int identifiant[4]={0,1,2,3};
		char nomabn[4][16]={"UN PEU","BEAUCOUP","PASSIONNÉMENT","A LA FOLIE"};
		int prix[4]={69,159,229,319};
		int nombreCredit[4]={1,3,5,8};
		for(int i=0;i<4;i++)
		{
			strcpy(creerabonnement_1_arg.nomabn,nomabn[i]);
			creerabonnement_1_arg.identifiant=identifiant[i];
			creerabonnement_1_arg.prix=prix[i];
			creerabonnement_1_arg.nombreCredit=nombreCredit[i];
			result_5 = creerabonnement_1(&creerabonnement_1_arg, clnt);
			if (result_5 == (boolean *) NULL) {
			clnt_perror (clnt, "Creation abonnement échouée");
			}
			printf("Abonnement %s créé !!! \n",creerabonnement_1_arg.nomabn);
		}
		printf("\n");
		printf("************ AFFICHAGE COMPTES ************\n");

		result_4 = nombrecompte_1((void*)&nombrecompte_1_arg, clnt);
		if (result_4 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
		}
		printf("Le nombre total de comptes dans la base %d \n",*result_4 );

		printf("\n");

		for(int i=0;i<*result_4;i++)
		{
			
			result_3 = affichercompte_1(&i, clnt);
			if (result_3 == (compte *) NULL) {
			clnt_perror (clnt, "call failed");
			}
			printf("****** Compte %d *****\n",i+1);
			printf("NOM : %s\n",result_3->nom);
			printf("PRENOM : %s\n",result_3->prenom);
			printf("IDENTIFIANT : %d\n",result_3->identifiant);
			printf("ADRESSE : %s\n",result_3->adresse);
			printf("TYPE DE COMPTE : %d\n",result_3->monType);
			if(result_3->monType==client)
			{
				printf("Abonnement %s\n",result_3->monEngagement.abn.nomabn );
				printf("Etat Abonnement %d\n",result_3->monEngagement.etat );
			}

			printf("\n");
		}

		printf("~~~~~~~~~ PARTIE CLIENT ~~~~~~~~~~~ \n");	
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
		printf("\n");
		printf("\n");
		printf("************ CREATION DE COMPTE *************\n");
		printf("\n");
		strcpy(clientCompte.nom,"Leclerc");
		strcpy(clientCompte.prenom,"Jean");
		clientCompte.identifiant=1;
		strcpy(clientCompte.mdp,"JLeclerc");
		strcpy(clientCompte.adresse,"89 rue Jean-jaures");
		clientCompte.monType=client; 
		result_1 = creercompte_1(&clientCompte, clnt);
		if (result_1 == (boolean *) NULL) {
		clnt_perror (clnt, "Creation échouée !");
		}
		if (*result_1==echoue )
		{
			printf("Creation du compte echoue \n");
			clnt_perror (clnt, "Creation échouée !");
		}
		else
		{
			printf("Creation compte reussie \n");
		}
		printf("\n");

		printf("************ CONNEXION *************\n");
		printf("\n");
		result_2 = seconnecter_1(&clientCompte, clnt);
		if (result_2 == (boolean *) NULL) {
		clnt_perror (clnt, "CONNEXION échouée !");
		}
		if (*result_2==echoue)
		{
			printf("Connexion echoue!\n");
			clnt_perror (clnt, "CONNEXION échouée !");
		}
		else
			printf("Connexion reussie!\n");

		printf("************ ABONNEMENT *************\n");
		printf("\n");
		
		result_6 = nombreabonnement_1((void*)&nombreabonnement_1_arg, clnt);
		if (result_6 == (int *) NULL) {
			clnt_perror (clnt, "call failed");
		}
		printf("Nous avons %d abonnement \n",(*result_6) );

		for (int i = 0; i < (*result_6); ++i)
		{
			result_7 = afficherabonnement_1(&i, clnt);
			if (result_7 == (abonnement *) NULL) {
				clnt_perror (clnt, "call failed");
			}
			printf("*******************************\n");
			printf("ABONNEMENT %d\n",i );
			printf("NOM :%s\n",result_7->nomabn);
			printf("PRIX :%d\n",result_7->prix);
			printf("NB CREDIT :%d\n",result_7->nombreCredit);
			printf("*******************************\n");
		}
		printf("AFFECTATION DE L'ABONNEMENT 3\n");
		clientCompte.monEngagement.abn.identifiant=3;
		result_9 = affectationabonnement_1(&clientCompte, clnt);
		if (result_9 == (boolean *) NULL) {
			clnt_perror (clnt, "call failed");
		}
		if (*result_9==echoue)
		{
			printf("affectation abonnement echoue!\n");
			clnt_perror (clnt, "affectation abonnement echoue!");
		}
		else
		{
			printf("affectation abonnement reussie!\n");
		}
		printf("\n");
		/**************************************************/
		printf("********************************************\n");
		printf("**************** COLLECTION ****************\n");
		result_11 = nombrecollection_1((void*)&nombrecollection_1_arg, clnt);
		if (result_11 == (int *) NULL) {
			clnt_perror (clnt, "call failed");
		}
		printf("Nous avons %d collections dans notre base\n",(*result_11));
		for (int i = 0; i < *result_11; ++i)
		{
			result_12 = affichercollection_1(&i, clnt);
			if (result_12 == (collection *) NULL) {
			clnt_perror (clnt, "call failed");
			}
			printf("*******************************\n");
			printf("COLLECTION %d\n",i);
			printf("NOM :%s\n",result_12->nomCollection);
			printf("*******************************\n");
		}
		printf("\n");
		printf("\n");
		printf("********************************************\n");
		printf("**************** VETEMENT ******************\n");
		result_16 = nombrevetement_1((void*)&nombrevetement_1_arg, clnt);
		if (result_16 == (int *) NULL) {
			clnt_perror (clnt, "call failed");
		}
		for (int i = 0; i < (*result_16); ++i)
		{
			result_15 = affichervetement_1(&i, clnt);
			if (result_15 == (vetement *) NULL) {
			clnt_perror (clnt, "call failed");
			}
			printf("\n");
			printf("VETEMENT n°%d\n",i);
			printf("NOM:%s\n",result_15->nomVetement);
			printf("PRIX: %d\n",result_15->prixVetement);
			printf("Nb Credit: %d\n",result_15->nbCredit);
			printf("Nb Exemplaire: %d\n",result_15->nbExemplaire);
			printf("\n");		
		}	
	/*louer un exemplaire du vetement 4*/
	printf("\n");
	printf("location du vetement4\n");
	louervetement_1_arg.identifiantClient=clientCompte.identifiant;
	louervetement_1_arg.identifiantVetement=4;

	result_17 = louervetement_1(&louervetement_1_arg, clnt);
	if (result_17 == (boolean *) NULL) {
		clnt_perror (clnt, "call failed");
	}
		if (*result_17==echoue)
	{
		printf("location echoue!\n");
	}
	else
		printf("location reussie!\n");

	/*louer un exemplaire du vetement 2*/
	printf("location du vetement 2\n");
	louervetement_1_arg.identifiantClient=clientCompte.identifiant;
	louervetement_1_arg.identifiantVetement=2;

	result_17 = louervetement_1(&louervetement_1_arg, clnt);
	if (result_17 == (boolean *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	if (*result_17==echoue)
	{
		printf("location echoue!\n");
	}
	else
		printf("location reussie!\n");

	/*louer un exemplaire du vetement 3*/
	printf("location du vetement 3\n");
	louervetement_1_arg.identifiantClient=clientCompte.identifiant;
	louervetement_1_arg.identifiantVetement=3;

	result_17 = louervetement_1(&louervetement_1_arg, clnt);
	if (result_17 == (boolean *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	if (*result_17==echoue)
	{
		printf("location echoue!\n");
	}
	else
		printf("location reussie!\n");


	printf("~~~~~~~~~~~~~FIN SCENARIO CLIENT~~~~~~~~~~~~\n");
	printf("\n");
	printf("\n");
	printf("~~~~~~~~~~~~~SUITE ET FIN SCENARIO GESTIONNAIRE~~~~~~~~~~~~\n");
	result_18 = nombrelocation_1((void*)&nombrelocation_1_arg, clnt);
	if (result_18 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	printf("AFFICHAGE LOCATIONS\n");
	for (int i = 0; i < *result_18; ++i)
	{
		result_19 = afficherlocation_1(&i, clnt);
		if (result_19 == (location *) NULL) {
			clnt_perror (clnt, "call failed");
		}
		printf("LOCATION N°%d CLIENT N° %5d VETEMENT N° %5d",result_19->identifiantLocation,result_19->identifiantClient,result_19->identifiantVetement);
		printf(" PRETE LE %d/%d/%d ",result_19->debut_location.jour,result_19->debut_location.mois,result_19->debut_location.annee );
		if (result_19->etatDeLaLocation==louer)
		{
			printf(" ETAT: LOUER\n");
		}
		else
			printf(" ETAT: RENDU\n");
	}
	printf("~~~~~~~~~~~~~FIN SCENARIO GESTIONNAIRE~~~~~~~~~~~~\n");

#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	panoplyprog_1 (host);
	
exit (0);
}
